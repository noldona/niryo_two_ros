from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration
from launch_ros.actions import Node, SetParameter
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

    return LaunchDescription([
        DeclareLaunchArgument(
            "execute_on_niryo_one_raspberry_pi_image",
            default_value="true",
            description="Start niryo one ROS nodes.",
        ),

        DeclareLaunchArgument(
            "urdf_without_meshes",
            default_value="true",
            description="Load the URDF without meshes.",
        ),

        DeclareLaunchArgument(
            "wifi_manager_enabled",
            default_value="true",
            description="Start WiFi manager.",
        ),

        IncludeLaunchDescription(
            [
                PathJoinSubstitution(
                    [
                        FindPackageShare("niryo_one_bringup"),
                        "launch",
                        "niryo_one_base.launch.py",
                    ]
                )
            ]
        ),

        SetParameter(name="launch_ros_processes", value=True),
        SetParameter(name="process_state_publish_rate", value=0.33),



        Node(
            package="niryo_one_rpi",
            executable="wifi_conntection",
            name="wifi_conntection",
            output="screen",
            parameters=[{
                'hotspot_ssid': 'Niryo One',
                'hotspot_password': 'niryoone',
                'filename_robot_name': '/home/niryo/niryo_one_saved_values/robot_name_for_user.txt',
            }],
            condition=IfCondition(LaunchConfiguration("wifi_manager_enabled")),
        ),

        Node(
            package="niryo_one_rpi",
            executable="fans_manager",
            name="fans_manager",
            output="screen",
        ),

        # Node(
        #     package="niryo_one_rpi",
        #     executable="ros_logs_manager",
        #     name="ros_logs_manager",
        #     output="screen",
        #     parameters=[{
        #         'ros_log_size_threshold': 1024,
        #         'should_purge_ros_log_on_startup_file': '/home_niryo/niryo_one_saved_values/purge_ros_logs_at_startup.txt',
        #         'ros_log_location': '/home/niryo/.ros/log',
        #     }],
        # ),

        Node(
            package="niryo_one_rpi",
            executable="shutdown_manager",
            name="shutdown_manager",
            output="screen",
        ),

        Node(
            package="niryo_one_rpi",
            executable="led_manager",
            name="led_manager",
            output="screen",
        ),

        Node(
            package="niryo_one_rpi",
            executable="niryo_one_button",
            name="niryo_one_button",
            output="screen",
        ),

        Node(
            package="niryo_one_rpi",
            executable="digital_io_panel",
            name="digital_io_panel",
            output="screen",
            parameters=[{
                'publish_io_state_frequency': 10.0,
            }],
        ),

        Node(
            package="niryo_one_rpi",
            executable="motor_debug",
            name="motor_debug",
            output="screen",
        ),
    ])
