// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:msg/Sequence.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/sequence.h"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE__STRUCT_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE__STRUCT_H_

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
// Member 'description'
// Member 'blockly_xml'
// Member 'python_code'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Sequence in the package niryo_one_msgs.
typedef struct niryo_one_msgs__msg__Sequence
{
  int32_t id;
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String description;
  int32_t created;
  int32_t updated;
  rosidl_runtime_c__String blockly_xml;
  rosidl_runtime_c__String python_code;
} niryo_one_msgs__msg__Sequence;

// Struct for a sequence of niryo_one_msgs__msg__Sequence.
typedef struct niryo_one_msgs__msg__Sequence__Sequence
{
  niryo_one_msgs__msg__Sequence * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__msg__Sequence__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE__STRUCT_H_
