// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/SoftwareVersion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/software_version.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SOFTWARE_VERSION__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SOFTWARE_VERSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'rpi_image_version'
// Member 'ros_niryo_one_version'
// Member 'motor_names'
// Member 'stepper_firmware_versions'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SoftwareVersion in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__SoftwareVersion
{
  rosidl_runtime_c__String rpi_image_version;
  rosidl_runtime_c__String ros_niryo_one_version;
  rosidl_runtime_c__String__Sequence motor_names;
  rosidl_runtime_c__String__Sequence stepper_firmware_versions;
} niryo_one_msgs__msg__SoftwareVersion;

// Struct for a sequence of niryo_one_msgs__msg__SoftwareVersion.
typedef struct niryo_one_msgs__msg__SoftwareVersion__Sequence
{
  niryo_one_msgs__msg__SoftwareVersion * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__SoftwareVersion__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SOFTWARE_VERSION__STRUCT_H_
