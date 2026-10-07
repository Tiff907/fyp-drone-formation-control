"""
formation_planner.launch.py

Starts the full formation_planner pipeline: shape_sampling_node,
coords_mapping_node, drone_validator_node, assignment_node, mapf_node.

All five nodes are message-driven and idle until real data flows
(drone states, drawn shapes), so they can start at any time relative
to Gazebo/drone spawn -- no ordering dependency on this file's own
nodes starting before or after drone_control's.
"""

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='formation_planner',
            executable='shape_sampling_node',
            name='shape_sampling_node',
            output='screen',
        ),
        Node(
            package='formation_planner',
            executable='coords_mapping_node',
            name='coords_mapping_node',
            output='screen',
        ),
        Node(
            package='formation_planner',
            executable='drone_validator_node',
            name='drone_validator_node',
            output='screen',
        ),
        Node(
            package='formation_planner',
            executable='assignment_node',
            name='assignment_node',
            output='screen',
        ),
        Node(
            package='formation_planner',
            executable='mapf_node',
            name='mapf_node',
            output='screen',
        ),
    ])
