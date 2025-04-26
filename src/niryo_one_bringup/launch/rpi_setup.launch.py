from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Declare launch arguments
    execute_on_pi = DeclareLaunchArgument(
        'execute_on_niryo_one_raspberry_pi_image', default_value='true'
    )
    urdf_without_meshes = DeclareLaunchArgument(
        'urdf_without_meshes', default_value='true'
    )

    # Paths
    bringup_path = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'launch', 'niryo_one_base.launch.py'
    )
    rosbridge_path = os.path.join(
        get_package_share_directory('rosbridge_server'),
        'launch', 'rosbridge_websocket.launch.py'
    )
    ros_processes_config = os.path.join(
        get_package_share_directory('niryo_one_bringup'),
        'config', 'rpi_ros_processes.yaml'
    )

    # Nodes
    base_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(bringup_path),
        launch_arguments={
            'execute_on_niryo_one_raspberry_pi_image': LaunchConfiguration('execute_on_niryo_one_raspberry_pi_image'),
            'urdf_without_meshes': LaunchConfiguration('urdf_without_meshes')
        }.items()
    )

    tf2_web_republisher = Node(
        package='tf2_web_republisher',
        executable='tf2_web_republisher',
        name='tf2_web_republisher',
        output='screen'
    )

    rosbridge_websocket = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(rosbridge_path),
        launch_arguments={'port': '9090'}.items()
    )

    niryo_one_rpi_node = Node(
        package='niryo_one_rpi',
        executable='niryo_one_rpi_node.py',
        name='niryo_one_rpi',
        output='screen',
        parameters=[
            {'launch_ros_processes': True},
            {'process_state_publish_rate': 0.33},
            {'wifi_manager_enabled': True},
            {'hotspot_ssid': 'Niryo_One'},
            {'hotspot_password': 'niryoone'},
            {'filename_robot_name': '/home/niryo/niryo_one_saved_values/robot_name_for_user.txt'},
            ros_processes_config,
            {'publish_io_state_frequency': 10.0},
            {'modbus_server_enabled': True},
            {'modbus_server_address': '0.0.0.0'},
            {'modbus_server_port': 5020},
            {'ros_log_size_treshold': 1024},
            {'should_purge_ros_log_on_startup_file': '/home/niryo/niryo_one_saved_values/purge_ros_log_at_startup.txt'},
            {'ros_log_location': '/home/niryo/.ros/log'}
        ]
    )

    return LaunchDescription([
        execute_on_pi,
        urdf_without_meshes,
        base_launch,
       # tf2_web_republisher,
        rosbridge_websocket,
        niryo_one_rpi_node
    ])
