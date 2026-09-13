"""
mapf_node.py

Publishing pipeline for /formation/drone_path, without CBS planning yet.

On receiving a FormationGoal, builds a straight-line 2-waypoint DronePath
per assigned drone (current known position -> assigned target point) and
publishes them all under one shared formation_start_time, using a single
long-lived publisher.

TODO(cbs): replace _plan_paths() with a real conflict-based search over
all assigned drones before publishing. Right now paths are independent
straight lines and can intersect/collide -- that's expected at this
stage, this node only exists to get the publishing pipeline right first.

Assumptions (adjust if the actual message definitions differ):
- Each drone's current position is tracked from DroneState.position on
  /drone/controller_state (published by drone_controller_node). If no
  state has been seen yet for a drone_id, it falls back to a resting
  position of (0, 0, 1.5) -- swap this for real localization/odometry
  once available.

Why one persistent publisher instead of per-call CLI/publisher setup:
each new rclpy publisher has to go through DDS discovery with matching
subscribers before messages are guaranteed to be delivered. Creating it
once at node startup and reusing it for every drone_path publish avoids
paying that discovery cost per-message, which is what caused drones to
activate at staggered times when paths were published via a loop of
separate `ros2 topic pub --once` processes.
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from builtin_interfaces.msg import Time as TimeMsg

from formation_msgs.msg import DronePath, DroneState, FormationGoal


# Fixed timing for the placeholder straight-line paths. Once CBS is added,
# per-drone duration will likely vary based on path length / conflicts.
START_DELAY_SEC = 2.0     # buffer so all subscribers are guaranteed to have
                            # received their DronePath before formation_start_time
SEGMENT_DURATION_SEC = 4.0

DEFAULT_REST_POSITION = (0.0, 0.0, 1.5)


def make_point(x: float, y: float, z: float) -> Point:
    p = Point()
    p.x, p.y, p.z = x, y, z
    return p


def ros_time_to_sec(t: TimeMsg) -> float:
    return t.sec + t.nanosec * 1e-9


def sec_to_ros_time(sec: float) -> TimeMsg:
    t = TimeMsg()
    t.sec = int(sec)
    t.nanosec = int((sec - t.sec) * 1e9)
    return t


class MapfNode(Node):

    def __init__(self):
        super().__init__('mapf_node')

        self._last_known_position = {}  # drone_id -> Point

        # Publisher created once, reused for every formation -- see module
        # docstring for why this matters for simultaneous drone startup.
        self._path_pub = self.create_publisher(DronePath, '/formation/drone_path', 10)

        self.create_subscription(DroneState, '/drone/controller_state', self._on_state, 10)
        self.create_subscription(FormationGoal, '/formation/goal', self._on_goal, 10)

        self.get_logger().info('mapf_node started (publishing pipeline only, no CBS yet)')

    def _on_state(self, msg: DroneState):
        self._last_known_position[msg.drone_id] = msg.position

    def _on_goal(self, msg: FormationGoal):
        drone_ids = list(msg.assigned_drone_ids)
        targets = list(msg.target_points)

        if len(drone_ids) != len(targets):
            self.get_logger().error(
                f'FormationGoal {msg.formation_id} has {len(drone_ids)} drone_ids but '
                f'{len(targets)} target_points -- ignoring goal'
            )
            return

        self.get_logger().info(
            f'Planning formation {msg.formation_id} for {len(drone_ids)} drones'
        )
        paths = self._plan_paths(drone_ids, targets)
        self._publish_paths(paths, formation_id=msg.formation_id)

    def _plan_paths(self, drone_ids, targets):
        """Builds one straight-line 2-waypoint path per drone.

        TODO(cbs): this is where conflict-based search goes. It should
        take the same (drone_id, start, target) tuples this function
        builds and return waypoint sequences that are mutually
        collision-free, instead of the direct start->target lines below.
        """
        paths = []
        for drone_id, target in zip(drone_ids, targets):
            start = self._last_known_position.get(
                drone_id,
                make_point(*DEFAULT_REST_POSITION),
            )
            paths.append((drone_id, [start, target]))
        return paths

    def _publish_paths(self, paths, formation_id: int):
        now_sec = ros_time_to_sec(self.get_clock().now().to_msg())
        formation_start = sec_to_ros_time(now_sec + START_DELAY_SEC)
        formation_end = sec_to_ros_time(now_sec + START_DELAY_SEC + SEGMENT_DURATION_SEC)

        for drone_id, waypoints in paths:
            msg = DronePath()
            msg.drone_id = drone_id
            msg.waypoints = waypoints
            msg.waypoint_times = [formation_start, formation_end]
            msg.formation_start_time = formation_start
            self._path_pub.publish(msg)
            self.get_logger().info(
                f'[formation {formation_id}] Published path for drone {drone_id}: '
                f'({waypoints[0].x:.2f}, {waypoints[0].y:.2f}, {waypoints[0].z:.2f}) -> '
                f'({waypoints[1].x:.2f}, {waypoints[1].y:.2f}, {waypoints[1].z:.2f})'
            )


def main(args=None):
    rclpy.init(args=args)
    node = MapfNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
