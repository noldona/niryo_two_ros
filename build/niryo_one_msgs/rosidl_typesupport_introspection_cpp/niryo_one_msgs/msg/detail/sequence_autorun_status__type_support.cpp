// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from niryo_one_msgs:msg/SequenceAutorunStatus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "niryo_one_msgs/msg/detail/sequence_autorun_status__functions.h"
#include "niryo_one_msgs/msg/detail/sequence_autorun_status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace niryo_one_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SequenceAutorunStatus_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) niryo_one_msgs::msg::SequenceAutorunStatus(_init);
}

void SequenceAutorunStatus_fini_function(void * message_memory)
{
  auto typed_message = static_cast<niryo_one_msgs::msg::SequenceAutorunStatus *>(message_memory);
  typed_message->~SequenceAutorunStatus();
}

size_t size_function__SequenceAutorunStatus__sequence_ids(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SequenceAutorunStatus__sequence_ids(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__SequenceAutorunStatus__sequence_ids(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__SequenceAutorunStatus__sequence_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__SequenceAutorunStatus__sequence_ids(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__SequenceAutorunStatus__sequence_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__SequenceAutorunStatus__sequence_ids(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__SequenceAutorunStatus__sequence_ids(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SequenceAutorunStatus_message_member_array[3] = {
  {
    "enabled",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::SequenceAutorunStatus, enabled),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::SequenceAutorunStatus, mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "sequence_ids",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::SequenceAutorunStatus, sequence_ids),  // bytes offset in struct
    nullptr,  // default value
    size_function__SequenceAutorunStatus__sequence_ids,  // size() function pointer
    get_const_function__SequenceAutorunStatus__sequence_ids,  // get_const(index) function pointer
    get_function__SequenceAutorunStatus__sequence_ids,  // get(index) function pointer
    fetch_function__SequenceAutorunStatus__sequence_ids,  // fetch(index, &value) function pointer
    assign_function__SequenceAutorunStatus__sequence_ids,  // assign(index, value) function pointer
    resize_function__SequenceAutorunStatus__sequence_ids  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SequenceAutorunStatus_message_members = {
  "niryo_one_msgs::msg",  // message namespace
  "SequenceAutorunStatus",  // message name
  3,  // number of fields
  sizeof(niryo_one_msgs::msg::SequenceAutorunStatus),
  false,  // has_any_key_member_
  SequenceAutorunStatus_message_member_array,  // message members
  SequenceAutorunStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  SequenceAutorunStatus_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SequenceAutorunStatus_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SequenceAutorunStatus_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__SequenceAutorunStatus__get_type_hash,
  &niryo_one_msgs__msg__SequenceAutorunStatus__get_type_description,
  &niryo_one_msgs__msg__SequenceAutorunStatus__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace niryo_one_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<niryo_one_msgs::msg::SequenceAutorunStatus>()
{
  return &::niryo_one_msgs::msg::rosidl_typesupport_introspection_cpp::SequenceAutorunStatus_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, niryo_one_msgs, msg, SequenceAutorunStatus)() {
  return &::niryo_one_msgs::msg::rosidl_typesupport_introspection_cpp::SequenceAutorunStatus_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
