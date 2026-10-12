"""
canvas_server_node.py

Bridges the HTML touchscreen canvas to ROS2 via a plain WebSocket
server (not rosbridge). Runs an asyncio WebSocket server on a
background thread alongside the normal rclpy executor, since the two
event loops don't share a thread.

Also serves the canvas page (web/index.html) over HTTP from the same
node, so starting the node is all that is needed: open
http://localhost:8080 on this machine, or http://<this machine's IP>:8080
from another device on the same network. The page connects its
WebSocket back to the same host on port 8765.

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
import functools
import json
import os
import socket
import threading
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import ColorRGBA

import websockets

from formation_msgs.msg import (
    DrawnShape, UserCommand, SystemState, RefinementCandidate, RefinementCmd,
)

WS_HOST = '0.0.0.0'      # all interfaces, so other devices on the network can connect
WS_PORT = 8765           # the page connects to this port; keep in sync with index.html
HTTP_PORT = 8080         # default for the 'http_port' parameter
PACKAGE_NAME = 'formation_ui'   # package whose share/web folder holds index.html


class _PageHandler(SimpleHTTPRequestHandler):
    """Serves the files in web_dir (index.html at '/'). No caching, so an
    edited page shows up on refresh; no per-request log lines."""

    def end_headers(self):
        self.send_header('Cache-Control', 'no-store')
        super().end_headers()

    def log_message(self, format, *args):
        pass


def _lan_ip() -> str:
    """This machine's address on the local network (no packet is sent)."""
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        s.connect(('10.255.255.255', 1))
        return s.getsockname()[0]
    except OSError:
        return '127.0.0.1'
    finally:
        s.close()


class CanvasServerNode(Node):

    def __init__(self):
        super().__init__('canvas_server_node')

        # web_dir: folder containing index.html. Empty = look in the package's
        # share/web folder, then in <package>/web next to this source file.
        self.declare_parameter('web_dir', '')
        self.declare_parameter('http_port', HTTP_PORT)
        self._http_server = None

        self._connected_clients = set()
        self._loop = None  # set once the asyncio loop starts, used for thread-safe sends

        self._shape_pub = self.create_publisher(DrawnShape, '/formation/drawn_shape', 10)
        self._command_pub = self.create_publisher(UserCommand, '/ui/user_command', 10)
        self._refinement_pub = self.create_publisher(RefinementCmd, '/refinement/command', 10)

        self.create_subscription(SystemState, '/system/state', self._on_system_state, 10)
        self.create_subscription(RefinementCandidate, '/refinement/candidate', self._on_refinement_candidate, 10)

        self._ws_thread = threading.Thread(target=self._run_ws_server, daemon=True)
        self._ws_thread.start()

        self._start_web_server()

        self.get_logger().info(f'canvas_server_node started, WebSocket on :{WS_PORT}')

    # ------------------------------------------------------------
    # Web page server (plain HTTP, runs on its own thread)
    # ------------------------------------------------------------

    def _resolve_web_dir(self):
        candidates = []

        configured = self.get_parameter('web_dir').get_parameter_value().string_value
        if configured:
            candidates.append(configured)

        try:
            from ament_index_python.packages import get_package_share_directory
            candidates.append(os.path.join(get_package_share_directory(PACKAGE_NAME), 'web'))
        except Exception:
            pass

        here = os.path.dirname(os.path.realpath(__file__))
        candidates.append(os.path.join(here, '..', 'web'))

        for path in candidates:
            path = os.path.abspath(path)
            if os.path.isfile(os.path.join(path, 'index.html')):
                return path
        return None

    def _start_web_server(self):
        web_dir = self._resolve_web_dir()
        if web_dir is None:
            self.get_logger().error(
                'index.html not found, so the web page is NOT being served '
                '(the WebSocket server still works). Put it in '
                f'{PACKAGE_NAME}/web/index.html and install that folder in '
                'setup.py, or set the web_dir parameter.')
            return

        port = int(self.get_parameter('http_port').value)
        handler = functools.partial(_PageHandler, directory=web_dir)
        try:
            self._http_server = ThreadingHTTPServer((WS_HOST, port), handler)
        except OSError as exc:
            self.get_logger().error(
                f'Could not start the web page server on port {port}: {exc}. '
                'Another program may be using it; change the http_port parameter.')
            return

        threading.Thread(target=self._http_server.serve_forever, daemon=True).start()
        self.get_logger().info(
            f'Canvas page: http://localhost:{port} on this machine, '
            f'http://{_lan_ip()}:{port} from other devices on the same network '
            f'(serving {web_dir})')

    def destroy_node(self):
        if self._http_server is not None:
            self._http_server.shutdown()
            self._http_server.server_close()
        super().destroy_node()

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
