// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from niryo_one_msgs:msg/ConveyorFeedback.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/conveyor_feedback__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "niryo_one_msgs/msg/detail/conveyor_feedback__struct.h"
#include "niryo_one_msgs/msg/detail/conveyor_feedback__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ConveyorFeedback__ros_msg_type = niryo_one_msgs__msg__ConveyorFeedback;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_serialize_niryo_one_msgs__msg__ConveyorFeedback(
  const niryo_one_msgs__msg__ConveyorFeedback * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: conveyor_id
  {
    cdr << ros_message->conveyor_id;
  }

  // Field name: connection_state
  {
    cdr << (ros_message->connection_state ? true : false);
  }

  // Field name: running
  {
    cdr << (ros_message->running ? true : false);
  }

  // Field name: speed
  {
    cdr << ros_message->speed;
  }

  // Field name: direction
  {
    cdr << ros_message->direction;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_deserialize_niryo_one_msgs__msg__ConveyorFeedback(
  eprosima::fastcdr::Cdr & cdr,
  niryo_one_msgs__msg__ConveyorFeedback * ros_message)
{
  // Field name: conveyor_id
  {
    cdr >> ros_message->conveyor_id;
  }

  // Field name: connection_state
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->connection_state = tmp ? true : false;
  }

  // Field name: running
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->running = tmp ? true : false;
  }

  // Field name: speed
  {
    cdr >> ros_message->speed;
  }

  // Field name: direction
  {
    cdr >> ros_message->direction;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t get_serialized_size_niryo_one_msgs__msg__ConveyorFeedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ConveyorFeedback__ros_msg_type * ros_message = static_cast<const _ConveyorFeedback__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: conveyor_id
  {
    size_t item_size = sizeof(ros_message->conveyor_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: connection_state
  {
    size_t item_size = sizeof(ros_message->connection_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: running
  {
    size_t item_size = sizeof(ros_message->running);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed
  {
    size_t item_size = sizeof(ros_message->speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: direction
  {
    size_t item_size = sizeof(ros_message->direction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t max_serialized_size_niryo_one_msgs__msg__ConveyorFeedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: conveyor_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: connection_state
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: running
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: speed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: direction
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = niryo_one_msgs__msg__ConveyorFeedback;
    is_plain =
      (
      offsetof(DataType, direction) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_serialize_key_niryo_one_msgs__msg__ConveyorFeedback(
  const niryo_one_msgs__msg__ConveyorFeedback * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: conveyor_id
  {
    cdr << ros_message->conveyor_id;
  }

  // Field name: connection_state
  {
    cdr << (ros_message->connection_state ? true : false);
  }

  // Field name: running
  {
    cdr << (ros_message->running ? true : false);
  }

  // Field name: speed
  {
    cdr << ros_message->speed;
  }

  // Field name: direction
  {
    cdr << ros_message->direction;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t get_serialized_size_key_niryo_one_msgs__msg__ConveyorFeedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ConveyorFeedback__ros_msg_type * ros_message = static_cast<const _ConveyorFeedback__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: conveyor_id
  {
    size_t item_size = sizeof(ros_message->conveyor_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: connection_state
  {
    size_t item_size = sizeof(ros_message->connection_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: running
  {
    size_t item_size = sizeof(ros_message->running);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed
  {
    size_t item_size = sizeof(ros_message->speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: direction
  {
    size_t item_size = sizeof(ros_message->direction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t max_serialized_size_key_niryo_one_msgs__msg__ConveyorFeedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: conveyor_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: connection_state
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: running
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: speed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: direction
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = niryo_one_msgs__msg__ConveyorFeedback;
    is_plain =
      (
      offsetof(DataType, direction) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _ConveyorFeedback__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const niryo_one_msgs__msg__ConveyorFeedback * ros_message = static_cast<const niryo_one_msgs__msg__ConveyorFeedback *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_niryo_one_msgs__msg__ConveyorFeedback(ros_message, cdr);
}

static bool _ConveyorFeedback__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  niryo_one_msgs__msg__ConveyorFeedback * ros_message = static_cast<niryo_one_msgs__msg__ConveyorFeedback *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_niryo_one_msgs__msg__ConveyorFeedback(cdr, ros_message);
}

static uint32_t _ConveyorFeedback__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_niryo_one_msgs__msg__ConveyorFeedback(
      untyped_ros_message, 0));
}

static size_t _ConveyorFeedback__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_niryo_one_msgs__msg__ConveyorFeedback(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ConveyorFeedback = {
  "niryo_one_msgs::msg",
  "ConveyorFeedback",
  _ConveyorFeedback__cdr_serialize,
  _ConveyorFeedback__cdr_deserialize,
  _ConveyorFeedback__get_serialized_size,
  _ConveyorFeedback__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ConveyorFeedback__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ConveyorFeedback,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__ConveyorFeedback__get_type_hash,
  &niryo_one_msgs__msg__ConveyorFeedback__get_type_description,
  &niryo_one_msgs__msg__ConveyorFeedback__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, msg, ConveyorFeedback)() {
  return &_ConveyorFeedback__type_support;
}

#if defined(__cplusplus)
}
#endif
