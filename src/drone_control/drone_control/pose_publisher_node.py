"""
pose_publisher_node.py

Publishes DroneState (global position + availability + arrival status)
for every known drone, continuously, on /drone/state.

Purely reactive -- learns about each drone from the first DroneSetpoint
it observes (whether from drone_controller_node's normal operation, or
from sim_bridge_node's/fylo_bridge_node's initial startup publish).
Has no hardcoded drone count or spawn layout, and no knowledge of
Gazebo or any specific hardware platform.

In kinematic simulation, commanded position and actual position are
identical (no physics lag to account for). In hardware deployment,
this node's data source would instead be real localization (motion
capture, GPS, etc.) rather than setpoint echo.
"""

import rclpy
from rclpy.node import Node

from formation_msgs.msg import DroneSetpoint, DroneState


class PosePublisherNode(Node):

    PUBLISH_RATE_HZ = 20.0

    def __init__(self):
        super().__init__('pose_publisher_node')

        self._positions = {}       # drone_id -> geometry_msgs/Point
        self._reached = {}         # drone_id -> bool

        self.create_subscription(DroneSetpoint, '/drone/setpoint', self._on_setpoint, 10)
        self.create_subscription(DroneState, '/drone/controller_state', self._on_controller_state, 10)

        self._state_pub = self.create_publisher(DroneState, '/drone/state', 10)

        self.create_timer(1.0 / self.PUBLISH_RATE_HZ, self._on_timer)
        self.get_logger().info('pose_publisher_node started')

    def _on_setpoint(self, msg: DroneSetpoint):
        self._positions[msg.drone_id] = msg.target_position
        self._reached.setdefault(msg.drone_id, True)  # idle until told otherwise

    def _on_controller_state(self, msg: DroneState):
        self._reached[msg.drone_id] = msg.reached_target

    def _on_timer(self):
        for drone_id, position in self._positions.items():
            state = DroneState()
            state.drone_id = drone_id
            state.position = position
            state.available = True
            state.reached_target = self._reached.get(drone_id, True)
            self._state_pub.publish(state)


def main(args=None):
    rclpy.init(args=args)
    node = PosePublisherNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
