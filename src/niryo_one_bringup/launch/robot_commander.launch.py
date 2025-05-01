import os
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch.substitutions import LaunchConfiguration
from launch.substitutions import IfElseSubstitution
from launch_ros.actions import Node, SetParameter
from launch_ros.substitutions import FindPackageShare
from moveit_configs_utils import MoveItConfigsBuilder

def generate_launch_description():

    ld = LaunchDescription()
    ld.add_action(
        DeclareLaunchArgument(
            'simulation_mode',
            default_value='false',
            description='Set to true to run in simulation mode'
        )
    )
    ld.add_action(
        DeclareLaunchArgument(
            'reference_frame',
            default_value='world',
            description='Reference frame for the robot'
        )
    )
    ld.add_action(
        DeclareLaunchArgument(
            'move_group_commander_name',
            default_value='arm',
            description='Name of the MoveGroupCommander'
        )
    )
    ld.add_action(
        DeclareLaunchArgument(
            'allow_replanning',
            default_value='true',
            description='Allow replanning during motion planning'
        )
    )
    ld.add_action(
        DeclareLaunchArgument(
            'goal_joint_tolerance',
            default_value='0.01',
            description='Joint tolerance for goal position'
        )
    )
    ld.add_action(
        DeclareLaunchArgument(
            'goal_position_tolerance',
            default_value='0.01',
            description='Position tolerance for goal position'
        )
    )
    ld.add_action(
        DeclareLaunchArgument(
            'goal_orientation_tolerance',
            default_value='0.01',
            description='Orientation tolerance for goal position'
        )
    )
    ld.add_action(
        DeclareLaunchArgument(
            'positions_dir',
            default_value=IfElseSubstitution(
                condition=LaunchConfiguration('simulation_mode'),
                if_value="~/niryo_one_positions",
                else_value="home/niryo/niryo_one_positions"),
            description='Directory for storing positions'
        )
    )
    ld.add_action(
        DeclareLaunchArgument(
            'trajectories_dir',
            default_value=IfElseSubstitution(
                condition=LaunchConfiguration('simulation_mode'),
                if_value="~/niryo_one_trajectories",
                else_value="home/niryo/niryo_one_trajectories"),
            description='Directory for storing trajectories'
        )
    )
    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([
                    FindPackageShare('niryo_one_moveit_config'),
                    'launch',
                    'move_group.launch.py'
                ])
            )
        )
    )
    
    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([
                    FindPackageShare('niryo_one_bringup'),
                    'launch',
                    'niryo_one_base.launch.py'
                ])
            )
        )
    )
    moveit_config = MoveItConfigsBuilder("niryo_one", package_name="niryo_one_moveit_config").moveit_cpp().planning_pipelines().to_moveit_configs()
    ld.add_action(
        Node(
            package='niryo_one_commander',
            executable='niryo_one_commander_node',
            name='niryo_one_commander',
            output='both',
            parameters=[{
                'reference_frame': LaunchConfiguration('reference_frame'),
                'move_group_commander_name': LaunchConfiguration('move_group_commander_name'),
                'allow_replanning': LaunchConfiguration('allow_replanning'),
                'goal_joint_tolerance': LaunchConfiguration('goal_joint_tolerance'),
                'goal_position_tolerance': LaunchConfiguration('goal_position_tolerance'),
                'goal_orientation_tolerance': LaunchConfiguration('goal_orientation_tolerance'),
                'positions_dir': LaunchConfiguration('positions_dir'),
                'trajectories_dir': LaunchConfiguration('trajectories_dir'),
            },
                moveit_config.to_dict()
            ],
            # remappings=[
            #     ('/niryo_one_commander/trajectory_execution_event', '/move_group/trajectory_execution_event'),
            #     ('/niryo_one_commander/robot_state', '/move_group/robot_state'),
            #     ('/niryo_one_commander/robot_state_publisher', '/move_group/robot_state_publisher'),
            #     ('/niryo_one_commander/move_group_commander', '/move_group/move_group_commander'),
            # ]
        )
    )
    return ld