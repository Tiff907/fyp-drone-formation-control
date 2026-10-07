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

Parking slots sit in a reserved depth strip (see PARK_Y / coords_mapping_node's
restricted BOUNDARY_Y_RANGE) at a single fixed depth, arranged in a
brick-offset grid across X and Z so no two parked drones ever share
the same X at different Z (avoiding vertical stacking / downwash risk).
"""

import numpy as np
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import ColorRGBA
from scipy.optimize import linear_sum_assignment

from formation_msgs.msg import SampledPoints, DroneState, FormationGoal

PARK_Y = 1.75             # fixed depth, centre of the reserved (1.5, 2.0) strip
PARK_X_RANGE = (-2.5, 2.5)
PARK_Z_RANGE = (0.5, 2.5)
PARK_SPACING = 0.4        # > SAFETY_RADIUS (0.30m) for margin

PARK_COLOR = ColorRGBA(r=0.3, g=0.3, b=0.3, a=1.0)


def compute_parking_positions(count: int):
    """Arranges `count` parking positions at fixed depth PARK_Y, using
    a brick-offset grid across X (within each row) and Z (across
    rows), so no two positions share the same X at different Z."""
    positions = []
    row = 0
    z = PARK_Z_RANGE[0]

    while len(positions) < count and z <= PARK_Z_RANGE[1]:
        offset = (PARK_SPACING / 2) if (row % 2 == 1) else 0.0
        x = PARK_X_RANGE[0] + PARK_SPACING + offset

        while x <= PARK_X_RANGE[1] - PARK_SPACING and len(positions) < count:
            positions.append((x, PARK_Y - PARK_SPACING, z))
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
