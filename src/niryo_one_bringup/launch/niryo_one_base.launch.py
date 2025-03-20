from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction, LogInfo
from launch.substitutions import LaunchConfiguration, Command, EqualsSubstitution, PythonExpression, TextSubstitution
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.actions import Node, SetParameter
from launch.conditions import IfCondition, UnlessCondition
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    # Load the URDF, SRDF and other .yaml configuration files

    robot_command_validation_v1 = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'config',
        'v1',
        'robot_command_validation.yaml'
    )
    robot_command_validation_v2 = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'config',
        'v2',
        'robot_command_validation.yaml'
    )

    niryo_one_motors_v1 = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'config',
        'v1',
        'niryo_one_motors.yaml'
    )
    niryo_one_motors_v2 = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'config',
        'v2',
        'niryo_one_motors.yaml'
    )
    stepper_params_v1 = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'config',
        'v1',
        'stepper_params.yaml'
    )
    stepper_params_v2 = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'config',
        'v2',
        'stepper_params.yaml'
    )

    robot_description_v1_without_meshes_path = os.path.join(
        get_package_share_directory('niryo_one_description'),
        'urdf',
        'v1',
        'without_mesh_niryo_one.urdf.xacro'
    )
    robot_description_v1_path = os.path.join(
        get_package_share_directory('niryo_one_description'),
        'urdf',
        'v1',
        'niryo_one.urdf.xacro'
    )
    robot_description_v2_without_meshes_path = os.path.join(
        get_package_share_directory('niryo_one_description'),
        'urdf',
        'v2',
        'without_mesh_niryo_one.urdf.xacro'
    )
    robot_description_v2_path = os.path.join(
        get_package_share_directory('niryo_one_description'),
        'urdf',
        'v2',
        'niryo_one.urdf.xacro'
    )
    robot_description_tf2_path = os.path.join(
        get_package_share_directory('niryo_one_description'),
        'urdf',
        'v2',
        'niryo_one.urdf.xacro'
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            'hardware_version',
            default_value='2',
            description='Set to 1 or 2 depending on your hardware version'),
        DeclareLaunchArgument(
            'urdf_without_meshes',
            default_value='true',
            description='Set to true to load URDF without meshes'),
        DeclareLaunchArgument(
            'niryo_one_sim_mode',
            default_value='false',
            description='Set to true to run in simulation mode'),
        DeclareLaunchArgument(
            'execute_on_niryo_one_raspberry_pi_image',
            default_value='true',
            description='Set to true if running on the Raspberry Pi image'),

        # niryo_one
        SetParameter(name='/niryo_one/hardware_version',
                     value=LaunchConfiguration('hardware_version')),
        SetParameter(
            name='/niryo_one/reboot_when_auto_change_version', value=True),

        # niryo_one/robot_command_validation
        DeclareLaunchArgument(
            'robot_command_validation_v1',
            default_value=robot_command_validation_v1,
            description='Path to the robot command validation configuration file for version 1'
        ),
        DeclareLaunchArgument(
            'robot_command_validation_v2',
            default_value=robot_command_validation_v2,
            description='Path to the robot command validation configuration file for version 2'
        ),

        # niryo_one/motors
        DeclareLaunchArgument(
            'niryo_one_motors_v1',
            default_value=niryo_one_motors_v1,
            description='Path to the niryo_one_motors configuration file for version 1'
        ),
        DeclareLaunchArgument(
            'niryo_one_motors_v2',
            default_value=niryo_one_motors_v2,
            description='Path to the niryo_one_motors configuration file for version 2'
        ),
        DeclareLaunchArgument(
            'stepper_params_v1',
            default_value=stepper_params_v1,
            description='Path to the stepper_params configuration file for version 1'
        ),
        DeclareLaunchArgument(
            'stepper_params_v2',
            default_value=stepper_params_v2,
            description='Path to the stepper_params configuration file for version 2'
        ),

        # niryo_one/python_api
        SetParameter(name='/niryo_one/python_api/service_timeout', value=2),
        SetParameter(
            name='/niryo_one/python_api/action_connection_timeout', value=2),
        SetParameter(
            name='/niryo_one/python_api/action_execute_timeout', value=15),
        SetParameter(
            name='/niryo_one/python_api/action_preempt_timeout', value=3),

        # niryo_one/info
        SetParameter(name='niryo_one/info/ros_version',
                     value=os.environ.get('ROS_DISTRO')),
        SetParameter(
            name='/niryo_one/info/niryo_one_one_robot_type', value='NIRYO_ONE'),
        SetParameter(name='/niryo_one/info/image_version', value='2.3.1'),

        # niryo_one/robot_state
        SetParameter(name='/niryo_one/robot_state/rate_tf_listener',
                     value=5.0),
        SetParameter(name='/niryo_one/robot_state/rate_publish_state',
                     value=5.0),

        # Load URDF
        DeclareLaunchArgument(
            'robot_description_v1_without_meshes_path',
            default_value=robot_description_v1_without_meshes_path,
            description='Path to the v1 robot description without meshes'),
        DeclareLaunchArgument(
            'robot_description_v1_path',
            default_value=robot_description_v1_path,
            description='Path to the v1 robot description'),
        DeclareLaunchArgument(
            'robot_description_v2_without_meshes_path',
            default_value=robot_description_v2_without_meshes_path,
            description='Path to the v2 robot description without meshes'),
        DeclareLaunchArgument(
            'robot_description_v2_path',
            default_value=robot_description_v2_path,
            description='Path to the v2 robot description'),
        DeclareLaunchArgument(
            'robot_description_tf2_path',
            default_value=robot_description_tf2_path,
            description='Path to the v2 robot description for tf2'),
    ])
