"""
shape_sampling_node.py

Shape sampling: Visvalingam-Whyatt point reduction with Kneedle-based
N_min detection, colour carried through every stage.

On receiving a drawn shape, reports N_min. On receiving a
SampleRequest for a specific target_n, returns exactly that many
points with their original drawn colours.

Run directly (python3 shape_sampling_node.py) to exercise the
algorithm standalone against test shapes, without ROS2.

Run via:
    ros2 run formation_planner shape_sampling_node

as the actual ROS2 node.
"""

import numpy as np
import visvalingamwyatt as vw
from kneed import KneeLocator


# ---------------------------------------------------------------------
# Core algorithm (no ROS2 dependency)
# ---------------------------------------------------------------------

# ---------------------------------------------------------------------
# Spacing repair (swap a too-close point for another raw point)
#
# Visvalingam-Whyatt keeps the N most important points. The set kept at
# N-1 is the set at N minus its least important point, so two important
# points that are closer than the safety radius (e.g. the overlapping
# ends of a hand-drawn closed shape, or two sides of a narrow part)
# stay too close at every N, and a loop that only lowers N ends up
# rejecting. Here, violations are repaired one at a time, worst first:
#   1. SWAP: replace one point of the pair with another raw point from
#      the stretch of the stroke it owns (between its two kept
#      neighbours), choosing the valid one closest to the original.
#   2. DROP: if no swap works, drop the less important point of the
#      pair (never below n_min).
#   3. Otherwise stop; the validator remains the independent judge.
# A swap only moves a point to a spot that is valid against all other
# kept points, so it cannot create a new violation and the loop ends.
# ---------------------------------------------------------------------

SAFETY_RADIUS = 0.30   # metres; keep equal to the validator and CBS values
MARGIN = 0.02          # repair to slightly more than the radius, so the
                       # validator's >= test is never borderline
BOUNDARY_X = (-2.5, 2.5)
BOUNDARY_Y = (0.0, 3.0)


def _in_bounds_mask(P, bx=BOUNDARY_X, by=BOUNDARY_Y):
    return (P[:, 0] >= bx[0]) & (P[:, 0] <= bx[1]) & \
           (P[:, 1] >= by[0]) & (P[:, 1] <= by[1])


def _tri_area(a, b, c):
    return 0.5 * abs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]))


def _importance(P, kept, k):
    """VW-style importance of kept[k]: area of the triangle it forms with
    its kept neighbours. End points are treated as most important."""
    if k == 0 or k == len(kept) - 1:
        return np.inf
    return _tri_area(P[kept[k - 1]], P[kept[k]], P[kept[k + 1]])


def _first_violation(P, kept, min_dist, bx, by):
    """Return ('bound', k) or ('pair', i, j) for the worst violation,
    or None if the selection is clean. Boundary problems come first."""
    K = P[kept]
    oob = np.where(~_in_bounds_mask(K, bx, by))[0]
    if len(oob) > 0:
        return ('bound', int(oob[0]))
    if len(K) < 2:
        return None
    diff = K[:, None, :] - K[None, :, :]
    D = np.hypot(diff[..., 0], diff[..., 1])
    np.fill_diagonal(D, np.inf)
    i, j = np.unravel_index(np.argmin(D), D.shape)
    if D[i, j] < min_dist:
        return ('pair', int(min(i, j)), int(max(i, j)))
    return None


