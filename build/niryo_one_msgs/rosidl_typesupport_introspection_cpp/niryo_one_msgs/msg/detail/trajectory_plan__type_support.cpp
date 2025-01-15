// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from niryo_one_msgs:msg/TrajectoryPlan.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "niryo_one_msgs/msg/detail/trajectory_plan__functions.h"
#include "niryo_one_msgs/msg/detail/trajectory_plan__struct.hpp"
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

void TrajectoryPlan_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) niryo_one_msgs::msg::TrajectoryPlan(_init);
}

void TrajectoryPlan_fini_function(void * message_memory)
{
  auto typed_message = static_cast<niryo_one_msgs::msg::TrajectoryPlan *>(message_memory);
  typed_message->~TrajectoryPlan();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TrajectoryPlan_message_member_array[3] = {
  {
    "trajectory_start",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<moveit_msgs::msg::RobotState>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::TrajectoryPlan, trajectory_start),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "group_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::TrajectoryPlan, group_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "trajectory",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<moveit_msgs::msg::RobotTrajectory>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs::msg::TrajectoryPlan, trajectory),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TrajectoryPlan_message_members = {
  "niryo_one_msgs::msg",  // message namespace
  "TrajectoryPlan",  // message name
  3,  // number of fields
  sizeof(niryo_one_msgs::msg::TrajectoryPlan),
  false,  // has_any_key_member_
  TrajectoryPlan_message_member_array,  // message members
  TrajectoryPlan_init_function,  // function to initialize message memory (memory has to be allocated)
  TrajectoryPlan_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TrajectoryPlan_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TrajectoryPlan_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__TrajectoryPlan__get_type_hash,
  &niryo_one_msgs__msg__TrajectoryPlan__get_type_description,
  &niryo_one_msgs__msg__TrajectoryPlan__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace niryo_one_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<niryo_one_msgs::msg::TrajectoryPlan>()
{
  return &::niryo_one_msgs::msg::rosidl_typesupport_introspection_cpp::TrajectoryPlan_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, niryo_one_msgs, msg, TrajectoryPlan)() {
  return &::niryo_one_msgs::msg::rosidl_typesupport_introspection_cpp::TrajectoryPlan_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
