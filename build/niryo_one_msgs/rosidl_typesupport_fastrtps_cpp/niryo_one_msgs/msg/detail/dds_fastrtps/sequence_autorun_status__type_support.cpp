// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from niryo_one_msgs:msg/SequenceAutorunStatus.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/sequence_autorun_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "niryo_one_msgs/msg/detail/sequence_autorun_status__functions.h"
#include "niryo_one_msgs/msg/detail/sequence_autorun_status__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace niryo_one_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_niryo_one_msgs
cdr_serialize(
  const niryo_one_msgs::msg::SequenceAutorunStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: enabled
  cdr << (ros_message.enabled ? true : false);

  // Member: mode
  cdr << ros_message.mode;

  // Member: sequence_ids
  {
    cdr << ros_message.sequence_ids;
  }

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_niryo_one_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  niryo_one_msgs::msg::SequenceAutorunStatus & ros_message)
{
  // Member: enabled
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.enabled = tmp ? true : false;
  }

  // Member: mode
  cdr >> ros_message.mode;

  // Member: sequence_ids
  {
    cdr >> ros_message.sequence_ids;
  }

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_niryo_one_msgs
get_serialized_size(
  const niryo_one_msgs::msg::SequenceAutorunStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: enabled
  {
    size_t item_size = sizeof(ros_message.enabled);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mode
  {
    size_t item_size = sizeof(ros_message.mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: sequence_ids
  {
    size_t array_size = ros_message.sequence_ids.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.sequence_ids[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_niryo_one_msgs
max_serialized_size_SequenceAutorunStatus(
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

  // Member: enabled
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: sequence_ids
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = niryo_one_msgs::msg::SequenceAutorunStatus;
    is_plain =
      (
      offsetof(DataType, sequence_ids) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_niryo_one_msgs
cdr_serialize_key(
  const niryo_one_msgs::msg::SequenceAutorunStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: enabled
  cdr << (ros_message.enabled ? true : false);

  // Member: mode
  cdr << ros_message.mode;

  // Member: sequence_ids
  {
    cdr << ros_message.sequence_ids;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_niryo_one_msgs
get_serialized_size_key(
  const niryo_one_msgs::msg::SequenceAutorunStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: enabled
  {
    size_t item_size = sizeof(ros_message.enabled);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mode
  {
    size_t item_size = sizeof(ros_message.mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: sequence_ids
  {
    size_t array_size = ros_message.sequence_ids.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.sequence_ids[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_niryo_one_msgs
max_serialized_size_key_SequenceAutorunStatus(
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

  // Member: enabled
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: sequence_ids
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = niryo_one_msgs::msg::SequenceAutorunStatus;
    is_plain =
      (
      offsetof(DataType, sequence_ids) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _SequenceAutorunStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const niryo_one_msgs::msg::SequenceAutorunStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SequenceAutorunStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<niryo_one_msgs::msg::SequenceAutorunStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SequenceAutorunStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const niryo_one_msgs::msg::SequenceAutorunStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SequenceAutorunStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SequenceAutorunStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SequenceAutorunStatus__callbacks = {
  "niryo_one_msgs::msg",
  "SequenceAutorunStatus",
  _SequenceAutorunStatus__cdr_serialize,
  _SequenceAutorunStatus__cdr_deserialize,
  _SequenceAutorunStatus__get_serialized_size,
  _SequenceAutorunStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SequenceAutorunStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SequenceAutorunStatus__callbacks,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__SequenceAutorunStatus__get_type_hash,
  &niryo_one_msgs__msg__SequenceAutorunStatus__get_type_description,
  &niryo_one_msgs__msg__SequenceAutorunStatus__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace niryo_one_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_niryo_one_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<niryo_one_msgs::msg::SequenceAutorunStatus>()
{
  return &niryo_one_msgs::msg::typesupport_fastrtps_cpp::_SequenceAutorunStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, niryo_one_msgs, msg, SequenceAutorunStatus)() {
  return &niryo_one_msgs::msg::typesupport_fastrtps_cpp::_SequenceAutorunStatus__handle;
}

#ifdef __cplusplus
}
#endif
