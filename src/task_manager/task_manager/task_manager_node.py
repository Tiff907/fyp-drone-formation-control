#!/usr/bin/env python3
import time

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from rclpy.duration import Duration
from std_msgs.msg import String

from formation_msgs.msg import SystemState, UserCommand
from formation_msgs.msg import DroneState, DronePath, PlanStatus
from formation_msgs.msg import RefinementCmd, RefinementCandidate
from formation_msgs.msg import SampledPoints, DrawnShape, FormationGoal


def _spread_indices(n, k):
    """k indices spread evenly over range(n), first and last included."""
    if k >= n:
        return list(range(n))
    if k == 1:
        return [0]
    return [round(i * (n - 1) / (k - 1)) for i in range(k)]


def map_colors(colors, m):
    """Colours for a shape of m points derived from the colours of the shape
    it was made from. The outline keeps its order, so point i takes the colour
    at the same fraction of the way along the old outline. One colour for the
    whole stroke stays one colour."""
    colors = list(colors)
    if not colors or m <= 0:
        return []
    if len(colors) == 1:
        return colors * m
    return [colors[round(i * (len(colors) - 1) / max(1, m - 1))] for i in range(m)]


class TaskManagerNode(Node):
    def __init__(self):
        super().__init__('task_manager_node')

        self.current_state = 'IDLE'
        self.drones = {}
        self._last_error = ''

        # --- refinement bookkeeping ---
        # The shape the LLM works on is the user's RAW drawing (the points
        # and per-point colours of the last /formation/drawn_shape), not the
        # drone positions, so colours and detail survive. 'pending' is
        # committed once MAPF reports success. After a refinement is
        # accepted, the accepted 30 points become the new drawing.
        self._pending_points = []
        self._pending_colors = []
        self._formation_points = []
        self._formation_colors = []
        self._instruction = ''      # latest text typed in the UI
        self._candidate = None      # RefinementCandidate awaiting review
        # A rejected suggestion that the next comment should be applied to
        # (only when reject_base == 'suggested'); None = use the formation.
        self._base_points = None
        self._base_colors = []
        self._refine_timer = None

        # --- END: park first, then land ---
        # None | 'PLANNING' (waiting for the parking plan) | 'MOVING' (drones
        # flying to their parking slots). Landing starts only once they are
        # parked, so descending drones cannot break the safety radius.
        self._park_phase = None
        self._park_failed = False
        self._park_timer = None
        self._land_timer = None
        self._park_targets = {}       # drone_id -> (x, y, z) from the parking FormationGoal
        self._park_since = None       # when every drone first sat on its slot

        self.declare_parameter('refinement_timeout_s', 60.0)
        # END: how long the drones get to reach their parking slots before
        # landing starts anyway. The parking move is an EMPTY drawn shape sent
        # into the planner like a blank canvas SUBMIT (sampling -> validator ->
        # mapping -> assignment -> MAPF), which parks every drone.
        self.declare_parameter('park_timeout_s', 30.0)
        self.declare_parameter('park_topic', '/formation/drawn_shape')
        # A drone counts as parked when its measured position is within this
        # distance of its parking slot, for park_settle_s without a break. The
        # drone's own reached_target flag is not used: it can still be true
        # from the previous formation when the parking plan is accepted.
        self.declare_parameter('park_tolerance_m', 0.20)
        self.declare_parameter('park_settle_s', 1.0)
        # A hand drawing can have hundreds of raw points; the LLM only needs
        # the outline, so at most this many are sent in the prompt.
        self.declare_parameter('max_prompt_points', 60)
        # After REJECT, which shape does the next comment apply to?
        #   'suggested': the suggestion that was just rejected
        #   'original' : the shape the drones are currently holding
        self.declare_parameter('reject_base', 'suggested')
        # Where an ACCEPTED candidate is sent. It re-enters the planner at
        # the very start, exactly like a freshly drawn shape: shape_sampling
        # -> validator loop -> coords_mapping -> assignment -> MAPF.
        self.declare_parameter('accept_topic', '/formation/drawn_shape')
        self.declare_parameter('instruction_topic', '/ui/refinement_text')

        self.state_pub = self.create_publisher(SystemState, '/system/state', 10)
        self.drone_path_pub = self.create_publisher(DronePath, '/formation/drone_path', 10)
        self.refine_cmd_pub = self.create_publisher(RefinementCmd, '/refinement/command', 10)
        self.park_pub = self.create_publisher(
            DrawnShape, self.get_parameter('park_topic').value, 10)
        self.accept_pub = self.create_publisher(
            DrawnShape, self.get_parameter('accept_topic').value, 10)

        self.create_subscription(UserCommand, '/ui/user_command', self.command_callback, 10)
        self.create_subscription(DroneState, '/drone/state', self.drone_state_callback, 10)
        self.create_subscription(FormationGoal, '/formation/goal', self.goal_callback, 10)
        self.create_subscription(PlanStatus, '/formation/plan_status', self.plan_status_callback, 10)
        self.create_subscription(
            DrawnShape, '/formation/drawn_shape', self.drawn_shape_callback, 10)
        self.create_subscription(
            RefinementCandidate, '/refinement/candidate', self.candidate_callback, 10)
        self.create_subscription(
            String, self.get_parameter('instruction_topic').value, self.instruction_callback, 10)

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

        elif self.current_state == 'LANDING' and self._park_phase == 'MOVING':
            if self._all_parked():
                self.get_logger().info('All drones are on their parking slots.')
                self._begin_landing()

    def goal_callback(self, msg: FormationGoal):
        """While END is parking the drones, remember where each one was sent."""
        if self.current_state == 'LANDING' and self._park_phase in ('PLANNING', 'MOVING'):
            self._park_targets = {
                int(d): (p.x, p.y, p.z)
                for d, p in zip(msg.assigned_drone_ids, msg.target_points)}
            self._park_since = None

    def _all_parked(self) -> bool:
        """True once every drone sent to a parking slot has been within
        park_tolerance_m of it for park_settle_s."""
        if not self._park_targets:
            # No goal seen (should not happen): fall back to the drones' own flag.
            return bool(self.drones) and all(d.reached_target for d in self.drones.values())
        tol = float(self.get_parameter('park_tolerance_m').value)
        for drone_id, (tx, ty, tz) in self._park_targets.items():
            d = self.drones.get(drone_id)
            if d is None:
                continue
            gap = ((d.position.x - tx) ** 2 + (d.position.y - ty) ** 2
                   + (d.position.z - tz) ** 2) ** 0.5
            if gap > tol:
                self._park_since = None
                return False
        now = time.monotonic()
        if self._park_since is None:
            self._park_since = now
        return now - self._park_since >= float(self.get_parameter('park_settle_s').value)

    def plan_status_callback(self, msg: PlanStatus):
        """Handles pass/fail reports from any formation_planner stage."""
        if self.current_state == 'LANDING' and self._park_phase is not None:
            self._park_plan_status(msg)
            return

        if not msg.success:
            self._cancel_refine_timer()
            self._base_points = None
            self._last_error = msg.status_message
            self.current_state = 'ERROR'
            self.get_logger().error(f'Planning failed: {msg.status_message}')
            self.publish_state()
            return

        if self.current_state == 'PLANNING':
            self._formation_points = self._pending_points
            self._formation_colors = self._pending_colors
            self._base_points = None
            for drone_id in self.drones:
                self.drones[drone_id].reached_target = False
            self.current_state = 'EXECUTING'
            self.get_logger().info('Planning successful. Executing formation...')
            self.publish_state()

    def drawn_shape_callback(self, msg: DrawnShape):
        """Remembers the latest drawing (canvas frame, raw points + colours).
        It becomes 'the current formation' once MAPF reports success. This
        also receives the DrawnShape that _accept_candidate publishes."""
        self._pending_points = list(msg.raw_points)
        self._pending_colors = list(msg.stroke_colors)

    def instruction_callback(self, msg: String):
        """Caches the latest refinement text typed in the UI. It is
        consumed when LLM_SUBMIT arrives."""
        self._instruction = msg.data

    def candidate_callback(self, msg: RefinementCandidate):
        """Holds the LLM-refined shape until the user accepts/rejects."""
        if self.current_state != 'REFINING':
            self.get_logger().warn(
                f'Refinement candidate received in {self.current_state}, not REFINING -- ignored '
                '(it arrived after the timeout? raise refinement_timeout_s)')
            return
        self._cancel_refine_timer()
        self._candidate = msg
        self.get_logger().info(
            f'Refinement candidate received ({len(msg.candidate_points)} points): '
            f'{msg.plan_description}')

    def _fail(self, reason: str):
        self._cancel_refine_timer()
        self._candidate = None
        self._base_points = None
        self._last_error = reason
        self.current_state = 'ERROR'
        self.get_logger().error(reason)
        self.publish_state()

    def _cancel_refine_timer(self):
        if self._refine_timer is not None:
            self._refine_timer.cancel()
            self.destroy_timer(self._refine_timer)
            self._refine_timer = None

    def _refine_timeout(self):
        self._cancel_refine_timer()
        if self.current_state == 'REFINING' and self._candidate is None:
            self._fail('Refinement timed out (no result from LLM)')

    def _start_refinement(self):
        base = self._base_points or self._formation_points
        if not base:
            self._fail('No formation to refine yet')
            return
        text = self._instruction.strip()
        if not text:
            self._fail('No refinement instruction received')
            return

        self._candidate = None
        self.current_state = 'REFINING'
        self.publish_state()

        cmd = RefinementCmd()
        cmd.instruction_text = text
        k = int(self.get_parameter('max_prompt_points').value)
        pick = _spread_indices(len(base), k)
        cmd.current_points = [base[i] for i in pick]
        src = self._base_colors if self._base_points else self._formation_colors
        colors = map_colors(src, len(base))           # one colour per point of the base
        cmd.current_colors = [colors[i] for i in pick] if colors else []
        self.refine_cmd_pub.publish(cmd)
        self._instruction = ''

        self._cancel_refine_timer()
        self._refine_timer = self.create_timer(
            float(self.get_parameter('refinement_timeout_s').value), self._refine_timeout)
        self.get_logger().info(f'Refinement requested: "{text}"')

    def _accept_candidate(self):
        cand = self._candidate
        if cand is None:
            self.get_logger().warn('ACCEPT ignored: no refinement candidate yet')
            return
        points = list(cand.candidate_points)
        colors = list(cand.candidate_colors)
        if len(colors) != len(points):
            # The candidate carries no colours: take them from the shape the
            # refinement was applied to, along the outline.
            src = self._base_colors if self._base_points else self._formation_colors
            colors = map_colors(src, len(points))
            if not colors:
                self._fail('Refined shape has no usable colours')
                return

        self._cancel_refine_timer()
        self._candidate = None
        self._base_points = None

        # State first, so a fast PlanStatus reply is not missed.
        self.current_state = 'PLANNING'
        self.publish_state()

        shape = DrawnShape()
        shape.raw_points = points
        shape.stroke_colors = colors
        self.accept_pub.publish(shape)

    def command_callback(self, msg: UserCommand):
        cmd = msg.command.upper()
        self.get_logger().info(f'Received User Command: {cmd} (current state: {self.current_state})')

        if cmd == 'START' and self.current_state in ('IDLE', 'LANDING'):
            self.takeoff_all()
            self.current_state = 'HOVERING'
            self.publish_state()

        elif cmd == 'SUBMIT' and self.current_state in ('HOVERING', 'HOLDING'):
            self._base_points = None            # a new drawing replaces any old suggestion
            self.current_state = 'PLANNING'
            self.publish_state()

        elif cmd == 'LLM_SUBMIT' and self.current_state == 'HOLDING':
            self._start_refinement()

        elif cmd == 'ACCEPT' and self.current_state == 'REFINING':
            # Accepted refinement proceeds to planning/execution.
            self._accept_candidate()

        elif cmd == 'REJECT' and self.current_state == 'REFINING':
            self._cancel_refine_timer()
            if (self._candidate is not None
                    and self.get_parameter('reject_base').value == 'suggested'):
                src = (self._candidate.candidate_colors
                       or (self._base_colors if self._base_points else self._formation_colors))
                self._base_points = list(self._candidate.candidate_points)
                self._base_colors = map_colors(src, len(self._base_points))
            self._candidate = None
            self.current_state = 'HOLDING'
            self.publish_state()

        elif cmd == 'REDRAW_INSTEAD' and self.current_state == 'REFINING':
            self._cancel_refine_timer()
            self._candidate = None
            self._base_points = None
            self.current_state = 'HOVERING'
            self.publish_state()

        elif cmd == 'ACKNOWLEDGE' and self.current_state == 'ERROR':
            # Returns to HOVERING if no formation was ever
            # successfully holding yet; otherwise HOLDING.
            self._last_error = ''
            self._park_failed = False
            self._park_phase = None
            self.current_state = 'HOLDING' if self._had_formation() else 'HOVERING'
            self.publish_state()

        elif cmd == 'END':
            self._end()

        else:
            self.get_logger().warn(
                f'Command {cmd} not valid from state {self.current_state} -- ignored'
            )

    # ------------------------------------------------------------
    # END: fly to the parking slots (a blank formation), then land
    # ------------------------------------------------------------

    def _end(self):
        if self._park_phase is not None and not self._park_failed:
            self.get_logger().warn('END ignored: already parking before landing')
            return
        self._cancel_refine_timer()
        self._candidate = None
        self._base_points = None
        self._cancel_park_timer()

        force = self._park_failed                 # second END after a failed parking plan
        self._park_failed = False
        if force or not self._formation_points:
            # Forced, or no formation was ever flown: nothing to tidy up.
            self.get_logger().info('END: landing now')
            self._park_phase = None
            self._begin_landing()
            return

        self.get_logger().info('END: sending drones to their parking slots before landing')
        self._park_phase = 'PLANNING'
        self._park_targets = {}
        self._park_since = None
        self.current_state = 'LANDING'
        self.publish_state()

        blank = DrawnShape()                      # empty canvas: every drone goes to its parking slot
        blank.raw_points = []
        blank.stroke_colors = []
        self.park_pub.publish(blank)

        self._park_timer = self.create_timer(
            float(self.get_parameter('park_timeout_s').value), self._park_timeout)

    def _park_plan_status(self, msg: PlanStatus):
        if not msg.success:
            self._cancel_park_timer()
            self._park_failed = True
            self._last_error = (f'Could not plan the parking move ({msg.status_message}). '
                                'Press END again to land immediately.')
            self.current_state = 'ERROR'
            self.get_logger().error(self._last_error)
            self.publish_state()
            return
        if self._park_phase == 'PLANNING':
            for d in self.drones.values():
                d.reached_target = False          # stale flags must not trigger landing
            self._park_phase = 'MOVING'
            self._formation_points = []           # nothing is flown any more
            self._formation_colors = []
            self.get_logger().info('Parking plan ready: drones moving to their slots')

    def _park_timeout(self):
        self._cancel_park_timer()
        if self.current_state == 'LANDING' and self._park_phase is not None:
            self.get_logger().warn('Parking timed out: landing anyway')
            self._begin_landing()

    def _cancel_park_timer(self):
        if self._park_timer is not None:
            self._park_timer.cancel()
            self.destroy_timer(self._park_timer)
            self._park_timer = None

    def _begin_landing(self):
        self._cancel_park_timer()
        self._park_phase = None
        self.land_all()
        self.current_state = 'LANDING'
        self.publish_state()
        self._land_timer = self.create_timer(5.0, self._reset_to_idle)

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
        if getattr(self, '_land_timer', None) is not None:
            self._land_timer.cancel()
            self.destroy_timer(self._land_timer)
            self._land_timer = None
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
