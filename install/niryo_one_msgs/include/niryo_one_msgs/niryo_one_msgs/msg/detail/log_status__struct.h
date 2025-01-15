// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/LogStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/log_status.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__LOG_STATUS__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__LOG_STATUS__STRUCT_H_

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

/// Struct defined in msg/LogStatus in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__LogStatus
{
  std_msgs__msg__Header header;
  /// in MB
  int32_t log_size;
  int32_t available_disk_size;
  bool purge_log_on_startup;
} niryo_one_msgs__msg__LogStatus;

// Struct for a sequence of niryo_one_msgs__msg__LogStatus.
typedef struct niryo_one_msgs__msg__LogStatus__Sequence
{
  niryo_one_msgs__msg__LogStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__LogStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__LOG_STATUS__STRUCT_H_
