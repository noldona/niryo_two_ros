// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/SequenceAutorunStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/sequence_autorun_status.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE_AUTORUN_STATUS__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE_AUTORUN_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'sequence_ids'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/SequenceAutorunStatus in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__SequenceAutorunStatus
{
  bool enabled;
  int32_t mode;
  rosidl_runtime_c__int32__Sequence sequence_ids;
} niryo_one_msgs__msg__SequenceAutorunStatus;

// Struct for a sequence of niryo_one_msgs__msg__SequenceAutorunStatus.
typedef struct niryo_one_msgs__msg__SequenceAutorunStatus__Sequence
{
  niryo_one_msgs__msg__SequenceAutorunStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__SequenceAutorunStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE_AUTORUN_STATUS__STRUCT_H_
