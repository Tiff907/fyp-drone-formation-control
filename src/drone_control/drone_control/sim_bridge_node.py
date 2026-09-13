"""
sim_bridge_node.py

Bridges DroneSetpoint commands to Gazebo Fortress via set_pose_vector
and visual_config. Kinematic only -- no physics, no flight dynamics.

Gazebo calls run on a dedicated background thread, decoupled from the
ROS2 executor: subprocess-based `ign service` calls are slow (process
spawn + service discovery, often 100s of ms), and running them
directly inside a ROS timer callback blocks the single-threaded
executor, starving the /drone/setpoint subscription and causing
setpoints to trickle in instead of being read as a consistent batch.
"""

import re
import subprocess
import threading
import time

import rclpy
from rclpy.node import Node

from formation_msgs.msg import DroneSetpoint

WORLD_NAME = 'formation_world'
REQ_TYPE_POSE_VECTOR = 'ignition.msgs.Pose_V'
REQ_TYPE_VISUAL = 'ignition.msgs.Visual'
REQ_TYPE_EMPTY = 'ignition.msgs.Empty'
REP_TYPE_BOOL = 'ignition.msgs.Boolean'
REP_TYPE_SCENE = 'ignition.msgs.Scene'


def entity_name(drone_id: int) -> str:
    return f'drone_{drone_id}'


class SimBridgeNode(Node):

    UPDATE_RATE_HZ = 20.0  # target rate; actual rate limited by subprocess latency

    def __init__(self):
        super().__init__('sim_bridge_node')

        self._lock = threading.Lock()
        self._latest = {}          # drone_id -> DroneSetpoint
        self._last_color = {}      # drone_id -> (r, g, b)
        self._visual_ids = {}      # drone_id -> (visual_id, parent_id)

        self._build_visual_lookup()

        self.create_subscription(DroneSetpoint, '/drone/setpoint', self._on_setpoint, 10)

        self._stop_event = threading.Event()
        self._worker = threading.Thread(target=self._worker_loop, daemon=True)
        self._worker.start()

        self.get_logger().info('sim_bridge_node started')

    def _build_visual_lookup(self):
        try:
            result = subprocess.run(
                [
                    'ign', 'service', '-s', f'/world/{WORLD_NAME}/scene/info',
                    '--reqtype', REQ_TYPE_EMPTY,
                    '--reptype', REP_TYPE_SCENE,
                    '--timeout', '2000',
                    '--req', '',
                ],
                check=True, capture_output=True, text=True,
            )
        except (subprocess.CalledProcessError, FileNotFoundError) as e:
            self.get_logger().error(f'Failed to query scene/info: {e}')
            return

        text = result.stdout
        model_blocks = re.split(r'\nmodel \{', text)[1:]
        for block in model_blocks:
            name_match = re.search(r'name:\s*"drone_(\d+)"', block)
            if not name_match:
                continue
            drone_id = int(name_match.group(1))
            visual_match = re.search(
                r'name:\s*"body_visual"\s*\n\s*id:\s*(\d+)\s*\n\s*parent_id:\s*(\d+)',
                block,
            )
            if visual_match:
                self._visual_ids[drone_id] = (int(visual_match.group(1)), int(visual_match.group(2)))

        self.get_logger().info(f'Resolved body_visual IDs for {len(self._visual_ids)} drones')

    def _on_setpoint(self, msg: DroneSetpoint):
        # Fast, non-blocking: just store under lock. Never touches Gazebo directly.
        with self._lock:
            self._latest[msg.drone_id] = msg

    def _worker_loop(self):
        """Runs independently of the ROS executor. Reads a consistent
        snapshot of all known setpoints each iteration and sends one
        batched pose update, so drones always move together even if
        each Gazebo call takes longer than one nominal tick."""
        period = 1.0 / self.UPDATE_RATE_HZ
        while not self._stop_event.is_set():
            start = time.monotonic()

            with self._lock:
                snapshot = dict(self._latest)

            if snapshot:
                self._send_pose_vector(snapshot)

                color_changes = []
                with self._lock:
                    for drone_id, msg in snapshot.items():
                        color = (msg.led_color.r, msg.led_color.g, msg.led_color.b)
                        if self._last_color.get(drone_id) != color:
                            color_changes.append((drone_id, msg.led_color))
                            self._last_color[drone_id] = color

                for drone_id, color in color_changes:
                    self._send_visual_color(drone_id, color)

            elapsed = time.monotonic() - start
            time.sleep(max(0.0, period - elapsed))

    def _send_pose_vector(self, setpoints: dict):
        pose_strs = []
        for drone_id, msg in setpoints.items():
            p = msg.target_position
            pose_strs.append(
                f'pose {{ name: "{entity_name(drone_id)}" position {{ x: {p.x} y: {p.y} z: {p.z} }} }}'
            )
        req = ' '.join(pose_strs)

        self._call_ign_service(
            service=f'/world/{WORLD_NAME}/set_pose_vector',
            req_type=REQ_TYPE_POSE_VECTOR,
            rep_type=REP_TYPE_BOOL,
            req=req,
        )

    def _send_visual_color(self, drone_id: int, color):
        ids = self._visual_ids.get(drone_id)
        if ids is None:
            return
        visual_id, parent_id = ids

        req = (
            f'id: {visual_id} parent_id: {parent_id} '
            f'material {{ '
            f'  ambient {{ r: {color.r} g: {color.g} b: {color.b} a: 1.0 }} '
            f'  diffuse {{ r: {color.r} g: {color.g} b: {color.b} a: 1.0 }} '
            f'  emissive {{ r: {color.r} g: {color.g} b: {color.b} a: 1.0 }} '
            f'}}'
        )

        self._call_ign_service(
            service=f'/world/{WORLD_NAME}/visual_config',
            req_type=REQ_TYPE_VISUAL,
            rep_type=REP_TYPE_BOOL,
            req=req,
        )

    def _call_ign_service(self, service: str, req_type: str, rep_type: str, req: str):
        try:
            subprocess.run(
                [
                    'ign', 'service', '-s', service,
                    '--reqtype', req_type,
                    '--reptype', rep_type,
                    '--timeout', '300',
                    '--req', req,
                ],
                check=True, capture_output=True, text=True,
            )
        except subprocess.CalledProcessError as e:
            self.get_logger().warn(f'ign service call to {service} failed: {e.stderr}')
        except FileNotFoundError:
            self.get_logger().error("'ign' command not found -- is Gazebo Fortress on PATH?")

    def destroy_node(self):
        self._stop_event.set()
        self._worker.join(timeout=1.0)
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = SimBridgeNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
