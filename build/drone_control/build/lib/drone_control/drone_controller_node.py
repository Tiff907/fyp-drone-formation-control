"""
drone_controller_node.py

Converts each drone's DronePath (waypoints + times) into a continuous
stream of DroneSetpoint commands, interpolated by elapsed time.

Publishes generic setpoints on /drone/setpoint -- consumed by whichever
bridge is active (sim_bridge_node or, later, fylo_bridge_node). This
node has no knowledge of Gazebo or the Fylo SDK; it only ever produces
"where should drone N be right now" commands.

Timing is anchored to DronePath.formation_start_time (a shared absolute
timestamp set once for the whole formation, not per-drone receipt
time), so all drones interpolate against the same clock regardless of
publishing jitter between individual messages.
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import ColorRGBA

from formation_msgs.msg import DronePath, DroneSetpoint, DroneState, FormationGoal


def ros_time_to_sec(t) -> float:
    """Converts either an rclpy.time.Time (has .nanoseconds) or a
    builtin_interfaces/Time message (has .sec/.nanosec) to seconds,
    so both types can be compared on the same scale."""
    if hasattr(t, 'nanoseconds'):
        return t.nanoseconds * 1e-9
    return t.sec + t.nanosec * 1e-9


def lerp_point(p0: Point, p1: Point, alpha: float) -> Point:
    p = Point()
    p.x = p0.x + (p1.x - p0.x) * alpha
    p.y = p0.y + (p1.y - p0.y) * alpha
    p.z = p0.z + (p1.z - p0.z) * alpha
    return p


class DroneControllerNode(Node):

    CONTROL_RATE_HZ = 30.0

    def __init__(self):
        super().__init__('drone_controller_node')

        self._paths = {}             # drone_id -> DronePath
        self._path_start_time = {}   # drone_id -> formation_start_time (shared, not receipt time)
        self._colors = {}            # drone_id -> ColorRGBA
        self._reached = {}           # drone_id -> bool

        self.create_subscription(FormationGoal, '/formation/goal', self._on_goal, 10)
        self.create_subscription(DronePath, '/formation/drone_path', self._on_path, 10)

        self._setpoint_pub = self.create_publisher(DroneSetpoint, '/drone/setpoint', 10)
        self._state_pub = self.create_publisher(DroneState, '/drone/controller_state', 10)

        self.create_timer(1.0 / self.CONTROL_RATE_HZ, self._on_timer)
        self.get_logger().info('drone_controller_node started')

    def _on_goal(self, msg: FormationGoal):
        # Carries pen colour per drone, set once a formation is assigned
        for drone_id, color in zip(msg.assigned_drone_ids, msg.point_colors):
            self._colors[drone_id] = color

    def _on_path(self, msg: DronePath):
        self._paths[msg.drone_id] = msg
        self._path_start_time[msg.drone_id] = msg.formation_start_time  # shared absolute time, not receipt time
        self._reached[msg.drone_id] = False
        self.get_logger().info(
            f'Received path for drone {msg.drone_id} ({len(msg.waypoints)} waypoints)'
        )

    def _on_timer(self):
        now_sec = ros_time_to_sec(self.get_clock().now())

        for drone_id, path in self._paths.items():
            if self._reached.get(drone_id):
                continue

            waypoints = path.waypoints
            times = path.waypoint_times
            if not waypoints or not times or len(waypoints) != len(times):
                continue

            start_sec = ros_time_to_sec(self._path_start_time[drone_id])
            elapsed = now_sec - start_sec

            t0 = ros_time_to_sec(times[0])
            rel_times = [ros_time_to_sec(t) - t0 for t in times]

            if elapsed <= rel_times[0]:
                target = waypoints[0]
            elif elapsed >= rel_times[-1]:
                target = waypoints[-1]
                if not self._reached[drone_id]:
                    self._reached[drone_id] = True
                    self._publish_state(drone_id, target, reached=True)
            else:
                target = waypoints[-1]
                for i in range(len(rel_times) - 1):
                    if rel_times[i] <= elapsed <= rel_times[i + 1]:
                        span = rel_times[i + 1] - rel_times[i]
                        alpha = 0.0 if span <= 0 else (elapsed - rel_times[i]) / span
                        target = lerp_point(waypoints[i], waypoints[i + 1], alpha)
                        break

            self._publish_setpoint(drone_id, target)

    def _publish_setpoint(self, drone_id: int, position: Point):
        msg = DroneSetpoint()
        msg.drone_id = drone_id
        msg.target_position = position
        msg.led_color = self._colors.get(
            drone_id, ColorRGBA(r=1.0, g=1.0, b=1.0, a=1.0)
        )
        self._setpoint_pub.publish(msg)

    def _publish_state(self, drone_id: int, position: Point, reached: bool):
        msg = DroneState()
        msg.drone_id = drone_id
        msg.position = position
        msg.available = True
        msg.reached_target = reached
        self._state_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = DroneControllerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
