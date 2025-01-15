// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/TrajectoryPlan.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/trajectory_plan.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY_PLAN__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY_PLAN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'trajectory_start'
#include "moveit_msgs/msg/detail/robot_state__struct.h"
// Member 'group_name'
#include "rosidl_runtime_c/string.h"
// Member 'trajectory'
#include "moveit_msgs/msg/detail/robot_trajectory__struct.h"

/// Struct defined in msg/TrajectoryPlan in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__TrajectoryPlan
{
  moveit_msgs__msg__RobotState trajectory_start;
  rosidl_runtime_c__String group_name;
  moveit_msgs__msg__RobotTrajectory trajectory;
} niryo_one_msgs__msg__TrajectoryPlan;

// Struct for a sequence of niryo_one_msgs__msg__TrajectoryPlan.
typedef struct niryo_one_msgs__msg__TrajectoryPlan__Sequence
{
  niryo_one_msgs__msg__TrajectoryPlan * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__TrajectoryPlan__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY_PLAN__STRUCT_H_
