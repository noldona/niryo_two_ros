// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/trajectory.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'description'
#include "rosidl_runtime_c/string.h"
// Member 'trajectory_plan'
#include "niryo_one_msgs/msg/detail/trajectory_plan__struct.h"

/// Struct defined in msg/Trajectory in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__Trajectory
{
  int32_t id;
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String description;
  niryo_one_msgs__msg__TrajectoryPlan trajectory_plan;
} niryo_one_msgs__msg__Trajectory;

// Struct for a sequence of niryo_one_msgs__msg__Trajectory.
typedef struct niryo_one_msgs__msg__Trajectory__Sequence
{
  niryo_one_msgs__msg__Trajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__Trajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_H_
