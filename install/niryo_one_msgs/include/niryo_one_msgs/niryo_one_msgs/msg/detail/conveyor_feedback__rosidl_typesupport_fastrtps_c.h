// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from niryo_one_msgs:msg/ConveyorFeedback.idl
// generated code does not contain a copyright notice
#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "niryo_one_msgs/msg/detail/conveyor_feedback__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_serialize_niryo_one_msgs__msg__ConveyorFeedback(
  const niryo_one_msgs__msg__ConveyorFeedback * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_deserialize_niryo_one_msgs__msg__ConveyorFeedback(
  eprosima::fastcdr::Cdr &,
  niryo_one_msgs__msg__ConveyorFeedback * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t get_serialized_size_niryo_one_msgs__msg__ConveyorFeedback(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t max_serialized_size_niryo_one_msgs__msg__ConveyorFeedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_serialize_key_niryo_one_msgs__msg__ConveyorFeedback(
  const niryo_one_msgs__msg__ConveyorFeedback * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t get_serialized_size_key_niryo_one_msgs__msg__ConveyorFeedback(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t max_serialized_size_key_niryo_one_msgs__msg__ConveyorFeedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, msg, ConveyorFeedback)();

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
