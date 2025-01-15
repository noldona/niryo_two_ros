// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/ShiftPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/shift_pose.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SHIFT_POSE__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SHIFT_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/ShiftPose in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__ShiftPose
{
  int32_t axis_number;
  double value;
} niryo_one_msgs__msg__ShiftPose;

// Struct for a sequence of niryo_one_msgs__msg__ShiftPose.
typedef struct niryo_one_msgs__msg__ShiftPose__Sequence
{
  niryo_one_msgs__msg__ShiftPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__ShiftPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SHIFT_POSE__STRUCT_H_
