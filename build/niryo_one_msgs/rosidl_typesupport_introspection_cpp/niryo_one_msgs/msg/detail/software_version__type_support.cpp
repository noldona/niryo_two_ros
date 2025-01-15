// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from niryo_one_msgs:msg/SoftwareVersion.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "niryo_one_msgs/msg/detail/software_version__functions.h"
#include "niryo_one_msgs/msg/detail/software_version__struct.hpp"
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

void SoftwareVersion_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) niryo_one_msgs::msg::SoftwareVersion(_init);
}

void SoftwareVersion_fini_function(void * message_memory)
{
  auto typed_message = static_cast<niryo_one_msgs::msg::SoftwareVersion *>(message_memory);
  typed_message->~SoftwareVersion();
}

size_t size_function__SoftwareVersion__motor_names(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SoftwareVersion__motor_names(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__SoftwareVersion__motor_names(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__SoftwareVersion__motor_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__SoftwareVersion__motor_names(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__SoftwareVersion__motor_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__SoftwareVersion__motor_names(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__SoftwareVersion__motor_names(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__SoftwareVersion__stepper_firmware_versions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SoftwareVersion__stepper_firmware_versions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__SoftwareVersion__stepper_firmware_versions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__SoftwareVersion__stepper_firmware_versions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__SoftwareVersion__stepper_firmware_versions(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__SoftwareVersion__stepper_firmware_versions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__SoftwareVersion__stepper_firmware_versions(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__SoftwareVersion__stepper_firmware_versions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SoftwareVersion_message_member_array[4] = {
  {
    "rpi_image_version",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::SoftwareVersion, rpi_image_version),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "ros_niryo_one_version",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::SoftwareVersion, ros_niryo_one_version),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "motor_names",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::SoftwareVersion, motor_names),  // bytes offset in struct
    nullptr,  // default value
    size_function__SoftwareVersion__motor_names,  // size() function pointer
    get_const_function__SoftwareVersion__motor_names,  // get_const(index) function pointer
    get_function__SoftwareVersion__motor_names,  // get(index) function pointer
    fetch_function__SoftwareVersion__motor_names,  // fetch(index, &value) function pointer
    assign_function__SoftwareVersion__motor_names,  // assign(index, value) function pointer
    resize_function__SoftwareVersion__motor_names  // resize(index) function pointer
  },
  {
    "stepper_firmware_versions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::SoftwareVersion, stepper_firmware_versions),  // bytes offset in struct
    nullptr,  // default value
    size_function__SoftwareVersion__stepper_firmware_versions,  // size() function pointer
    get_const_function__SoftwareVersion__stepper_firmware_versions,  // get_const(index) function pointer
    get_function__SoftwareVersion__stepper_firmware_versions,  // get(index) function pointer
    fetch_function__SoftwareVersion__stepper_firmware_versions,  // fetch(index, &value) function pointer
    assign_function__SoftwareVersion__stepper_firmware_versions,  // assign(index, value) function pointer
    resize_function__SoftwareVersion__stepper_firmware_versions  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SoftwareVersion_message_members = {
  "niryo_one_msgs::msg",  // message namespace
  "SoftwareVersion",  // message name
  4,  // number of fields
  sizeof(niryo_one_msgs::msg::SoftwareVersion),
  false,  // has_any_key_member_
  SoftwareVersion_message_member_array,  // message members
  SoftwareVersion_init_function,  // function to initialize message memory (memory has to be allocated)
  SoftwareVersion_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SoftwareVersion_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SoftwareVersion_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__SoftwareVersion__get_type_hash,
  &niryo_one_msgs__msg__SoftwareVersion__get_type_description,
  &niryo_one_msgs__msg__SoftwareVersion__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace niryo_one_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<niryo_one_msgs::msg::SoftwareVersion>()
{
  return &::niryo_one_msgs::msg::rosidl_typesupport_introspection_cpp::SoftwareVersion_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, niryo_one_msgs, msg, SoftwareVersion)() {
  return &::niryo_one_msgs::msg::rosidl_typesupport_introspection_cpp::SoftwareVersion_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
