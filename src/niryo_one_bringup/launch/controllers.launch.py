from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.substitutions import LaunchConfiguration, PythonExpression, EqualsSubstitution, Command
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.actions import Node
from launch.conditions import IfCondition, UnlessCondition
from ament_index_python.packages import get_package_share_directory
import os
from launch.actions import IncludeLaunchDescription


def generate_launch_description():
    logger = LaunchConfiguration('log_level')

    niryo_one_driver_config = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'config',
        'niryo_one_driver.yaml'
    )

    niryo_one_end_effector_config = os.path.join(
        get_package_share_directory('niryo_one_tools'),
        'config',
        'end_effectors.yaml'
    )

    niryo_one_controllers_config = os.path.join(
        get_package_share_directory('niryo_one_driver'),
        'config',
        'niryo_one_controllers.yaml'
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            'log_level',
            default_value='INFO',
            description='Logging level'
        ),

        IncludeLaunchDescription(
            os.path.join(
                get_package_share_directory('niryo_one_bringup'),
                'launch',
                'niryo_one_base.launch.py'
            )
        ),

        DeclareLaunchArgument(
            'simulation_mode',
            default_value='false',
            description='Set to true if you want to launch ROS on your computer'),
        DeclareLaunchArgument(
            'disable_can_for_debug',
            default_value='false',
            description='Set to true to disable hardware communication for CAN bus(Niryo Steppers)'),
        DeclareLaunchArgument(
            'disable_dxl_for_debug',
            default_value='false',
            description='Set to true to disable hardware communication for DXL bus(DEBUG PURPOSES)'),

        GroupAction(
            actions=[
                Node(
                    package='niryo_one_driver',
                    executable='niryo_one_driver',
                    name='niryo_one_driver',
                    output='screen',
                    parameters=[
                        niryo_one_driver_config,
                        LaunchConfiguration('robot_command_validation_v1'),
                        LaunchConfiguration('niryo_one_motors_v1'),
                        LaunchConfiguration('stepper_params_v1'),
                        {
                            'fake_communication': LaunchConfiguration('simulation_mode'),
                            'can_enabled': PythonExpression([
                                '"false" if "', LaunchConfiguration('disable_can_for_debug'), '" == "true" else "true"']),
                            'dxl_enabled': PythonExpression([
                                '"false" if "', LaunchConfiguration('disable_dxl_for_debug'), '" == "true" else "true"']),
                        },
                    ],
                    arguments=[
                        '--ros-args',
                        '--log-level', logger
                    ]
                ),

                Node(
                    package='niryo_one_tools',
                    executable='tool_controller',
                    name='niryo_one_tools',
                    output='screen',
                    parameters=[
                        niryo_one_end_effector_config,
                    ],
                    arguments=[
                        '--ros-args',
                        '--log-level', logger
                    ]
                ),

                GroupAction(
                    actions=[
                        Node(
                            package='controller_manager',
                            executable='spawner',
                            name='controller_spawner',
                            output='screen',
                            parameters=[
                                niryo_one_controllers_config,
                                {
                                    'robot_description': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_v1_without_meshes_path')]), value_type=str),
                                    'robot_description_tf2': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_tf2_path')]), value_type=str)
                                }
                            ],
                            arguments=[
                                'joint_state_controller',
                                'niryo_one_follow_joint_trajectory_controller',
                                # '--shutdown-timeout', '1',
                                '--ros-args',
                                '--log-level', logger
                            ],
                        ),

                        Node(
                            package='robot_state_publisher',
                            executable='robot_state_publisher',
                            name='robot_state_publisher',
                            output='screen',
                            parameters=[
                                niryo_one_controllers_config,
                                {
                                    'robot_description': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_v1_without_meshes_path')]), value_type=str),
                                    'robot_description_tf2': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_tf2_path')]), value_type=str)
                                }
                            ],
                            arguments=[
                                '--ros-args',
                                '--log-level', logger
                            ]
                        )
                    ],
                    condition=IfCondition(
                        LaunchConfiguration('urdf_without_meshes'))
                ),

                GroupAction(
                    actions=[
                        Node(
                            package='controller_manager',
                            executable='spawner',
                            name='controller_spawner',
                            output='screen',
                            parameters=[
                                niryo_one_controllers_config,
                                {
                                    'robot_description': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_v1_path')]), value_type=str),
                                    'robot_description_tf2': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_tf2_path')]), value_type=str)
                                }
                            ],
                            arguments=[
                                'joint_state_controller',
                                'niryo_one_follow_joint_trajectory_controller',
                                # '--shutdown-timeout', '1',
                                '--ros-args',
                                '--log-level', logger
                            ],
                        ),

                        Node(
                            package='robot_state_publisher',
                            executable='robot_state_publisher',
                            name='robot_state_publisher',
                            output='screen',
                            parameters=[
                                niryo_one_controllers_config,
                                {
                                    'robot_description': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_v1_path')]), value_type=str),
                                    'robot_description_tf2': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_tf2_path')]), value_type=str)
                                }
                            ],
                            arguments=[
                                '--ros-args',
                                '--log-level', logger
                            ]

                        )
                    ],
                    condition=UnlessCondition(
                        LaunchConfiguration('urdf_without_meshes'))
                ),
            ],
            condition=IfCondition(EqualsSubstitution(
                LaunchConfiguration('hardware_version'), '1'))
        ),

        GroupAction(
            actions=[
                Node(
                    package='niryo_one_driver',
                    executable='niryo_one_driver',
                    name='niryo_one_driver',
                    output='screen',
                    parameters=[
                        niryo_one_driver_config,
                        LaunchConfiguration('robot_command_validation_v2'),
                        LaunchConfiguration('niryo_one_motors_v2'),
                        LaunchConfiguration('stepper_params_v2'),
                        {
                            'fake_communication': LaunchConfiguration('simulation_mode'),
                            'can_enabled': PythonExpression([
                                '"false" if "', LaunchConfiguration('disable_can_for_debug'), '" == "true" else "true"']),
                            'dxl_enabled': PythonExpression([
                                '"false" if "', LaunchConfiguration('disable_dxl_for_debug'), '" == "true" else "true"'])
                        },
                    ],
                    arguments=[
                        '--ros-args',
                        '--log-level', logger
                    ]

                ),

                Node(
                    package='niryo_one_tools',
                    executable='tool_controller',
                    name='niryo_one_tools',
                    output='screen',
                    parameters=[
                        niryo_one_end_effector_config,
                    ],
                    arguments=[
                        '--ros-args',
                        '--log-level', logger
                    ]
                ),

                GroupAction(
                    actions=[
                        Node(
                            package='controller_manager',
                            executable='spawner',
                            name='controller_spawner',
                            output='screen',
                            parameters=[
                                niryo_one_controllers_config,
                                {
                                    'robot_description': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_v2_without_meshes_path')]), value_type=str),
                                    'robot_description_tf2': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_tf2_path')]), value_type=str)
                                }
                            ],
                            arguments=[
                                'joint_state_controller',
                                'niryo_one_follow_joint_trajectory_controller',
                                # '--shutdown-timeout', '1',
                                '--ros-args',
                                '--log-level', logger
                            ],
                        ),

                        Node(
                            package='robot_state_publisher',
                            executable='robot_state_publisher',
                            name='robot_state_publisher',
                            output='screen',
                            parameters=[
                                niryo_one_controllers_config,
                                {
                                    'robot_description': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_v2_without_meshes_path')]), value_type=str),
                                    'robot_description_tf2': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_tf2_path')]), value_type=str)
                                }
                            ],
                            arguments=[
                                '--ros-args',
                                '--log-level', logger
                            ]

                        )
                    ],
                    condition=IfCondition(
                        LaunchConfiguration('urdf_without_meshes'))
                ),

                GroupAction(
                    actions=[
                        Node(
                            package='controller_manager',
                            executable='spawner',
                            name='controller_spawner',
                            output='screen',
                            parameters=[
                                niryo_one_controllers_config,
                                {
                                    'robot_description': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_v2_path')]), value_type=str),
                                    'robot_description_tf2': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_tf2_path')]), value_type=str)
                                }
                            ],
                            arguments=[
                                'joint_state_controller',
                                'niryo_one_follow_joint_trajectory_controller',
                                # '--shutdown-timeout', '1',
                                '--ros-args',
                                '--log-level', logger
                            ],
                        ),

                        Node(
                            package='robot_state_publisher',
                            executable='robot_state_publisher',
                            name='robot_state_publisher',
                            output='screen',
                            parameters=[
                                niryo_one_controllers_config,
                                {
                                    'robot_description': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_v2_path')]), value_type=str),
                                    'robot_description_tf2': ParameterValue(Command(['xacro ', LaunchConfiguration('robot_description_tf2_path')]), value_type=str)
                                }
                            ],
                            arguments=[
                                '--ros-args',
                                '--log-level', logger
                            ]

                        )
                    ],
                    condition=UnlessCondition(
                        LaunchConfiguration('urdf_without_meshes'))
                ),
            ],
            condition=IfCondition(EqualsSubstitution(
                LaunchConfiguration('hardware_version'), '2'))
        )
    ])
