// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/RobotMoveCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/robot_move_command.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_MOVE_COMMAND__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_MOVE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'joints'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'rpy'
#include "niryo_one_msgs/msg/detail/rpy__struct.h"
// Member 'shift'
#include "niryo_one_msgs/msg/detail/shift_pose__struct.h"
// Member 'trajectory'
#include "niryo_one_msgs/msg/detail/trajectory_plan__struct.h"
// Member 'pose_quat'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'saved_position_name'
#include "rosidl_runtime_c/string.h"
// Member 'tool_cmd'
#include "niryo_one_msgs/msg/detail/tool_command__struct.h"

/// Struct defined in msg/RobotMoveCommand in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__RobotMoveCommand
{
  int32_t cmd_type;
  rosidl_runtime_c__double__Sequence joints;
  geometry_msgs__msg__Point position;
  niryo_one_msgs__msg__RPY rpy;
  niryo_one_msgs__msg__ShiftPose shift;
  niryo_one_msgs__msg__TrajectoryPlan trajectory;
  geometry_msgs__msg__Pose pose_quat;
  rosidl_runtime_c__String saved_position_name;
  int32_t saved_trajectory_id;
  niryo_one_msgs__msg__ToolCommand tool_cmd;
} niryo_one_msgs__msg__RobotMoveCommand;

// Struct for a sequence of niryo_one_msgs__msg__RobotMoveCommand.
typedef struct niryo_one_msgs__msg__RobotMoveCommand__Sequence
{
  niryo_one_msgs__msg__RobotMoveCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__RobotMoveCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_MOVE_COMMAND__STRUCT_H_
