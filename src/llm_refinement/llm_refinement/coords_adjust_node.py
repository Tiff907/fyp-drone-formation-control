"""
coords_adjust_node.py

Checks the points the LLM proposed for a refinement instruction and
publishes them as a RefinementCandidate for the user to ACCEPT / REJECT /
REDRAW.

    /refinement/generated_transform (GeneratedTransform) -> checks
        -> /refinement/candidate (RefinementCandidate)

The LLM only returns numbers, so nothing is executed here, and no spacing,
safety-radius or drone-count check is done: the proposal is a shape, and the
planning pipeline (sampling, validator, assignment, MAPF) deals with those
once the user accepts it. The only handling here is:
  1. the proposal must be non-empty and every coordinate finite,
  2. points are clamped into the canvas boundary so a stray coordinate
     cannot break the later coordinate mapping,
  3. the outline is resampled to exactly N_RAW_POINTS evenly spaced points,
     keeping sharp corners, so the sampler always gets the same kind of input
     whatever number or spacing of points the LLM returned.

candidate_colors carries the LLM's colours (resampled with the outline); if the LLM gave none it
is left empty and task_manager decides.

Any failure is reported on /formation/plan_status (success=False), which
task_manager turns into an ERROR the user can acknowledge.
"""

import json
import math
import os
import time

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import ColorRGBA

from formation_msgs.msg import GeneratedTransform, RefinementCandidate, PlanStatus


BOUNDARY_X = (-2.5, 2.5)  # canvas frame: x left-right
BOUNDARY_Y = (0.0, 3.0)   # canvas frame: y is height

N_RAW_POINTS = 30         # raw points handed to the sampler (it caps at 120)
CORNER_DEG = 35.0         # a turn sharper than this is a corner and is kept exactly
MIN_LENGTH = 0.05         # metres; shorter than this the shape has collapsed


class TransformError(Exception):
    """The proposed points could not be used."""


def _dist(a, b):
    return math.hypot(b[0] - a[0], b[1] - a[1])


def _point_at(pts, cum, d, with_index=False):
    """Point at arc-length d along the polyline pts (cum = cumulative lengths).
    With with_index, also returns the index of the nearer end of its segment."""
    lo, hi = 0, len(cum) - 1
    while hi - lo > 1:
        mid = (lo + hi) // 2
        if cum[mid] <= d:
            lo = mid
        else:
            hi = mid
    seg = cum[hi] - cum[lo]
    t = 0.0 if seg <= 0 else (d - cum[lo]) / seg
    pt = (pts[lo][0] + t * (pts[hi][0] - pts[lo][0]),
          pts[lo][1] + t * (pts[hi][1] - pts[lo][1]))
    return (pt, lo if t < 0.5 else hi) if with_index else pt


