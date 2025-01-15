// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/ConveyorFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/conveyor_feedback.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/ConveyorFeedback in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__ConveyorFeedback
{
  /// Conveyor ID (either 6 or 7)
  uint8_t conveyor_id;
  /// Conveyor connection state (if it is enbled)
  bool connection_state;
  /// Conveyor controls state: ON or OFF
  bool running;
  /// Conveyor speed (1 -> 100%)
  int16_t speed;
  /// Conveyor direction (backwards or forward)
  int8_t direction;
} niryo_one_msgs__msg__ConveyorFeedback;

// Struct for a sequence of niryo_one_msgs__msg__ConveyorFeedback.
typedef struct niryo_one_msgs__msg__ConveyorFeedback__Sequence
{
  niryo_one_msgs__msg__ConveyorFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__ConveyorFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__STRUCT_H_
