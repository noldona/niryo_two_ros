// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/ProcessState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/process_state.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__PROCESS_STATE__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__PROCESS_STATE__STRUCT_H_

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
// Member 'is_active'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ProcessState in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__ProcessState
{
  rosidl_runtime_c__String__Sequence name;
  rosidl_runtime_c__boolean__Sequence is_active;
} niryo_one_msgs__msg__ProcessState;

// Struct for a sequence of niryo_one_msgs__msg__ProcessState.
typedef struct niryo_one_msgs__msg__ProcessState__Sequence
{
  niryo_one_msgs__msg__ProcessState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__ProcessState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__PROCESS_STATE__STRUCT_H_