def _best_replacement(P, kept, k, min_dist, bx, by):
    """Find another raw point for kept[k], taken from the stretch of the
    stroke between its kept neighbours. It must be inside the boundary
    and at least min_dist from every other kept point. Of the valid
    candidates, return the one closest to the point it replaces (so the
    outline barely changes), or None if there is no valid candidate."""
    lo = kept[k - 1] + 1 if k > 0 else 0
    hi = kept[k + 1] - 1 if k < len(kept) - 1 else len(P) - 1
    if hi < lo:
        return None
    cand_idx = np.arange(lo, hi + 1)
    cand_idx = cand_idx[cand_idx != kept[k]]
    if len(cand_idx) == 0:
        return None
    C = P[cand_idx]
    others = P[[idx for n, idx in enumerate(kept) if n != k]]
    ok = _in_bounds_mask(C, bx, by)
    if len(others) > 0:
        diff = C[:, None, :] - others[None, :, :]
        dmin = np.hypot(diff[..., 0], diff[..., 1]).min(axis=1)
        ok &= dmin >= min_dist
    if not ok.any():
        return None
    cand_idx, C = cand_idx[ok], C[ok]
    d_to_orig = np.hypot(C[:, 0] - P[kept[k]][0], C[:, 1] - P[kept[k]][1])
    return int(cand_idx[np.argmin(d_to_orig)])


def repair_indices(points, kept, n_min,
                   min_dist=SAFETY_RADIUS + MARGIN,
                   bx=BOUNDARY_X, by=BOUNDARY_Y, max_iter=500):
    """
    Repair a selection of raw-point indices so that all kept points are
    inside the boundary and at least min_dist apart.

    points : (n_raw, 2) raw point pool, in path order
    kept   : indices into points chosen by VW
    n_min  : never drop below this many points
    Returns (kept_indices, info) with info = {'swaps', 'drops', 'clean'}.
    """
    P = np.asarray(points, dtype=float)
    kept = sorted(set(int(i) for i in kept))
    swaps = drops = 0
    clean = False

    for _ in range(max_iter):
        v = _first_violation(P, kept, min_dist, bx, by)
        if v is None:
            clean = True
            break

        if v[0] == 'bound':
            order = [v[1]]
        else:
            order = sorted([v[1], v[2]], key=lambda k: _importance(P, kept, k))

        moved = False
        for k in order:                       # try the less important one first
            new = _best_replacement(P, kept, k, min_dist, bx, by)
            if new is not None:
                kept[k] = new
                swaps += 1
                moved = True
                break
        if moved:
            continue

        if len(kept) - 1 >= n_min:            # no swap possible: drop one
            del kept[order[0]]
            drops += 1
            continue
        break                                 # give up; validator will decide

    return kept, {'swaps': swaps, 'drops': drops, 'clean': clean}


def cap_raw_points(points, colors=None, max_pts=30):
    """
    Caps raw points to a maximum number of points using uniform
    downsampling.

    If colors are supplied, the corresponding colors are sampled using
    exactly the same indices so point/color alignment is preserved.

    Parameters
    ----------
    points : list
        List of (x, y) points.

    colors : list or None
        Optional list of colors corresponding to points.

    max_pts : int
        Maximum number of points to keep.

    Returns
    -------
    If colors is None:
        capped_points

    If colors is supplied:
        capped_points, capped_colors
    """

    if max_pts <= 0:
        raise ValueError("max_pts must be greater than 0")

    # Nothing to cap
    if len(points) <= max_pts:
        if colors is None:
            return list(points)

        return list(points), list(colors)

    # Uniformly select max_pts indices
    step = len(points) / max_pts
    indices = [int(i * step) for i in range(max_pts)]

    capped_points = [points[i] for i in indices]

    if colors is None:
        return capped_points

    capped_colors = [colors[i] for i in indices]

    return capped_points, capped_colors


N_MIN_TOL = 0.04   # outline may deviate by this fraction of the shape's diagonal


def _dist_to_segment(p, a, b):
    ab = b - a
    L = float(ab @ ab)
    t = 0.0 if L == 0 else max(0.0, min(1.0, float((p - a) @ ab) / L))
    return float(np.hypot(*(p - (a + t * ab))))


def _rdp(P, i, j, tol, keep):
    """Ramer-Douglas-Peucker: add to keep the vertices between i and j that
    are needed to stay within tol of the original outline."""
    if j <= i + 1:
        return
    d = [_dist_to_segment(P[k], P[i], P[j]) for k in range(i + 1, j)]
    m = int(np.argmax(d))
    if d[m] > tol:
        k = i + 1 + m
        keep.add(k)
        _rdp(P, i, k, tol, keep)
        _rdp(P, k, j, tol, keep)


