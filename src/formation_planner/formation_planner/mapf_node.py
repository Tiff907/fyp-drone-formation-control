"""
mapf_node.py

Self-contained ROS2 node encapsulating Conflict-Based Search (CBS).
Consumes a FormationGoal and publishes DronePath per drone, or PlanStatus on failure/timeout.
"""

import heapq
import itertools
import time
import numpy as np

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from builtin_interfaces.msg import Time as TimeMsg

from formation_msgs.msg import FormationGoal, DroneState, DronePath, PlanStatus


# ---------------------------------------------------------------------
# CBS Core Parameters and Geometry Helpers
# ---------------------------------------------------------------------

CELL_SIZE = 0.10          # metres, 10cm grid resolution
SAFETY_RADIUS = 0.300001  # metres (avoiding edge situations by adding 0.000001m)
DT = 0.5                  # seconds per grid timestep

_NEIGHBOR_OFFSETS = [
    (dx, dy, dz)
    for dx in (-1, 0, 1)
    for dy in (-1, 0, 1)
    for dz in (-1, 0, 1)
]


def world_to_cell(p, origin=(0.0, 0.0, 0.0)):
    return (
        round((p[0] - origin[0]) / CELL_SIZE),
        round((p[1] - origin[1]) / CELL_SIZE),
        round((p[2] - origin[2]) / CELL_SIZE),
    )


def cell_to_world(c, origin=(0.0, 0.0, 0.0)):
    return (
        origin[0] + c[0] * CELL_SIZE,
        origin[1] + c[1] * CELL_SIZE,
        origin[2] + c[2] * CELL_SIZE,
    )


def cell_distance_m(c1, c2):
    return np.sqrt(sum(((a - b) * CELL_SIZE) ** 2 for a, b in zip(c1, c2)))


def exclusion_cells(center_cell, radius=SAFETY_RADIUS):
    r_cells = int(np.ceil(radius / CELL_SIZE))
    cells = set()
    for dx in range(-r_cells, r_cells + 1):
        for dy in range(-r_cells, r_cells + 1):
            for dz in range(-r_cells, r_cells + 1):
                cand = (center_cell[0] + dx, center_cell[1] + dy, center_cell[2] + dz)
                if cell_distance_m(center_cell, cand) <= radius:
                    cells.add(cand)
    return cells


# ---------------------------------------------------------------------
# Low Level: Space-Time A*
# ---------------------------------------------------------------------

def low_level_astar(start_cell, goal_cell, constraints, max_t):
    def heuristic(c):
        return cell_distance_m(c, goal_cell) / CELL_SIZE

    start = (start_cell, 0)
    open_heap = [(heuristic(start_cell), 0, start)]
    came_from = {}
    g_score = {start: 0}
    counter = itertools.count()

    while open_heap:
        _, _, (cell, t) = heapq.heappop(open_heap)

        if cell == goal_cell:
            return _reconstruct_path(came_from, (cell, t))

        if t >= max_t:
            continue

        for dx, dy, dz in _NEIGHBOR_OFFSETS:
            next_cell = (cell[0] + dx, cell[1] + dy, cell[2] + dz)
            next_t = t + 1

            if next_cell in constraints.get(next_t, ()):
                continue
            if (cell, next_cell, next_t) in constraints.get('swap', ()):
                continue

            tentative_g = g_score[(cell, t)] + 1
            key = (next_cell, next_t)
            if tentative_g < g_score.get(key, float('inf')):
                g_score[key] = tentative_g
                came_from[key] = (cell, t)
                f = tentative_g + heuristic(next_cell)
                heapq.heappush(open_heap, (f, next(counter), key))

    return None


def _reconstruct_path(came_from, end):
    path = [end]
    while path[-1] in came_from:
        path.append(came_from[path[-1]])
    path.reverse()
    return path


# ---------------------------------------------------------------------
# High Level: Constraint Tree & Conflict Resolution
# ---------------------------------------------------------------------

