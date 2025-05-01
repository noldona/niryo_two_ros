#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import Command

def generate_launch_description():
    
    robot_description_content = Command([
        'xacro ',
        PathJoinSubstitution([
            FindPackageShare('niryo_one_hardware'),
            'description/urdf','niryo_one.urdf.xacro'
        ])
    ])
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': robot_description_content}]
    )
    
    # 1) Declare launch arguments
    controllers_arg = DeclareLaunchArgument(
        'controllers_file',
        default_value=PathJoinSubstitution([
            FindPackageShare('niryo_one_moveit_config'),
            'config',
            'ros2_controllers.yaml'
        ]),
        description='Full path to ros2_control controller parameters file'
    ) 

    use_fake_hardware_arg = DeclareLaunchArgument(
        'use_fake_hardware',
        default_value='false',
        description='Use fake hardware for simulation'
    ) 

    controllers_file = LaunchConfiguration('controllers_file')
    use_fake_hardware = LaunchConfiguration('use_fake_hardware')

    # 2) Launch the controller manager (ros2_control_node)
    ros2_control_node = Node(
        package='controller_manager',
        executable='ros2_control_node',
        parameters=[controllers_file, {'use_sim_time': False}],
        output='both'
    ) 

    # 3) Spawn the joint state broadcaster
    joint_state_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster', '--controller-manager', '/controller_manager'],
        output='both'
    ) 

    # 4) Spawn the Niryo controller
    niryo_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['niryo_one_controller', '--controller-manager', '/controller_manager'],
        output='screen'
    ) 

    # 5) Include MoveIt’s move_group launch
    move_group_include = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('niryo_one_moveit_config'),
                'launch',
                'move_group.launch.py'
            ])
        ]),
        launch_arguments={
            'controllers': 'moveit_controllers.yaml',
            'use_fake_hardware': use_fake_hardware
        }.items()
)
    return LaunchDescription([
        robot_state_publisher,
        controllers_arg,
        use_fake_hardware_arg,
        ros2_control_node,
        joint_state_spawner,
        niryo_spawner,
        move_group_include
    ])
