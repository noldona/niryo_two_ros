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

    declared_arguments.append(DeclareLaunchArgument('simulation_mode', default_value='false'))
    declared_arguments.append(DeclareLaunchArgument('reference_frame', default_value='world'))
    declared_arguments.append(DeclareLaunchArgument('move_group_commander_name', default_value='arm'))
    declared_arguments.append(DeclareLaunchArgument('allow_replanning', default_value='true'))
    declared_arguments.append(DeclareLaunchArgument('goal_joint_tolerance', default_value='0.01'))
    declared_arguments.append(DeclareLaunchArgument('goal_position_tolerance', default_value='0.01'))
    declared_arguments.append(DeclareLaunchArgument('goal_orientation_tolerance', default_value='0.01'))
    declared_arguments.append(DeclareLaunchArgument(
        'positions_dir',
        default_value=IfElseSubstitution(
            condition=LaunchConfiguration('simulation_mode'),
            if_value="~/niryo_one_positions",
            else_value="~/niryo/niryo_one_positions"  
        )
    ))
    declared_arguments.append(DeclareLaunchArgument(
        'trajectories_dir',
        default_value=IfElseSubstitution(
            condition=LaunchConfiguration('simulation_mode'),
            if_value="~/niryo_one_trajectories",
            else_value="~/niryo/niryo_one_trajectories"  
        )
    ))

    
    declared_arguments.append(DeclareLaunchArgument('move_group_namespace', default_value='move_group'))
    declared_arguments.append(DeclareLaunchArgument('move_group_name', default_value='niryo_move_group'))
    declared_arguments.append(DeclareLaunchArgument('move_group_prefix', default_value=''))


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
            'move_group_namespace': LaunchConfiguration('move_group_namespace'),   
            'move_group_name': LaunchConfiguration('move_group_name'),             
            'move_group_prefix': LaunchConfiguration('move_group_prefix')          
        }]
    )

    return LaunchDescription(
        declared_arguments + [launch_include, niryo_one_commander_node]
    )
