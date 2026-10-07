"""
canvas_server_node.py

Bridges the HTML touchscreen canvas to ROS2 via a plain WebSocket
server (not rosbridge). Runs an asyncio WebSocket server on a
background thread alongside the normal rclpy executor, since the two
event loops don't share a thread.

Browser <-> node wire protocol (plain JSON, defined here -- not
generated ROS message JSON):

  Browser -> node:
    {"type": "user_command", "command": "START"|"SUBMIT"|...}
    {"type": "drawn_shape", "raw_points": [{"x":..,"y":..}, ...],
                             "stroke_colors": [{"r":..,"g":..,"b":..,"a":..}, ...]}
    {"type": "refinement_command", "instruction_text": "..."}

  Node -> browser:
    {"type": "system_state", "state": "HOVERING"|"PLANNING"|...}
    {"type": "refinement_candidate",
       "candidate_points": [{"x":..,"y":..}, ...],
       "candidate_colors": [{"r":..,"g":..,"b":..,"a":..}, ...],
       "plan_description": "..."}
"""

import asyncio
import json
import threading

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import ColorRGBA

import websockets

from formation_msgs.msg import (
    DrawnShape, UserCommand, SystemState, RefinementCandidate, RefinementCmd,
)

WS_HOST = '0.0.0.0'
WS_PORT = 8765


class CanvasServerNode(Node):

    def __init__(self):
        super().__init__('canvas_server_node')

        self._connected_clients = set()
        self._loop = None  # set once the asyncio loop starts, used for thread-safe sends

        self._shape_pub = self.create_publisher(DrawnShape, '/formation/drawn_shape', 10)
        self._command_pub = self.create_publisher(UserCommand, '/ui/user_command', 10)
        self._refinement_pub = self.create_publisher(RefinementCmd, '/refinement/command', 10)

        self.create_subscription(SystemState, '/system/state', self._on_system_state, 10)
        self.create_subscription(RefinementCandidate, '/refinement/candidate', self._on_refinement_candidate, 10)

        self._ws_thread = threading.Thread(target=self._run_ws_server, daemon=True)
        self._ws_thread.start()

        self.get_logger().info(f'canvas_server_node started, WebSocket on :{WS_PORT}')

    # ------------------------------------------------------------
    # WebSocket server (runs on its own thread/event loop)
    # ------------------------------------------------------------

    def _run_ws_server(self):
        self._loop = asyncio.new_event_loop()
        asyncio.set_event_loop(self._loop)

        async def handler(websocket):
            self._connected_clients.add(websocket)
            self.get_logger().info('Browser client connected')
            try:
                async for message in websocket:
                    self._handle_browser_message(message)
            except websockets.exceptions.ConnectionClosed:
                pass
            finally:
                self._connected_clients.discard(websocket)
                self.get_logger().info('Browser client disconnected')

        async def main():
            async with websockets.serve(handler, WS_HOST, WS_PORT):
                await asyncio.Future()  # run forever

        self._loop.run_until_complete(main())

    def _handle_browser_message(self, raw_message: str):
        try:
            msg = json.loads(raw_message)
        except json.JSONDecodeError:
            self.get_logger().warn('Received malformed JSON from browser')
            return

        msg_type = msg.get('type')

        if msg_type == 'user_command':
            self._publish_user_command(msg['command'])
        elif msg_type == 'drawn_shape':
            self._publish_drawn_shape(msg['raw_points'], msg['stroke_colors'])
        elif msg_type == 'refinement_command':
            self._publish_refinement_command(msg['instruction_text'])
        else:
            self.get_logger().warn(f'Unknown message type from browser: {msg_type}')

    def _publish_user_command(self, command: str):
        msg = UserCommand()
        msg.command = command
        self._command_pub.publish(msg)

    def _publish_drawn_shape(self, raw_points, stroke_colors):
        msg = DrawnShape()
        msg.raw_points = [
            Point(x=float(p['x']), y=float(p['y']), z=0.0) 
            for p in raw_points
        ]
        msg.stroke_colors = [
            ColorRGBA(
                r=float(c['r']), 
                g=float(c['g']), 
                b=float(c['b']), 
                a=float(c['a'])
            ) 
            for c in stroke_colors
        ]
        self._shape_pub.publish(msg)

    def _publish_refinement_command(self, instruction_text: str):
        msg = RefinementCmd()
        msg.instruction_text = instruction_text
        # current_points intentionally left empty here -- llm_interface_node
        # is expected to use the last submitted/accepted point set it
        # already has, not rely on the browser resending it.
        self._refinement_pub.publish(msg)

    # ------------------------------------------------------------
    # ROS2 -> browser
    # ------------------------------------------------------------

    def _on_system_state(self, msg: SystemState):
        self._broadcast({'type': 'system_state', 'state': msg.state})

    def _on_refinement_candidate(self, msg: RefinementCandidate):
        self._broadcast({
            'type': 'refinement_candidate',
            'candidate_points': [{'x': p.x, 'y': p.y} for p in msg.candidate_points],
            'candidate_colors': [
                {'r': c.r, 'g': c.g, 'b': c.b, 'a': c.a} for c in msg.candidate_colors
            ],
            'plan_description': msg.plan_description,
        })

    def _broadcast(self, payload: dict):
        if not self._connected_clients or self._loop is None:
            return
        message = json.dumps(payload)

        async def send_all():
            for client in list(self._connected_clients):
                try:
                    await client.send(message)
                except websockets.exceptions.ConnectionClosed:
                    pass

        asyncio.run_coroutine_threadsafe(send_all(), self._loop)


def main(args=None):
    rclpy.init(args=args)
    node = CanvasServerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
