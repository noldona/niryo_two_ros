// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/DigitalIOState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/digital_io_state.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__DIGITAL_IO_STATE__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__DIGITAL_IO_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'pins'
// Member 'modes'
// Member 'states'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'names'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DigitalIOState in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__DigitalIOState
{
  /// GPIO pin
  rosidl_runtime_c__int32__Sequence pins;
  /// PIN names seen by user to make it simpler
  rosidl_runtime_c__String__Sequence names;
  /// IN/OUT
  rosidl_runtime_c__int32__Sequence modes;
  /// HIGH/LOW
  rosidl_runtime_c__int32__Sequence states;
} niryo_one_msgs__msg__DigitalIOState;

// Struct for a sequence of niryo_one_msgs__msg__DigitalIOState.
typedef struct niryo_one_msgs__msg__DigitalIOState__Sequence
{
  niryo_one_msgs__msg__DigitalIOState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__DigitalIOState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__DIGITAL_IO_STATE__STRUCT_H_