def shape_n_min(points, floor=3, tol_frac=N_MIN_TOL):
    """
    N_min judged from the shape itself: the number of vertices needed to
    redraw the outline within tol_frac of its diagonal. A square needs 4,
    a triangle 3, a circle about 8, a star 10; collinear points cost
    nothing, so how many raw points the outline happens to have does not
    matter. A closed outline (last point near the first) is split at the
    point farthest from the start, so it is treated as a loop.
    """
    P = np.asarray(points, dtype=float)
    n = len(P)
    if n <= floor:
        return n
    diag = float(np.hypot(*(P.max(axis=0) - P.min(axis=0))))
    if diag == 0:
        return floor
    gaps = np.sort(np.hypot(*(P[1:] - P[:-1]).T))
    closed = float(np.hypot(*(P[0] - P[-1]))) <= 1.5 * gaps[len(gaps) // 2]
    tol = tol_frac * diag
    keep = set()
    if closed:
        f = int(np.argmax(np.hypot(*(P - P[0]).T)))
        keep |= {0, f}
        _rdp(P, 0, f, tol, keep)
        _rdp(np.vstack([P, P[:1]]), f, n, tol, keep)
        keep.discard(n)
    else:
        keep |= {0, n - 1}
        _rdp(P, 0, n - 1, tol, keep)
    return max(floor, min(n, len(keep)))


def find_n_min(points, floor=3):
    """
    Determines the minimum number of points that keeps the shape
    recognisable, using the Kneedle algorithm over Visvalingam-Whyatt's
    natural removal order.

    Internally caps to 40 points for threshold computation only.
    The original point set is not modified.

    Parameters
    ----------
    points : list of (x, y)
        Input shape points.

    floor : int
        Minimum allowed N_min.

    Returns
    -------
    int
        Estimated minimum useful number of points.
    """

    if len(points) <= floor:
        return len(points)

    # Geometry-only cap.
    # This returns only points because colors are not supplied.
    capped = cap_raw_points(points, max_pts=30)

    if len(capped) <= floor:
        return len(capped)

    simplifier = vw.Simplifier(capped)

    thresholds = np.sort(np.asarray(simplifier.thresholds))

    n = len(capped)
    n_removable = len(thresholds)

    # Not enough information for Kneedle, or degenerate threshold data:
    # judge the shape directly instead of using a fixed number.
    if n_removable < 3 or thresholds.max() == thresholds.min():
        return shape_n_min(capped, floor)

    ranks = np.arange(n_removable)

    kl = KneeLocator(
        ranks,
        thresholds,
        curve='convex',
        direction='increasing',
        interp_method='polynomial',
        S=0.5
    )

    if kl.knee is None:
        # No knee in the VW curve (common once points are evenly spaced or
        # collinear): judge the shape directly instead of using n * 0.3.
        return shape_n_min(capped, floor)

    n_removed_at_elbow = int(kl.knee) + 1

    n_min = n - n_removed_at_elbow

    return max(floor, n_min)


def sample_to_n(points, colors, target_n):
    """
    Reduces or interpolates the drawn stroke to exactly target_n points.
    Uses Visvalingam-Whyatt to preserve sharp corners when possible,
    and falls back to uniform arc-length interpolation if exact target_n 
    cannot be met by VW alone.
    """
    if len(points) == 0:
        return [], []

    if len(colors) == 0:
        colors = [None] * len(points)
    elif len(colors) == 1 and len(points) > 1:
        colors = list(colors) * len(points)
    elif len(colors) != len(points):
        raise ValueError(f"Point/color length mismatch: {len(points)} points vs {len(colors)} colors")

    target_n = max(1, int(target_n))
    pts_arr = np.array(points)

    if target_n >= len(points):
        return list(points), list(colors)

    # 1. Try Visvalingam-Whyatt simplification first to keep sharp corners
    simplifier = vw.Simplifier(points)
    try:
        simplified = simplifier.simplify(number=target_n)
    except Exception:
        simplified = []

    vw_points = []
    vw_colors = []
    used_indices = set()

    for sp in simplified:
        sp = np.asarray(sp)
        dists = np.hypot(pts_arr[:, 0] - sp[0], pts_arr[:, 1] - sp[1])
        for idx in used_indices:
            dists[idx] = np.inf
        idx = int(np.argmin(dists))
        used_indices.add(idx)
        vw_points.append(tuple(points[idx]))
        vw_colors.append(colors[idx])

    # 2. If VW gave us enough points, use them. Otherwise, blend with arc-length interpolation
    if len(vw_points) >= target_n:
        # Sort back to original order along the path
        # (or take first target_n points)
        return vw_points[:target_n], vw_colors[:target_n]

    # Fallback/Supplement with cumulative arc-length interpolation to guarantee target_n
    diffs = np.diff(pts_arr, axis=0)
    segment_lengths = np.hypot(diffs[:, 0], diffs[:, 1])
    cumulative_lengths = np.insert(np.cumsum(segment_lengths), 0, 0.0)
    total_length = cumulative_lengths[-1]

    if total_length == 0.0:
        return [points[0]] * target_n, [colors[0]] * target_n

    target_distances = np.linspace(0, total_length, target_n)
    sampled_points = []
    sampled_colors = []

    for dist in target_distances:
        idx = np.searchsorted(cumulative_lengths, dist) - 1
        idx = max(0, min(idx, len(pts_arr) - 2))

        seg_start_dist = cumulative_lengths[idx]
        seg_end_dist = cumulative_lengths[idx + 1]
        seg_len = seg_end_dist - seg_start_dist

        t = 0.0 if seg_len == 0.0 else (dist - seg_start_dist) / seg_len

        p0 = pts_arr[idx]
        p1 = pts_arr[idx + 1]
        interp_x = p0[0] + t * (p1[0] - p0[0])
        interp_y = p0[1] + t * (p1[1] - p0[1])
        sampled_points.append((interp_x, interp_y))
        sampled_colors.append(colors[idx])

    return sampled_points, sampled_colors


def vw_indices(points, target_n):
    """Indices (into points, in path order) of the target_n points that
    Visvalingam-Whyatt keeps. Returns [] if VW fails."""
    pts_arr = np.asarray(points, dtype=float)
    try:
        simplified = vw.Simplifier(points).simplify(number=target_n)
    except Exception:
        return []

    used = set()
    idxs = []
    for sp in simplified:
        sp = np.asarray(sp)
        dists = np.hypot(pts_arr[:, 0] - sp[0], pts_arr[:, 1] - sp[1])
        for u in used:
            dists[u] = np.inf
        i = int(np.argmin(dists))
        used.add(i)
        idxs.append(i)
    return sorted(idxs)


def sample_to_n_spaced(points, colors, target_n, n_min=1, return_info=False):
    """
    Like sample_to_n, but if two of the chosen points are closer than the
    safety radius (or outside the boundary), tries a different raw point
    for one of them before giving up (see the spacing repair section above). The result
    can have fewer than target_n points only if a swap was impossible,
    and never fewer than n_min.
    """
    info = {'swaps': 0, 'drops': 0, 'clean': True}

    def done(pts, cols):
        return (pts, cols, info) if return_info else (pts, cols)

    if len(points) == 0:
        return done([], [])

    if len(colors) == 0:
        colors = [None] * len(points)
    elif len(colors) == 1 and len(points) > 1:
        colors = list(colors) * len(points)
    elif len(colors) != len(points):
        raise ValueError(f"Point/color length mismatch: {len(points)} points vs {len(colors)} colors")

    target_n = max(1, int(target_n))

    if target_n >= len(points):
        idxs = list(range(len(points)))
    else:
        idxs = vw_indices(points, target_n)
        if len(idxs) < target_n:
            # VW could not give exactly target_n raw points: use the
            # original arc-length fallback (no raw points to swap to).
            pts, cols = sample_to_n(points, colors, target_n)
            return done(pts, cols)

    idxs, info = repair_indices(points, idxs, n_min=max(1, int(n_min or 1)))
    return done([tuple(points[i]) for i in idxs], [colors[i] for i in idxs])


def remove_close_points(points, colors, min_distance=0.35):
    """
    Removes consecutive points that are closer than min_distance.

    The matching colors are removed at the same time.

    Also checks the closing gap between the last and first point
    because the drawn shape is treated as a closed shape.
    """

    if len(points) <= 2:
        return list(points), list(colors)

    # Safety: make sure colors match points
    if len(colors) == 1 and len(points) > 1:
        colors = list(colors) * len(points)

    if len(colors) != len(points):
        raise ValueError(
            f"Point/color length mismatch in remove_close_points: "
            f"{len(points)} points vs {len(colors)} colors"
        )

    filtered_points = [points[0]]
    filtered_colors = [colors[0]]

    # Remove consecutive points that are too close
    for p, c in zip(points[1:], colors[1:]):

        last_p = filtered_points[-1]

        dist = np.hypot(
            p[0] - last_p[0],
            p[1] - last_p[1]
        )

        if dist >= min_distance:
            filtered_points.append(p)
            filtered_colors.append(c)

    # Check closing gap for closed shape
    if len(filtered_points) > 2:

        dist_loop = np.hypot(
            filtered_points[0][0] - filtered_points[-1][0],
            filtered_points[0][1] - filtered_points[-1][1]
        )

        if dist_loop < min_distance:
            filtered_points.pop()
            filtered_colors.pop()

    return filtered_points, filtered_colors


# ---------------------------------------------------------------------
# ROS2 node
# ---------------------------------------------------------------------

def _build_node():
    """
    Deferred rclpy/formation_msgs import.

    This allows the algorithm to be tested standalone with:

        python3 shape_sampling_node.py

    without requiring ROS2 imports at module import time.
    """

    import rclpy
    from rclpy.node import Node

    from geometry_msgs.msg import Point

    from formation_msgs.msg import (
        DrawnShape,
        SampleRequest,
        SampledPoints
    )

    # -------------------------------------------------------------
    # ROS message conversion
    # -------------------------------------------------------------

    def points_from_msg(msg):
        """
        Convert DrawnShape ROS message into Python point/color lists.

        The DrawnShape message may contain one stroke color for the
        entire shape. Internally we expand that single color so there
        is one color per point.
        """

        points = [
            (p.x, p.y)
            for p in msg.raw_points
        ]

        colors = list(msg.stroke_colors)

        # No points
        if len(points) == 0:
            return [], []

        # No colors supplied
        if len(colors) == 0:
            colors = [None] * len(points)

        # One color applies to the entire stroke
        elif len(colors) == 1 and len(points) > 1:
            colors = colors * len(points)

        # Otherwise colors must correspond to points
        elif len(colors) != len(points):
            raise ValueError(
                f"DrawnShape contains {len(points)} points but "
                f"{len(colors)} colors. Expected either 1 color "
                f"or one color per point."
            )

        return points, colors

    # -------------------------------------------------------------
    # Point conversion
    # -------------------------------------------------------------

    def to_point_msg(p):
        pt = Point()

        pt.x = float(p[0])
        pt.y = float(p[1])
        pt.z = 0.0

        return pt

    # -------------------------------------------------------------
    # ROS2 Node
    # -------------------------------------------------------------

    class ShapeSamplingNode(Node):

        # Candidate pool for sampling. find_n_min() still caps to 30
        # internally, so N_min is computed as before; the larger pool
        # only gives the spacing repair more raw points to choose from.
        MAX_RAW_POINTS = 120

        def __init__(self):

            super().__init__('shape_sampling_node')

            # Current shape stored by the node
            self._current_points = None
            self._current_colors = None

            # Calculated minimum number of useful points
            self._n_min = None

            # -------------------------------------------------
            # Subscribers
            # -------------------------------------------------

            self.create_subscription(
                DrawnShape,
                '/formation/drawn_shape',
                self._on_drawn_shape,
                10
            )

            self.create_subscription(
                SampleRequest,
                '/formation/sample_request',
                self._on_sample_request,
                10
            )

            # -------------------------------------------------
            # Publisher
            # -------------------------------------------------

            self._result_pub = self.create_publisher(
                SampledPoints,
                '/formation/sampled_points',
                10
            )

            self.get_logger().info(
                'shape_sampling_node started'
            )

        # ---------------------------------------------------------
        # Drawn shape callback
        # ---------------------------------------------------------

        def _on_drawn_shape(self, msg):

            try:

                points, colors = points_from_msg(msg)

            except ValueError as exc:

                self.get_logger().error(
                    f'Invalid DrawnShape: {exc}'
                )

                return

            # -------------------------------------------------
            # Check for empty shape
            # -------------------------------------------------

            if len(points) == 0:

                self.get_logger().warn(
                    'Received drawn shape with no points'
                )

                self._current_points = []
                self._current_colors = []
                self._n_min = 0

                result = SampledPoints()

                result.n_min_only = True
                result.n_min = 0
                result.target_n_used = 0

                self._result_pub.publish(result)

                return

            # -------------------------------------------------
            # Cap raw points and colors together
            # -------------------------------------------------

            points, colors = cap_raw_points(
                points,
                colors,
                max_pts=self.MAX_RAW_POINTS
            )

            # -------------------------------------------------
            # Store current shape
            # -------------------------------------------------

            self._current_points = points
            self._current_colors = colors

            # -------------------------------------------------
            # Determine N_min
            # -------------------------------------------------

            self._n_min = find_n_min(points)

            self.get_logger().info(
                f'Received drawn shape '
                f'({len(points)} raw points), '
                f'N_min = {self._n_min}'
            )

            # -------------------------------------------------
            # Publish N_min-only result
            # -------------------------------------------------

            result = SampledPoints()

            result.n_min_only = True
            result.n_min = self._n_min
            result.target_n_used = 0

            self._result_pub.publish(result)

        # ---------------------------------------------------------
        # Sample request callback
        # ---------------------------------------------------------

        def _on_sample_request(self, msg):

            # No shape received yet
            if self._current_points is None:

                self.get_logger().warn(
                    'SampleRequest received but no drawn '
                    'shape stored yet'
                )

                return

            target_n = int(msg.target_n)

            # -------------------------------------------------
            # Validate target
            # -------------------------------------------------

            if target_n <= 0:

                self.get_logger().warn(
                    f'Invalid target_n={target_n}; '
                    f'target_n must be greater than 0'
                )

                return

            try:

                # -------------------------------------------------
                # VW sampling
                # -------------------------------------------------

                sampled, sampled_colors, repair = sample_to_n_spaced(
                    self._current_points,
                    self._current_colors,
                    target_n,
                    n_min=self._n_min,
                    return_info=True
                )

                if repair['swaps'] or repair['drops']:
                    self.get_logger().info(
                        f"Spacing repair: {repair['swaps']} swaps, "
                        f"{repair['drops']} drops"
                    )

                # -------------------------------------------------
                # Remove consecutive points that are too close. After
                # the repair this does nothing, except in the
                # arc-length fallback, which has no raw points to swap.
                # -------------------------------------------------

                sampled, sampled_colors = remove_close_points(
                    sampled,
                    sampled_colors,
                    min_distance=SAFETY_RADIUS
                )

            except (ValueError, RuntimeError) as exc:

                self.get_logger().error(
                    f'Failed to sample shape: {exc}'
                )

                return

            # -------------------------------------------------
            # Create result message
            # -------------------------------------------------

            result = SampledPoints()

            result.n_min_only = False
            result.n_min = self._n_min
            result.target_n_used = len(sampled)

            result.points = [
                to_point_msg(p)
                for p in sampled
            ]

            result.colors = sampled_colors

            # -------------------------------------------------
            # Publish
            # -------------------------------------------------

            self.get_logger().info(
                f'Sampled to {len(sampled)} points '
                f'(requested {target_n})'
            )

            self._result_pub.publish(result)

    return rclpy, ShapeSamplingNode


# ---------------------------------------------------------------------
# ROS2 main
# ---------------------------------------------------------------------

def main(args=None):

    rclpy, ShapeSamplingNode = _build_node()

    rclpy.init(args=args)

    node = ShapeSamplingNode()

    try:

        rclpy.spin(node)

    except KeyboardInterrupt:
        pass

    finally:

        node.destroy_node()
        rclpy.shutdown()


# ---------------------------------------------------------------------
# Standalone test harness
# ---------------------------------------------------------------------

if __name__ == '__main__':

    import matplotlib.pyplot as plt

    # -------------------------------------------------------------
    # Test shape generators
    # -------------------------------------------------------------

    def circle_points(n=60, r=2.0):

        angles = np.linspace(
            0,
            2 * np.pi,
            n,
            endpoint=False
        )

        return [
            (r * np.cos(a), r * np.sin(a))
            for a in angles
        ]

    def star_points(
        n_spikes=5,
        r_outer=2.0,
        r_inner=1.0,
        points_per_edge=6
    ):

        pts = []

        n_verts = n_spikes * 2

        for i in range(n_verts):

            angle = i * np.pi / n_spikes

            r = (
                r_outer
                if i % 2 == 0
                else r_inner
            )

            pts.append(
                (
                    r * np.cos(angle),
                    r * np.sin(angle)
                )
            )

        dense = []

        for i in range(len(pts)):

            p0 = pts[i]
            p1 = pts[(i + 1) % len(pts)]

            for t in np.linspace(
                0,
                1,
                points_per_edge,
                endpoint=False
            ):

                dense.append(
                    (
                        p0[0] + (p1[0] - p0[0]) * t,
                        p0[1] + (p1[1] - p0[1]) * t
                    )
                )

        return dense

    def zigzag_points(
        n_segments=8,
        amplitude=1.0,
        length=5.0
    ):

        xs = np.linspace(
            0,
            length,
            n_segments * 4
        )

        ys = [
            amplitude
            * (
                1
                if (i // 4) % 2 == 0
                else -1
            )
            * (i % 4)
            / 4
            for i in range(len(xs))
        ]

        return list(zip(xs, ys))

    # -------------------------------------------------------------
    # Test shapes
    # -------------------------------------------------------------

    test_shapes = {
        'circle (smooth curve)': circle_points(),
        'star (sharp features)': star_points(),
        'zigzag (many gentle bends)': zigzag_points(),
    }

    fig, axes = plt.subplots(
        1,
        len(test_shapes),
        figsize=(14, 4)
    )

    for ax, (name, pts) in zip(
        axes,
        test_shapes.items()
    ):

        # One placeholder color for every point
        colors = [
            (1.0, 0.0, 0.0, 1.0)
        ] * len(pts)

        # Find N_min
        n_min = find_n_min(pts)

        # Sample
        sampled, sampled_colors = sample_to_n(
            pts,
            colors,
            n_min
        )

        # Remove close points
        sampled, sampled_colors = remove_close_points(
            sampled,
            sampled_colors,
            min_distance=0.5
        )

        # ---------------------------------------------------------
        # Print result
        # ---------------------------------------------------------

        print(
            f'{name}: '
            f'{len(pts)} raw points -> '
            f'N_min = {n_min} '
            f'(post-filtered: {len(sampled)})'
        )

        print(
            '  sampled points:',
            [
                (
                    round(x, 2),
                    round(y, 2)
                )
                for x, y in sampled
            ]
        )

        print()

        # ---------------------------------------------------------
        # Plot
        # ---------------------------------------------------------

        if len(sampled) > 0:

            xs, ys = zip(*sampled)

            ax.plot(
                xs,
                ys,
                'o-',
                color='b',
                markersize=6,
                linewidth=2
            )

        ax.set_title(
            f"{name}\nN_min = {len(sampled)}"
        )

        ax.grid(True)

        ax.set_aspect(
            'equal',
            adjustable='datalim'
        )

    plt.tight_layout()

    plt.show()
