"""
assignment_node.py

Optimal drone-to-target assignment via a single Hungarian algorithm
solve (SciPy's linear_sum_assignment) over a combined M x M cost
matrix: the first N columns are formation target points, the
remaining M - N columns are parking slots (see compute_parking_positions).

Solving formation and parking jointly, in one assignment, is genuinely
optimal -- unlike assigning formation drones first and parking
whichever drones are left over, which can produce a locally good
formation match that forces a globally worse total cost once parking
distances are also considered.

Parking slots sit in the reserved depth strip (see PARK_Y_LAYERS / coords_mapping_node's
restricted BOUNDARY_Y_RANGE), in rows at increasing height (Z). Consecutive
rows differ in BOTH depth (Y) and X: Y cycles through three layers and the
middle layer is shifted by half a slot in X, so a parked drone is never
directly above another within downwash range (rows up to two apart, 0.8 m).
Nearest horizontal distance between such drones is 0.28 m, against 0 m
when all rows share one depth and are only offset in X.
"""

import numpy as np
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import ColorRGBA
from scipy.optimize import linear_sum_assignment

from formation_msgs.msg import SampledPoints, DroneState, FormationGoal, PlanStatus

# Depth layers inside the reserved (1.5, 2.0) strip; row r uses layer r % 3.
PARK_Y_LAYERS = (1.5, 1.9)
PARK_X_RANGE = (-2.5, 2.5)
PARK_Z_RANGE = (0.5, 2.5)
PARK_SPACING = 0.4

PARK_COLOR = ColorRGBA(r=0.3, g=0.3, b=0.3, a=1.0)


def compute_parking_positions(count: int):
    """Arranges `count` parking positions in rows at increasing Z. Row r sits at
    depth PARK_Y_LAYERS[r % 3], and rows with r % 3 == 1 are shifted by half a
    slot in X, so rows that are close in height differ in both X and Y."""
    positions = []
    row = 0
    z = PARK_Z_RANGE[0]

    while len(positions) < count and z <= PARK_Z_RANGE[1]:
        offset = (PARK_SPACING / 2) if (row % 3 == 1) else 0.0
        y = PARK_Y_LAYERS[row % len(PARK_Y_LAYERS)]
        x = PARK_X_RANGE[0] + PARK_SPACING + offset

        while x <= PARK_X_RANGE[1] - PARK_SPACING and len(positions) < count:
            positions.append((x, y, z))
            x += PARK_SPACING

        row += 1
        z += PARK_SPACING

    return positions


class AssignmentNode(Node):

    def __init__(self):
        super().__init__('assignment_node')

        self._drone_positions = {}   # drone_id -> (x, y, z)
        self._formation_id = 0

        self.create_subscription(DroneState, '/drone/state', self._on_drone_state, 10)
        self.create_subscription(SampledPoints, '/formation/mapped_points', self._on_mapped_points, 10)

        self._goal_pub = self.create_publisher(FormationGoal, '/formation/goal', 10)
        self._status_pub = self.create_publisher(PlanStatus, '/formation/plan_status', 10)

        self.get_logger().info('assignment_node started')

    def _on_drone_state(self, msg: DroneState):
        if msg.available:
            self._drone_positions[msg.drone_id] = (msg.position.x, msg.position.y, msg.position.z)
        else:
            self._drone_positions.pop(msg.drone_id, None)

    def _on_mapped_points(self, msg: SampledPoints):
        drone_ids = list(self._drone_positions.keys())
        m = len(drone_ids)
        n = len(msg.points)

        if m < n:
            self.get_logger().error(
                f'Assignment infeasible: {m} available drones < {n} target points -- '
                f'this should have been caught by drone_validator_node'
            )
            status_msg = PlanStatus()
            status_msg.success = False
            status_msg.status_message = f'{m} drones available, {n} needed'
            status_msg.usable_drone_count = m
            self._status_pub.publish(status_msg)
            return

        # Build the combined target list: N formation points + (M - N)
        # parking slots, so every drone gets exactly one target.
        n_park = m - n
        parking_positions = compute_parking_positions(n_park)

        if len(parking_positions) < n_park:
            self.get_logger().warn(
                f'Parking capacity exceeded: only {len(parking_positions)} slots for '
                f'{n_park} drones needing parking -- PARK_Z_RANGE or PARK_X_RANGE too small'
            )
            n_park = len(parking_positions)  # truncate; remaining drones left unassigned this cycle

        combined_targets = list(msg.points) + [
            Point(x=x, y=y, z=z) for x, y, z in parking_positions
        ]
        combined_colors = list(msg.colors) + [PARK_COLOR] * len(parking_positions)
        is_parking = [False] * n + [True] * len(parking_positions)

        m_used = n + len(parking_positions)  # may be < m if parking capacity was exceeded

        # Single combined cost matrix: all drones vs. all targets
        # (formation + parking together).
        cost_matrix = np.zeros((m, m_used))
        for i, drone_id in enumerate(drone_ids):
            dx, dy, dz = self._drone_positions[drone_id]
            for j, target in enumerate(combined_targets):
                cost_matrix[i, j] = np.sqrt(
                    (dx - target.x) ** 2 + (dy - target.y) ** 2 + (dz - target.z) ** 2
                )

        row_ind, col_ind = linear_sum_assignment(cost_matrix)

        self._formation_id += 1

        goal = FormationGoal()
        goal.target_points = [combined_targets[c] for c in col_ind]
        goal.assigned_drone_ids = [drone_ids[r] for r in row_ind]
        goal.point_colors = [combined_colors[c] for c in col_ind]
        goal.formation_id = self._formation_id
        goal.timestamp = self.get_clock().now().to_msg()

        n_formation_assigned = sum(1 for c in col_ind if not is_parking[c])
        n_parking_assigned = sum(1 for c in col_ind if is_parking[c])
        total_cost = cost_matrix[row_ind, col_ind].sum()

        self.get_logger().info(
            f'Combined assignment: {n_formation_assigned} to formation, '
            f'{n_parking_assigned} parked (total cost={total_cost:.2f})'
        )
        self._goal_pub.publish(goal)


def main(args=None):
    rclpy.init(args=args)
    node = AssignmentNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