def resample_outline(pts, k=N_RAW_POINTS, corner_deg=CORNER_DEG, labels=None):
    """Resample an ordered outline to exactly k evenly spaced points.

    Sharp corners (turns above corner_deg) are kept as they are, so a square
    stays a square; the points in between are spread by arc length, with the
    count per side proportional to its length. A shape whose last point lands
    near its first is treated as closed.

    labels (one per input point, e.g. colours) are carried along: each output
    point gets the label of the nearer end of the segment it lies on. With
    labels the result is (points, labels).
    """
    # drop repeated points
    clean = [pts[0]]
    clean_lab = [labels[0]] if labels is not None else None
    for i, p in enumerate(pts[1:], 1):
        if _dist(p, clean[-1]) > 1e-6:
            clean.append(p)
            if labels is not None:
                clean_lab.append(labels[i])
    if len(clean) < 2:
        raise TransformError('Refined shape collapsed to a single point')

    gaps = sorted(_dist(a, b) for a, b in zip(clean, clean[1:]))
    median_gap = gaps[len(gaps) // 2]
    closed = len(clean) >= 3 and _dist(clean[0], clean[-1]) <= 1.5 * median_gap
    if closed and _dist(clean[0], clean[-1]) < 1e-6:
        clean.pop()                                   # explicit closing point
        if labels is not None:
            clean_lab.pop()
    path = clean + [clean[0]] if closed else clean    # closed: walk back to the start
    path_lab = (clean_lab + [clean_lab[0]] if closed else clean_lab) if labels is not None else None

    cum = [0.0]
    for a, b in zip(path, path[1:]):
        cum.append(cum[-1] + _dist(a, b))
    total = cum[-1]
    if total < MIN_LENGTH:
        raise TransformError('Refined shape collapsed to a point')

    # corner vertices (indices into path)
    def turn(i, j, l):
        ax, ay = path[j][0] - path[i][0], path[j][1] - path[i][1]
        bx, by = path[l][0] - path[j][0], path[l][1] - path[j][1]
        return abs(math.degrees(math.atan2(ax * by - ay * bx, ax * bx + ay * by)))

    # anchors: the start, every corner, and the end (for a closed shape the
    # end is the repeated start, which closes the last side)
    anchors = [0]
    for i in range(1, len(path) - 1):
        if turn(i - 1, i, i + 1) > corner_deg:
            anchors.append(i)
    anchors.append(len(path) - 1)
    n_sides = len(anchors) - 1
    n_out = k if closed else k - 1                    # an open path adds its end point below
    if n_sides > n_out:
        anchors = [0, len(path) - 1]                  # too many corners: plain even spacing
        n_sides = 1

    lengths = [cum[anchors[i + 1]] - cum[anchors[i]] for i in range(n_sides)]
    raw = [n_out * L / total for L in lengths]
    counts = [max(1, int(r)) for r in raw]
    while sum(counts) < n_out:
        counts[max(range(n_sides), key=lambda i: raw[i] - counts[i])] += 1
    while sum(counts) > n_out:
        cand = [i for i in range(n_sides) if counts[i] > 1]
        counts[min(cand, key=lambda i: raw[i] - counts[i])] -= 1

    out, out_lab = [], []
    for i in range(n_sides):
        d0, d1 = cum[anchors[i]], cum[anchors[i + 1]]
        for j in range(counts[i]):
            pt, idx = _point_at(path, cum, d0 + (d1 - d0) * j / counts[i], with_index=True)
            out.append(pt)
            if labels is not None:
                out_lab.append(path_lab[idx])
    if not closed:
        out.append(path[-1])
        if labels is not None:
            out_lab.append(path_lab[-1])
    return (out, out_lab) if labels is not None else out


def apply_transform(proposed, points=None, n_raw=N_RAW_POINTS, labels=None):
    """Turn the proposal into a clean list of exactly n_raw (x, y) tuples.

    `points` (the current shape) is accepted for API compatibility and is
    not used. Plain lists in and out, so it is usable without ROS. If labels
    (one per proposed point, e.g. colours) are given, they are resampled
    along with the outline and the result is (points, labels).
    """
    if labels is not None and len(labels) != len(proposed):
        labels = None
    try:
        pts = [(float(p[0]), float(p[1])) for p in proposed]
    except (TypeError, ValueError, IndexError) as exc:
        raise TransformError(f'Could not read proposed points: {exc}')
    if not pts:
        raise TransformError('Refined shape has no points')
    out = []
    for i, (x, y) in enumerate(pts):
        if not (math.isfinite(x) and math.isfinite(y)):
            raise TransformError(f'Point {i} is not a finite number')
        out.append((min(max(x, BOUNDARY_X[0]), BOUNDARY_X[1]),
                    min(max(y, BOUNDARY_Y[0]), BOUNDARY_Y[1])))
    return resample_outline(out, n_raw, labels=labels)


# ---------------------------------------------------------------------
# ROS 2 node
# ---------------------------------------------------------------------

class CoordsAdjustNode(Node):

    def __init__(self):
        super().__init__('coords_adjust_node')

        self.declare_parameter('log_path', os.path.expanduser('~/llm_refinement_log.jsonl'))
        self.declare_parameter('n_raw_points', N_RAW_POINTS)

        self.create_subscription(
            GeneratedTransform, '/refinement/generated_transform', self._on_transform, 10)
        self._cand_pub = self.create_publisher(RefinementCandidate, '/refinement/candidate', 10)
        self._status_pub = self.create_publisher(PlanStatus, '/formation/plan_status', 10)

        self.get_logger().info('coords_adjust_node started')

    def _log(self, record):
        path = self.get_parameter('log_path').value
        if not path:
            return
        try:
            with open(path, 'a') as f:
                f.write(json.dumps(record) + '\n')
        except OSError as exc:
            self.get_logger().warn(f'Could not write log: {exc}')

    def _on_transform(self, msg: GeneratedTransform):
        try:
            self._handle_transform(msg)
        except Exception as exc:                            # noqa: BLE001
            self.get_logger().error(f'Unexpected error: {type(exc).__name__}: {exc}')
            self._fail(f'Refinement failed: {type(exc).__name__}: {str(exc)[:80]}')

    def _handle_transform(self, msg: GeneratedTransform):
        points = [(p.x, p.y) for p in msg.current_points]
        proposed = [(p.x, p.y) for p in msg.proposed_points]
        labels = ([(c.r, c.g, c.b, c.a) for c in msg.proposed_colors]
                  if len(msg.proposed_colors) == len(proposed) else None)
        t0 = time.time()
        record = {'stage': 'coords_adjust', 'time': t0, 'n_in': len(points),
                  'plan': msg.plan_description, 'proposed': proposed}
        try:
            out = apply_transform(proposed, points,
                                  n_raw=int(self.get_parameter('n_raw_points').value),
                                  labels=labels)
        except TransformError as exc:
            record.update(passed=False, reason=str(exc), seconds=time.time() - t0)
            self._log(record)
            self.get_logger().error(f'Refinement rejected: {exc}')
            self._fail(f'Refinement rejected: {exc}')
            return

        out_colors = None
        if labels is not None:
            out, out_colors = out
        record.update(passed=True, n_out=len(out), coloured=out_colors is not None,
                      seconds=time.time() - t0)
        self._log(record)

        cand = RefinementCandidate()
        cand.candidate_points = [Point(x=x, y=y, z=0.0) for x, y in out]
        # The LLM's own colours, resampled with the outline. Empty when it gave
        # none; task_manager then carries the old colours along the outline.
        cand.candidate_colors = ([ColorRGBA(r=r, g=g, b=b, a=a) for r, g, b, a in out_colors]
                                 if out_colors else [])
        cand.plan_description = msg.plan_description
        self._cand_pub.publish(cand)
        self.get_logger().info(f'Published refinement candidate ({len(out)} points)')

    def _fail(self, message: str):
        status = PlanStatus()
        status.success = False
        status.status_message = message
        status.usable_drone_count = 0
        self._status_pub.publish(status)


def main(args=None):
    rclpy.init(args=args)
    node = CoordsAdjustNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
