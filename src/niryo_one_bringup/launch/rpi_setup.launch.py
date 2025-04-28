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

        IncludeLaunchDescription(
            [
                PathJoinSubstitution(
                    [
                        FindPackageShare("niryo_one_bringup"),
                        "launch",
                        "niryo_one_rpi.launch.py",
                    ]
                )
            ]
        ),

        IncludeLaunchDescription(
            [
                PathJoinSubstitution(
                    [
                        FindPackageShare("niryo_one_hardware"),
                        "launch",
                        "niryo_one_controller.launch.py",
                    ]
                )
            ]
        ),
    ])
