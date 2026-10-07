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
    ARRIVAL_THRESHOLD = 0.05  # Meters

    def __init__(self):
        super().__init__('pose_publisher_node')

        self._positions = {}       # drone_id -> geometry_msgs/Point (current/last known)
        self._targets = {}         # drone_id -> geometry_msgs/Point (active setpoint goal)
        self._reached = {}         # drone_id -> bool

        self.create_subscription(DroneSetpoint, '/drone/setpoint', self._on_setpoint, 10)
        self.create_subscription(DroneState, '/drone/controller_state', self._on_controller_state, 10)

        self._state_pub = self.create_publisher(DroneState, '/drone/state', 10)

        self.create_timer(1.0 / self.PUBLISH_RATE_HZ, self._on_timer)
        self.get_logger().info('pose_publisher_node started with auto-arrival check')

    def _on_setpoint(self, msg: DroneSetpoint):
        # Track both current position/target and the goal target
        self._positions[msg.drone_id] = msg.target_position
        self._targets[msg.drone_id] = msg.target_position
        # Reset to False upon receiving a new movement goal
        self._reached[msg.drone_id] = False

    def _on_controller_state(self, msg: DroneState):
        # If an external controller *does* speak up, respect its state
        self._positions[msg.drone_id] = msg.position
        self._reached[msg.drone_id] = msg.reached_target

    def _on_timer(self):
        for drone_id, position in self._positions.items():
            target = self._targets.get(drone_id, position)
            
            # Compute distance error between current position and target goal
            dist = ((position.x - target.x) ** 2 + 
                    (position.y - target.y) ** 2 + 
                    (position.z - target.z) ** 2) ** 0.5

            # Automatically flip to True if close enough, otherwise stay False
            if dist < self.ARRIVAL_THRESHOLD:
                self._reached[drone_id] = True

            state = DroneState()
            state.drone_id = drone_id
            state.position = position
            state.available = True
            state.reached_target = self._reached.get(drone_id, False)
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
