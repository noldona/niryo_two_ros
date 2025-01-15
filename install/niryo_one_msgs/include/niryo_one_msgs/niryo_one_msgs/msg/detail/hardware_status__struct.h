// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/HardwareStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/hardware_status.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__HARDWARE_STATUS__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__HARDWARE_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'error_message'
// Member 'motor_names'
// Member 'motor_types'
#include "rosidl_runtime_c/string.h"
// Member 'temperatures'
// Member 'voltages'
// Member 'hardware_errors'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/HardwareStatus in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__HardwareStatus
{
  std_msgs__msg__Header header;
  /// Raspberry Pi board
  int32_t rpi_temperature;
  /// Robot version : 1 (previous one) or 2 (current one)
  int32_t hardware_version;
  /// Motors
  bool connection_up;
  rosidl_runtime_c__String error_message;
  int32_t calibration_needed;
  bool calibration_in_progress;
  rosidl_runtime_c__String__Sequence motor_names;
  rosidl_runtime_c__String__Sequence motor_types;
  rosidl_runtime_c__int32__Sequence temperatures;
  rosidl_runtime_c__double__Sequence voltages;
  rosidl_runtime_c__int32__Sequence hardware_errors;
} niryo_one_msgs__msg__HardwareStatus;

// Struct for a sequence of niryo_one_msgs__msg__HardwareStatus.
typedef struct niryo_one_msgs__msg__HardwareStatus__Sequence
{
  niryo_one_msgs__msg__HardwareStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__HardwareStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__HARDWARE_STATUS__STRUCT_H_
