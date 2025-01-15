// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/Position.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/position.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__POSITION__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__POSITION__STRUCT_H_

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
#include "rosidl_runtime_c/string.h"
// Member 'joints'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'rpy'
#include "niryo_one_msgs/msg/detail/rpy__struct.h"
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__struct.h"

/// Struct defined in msg/Position in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__Position
{
  rosidl_runtime_c__String name;
  rosidl_runtime_c__double__Sequence joints;
  niryo_one_msgs__msg__RPY rpy;
  geometry_msgs__msg__Point point;
  geometry_msgs__msg__Quaternion quaternion;
} niryo_one_msgs__msg__Position;

// Struct for a sequence of niryo_one_msgs__msg__Position.
typedef struct niryo_one_msgs__msg__Position__Sequence
{
  niryo_one_msgs__msg__Position * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__Position__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__POSITION__STRUCT_H_
