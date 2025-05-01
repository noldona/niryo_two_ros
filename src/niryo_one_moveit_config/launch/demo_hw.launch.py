import os

from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

# import MoveIt’s helpers
from moveit_configs_utils import MoveItConfigsBuilder
from moveit_configs_utils.launches import generate_demo_launch

def generate_launch_description():
    # build the standard MoveIt demo
    moveit_config = MoveItConfigsBuilder(
        "niryo_one",
        package_name="niryo_one_moveit_config"
    ).to_moveit_configs()
    demo_ld = generate_demo_launch(moveit_config)

    # path to your hardware-specific controller params
    hw_yaml = os.path.join(
        get_package_share_directory("niryo_one_hardware"),
        "bringup", "config", "niryo_one_controller.yaml"
    )

    # find the ros2_control_node action and append our YAML
    for entity in demo_ld.entities:
        if (
            isinstance(entity, Node)
            and entity.package == "controller_manager"
            and entity.executable == "ros2_control_node"
        ):
            # Node.parameters is a list; just append your file
            entity.parameters.append(hw_yaml)
            break

    return demo_ld
