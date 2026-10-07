#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from rclpy.duration import Duration

from formation_msgs.msg import SystemState, UserCommand
from formation_msgs.msg import DroneState, DronePath, PlanStatus


class TaskManagerNode(Node):
    def __init__(self):
        super().__init__('task_manager_node')

        self.current_state = 'IDLE'
        self.drones = {}
        self._last_error = ''

        self.state_pub = self.create_publisher(SystemState, '/system/state', 10)
        self.drone_path_pub = self.create_publisher(DronePath, '/formation/drone_path', 10)

        self.create_subscription(UserCommand, '/ui/user_command', self.command_callback, 10)
        self.create_subscription(DroneState, '/drone/state', self.drone_state_callback, 10)
        self.create_subscription(PlanStatus, '/formation/plan_status', self.plan_status_callback, 10)

        self.get_logger().info('Task Manager initialized. Waiting for commands...')
        self.publish_state()

    def publish_state(self):
        """Broadcasts the FSM state (and, for ERROR, the failure
        reason) to the ROS2 network so the UI can reflect it."""
        msg = SystemState()
        msg.state = self.current_state
        if self.current_state == 'ERROR':
            msg.state = f'ERROR:{self._last_error}'
        self.state_pub.publish(msg)
        self.get_logger().info(f'Broadcasted System State: {msg.state}')

    def drone_state_callback(self, msg: DroneState):
        """Caches each drone's latest state and monitors execution
        completion while EXECUTING."""
        self.drones[msg.drone_id] = msg

        if self.current_state == 'EXECUTING':
            if self.drones and all(d.reached_target for d in self.drones.values()):
                self.get_logger().info('All drones reached target formation! Returning to HOLDING state.')
                self.current_state = 'HOLDING'
                self.publish_state()
        
    def plan_status_callback(self, msg: PlanStatus):
        """Handles pass/fail reports from any formation_planner stage."""
        if not msg.success:
            self._last_error = msg.status_message
            self.current_state = 'ERROR'
            self.get_logger().error(f'Planning failed: {msg.status_message}')
            self.publish_state()
            return

        if self.current_state == 'PLANNING':
            for drone_id in self.drones:
                self.drones[drone_id].reached_target = False
            self.current_state = 'EXECUTING'
            self.get_logger().info('Planning successful. Executing formation...')
            self.publish_state()

    def command_callback(self, msg: UserCommand):
        cmd = msg.command.upper()
        self.get_logger().info(f'Received User Command: {cmd} (current state: {self.current_state})')

        if cmd == 'START' and self.current_state in ('IDLE', 'LANDING'):
            self.takeoff_all()
            self.current_state = 'HOVERING'
            self.publish_state()

        elif cmd == 'SUBMIT' and self.current_state in ('HOVERING', 'HOLDING'):
            self.current_state = 'PLANNING'
            self.publish_state()

        elif cmd == 'LLM_SUBMIT' and self.current_state == 'HOLDING':
            self.current_state = 'REFINING'
            self.publish_state()

        elif cmd == 'ACCEPT' and self.current_state == 'REFINING':
            # Accepted refinement proceeds to planning/execution.
            self.current_state = 'PLANNING'
            self.publish_state()

        elif cmd == 'REJECT' and self.current_state == 'REFINING':
            self.current_state = 'HOLDING'
            self.publish_state()

        elif cmd == 'REDRAW_INSTEAD' and self.current_state == 'REFINING':
            self.current_state = 'HOVERING'
            self.publish_state()

        elif cmd == 'ACKNOWLEDGE' and self.current_state == 'ERROR':
            # Returns to HOVERING if no formation was ever
            # successfully holding yet; otherwise HOLDING.
            self._last_error = ''
            self.current_state = 'HOLDING' if self._had_formation() else 'HOVERING'
            self.publish_state()

        elif cmd == 'END':
            self.land_all()
            self.current_state = 'LANDING'
            self.publish_state()
            self.create_timer(5.0, self._reset_to_idle)

        else:
            self.get_logger().warn(
                f'Command {cmd} not valid from state {self.current_state} -- ignored'
            )

    def _had_formation(self) -> bool:
        """Heuristic: if any drone has previously reported
        reached_target True, a formation was held before this error,
        so ERROR should return to HOLDING rather than HOVERING."""
        return any(d.reached_target for d in self.drones.values())

    def takeoff_all(self):
        if not self.drones:
            self.get_logger().warn('No drones detected on /drone/state! Cannot takeoff.')
            return

        now = self.get_clock().now().to_msg()
        self.get_logger().info(f'Commanding {len(self.drones)} drones to takeoff (z=0.5).')

        for drone_id, state in self.drones.items():
            path_msg = DronePath()
            path_msg.drone_id = drone_id
            path_msg.formation_start_time = now

            target_pt = Point()
            target_pt.x = state.position.x
            target_pt.y = state.position.y
            target_pt.z = 0.5
            path_msg.waypoints = [target_pt]

            arrival_time = (self.get_clock().now() + Duration(seconds=3)).to_msg()
            path_msg.waypoint_times = [arrival_time]

            self.drone_path_pub.publish(path_msg)

    def land_all(self):
        if not self.drones:
            return

        now = self.get_clock().now().to_msg()
        self.get_logger().info('Commanding all drones to land (z=0.0).')

        for drone_id, state in self.drones.items():
            path_msg = DronePath()
            path_msg.drone_id = drone_id
            path_msg.formation_start_time = now

            target_pt = Point()
            target_pt.x = state.position.x
            target_pt.y = state.position.y
            target_pt.z = 0.0
            path_msg.waypoints = [target_pt]

            arrival_time = (self.get_clock().now() + Duration(seconds=3)).to_msg()
            path_msg.waypoint_times = [arrival_time]

            self.drone_path_pub.publish(path_msg)

    def _reset_to_idle(self):
        if self.current_state == 'LANDING':
            self.current_state = 'IDLE'
            self.publish_state()
            self.get_logger().info('Landing complete. System returned to IDLE.')


def main(args=None):
    rclpy.init(args=args)
    node = TaskManagerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
