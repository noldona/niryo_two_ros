// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from niryo_one_msgs:msg/DigitalIOState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "niryo_one_msgs/msg/detail/digital_io_state__functions.h"
#include "niryo_one_msgs/msg/detail/digital_io_state__struct.hpp"
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

void DigitalIOState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) niryo_one_msgs::msg::DigitalIOState(_init);
}

void DigitalIOState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<niryo_one_msgs::msg::DigitalIOState *>(message_memory);
  typed_message->~DigitalIOState();
}

size_t size_function__DigitalIOState__pins(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DigitalIOState__pins(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__DigitalIOState__pins(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__DigitalIOState__pins(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__DigitalIOState__pins(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__DigitalIOState__pins(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__DigitalIOState__pins(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__DigitalIOState__pins(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DigitalIOState__names(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DigitalIOState__names(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__DigitalIOState__names(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__DigitalIOState__names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__DigitalIOState__names(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__DigitalIOState__names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__DigitalIOState__names(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__DigitalIOState__names(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DigitalIOState__modes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DigitalIOState__modes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__DigitalIOState__modes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__DigitalIOState__modes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__DigitalIOState__modes(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__DigitalIOState__modes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__DigitalIOState__modes(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__DigitalIOState__modes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DigitalIOState__states(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DigitalIOState__states(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__DigitalIOState__states(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__DigitalIOState__states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__DigitalIOState__states(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__DigitalIOState__states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__DigitalIOState__states(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__DigitalIOState__states(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DigitalIOState_message_member_array[4] = {
  {
    "pins",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::DigitalIOState, pins),  // bytes offset in struct
    nullptr,  // default value
    size_function__DigitalIOState__pins,  // size() function pointer
    get_const_function__DigitalIOState__pins,  // get_const(index) function pointer
    get_function__DigitalIOState__pins,  // get(index) function pointer
    fetch_function__DigitalIOState__pins,  // fetch(index, &value) function pointer
    assign_function__DigitalIOState__pins,  // assign(index, value) function pointer
    resize_function__DigitalIOState__pins  // resize(index) function pointer
  },
  {
    "names",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::DigitalIOState, names),  // bytes offset in struct
    nullptr,  // default value
    size_function__DigitalIOState__names,  // size() function pointer
    get_const_function__DigitalIOState__names,  // get_const(index) function pointer
    get_function__DigitalIOState__names,  // get(index) function pointer
    fetch_function__DigitalIOState__names,  // fetch(index, &value) function pointer
    assign_function__DigitalIOState__names,  // assign(index, value) function pointer
    resize_function__DigitalIOState__names  // resize(index) function pointer
  },
  {
    "modes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::DigitalIOState, modes),  // bytes offset in struct
    nullptr,  // default value
    size_function__DigitalIOState__modes,  // size() function pointer
    get_const_function__DigitalIOState__modes,  // get_const(index) function pointer
    get_function__DigitalIOState__modes,  // get(index) function pointer
    fetch_function__DigitalIOState__modes,  // fetch(index, &value) function pointer
    assign_function__DigitalIOState__modes,  // assign(index, value) function pointer
    resize_function__DigitalIOState__modes  // resize(index) function pointer
  },
  {
    "states",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::DigitalIOState, states),  // bytes offset in struct
    nullptr,  // default value
    size_function__DigitalIOState__states,  // size() function pointer
    get_const_function__DigitalIOState__states,  // get_const(index) function pointer
    get_function__DigitalIOState__states,  // get(index) function pointer
    fetch_function__DigitalIOState__states,  // fetch(index, &value) function pointer
    assign_function__DigitalIOState__states,  // assign(index, value) function pointer
    resize_function__DigitalIOState__states  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DigitalIOState_message_members = {
  "niryo_one_msgs::msg",  // message namespace
  "DigitalIOState",  // message name
  4,  // number of fields
  sizeof(niryo_one_msgs::msg::DigitalIOState),
  false,  // has_any_key_member_
  DigitalIOState_message_member_array,  // message members
  DigitalIOState_init_function,  // function to initialize message memory (memory has to be allocated)
  DigitalIOState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DigitalIOState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DigitalIOState_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__DigitalIOState__get_type_hash,
  &niryo_one_msgs__msg__DigitalIOState__get_type_description,
  &niryo_one_msgs__msg__DigitalIOState__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace niryo_one_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<niryo_one_msgs::msg::DigitalIOState>()
{
  return &::niryo_one_msgs::msg::rosidl_typesupport_introspection_cpp::DigitalIOState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, niryo_one_msgs, msg, DigitalIOState)() {
  return &::niryo_one_msgs::msg::rosidl_typesupport_introspection_cpp::DigitalIOState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
