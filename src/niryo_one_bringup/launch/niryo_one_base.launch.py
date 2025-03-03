from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    # Load the URDF, SRDF and other .yaml configuration files

    hardware_version = LaunchConfiguration('hardware_version')
    urdf_without_meshes = LaunchConfiguration('urdf_without_meshes')
    niryo_one_sim_mode = LaunchConfiguration('niryo_one_sim_mode')
    execute_on_niryo_one_raspberry_pi_image = LaunchConfiguration(
        'execute_on_niryo_one_raspberry_pi_image')

    niryo_one_driver_config = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'config',
        'niryo_one_driver.yaml'
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            'hardware_version',
            default_value='2',
            description='Set to 1 or 2 depending on your hardware version'),
        DeclareLaunchArgument(
            'urdf_without_meshes',
            default_value='true',
            description='Set to true if you want to launch ROS on your computer'),
        DeclareLaunchArgument(
            'niryo_one_sim_mode',
            default_value='false',
            description='Set to true if you want to launch ROS on your computer'),
        DeclareLaunchArgument(
            'execute_on_niryo_one_raspberry_pi_image',
            default_value='true',
            description='Set to true if you want to launch ROS on your computer'),

        Node(
            package='niryo_one_driver',
            executable='niryo_one_driver',
            name='niryo_one_driver',
            namespace='niryo_one',
            output='screen',
            parameters=[
                niryo_one_driver_config,
                {'fake_communication': simulation_mode},
                {'can_enabled': [LaunchConfiguration(
                    'disable_can_for_debug') == 'false']},
                {'dxl_enabled': [LaunchConfiguration(
                    'disable_can_for_debug') == 'false']},
            ],
        ),
    ])


# <launch>
#     <!-- Load the URDF, SRDF and other .yaml configuration files on the param server -->

#     <arg name="hardware_version" default="2" />
#     <arg name="urdf_without_meshes" default="true" />
#     <arg name="niryo_one_sim_mode" default="false" />
#     <arg name="execute_on_niryo_one_raspberry_pi_image" default="true" />

#     <!-- PARAMS -->
#     <group ns="niryo_one">
#         <param name="hardware_version" type="int" value="$(arg hardware_version)" />
#         <param name="reboot_when_auto_change_version" type="bool" value="true" />
#     </group>

#     <group ns="niryo_one/robot_command_validation">
#         <rosparam file="$(find niryo_one_bringup)/config/v1/robot_command_validation.yaml" if="$(eval hardware_version == 1)" />
#         <rosparam file="$(find niryo_one_bringup)/config/v2/robot_command_validation.yaml" if="$(eval hardware_version == 2)" />
#     </group>

#     <group ns="niryo_one/motors">
#         <rosparam file="$(find niryo_one_bringup)/config/v1/niryo_one_motors.yaml" if="$(eval hardware_version == 1)"/>
#         <rosparam file="$(find niryo_one_bringup)/config/v2/niryo_one_motors.yaml" if="$(eval hardware_version == 2)"/>
#         <rosparam file="$(find niryo_one_bringup)/config/v1/stepper_params.yaml" if="$(eval hardware_version == 1)"/>
#         <rosparam file="$(find niryo_one_bringup)/config/v2/stepper_params.yaml" if="$(eval hardware_version == 2)"/>
#     </group>

#     <group ns="niryo_one/python_api">
#         <param name="service_timeout" type="int" value="2" />
#         <param name="action_connection_timeout" type="int" value="2" />
#         <param name="action_execute_timeout" type="int" value="15" />
#         <param name="action_preempt_timeout" type="int" value="3" />
#     </group>

#     <group ns="niryo_one/info">
#         <param name="ros_version"               type="string" command="rosversion niryo_one_bringup" />
#         <param name="niryo_one_one_robot_type"  type="string" value="NIRYO_ONE" />
#         <param name="image_version"             type="string" if="$(arg execute_on_niryo_one_raspberry_pi_image)"
#             textfile="/home/niryo/niryo_one_saved_values/niryo_one_image_version_do_not_edit.txt" />
#     </group>

#     <group ns="niryo_one/robot_state">
#         <param name="rate_tf_listener" type="double" value="5.0" />
#         <param name="rate_publish_state" type="double" value="5.0" />
#     </group>

#     <!-- load URDF -->
#     <!-- on Raspberry Pi 3 (ARM architecture) we get a segfault when using visual and collision stuff -->
#     <param name="urdf_without_meshes" value="$(arg urdf_without_meshes)" />
#     <group if="$(eval hardware_version == 1)">
#         <param name="robot_description" command="$(find xacro)/xacro --inorder $(find niryo_one_description)/urdf/v1/without_mesh_niryo_one.urdf.xacro" if="$(arg urdf_without_meshes)"/>
#         <param name="robot_description" command="$(find xacro)/xacro --inorder $(find niryo_one_description)/urdf/v1/niryo_one.urdf.xacro" unless="$(arg urdf_without_meshes)"/>
#         <param name="robot_description_tf2" command="$(find xacro)/xacro --inorder $(find niryo_one_description)/urdf/v2/niryo_one.urdf.xacro" />
#     </group>
#     <group if="$(eval hardware_version == 2)">
#         <param name="robot_description" command="$(find xacro)/xacro --inorder $(find niryo_one_description)/urdf/v2/without_mesh_niryo_one.urdf.xacro" if="$(arg urdf_without_meshes)"/>
#         <param name="robot_description" command="$(find xacro)/xacro --inorder $(find niryo_one_description)/urdf/v2/niryo_one.urdf.xacro" unless="$(arg urdf_without_meshes)"/>
#         <param name="robot_description_tf2" command="$(find xacro)/xacro --inorder $(find niryo_one_description)/urdf/v2/niryo_one.urdf.xacro" />
#     </group>
# </launch>
