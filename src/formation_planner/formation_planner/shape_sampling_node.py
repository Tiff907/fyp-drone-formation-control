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

def cap_raw_points(points, colors=None, max_pts=40):
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
    capped = cap_raw_points(points, max_pts=40)

    if len(capped) <= floor:
        return len(capped)

    simplifier = vw.Simplifier(capped)

    thresholds = np.sort(np.asarray(simplifier.thresholds))

    n = len(capped)
    n_removable = len(thresholds)

    # Not enough information for Kneedle
    if n_removable < 3:
        return max(floor, n)

    # Avoid degenerate threshold data
    if thresholds.max() == thresholds.min():
        return max(floor, n)

    ranks = np.arange(n_removable)

    kl = KneeLocator(
        ranks,
        thresholds,
        curve='convex',
        direction='increasing',
        interp_method='polynomial',
        S=1.0
    )

    if kl.knee is None:
        # Fallback
        return max(floor, int(n * 0.3))

    n_removed_at_elbow = int(kl.knee) + 1

    n_min = n - n_removed_at_elbow

    return max(floor, n_min)


def sample_to_n(points, colors, target_n):
    """
    Reduces the drawn stroke to exactly target_n points using
    Visvalingam-Whyatt's native point-count stopping condition.

    Each sampled point keeps its original colour.

    Parameters
    ----------
    points : list of (x, y)
        Original points.

    colors : list
        Color corresponding to each point.

    target_n : int
        Requested number of output points.

    Returns
    -------
    sampled_points, sampled_colors
    """

    if len(points) == 0:
        return [], []

    # Make sure colors has one entry per point.
    if len(colors) == 0:
        colors = [None] * len(points)

    elif len(colors) == 1 and len(points) > 1:
        # One stroke color applies to the entire shape.
        colors = list(colors) * len(points)

    elif len(colors) != len(points):
        raise ValueError(
            f"Point/color length mismatch: "
            f"{len(points)} points but {len(colors)} colors"
        )

    # Clamp target_n
    target_n = max(1, int(target_n))

    # No reduction needed
    if target_n >= len(points):
        return list(points), list(colors)

    # VW simplification
    simplifier = vw.Simplifier(points)

    simplified = simplifier.simplify(number=target_n)

    points_arr = np.asarray(points)

    used_indices = set()

    sampled_points = []
    sampled_colors = []

    for sp in simplified:

        sp = np.asarray(sp)

        # Distance from this simplified point to every original point
        dists = np.hypot(
            points_arr[:, 0] - sp[0],
            points_arr[:, 1] - sp[1]
        )

        # Do not reuse the same original point
        for idx in used_indices:
            dists[idx] = np.inf

        idx = int(np.argmin(dists))

        used_indices.add(idx)

        sampled_points.append(tuple(points[idx]))
        sampled_colors.append(colors[idx])

    return sampled_points, sampled_colors


def remove_close_points(points, colors, min_distance=0.3):
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

        MAX_RAW_POINTS = 40

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

                sampled, sampled_colors = sample_to_n(
                    self._current_points,
                    self._current_colors,
                    target_n
                )

                # -------------------------------------------------
                # Remove points that are too close
                # -------------------------------------------------

                sampled, sampled_colors = remove_close_points(
                    sampled,
                    sampled_colors
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

