// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/robot_state.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'rpy'
#include "niryo_one_msgs/msg/detail/rpy__struct.h"

/// Struct defined in msg/RobotState in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__RobotState
{
  geometry_msgs__msg__Point position;
  niryo_one_msgs__msg__RPY rpy;
} niryo_one_msgs__msg__RobotState;

// Struct for a sequence of niryo_one_msgs__msg__RobotState.
typedef struct niryo_one_msgs__msg__RobotState__Sequence
{
  niryo_one_msgs__msg__RobotState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__RobotState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
