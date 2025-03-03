from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    # Set to true if you want to launch ROS on your computer
    # - controller will just echo position command
    # - all hardware relative stuff is deactivated - ->
    simulation_mode = LaunchConfiguration('simulation_mode')

    # Set to true to disable hardware communication for CAN bus(Niryo Steppers)
    # or DXL bus(DEBUG PURPOSES) - ->
    disable_can_for_debug = LaunchConfiguration('disable_can_for_debug')
    disable_dxl_for_debug = LaunchConfiguration('disable_dxl_for_debug')

    hardware_version = LaunchConfiguration('hardware_version')

    niryo_one_driver_config = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'config',
        'niryo_one_driver.yaml'
    )

    niryo_one_motors_config = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'config',
        'niryo_one_motors.yaml'
    )

    niryo_one_stepper_config = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'config',
        'stepper_params.yaml'
    )

    return LaunchDescription([
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

        DeclareLaunchArgument(
            'hardware_version',
            default_value='2',
            description='Set hardware version'),

        Node(
            package='niryo_one_driver',
            executable='niryo_one_driver',
            name='niryo_one_driver',
            output='screen',
            parameters=[
                niryo_one_driver_config,
                niryo_one_motors_config,
                niryo_one_stepper_config,
                {
                    'fake_communication': simulation_mode,
                    'can_enabled': LaunchConfiguration(
                        'disable_can_for_debug') == 'false',
                    'dxl_enabled': LaunchConfiguration(
                        'disable_can_for_debug') == 'false',
                },
            ],
        ),
    ])


#     <arg name="hardware_version" default="2" />
#     <arg name="urdf_without_meshes" default="true" />
#     <arg name="niryo_one_sim_mode" default="false" />
#     <arg name="execute_on_niryo_one_raspberry_pi_image" default="true" />

#     <!-- PARAMS -->
#     <group ns="niryo_one">
#         <param name="hardware_version" type="int" value="$(arg hardware_version)" />
#         <param name="reboot_when_auto_change_version" type="bool" value="true" />
#     </group>

# <launch >

#     <!-- set to true if you want to launch ROS on your computer
#         - controller will just echo position command
#         - all hardware relative stuff is deactivated - ->
#     <arg name = "simulation_mode" default = "false" / >
#     <!-- set to true to disable hardware communication for CAN bus(Niryo Steppers)
#      or DXl bus(DEBUG PURPOSES) - ->
#     <arg name = "disable_can_for_debug" default = "false" / >
#     <arg name = "disable_dxl_for_debug" default = "false" / >

#     <node name = "niryo_one_driver" pkg = "niryo_one_driver" type = "niryo_one_driver" output = "screen" >

#         <rosparam file = "$(find niryo_one_bringup)/config/niryo_one_driver.yaml" / >

#         <param name = "fake_communication" type = "bool" value = "$(arg simulation_mode)" / >

#         <param name = "can_enabled" type = "bool" value = "true"  unless = "$(arg disable_can_for_debug)" / >
#         <param name = "can_enabled" type = "bool" value = "false" if = "$(arg disable_can_for_debug)" / >
#         <param name = "dxl_enabled" type = "bool" value = "true"  unless = "$(arg disable_dxl_for_debug)" / >
#         <param name = "dxl_enabled" type = "bool" value = "false" if = "$(arg disable_dxl_for_debug)" / >
#     </node >

#     <node name = "niryo_one_tools" pkg = "niryo_one_tools" type = "tool_controller.py" output = "screen" respawn = "false" >
#         <rosparam file = "$(find niryo_one_tools)/config/end_effectors.yaml" / >
#     </node >

#     <!-- Load controller settings - ->
#     <rosparam file = "$(find niryo_one_driver)/config/niryo_one_controllers.yaml" command = "load"/>

#     <!-- spawn controllers - ->
#     <node name = "controller_spawner" pkg = "controller_manager" type = "spawner" respawn = "false" output = "screen"
#         args ="joint_state_controller niryo_one_follow_joint_trajectory_controller
#         --shutdown-timeout 1"/>

#     <!-- robot state publisher -->
#     <node name="robot_state_publisher" pkg="robot_state_publisher" type="robot_state_publisher" output="screen" />
# </launch>
