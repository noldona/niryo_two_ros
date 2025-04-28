import os
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration, IfElseSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

    declared_arguments = []
    declared_arguments.append(
        DeclareLaunchArgument('simulation_mode', default_value='false'),
        DeclareLaunchArgument('reference_frame', default_value='world'),
        DeclareLaunchArgument('move_group_commander_name', default_value='arm'),
        DeclareLaunchArgument('allow_replanning', default_value='true'),
        DeclareLaunchArgument('goal_joint_tolerance', default_value='0.01'),
        DeclareLaunchArgument('goal_position_tolerance', default_value='0.01'),
        DeclareLaunchArgument('goal_orientation_tolerance', default_value='0.01'),
        DeclareLaunchArgument('positions_dir', default_value=IfElseSubstitution(
            condition=LaunchConfiguration('simulation_mode'),
            if_value="~/niryo_one_positions",
            else_value="home/niryo/niryo_one_positions")),
        DeclareLaunchArgument('trajectories_dir', default_value=IfElseSubstitution(
            condition=LaunchConfiguration('simulation_mode'),
            if_value="~/niryo_one_trajectories",
            else_value="home/niryo/niryo_one_trajectories")),
    )

    launch_include = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                FindPackageShare('niryo_one_moveit_config'),
                'launch',
                'move_group.launch.py'
            ])
        )
    )

    niryo_one_commander_node = Node(
        package='niryo_one_commander',
        executable='niryo_one_commander_node.py',
        name='niryo_one_commander',
        output='screen',
        respawn='false',
        parameters=[{
            'reference_frame': LaunchConfiguration('reference_frame'),
            'move_group_commander_name': LaunchConfiguration('move_group_commander_name'),
            'allow_replanning': LaunchConfiguration('allow_replanning'),
            'goal_joint_tolerance': LaunchConfiguration('goal_joint_tolerance'),
            'goal_position_tolerance': LaunchConfiguration('goal_position_tolerance'),
            'goal_orientation_tolerance': LaunchConfiguration('goal_orientation_tolerance'),
            'positions_dir': LaunchConfiguration('positions_dir'),
            'trajectories_dir': LaunchConfiguration('trajectories_dir'),
            # 🔵 Added the missing 3 move_group parameters
            '/move_group/trajectory_execution/allowed_start_tolerance': 0.0,
            '/move_group/trajectory_execution/execution_duration_monitoring': False,
            '/move_group/start_state_max_bounds_error': 0.3
        }]
    )

    return LaunchDescription([
        launch_include,
        declared_arguments,
        niryo_one_commander_node
    ])

