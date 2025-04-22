from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    fix_node = Node(
        package="niryo_one_hardware",
        executable="fix",
        name="fix",
    )

    nodes_to_start = [fix_node]

    return LaunchDescription(nodes_to_start)