class CTNode:
    _id_counter = itertools.count()

    def __init__(self, constraints, paths):
        self.constraints = constraints
        self.paths = paths
        self.id = next(CTNode._id_counter)

    def cost(self):
        return max(path[-1][1] for path in self.paths.values())

    def __lt__(self, other):
        return self.cost() < other.cost()


def find_conflict(paths, max_t):
    agents = list(paths.keys())

    def pos_at(agent, t):
        path = paths[agent]
        if t < len(path):
            return path[t][0]
        return path[-1][0]

    for t in range(max_t + 1):
        for i in range(len(agents)):
            for j in range(i + 1, len(agents)):
                a, b = agents[i], agents[j]
                ca, cb = pos_at(a, t), pos_at(b, t)
                if cell_distance_m(ca, cb) < SAFETY_RADIUS:
                    return ('vertex', a, b, ca, t)

    for t in range(max_t):
        for i in range(len(agents)):
            for j in range(i + 1, len(agents)):
                a, b = agents[i], agents[j]
                ca_t, ca_t1 = pos_at(a, t), pos_at(a, t + 1)
                cb_t, cb_t1 = pos_at(b, t), pos_at(b, t + 1)
                if ca_t == cb_t1 and cb_t == ca_t1:
                    return ('swap', a, b, t + 1)

    return None


def cbs_plan(starts, goals, max_t=200, timeout=5.0):
    start_time = time.time()
    agent_ids = list(starts.keys())
    start_cells = {a: world_to_cell(starts[a]) for a in agent_ids}
    goal_cells = {a: world_to_cell(goals[a]) for a in agent_ids}

    root_constraints = {a: {'swap': set()} for a in agent_ids}
    root_paths = {}
    for a in agent_ids:
        if time.time() - start_time > timeout:
            return None
        path = low_level_astar(start_cells[a], goal_cells[a], root_constraints[a], max_t)
        if path is None:
            return None
        root_paths[a] = path

    root = CTNode(root_constraints, root_paths)
    open_heap = [root]

    while open_heap:
        if time.time() - start_time > timeout:
            return None  # Exceeded time limit

        node = heapq.heappop(open_heap)
        conflict = find_conflict(node.paths, max_t)

        if conflict is None:
            return _paths_to_world(node.paths)

        kind = conflict[0]

        if kind == 'vertex':
            _, a, b, center_cell, t = conflict
            excl = exclusion_cells(center_cell)
            for blocked_agent in (a, b):
                new_constraints = _deep_copy_constraints(node.constraints)
                new_constraints[blocked_agent].setdefault(t, set())
                new_constraints[blocked_agent][t] |= excl

                new_path = low_level_astar(
                    start_cells[blocked_agent], goal_cells[blocked_agent],
                    new_constraints[blocked_agent], max_t,
                )
                if new_path is None:
                    continue

                new_paths = dict(node.paths)
                new_paths[blocked_agent] = new_path
                heapq.heappush(open_heap, CTNode(new_constraints, new_paths))

        elif kind == 'swap':
            _, a, b, t = conflict
            for blocked_agent, other in ((a, b), (b, a)):
                new_constraints = _deep_copy_constraints(node.constraints)
                ca_prev = node.paths[blocked_agent][t - 1][0]
                ca_cur = node.paths[blocked_agent][t][0]
                new_constraints[blocked_agent]['swap'].add((ca_prev, ca_cur, t))

                new_path = low_level_astar(
                    start_cells[blocked_agent], goal_cells[blocked_agent],
                    new_constraints[blocked_agent], max_t,
                )
                if new_path is None:
                    continue

                new_paths = dict(node.paths)
                new_paths[blocked_agent] = new_path
                heapq.heappush(open_heap, CTNode(new_constraints, new_paths))

    return None


def _deep_copy_constraints(constraints):
    return {
        agent: {
            k: (set(v) if k != 'swap' else set(v))
            for k, v in agent_constraints.items()
        }
        for agent, agent_constraints in constraints.items()
    }


