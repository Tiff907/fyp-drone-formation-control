"""
drone_validator_node.py

Validates a drawn shape against the available drone count and safety
constraints, driving the shape_sampling_node retry loop described in
the Planning Process diagram.

Two checks, same node:
  1. Hard rejection: if available drones M < N_min, reject immediately.
  2. Retry loop: request a sample at decreasing target_n (starting at
     M) until the returned points pass the safety check (inter-point
     spacing >= SAFETY_RADIUS, all points within the physical
     boundary), or target_n falls below N_min (reject).

M (available drone count) is derived from accumulated /drone/state
messages, published continuously by pose_publisher_node.

On success, publishes the validated point set (reusing the
SampledPoints message type) on /formation/validated_points for
coords_mapping_node. On failure (either check), publishes PlanStatus
with success=False so task_manager can transition to ERROR.
"""

import numpy as np
import rclpy
from rclpy.node import Node

from formation_msgs.msg import (
    SampleRequest, SampledPoints, PlanStatus, DroneState,
)


SAFETY_RADIUS = 0.30  # metres, matches the CBS conflict-check radius

# Physical boundary, ENU, matching the Gazebo world (5m x 4m x 3m),
# centred at the origin.
BOUNDARY_X = (-2.5, 2.5)
BOUNDARY_Y = (-2.0, 2.0)
BOUNDARY_Z = (0.0, 3.0)  # unused at this stage -- points are still 2D canvas coords


def points_pass_safety_check(points):
    """Checks pairwise spacing (>= SAFETY_RADIUS) and boundary
    containment for a list of (x, y) points. Z is not carried by
    SampledPoints at this stage (2D canvas sampling, pre coordinate
    mapping) -- boundary check here covers x/y only; z is validated
    later, after coords_mapping_node runs."""
    for i in range(len(points)):
        x, y = points[i]
        if not (BOUNDARY_X[0] <= x <= BOUNDARY_X[1] and BOUNDARY_Y[0] <= y <= BOUNDARY_Y[1]):
            return False, f'Point {i} at ({x:.2f}, {y:.2f}) outside boundary'

    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            dist = np.hypot(points[i][0] - points[j][0], points[i][1] - points[j][1])
            if dist < SAFETY_RADIUS:
                return False, f'Points {i} and {j} too close ({dist:.2f}m < {SAFETY_RADIUS}m)'

    return True, ''


class DroneValidatorNode(Node):

    def __init__(self):
        super().__init__('drone_validator_node')

        self._available_drones = set()   # drone_id, tracked via DroneState.available
        self._n_min = None
        self._target_n = None
        self._retrying = False

        self.create_subscription(DroneState, '/drone/state', self._on_drone_state, 10)
        self.create_subscription(SampledPoints, '/formation/sampled_points', self._on_sampled_points, 10)

        self._sample_request_pub = self.create_publisher(SampleRequest, '/formation/sample_request', 10)
        self._validated_pub = self.create_publisher(SampledPoints, '/formation/validated_points', 10)
        self._status_pub = self.create_publisher(PlanStatus, '/formation/plan_status', 10)

        self.get_logger().info('drone_validator_node started')

    def _on_drone_state(self, msg: DroneState):
        if msg.available:
            self._available_drones.add(msg.drone_id)
        else:
            self._available_drones.discard(msg.drone_id)

    def _available_count(self) -> int:
        return len(self._available_drones)

    def _on_sampled_points(self, msg: SampledPoints):
        if msg.n_min_only:
            self._handle_n_min(msg.n_min)
            return

        if not self._retrying:
            # Unexpected: a sampled-points result arrived while no
            # retry sequence is in progress (e.g. shape_sampling_node
            # publishing unprompted). Ignore.
            return

        self._handle_sample_result(msg)

    def _handle_n_min(self, n_min: int):
        self._n_min = n_min
        m = self._available_count()

        self.get_logger().info(f'N_min={n_min}, available drones={m}')

        if m < n_min:
            self._reject(f'Available drones ({m}) below N_min ({n_min})')
            return

        # Start the retry loop at the largest feasible target.
        self._target_n = m
        self._retrying = True
        self._request_sample(self._target_n)

    def _request_sample(self, target_n: int):
        req = SampleRequest()
        req.target_n = target_n
        self.get_logger().info(f'Requesting sample at N={target_n}')
        self._sample_request_pub.publish(req)

    def _handle_sample_result(self, msg: SampledPoints):
        points = [(p.x, p.y) for p in msg.points]

        passed, reason = points_pass_safety_check(points)

        if passed:
            self.get_logger().info(f'Safety check passed at N={msg.target_n_used}')
            self._retrying = False
            self._validated_pub.publish(msg)
            self._publish_status(True, f'Validated at N={msg.target_n_used}')
            return

        self.get_logger().warn(f'Safety check failed at N={msg.target_n_used}: {reason}')

        self._target_n -= 1
        if self._target_n < self._n_min:
            self._reject(f'Exhausted retry loop below N_min ({self._n_min}) without passing safety check')
            return

        self._request_sample(self._target_n)

    def _reject(self, reason: str):
        self.get_logger().error(f'Shape rejected: {reason}')
        self._retrying = False
        self._publish_status(False, reason)

    def _publish_status(self, success: bool, message: str):
        status = PlanStatus()
        status.success = success
        status.status_message = message
        status.usable_drone_count = self._available_count()
        self._status_pub.publish(status)


def main(args=None):
    rclpy.init(args=args)
    node = DroneValidatorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
