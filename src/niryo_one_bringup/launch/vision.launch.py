from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Resolve package paths
    grip_dir_path = os.path.join(
        get_package_share_directory('niryo_one_pose_converter'),
        'grips'
    )
    rosparam_file = os.path.join(
        get_package_share_directory('niryo_one_camera'),
        'config', 'video_server_setup.yaml'
    )

    # Pose converter node
    pose_converter_node = Node(
        package='niryo_one_pose_converter',
        executable='pose_converter.py',
        name='niryo_one_pose_converter',
        output='screen',
        parameters=[
            {'workspace_dir': '~/niryo_one_workspaces/'},
            {'grip_dir': grip_dir_path}
        ]
    )

    # Vision (camera) node
    vision_node = Node(
        package='niryo_one_camera',
        executable='camera_publisher_and_services.py',
        name='niryo_one_vision',
        output='screen',
        parameters=[rosparam_file]
    )

    return LaunchDescription([
        pose_converter_node,
        vision_node
    ])
