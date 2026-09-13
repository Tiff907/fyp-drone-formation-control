import os

from ament_index_python.packages import get_package_share_directory, get_package_prefix
from launch import LaunchDescription
from launch.actions import ExecuteProcess, TimerAction
from launch_ros.actions import Node


def generate_launch_description():
    gazebo_pkg_share = get_package_share_directory('formation_gazebo')
    gazebo_pkg_prefix = get_package_prefix('formation_gazebo')

    world_path = os.path.join(gazebo_pkg_share, 'worlds', 'formation_world.sdf')
    spawn_script_path = os.path.join(gazebo_pkg_prefix, 'lib', 'formation_gazebo', 'spawn_drones.sh')

    gazebo = ExecuteProcess(
        cmd=['ign', 'gazebo', world_path],
        output='screen',
    )

    spawn_drones = TimerAction(
        period=5.0,
        actions=[
            ExecuteProcess(
                cmd=['bash', spawn_script_path],
                output='screen',
            )
        ],
    )

    ros_nodes = TimerAction(
        period=12.0,
        actions=[
            Node(
                package='drone_control',
                executable='drone_controller_node',
                name='drone_controller_node',
                output='screen',
            ),
            Node(
                package='drone_control',
                executable='pose_publisher_node',
                name='pose_publisher_node',
                output='screen',
            ),
            Node(
                package='drone_control',
                executable='sim_bridge_node',
                name='sim_bridge_node',
                output='screen',
            ),
        ],
    )

    return LaunchDescription([
        gazebo,
        spawn_drones,
        ros_nodes,
    ])
