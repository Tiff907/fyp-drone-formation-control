"""
coords_mapping_node.py

Maps validated 2D canvas points into 3D real-world coordinates.
Canvas (x, y) -> real-world (x, z) directly. Canvas y additionally
maps to a real-world y-offset (depth) via a fixed linear relationship
y = z/B, keeping drones with similar x-coordinates spread in depth
rather than stacked vertically (avoids downwash risk) and guaranteeing
every point stays within the physical boundary.

B is a constant computed once from the ratio of the canvas's full
y-range to the physical flight boundary's available y-range, since
both are fixed and known in advance.
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point

from formation_msgs.msg import SampledPoints

CANVAS_X_RANGE = (-2.5, 2.5)  # Span: 5.0
CANVAS_Y_RANGE = (0.0, 3.0)   # Span: 3.0

BOUNDARY_Y_RANGE = (-1.5, 1.5)
B = (CANVAS_Y_RANGE[1] - CANVAS_Y_RANGE[0]) / (BOUNDARY_Y_RANGE[1] - BOUNDARY_Y_RANGE[0])

def map_point(x: float, y: float) -> Point:
    p = Point()
    
    p.x = x
    p.y = (y - CANVAS_Y_RANGE[0]) / B + BOUNDARY_Y_RANGE[0]
    p.z = y
    
    return p


class CoordsMappingNode(Node):

    def __init__(self):
        super().__init__('coords_mapping_node')

        self.create_subscription(SampledPoints, '/formation/validated_points', self._on_validated_points, 10)
        self._mapped_pub = self.create_publisher(SampledPoints, '/formation/mapped_points', 10)

        self.get_logger().info(f'coords_mapping_node started (B={B:.4f})')

    def _on_validated_points(self, msg: SampledPoints):
        mapped = SampledPoints()
        mapped.n_min_only = False
        mapped.n_min = msg.n_min
        mapped.target_n_used = msg.target_n_used
        mapped.points = [map_point(p.x, p.y) for p in msg.points]
        mapped.colors = list(msg.colors)

        self.get_logger().info(f'Mapped {len(mapped.points)} points to 3D coordinates')
        self._mapped_pub.publish(mapped)


def main(args=None):
    rclpy.init(args=args)
    node = CoordsMappingNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
