from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.substitutions import Command, LaunchConfiguration
from launch.conditions import IfCondition, UnlessCondition
from launch_ros.actions import Node, SetParameter
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    urdf_file_v1 = Command([
        'xacro --inorder ',
        os.path.join(
            get_package_share_directory('niryo_one_description'),
            'urdf',
            'v1',
            'without_mesh_niryo_one.urdf.xacro'
        )
    ])

    urdf_file_v2 = Command([
        'xacro --inorder ',
        os.path.join(
            get_package_share_directory('niryo_one_description'),
            'urdf',
            'v2',
            'without_mesh_niryo_one.urdf.xacro'
        )
    ])

    return LaunchDescription([
        DeclareLaunchArgument(
            'hardware_version',
            default_value=2,
            description='Set to 1 or 2 depending on your hardware version'
        ),
        DeclareLaunchArgument(
            'urdf_file',
            default_value=urdf_file_v1,
            description='Absolute path to robot urdf file',
            condition=IfCondition(LaunchConfiguration('hardware_version') == 1)
        ),
        DeclareLaunchArgument(
            'urdf_file',
            default_value=urdf_file_v2,
            description='Absolute path to robot urdf file',
            condition=IfCondition(LaunchConfiguration('hardware_version') == 2)
        ),
        DeclareLaunchArgument(
            'gui',
            default_value='true',
            description='Set to "true" to run GUI'
        ),

        GroupAction(
            actions=[
                SetParameter(name='robot_description',
                             value=LaunchConfiguration('urdf_file')),
                SetParameter(name='use_gui', value=LaunchConfiguration('gui')),

                Node(
                    package='joint_state_publisher',
                    executable='joint_state_publisher',
                    name='joint_state_publisher'
                ),
                Node(
                    package='robot_state_publisher',
                    executable='robot_state_publisher',
                    name='robot_state_publisher'
                ),
                Node(
                    package='rviz',
                    executable='rviz',
                    name='rviz',
                    arguments=['-d', os.path.join(
                        get_package_share_directory('niryo_one_description'),
                        'config',
                        'default_config.rviz'
                    )]
                )
            ]
        )
    ])
