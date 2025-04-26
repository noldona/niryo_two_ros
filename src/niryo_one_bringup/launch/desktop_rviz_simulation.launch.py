from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os

from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    niryo_bringup_dir = get_package_share_directory('niryo_one_bringup')
    niryo_desc_dir = get_package_share_directory('niryo_one_description')
    rosbridge_dir = get_package_share_directory('rosbridge_server')

    return LaunchDescription([
        # Arguments
        DeclareLaunchArgument(
            'execute_on_niryo_one_raspberry_pi_image',
            default_value='false'
        ),
        DeclareLaunchArgument(
            'urdf_without_meshes',
            default_value='false'
        ),

        # Includes
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(niryo_bringup_dir, 'launch', 'niryo_one_base.launch.py')
            )
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(niryo_bringup_dir, 'launch', 'controllers.launch.py')
            ),
            launch_arguments={'simulation_mode': 'true'}.items()
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(niryo_bringup_dir, 'launch', 'robot_commander.launch.py')
            ),
            launch_arguments={'simulation_mode': 'true'}.items()
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(niryo_bringup_dir, 'launch', 'user_interface.launch.py')
            ),
            launch_arguments={'simulation_mode': 'true'}.items()
        ),

        # tf2_web_republisher Node
        Node(
            package='tf2_web_republisher',
            executable='tf2_web_republisher',
            name='tf2_web_republisher',
            output='screen'
        ),

        # rosbridge websocket
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(rosbridge_dir, 'launch', 'rosbridge_websocket_launch.py')
            ),
            launch_arguments={'port': '9090'}.items()
        ),

        # RViz
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz',
            arguments=['-d', os.path.join(niryo_desc_dir, 'config', 'default_config.rviz')],
            output='screen'
        )
    ])
