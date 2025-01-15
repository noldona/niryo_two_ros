// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/MatlabMoveResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/matlab_move_result.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__MATLAB_MOVE_RESULT__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__MATLAB_MOVE_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MatlabMoveResult in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__MatlabMoveResult
{
  int32_t status;
  rosidl_runtime_c__String message;
} niryo_one_msgs__msg__MatlabMoveResult;

// Struct for a sequence of niryo_one_msgs__msg__MatlabMoveResult.
typedef struct niryo_one_msgs__msg__MatlabMoveResult__Sequence
{
  niryo_one_msgs__msg__MatlabMoveResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__MatlabMoveResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__MATLAB_MOVE_RESULT__STRUCT_H_
