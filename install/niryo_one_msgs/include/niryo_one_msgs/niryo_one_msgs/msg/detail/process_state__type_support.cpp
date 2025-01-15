// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from niryo_one_msgs:msg/ProcessState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "niryo_one_msgs/msg/detail/process_state__functions.h"
#include "niryo_one_msgs/msg/detail/process_state__struct.hpp"
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

void ProcessState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) niryo_one_msgs::msg::ProcessState(_init);
}

void ProcessState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<niryo_one_msgs::msg::ProcessState *>(message_memory);
  typed_message->~ProcessState();
}

size_t size_function__ProcessState__name(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ProcessState__name(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__ProcessState__name(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__ProcessState__name(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__ProcessState__name(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__ProcessState__name(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__ProcessState__name(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__ProcessState__name(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ProcessState__is_active(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<bool> *>(untyped_member);
  return member->size();
}

void fetch_function__ProcessState__is_active(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & member = *reinterpret_cast<const std::vector<bool> *>(untyped_member);
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = member[index];
}

void assign_function__ProcessState__is_active(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & member = *reinterpret_cast<std::vector<bool> *>(untyped_member);
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  member[index] = value;
}

void resize_function__ProcessState__is_active(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<bool> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ProcessState_message_member_array[2] = {
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::ProcessState, name),  // bytes offset in struct
    nullptr,  // default value
    size_function__ProcessState__name,  // size() function pointer
    get_const_function__ProcessState__name,  // get_const(index) function pointer
    get_function__ProcessState__name,  // get(index) function pointer
    fetch_function__ProcessState__name,  // fetch(index, &value) function pointer
    assign_function__ProcessState__name,  // assign(index, value) function pointer
    resize_function__ProcessState__name  // resize(index) function pointer
  },
  {
    "is_active",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::ProcessState, is_active),  // bytes offset in struct
    nullptr,  // default value
    size_function__ProcessState__is_active,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    fetch_function__ProcessState__is_active,  // fetch(index, &value) function pointer
    assign_function__ProcessState__is_active,  // assign(index, value) function pointer
    resize_function__ProcessState__is_active  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ProcessState_message_members = {
  "niryo_one_msgs::msg",  // message namespace
  "ProcessState",  // message name
  2,  // number of fields
  sizeof(niryo_one_msgs::msg::ProcessState),
  false,  // has_any_key_member_
  ProcessState_message_member_array,  // message members
  ProcessState_init_function,  // function to initialize message memory (memory has to be allocated)
  ProcessState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ProcessState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ProcessState_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__ProcessState__get_type_hash,
  &niryo_one_msgs__msg__ProcessState__get_type_description,
  &niryo_one_msgs__msg__ProcessState__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace niryo_one_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<niryo_one_msgs::msg::ProcessState>()
{
  return &::niryo_one_msgs::msg::rosidl_typesupport_introspection_cpp::ProcessState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, niryo_one_msgs, msg, ProcessState)() {
  return &::niryo_one_msgs::msg::rosidl_typesupport_introspection_cpp::ProcessState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
