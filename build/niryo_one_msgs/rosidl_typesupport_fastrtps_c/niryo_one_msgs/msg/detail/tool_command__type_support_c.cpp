// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from niryo_one_msgs:msg/ToolCommand.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/tool_command__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "niryo_one_msgs/msg/detail/tool_command__struct.h"
#include "niryo_one_msgs/msg/detail/tool_command__functions.h"
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


using _ToolCommand__ros_msg_type = niryo_one_msgs__msg__ToolCommand;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_serialize_niryo_one_msgs__msg__ToolCommand(
  const niryo_one_msgs__msg__ToolCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: tool_id
  {
    cdr << ros_message->tool_id;
  }

  // Field name: cmd_type
  {
    cdr << ros_message->cmd_type;
  }

  // Field name: gripper_close_speed
  {
    cdr << ros_message->gripper_close_speed;
  }

  // Field name: gripper_open_speed
  {
    cdr << ros_message->gripper_open_speed;
  }

  // Field name: activate
  {
    cdr << (ros_message->activate ? true : false);
  }

  // Field name: gpio
  {
    cdr << ros_message->gpio;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_deserialize_niryo_one_msgs__msg__ToolCommand(
  eprosima::fastcdr::Cdr & cdr,
  niryo_one_msgs__msg__ToolCommand * ros_message)
{
  // Field name: tool_id
  {
    cdr >> ros_message->tool_id;
  }

  // Field name: cmd_type
  {
    cdr >> ros_message->cmd_type;
  }

  // Field name: gripper_close_speed
  {
    cdr >> ros_message->gripper_close_speed;
  }

  // Field name: gripper_open_speed
  {
    cdr >> ros_message->gripper_open_speed;
  }

  // Field name: activate
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->activate = tmp ? true : false;
  }

  // Field name: gpio
  {
    cdr >> ros_message->gpio;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t get_serialized_size_niryo_one_msgs__msg__ToolCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ToolCommand__ros_msg_type * ros_message = static_cast<const _ToolCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: tool_id
  {
    size_t item_size = sizeof(ros_message->tool_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: cmd_type
  {
    size_t item_size = sizeof(ros_message->cmd_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gripper_close_speed
  {
    size_t item_size = sizeof(ros_message->gripper_close_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gripper_open_speed
  {
    size_t item_size = sizeof(ros_message->gripper_open_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: activate
  {
    size_t item_size = sizeof(ros_message->activate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gpio
  {
    size_t item_size = sizeof(ros_message->gpio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t max_serialized_size_niryo_one_msgs__msg__ToolCommand(
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

  // Field name: tool_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: cmd_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gripper_close_speed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: gripper_open_speed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: activate
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gpio
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
    using DataType = niryo_one_msgs__msg__ToolCommand;
    is_plain =
      (
      offsetof(DataType, gpio) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_serialize_key_niryo_one_msgs__msg__ToolCommand(
  const niryo_one_msgs__msg__ToolCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: tool_id
  {
    cdr << ros_message->tool_id;
  }

  // Field name: cmd_type
  {
    cdr << ros_message->cmd_type;
  }

  // Field name: gripper_close_speed
  {
    cdr << ros_message->gripper_close_speed;
  }

  // Field name: gripper_open_speed
  {
    cdr << ros_message->gripper_open_speed;
  }

  // Field name: activate
  {
    cdr << (ros_message->activate ? true : false);
  }

  // Field name: gpio
  {
    cdr << ros_message->gpio;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t get_serialized_size_key_niryo_one_msgs__msg__ToolCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ToolCommand__ros_msg_type * ros_message = static_cast<const _ToolCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: tool_id
  {
    size_t item_size = sizeof(ros_message->tool_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: cmd_type
  {
    size_t item_size = sizeof(ros_message->cmd_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gripper_close_speed
  {
    size_t item_size = sizeof(ros_message->gripper_close_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gripper_open_speed
  {
    size_t item_size = sizeof(ros_message->gripper_open_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: activate
  {
    size_t item_size = sizeof(ros_message->activate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gpio
  {
    size_t item_size = sizeof(ros_message->gpio);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t max_serialized_size_key_niryo_one_msgs__msg__ToolCommand(
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
  // Field name: tool_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: cmd_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gripper_close_speed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: gripper_open_speed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: activate
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gpio
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
    using DataType = niryo_one_msgs__msg__ToolCommand;
    is_plain =
      (
      offsetof(DataType, gpio) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _ToolCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const niryo_one_msgs__msg__ToolCommand * ros_message = static_cast<const niryo_one_msgs__msg__ToolCommand *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_niryo_one_msgs__msg__ToolCommand(ros_message, cdr);
}

static bool _ToolCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  niryo_one_msgs__msg__ToolCommand * ros_message = static_cast<niryo_one_msgs__msg__ToolCommand *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_niryo_one_msgs__msg__ToolCommand(cdr, ros_message);
}

static uint32_t _ToolCommand__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_niryo_one_msgs__msg__ToolCommand(
      untyped_ros_message, 0));
}

static size_t _ToolCommand__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_niryo_one_msgs__msg__ToolCommand(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ToolCommand = {
  "niryo_one_msgs::msg",
  "ToolCommand",
  _ToolCommand__cdr_serialize,
  _ToolCommand__cdr_deserialize,
  _ToolCommand__get_serialized_size,
  _ToolCommand__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ToolCommand__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ToolCommand,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__ToolCommand__get_type_hash,
  &niryo_one_msgs__msg__ToolCommand__get_type_description,
  &niryo_one_msgs__msg__ToolCommand__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, msg, ToolCommand)() {
  return &_ToolCommand__type_support;
}

#if defined(__cplusplus)
}
#endif