def _paths_to_world(paths):
    result = {}
    for agent, path in paths.items():
        result[agent] = [
            (*cell_to_world(cell), t * DT) for cell, t in path
        ]
    return result


# ---------------------------------------------------------------------
# ROS 2 Time Helpers and Node Class
# ---------------------------------------------------------------------

def ros_time_to_msg(rclpy_time) -> TimeMsg:
    sec, nanosec = divmod(rclpy_time.nanoseconds, 1_000_000_000)
    msg = TimeMsg()
    msg.sec = int(sec)
    msg.nanosec = int(nanosec)
    return msg


def offset_time_msg(base: TimeMsg, offset_sec: float) -> TimeMsg:
    total_nanosec = base.sec * 1_000_000_000 + base.nanosec + int(offset_sec * 1e9)
    sec, nanosec = divmod(total_nanosec, 1_000_000_000)
    msg = TimeMsg()
    msg.sec = int(sec)
    msg.nanosec = int(nanosec)
    return msg


class MapfNode(Node):

    MAX_T = 200  # grid timesteps

    def __init__(self):
        super().__init__('mapf_node')
        self._drone_positions = {}
        
        self.create_subscription(DroneState, '/drone/state', self._on_drone_state, 10)
        self.create_subscription(FormationGoal, '/formation/goal', self._on_formation_goal, 10)
        
        self._path_pub = self.create_publisher(DronePath, '/formation/drone_path', 50)
        self._status_pub = self.create_publisher(PlanStatus, '/formation/plan_status', 10)

        self.get_logger().info('mapf_node (Strict CBS with 5s timeout) started')

    def _on_drone_state(self, msg: DroneState):
        if msg.available:
            self._drone_positions[msg.drone_id] = (msg.position.x, msg.position.y, msg.position.z)
        else:
            self._drone_positions.pop(msg.drone_id, None)

    def _on_formation_goal(self, msg: FormationGoal):
        drone_ids = list(msg.assigned_drone_ids)
        targets = list(msg.target_points)

        if not drone_ids or not targets:
            self.get_logger().error('Received empty assignment goal -- ignoring')
            return

        starts = {}
        goals = {}

        for drone_id, target in zip(drone_ids, targets):
            if drone_id not in self._drone_positions:
                self.get_logger().error(f'Missing current position for assigned drone {drone_id}')
                self._publish_failure(f'Missing position for drone {drone_id}')
                return
            starts[drone_id] = self._drone_positions[drone_id]
            goals[drone_id] = (target.x, target.y, target.z)

        self.get_logger().info(f'Planning CBS for {len(starts)} assigned drones (formation_id={msg.formation_id})')

        # Run strict CBS with a 5.0s timeout limit
        result = cbs_plan(starts, goals, max_t=self.MAX_T, timeout=5.0)

        if not result:
            self.get_logger().error('CBS planning failed or exceeded 5.0s timeout limit.')
            self._publish_failure('CBS planning failed or timed out (5s exceeded).')
            return

        # Publish planned collision-free paths
        formation_start = self.get_clock().now()
        start_time_msg = ros_time_to_msg(formation_start)

        for drone_id, waypoints in result.items():
            path_msg = DronePath()
            path_msg.drone_id = drone_id
            path_msg.waypoints = [Point(x=x, y=y, z=z) for x, y, z, t in waypoints]
            path_msg.waypoint_times = [offset_time_msg(start_time_msg, t) for x, y, z, t in waypoints]
            path_msg.formation_start_time = start_time_msg
            self._path_pub.publish(path_msg)

        self._publish_success(f'Successfully published paths for {len(result)} drones')

    def _publish_success(self, message: str):
        status = PlanStatus()
        status.success = True
        status.status_message = message
        status.usable_drone_count = len(self._drone_positions)
        self._status_pub.publish(status)

    def _publish_failure(self, message: str):
        status = PlanStatus()
        status.success = False
        status.status_message = message
        status.usable_drone_count = len(self._drone_positions)
        self._status_pub.publish(status)


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
