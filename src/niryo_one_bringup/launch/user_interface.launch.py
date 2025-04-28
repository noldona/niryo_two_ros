from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.conditions import IfCondition, UnlessCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Declare launch arguments
    simulation_mode = DeclareLaunchArgument(
        'simulation_mode', default_value='false'
    )
    joy_enabled = DeclareLaunchArgument(
        'joy_enabled', default_value='true'
    )

    # Joystick setup
    joy_node = GroupAction(
        condition=IfCondition(LaunchConfiguration('joy_enabled')),
        actions=[
            Node(
                package='joy',
                executable='joy_node',
                name='joy_node',
                namespace='joy_node',  #  Added namespace
                output='screen',
                parameters=[{
                    'joy_node.deadzone': 0.2,
                    'joy_node.coalesce_interval': 0.1
                }]
            )
        ]
    )

    # Shared parameters
    blockly_path = os.path.join(
        get_package_share_directory('niryo_one_user_interface'),
        'tmp_blockly'
    )
    code_exec_path = os.path.join(
        get_package_share_directory('niryo_one_user_interface'),
        'tmp_code_to_execute'
    )

    # User interface node for real hardware
    ui_node_real = Node(
        condition=UnlessCondition(LaunchConfiguration('simulation_mode')),
        package='niryo_one_user_interface',
        executable='user_interface.py',
        name='user_interface',
        output='screen',
        parameters=[
            {'joystick_timer_rate_sec': 0.15},
            {'niryo_one_blockly_path': blockly_path},
            {'niryo_one_blockly_tcp_port': 1337},
            {'sequence_code_to_execute_path': code_exec_path},
            {'sequences_dir': '/home/niryo/niryo_one_sequences'},
            {'sequence_autorun_status_file': '/home/niryo/niryo_one_saved_values/sequence_autorun_status.txt'},
        ]
    )

    # User interface node for simulation
    ui_node_sim = Node(
        condition=IfCondition(LaunchConfiguration('simulation_mode')),
        package='niryo_one_user_interface',
        executable='user_interface.py',
        name='user_interface',
        output='screen',
        parameters=[
            {'joystick_timer_rate_sec': 0.15},
            {'niryo_one_blockly_path': blockly_path},
            {'niryo_one_blockly_tcp_port': 1337},
            {'sequence_code_to_execute_path': code_exec_path},
            {'sequences_dir': '~/niryo_one_sequences'},
            {'sequence_autorun_status_file': '~/sequence_autorun_status.txt'},
        ]
    )

    return LaunchDescription([
        simulation_mode,
        joy_enabled,
        joy_node,
        ui_node_real,
        ui_node_sim
    ])
