from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    declared_arguments = []
    declared_arguments.append(
        DeclareLaunchArgument(
            "gui",
            default_value="true",
            description="Start Rviz2 automatically with this launch file.",
        )
    )
    gui = LaunchConfiguration("gui")

    rviz_config_file = PathJoinSubstitution(
        [FindPackageShare("niryo_one_description"), "rviz", "niryo_one.rviz"]
    )

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config_file],
        condition=IfCondition(gui),
    )

    joint_state_publisher_node = Node(
        package="joint_state_publisher_gui",
        executable="joint_state_publisher_gui",
        condition=IfCondition(gui),
        remappings=[
            ('/joint_states', '/niryo_one/joint_states')
        ],
    )

    nodes = [
        rviz_node,
        joint_state_publisher_node,
    ]

    return LaunchDescription(declared_arguments + nodes)
