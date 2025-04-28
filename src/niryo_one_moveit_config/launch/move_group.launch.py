from moveit_configs_utils import MoveItConfigsBuilder
from moveit_configs_utils.launches import generate_move_group_launch

def generate_launch_description():
    moveit_config = (
        MoveItConfigsBuilder("niryo_one", package_name="niryo_one_moveit_config")
        .to_moveit_configs()
    )

    # Inject custom planning parameters
    moveit_config.planning_scene_monitor = {
        "trajectory_execution.execution_duration_monitoring": False,
        "trajectory_execution.allowed_start_tolerance": 0.0,
        "start_state_max_bounds_error": 0.3,
    }

    return generate_move_group_launch(moveit_config)
