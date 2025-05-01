import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    demo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory('niryo_one_moveit_config'),
                'launch','demo.launch.py'
            )
        )
    )
    # Now override/add parameters on the controller_manager Node:
    demo.launch_arguments.update({
        'ros2_control_node__parameters':
          [ os.path.join(
              get_package_share_directory('niryo_one_moveit_config'),
              'config','ros2_controllers.yaml'
            ),
            os.path.join(
              get_package_share_directory('niryo_one_hardware'),
              'bringup/config/niryo_one_controller.yaml'
            )
          ]
    })
    return LaunchDescription([demo])
