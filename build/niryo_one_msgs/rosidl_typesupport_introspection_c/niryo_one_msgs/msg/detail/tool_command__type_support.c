// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from niryo_one_msgs:msg/ToolCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "niryo_one_msgs/msg/detail/tool_command__rosidl_typesupport_introspection_c.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "niryo_one_msgs/msg/detail/tool_command__functions.h"
#include "niryo_one_msgs/msg/detail/tool_command__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void niryo_one_msgs__msg__ToolCommand__rosidl_typesupport_introspection_c__ToolCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  niryo_one_msgs__msg__ToolCommand__init(message_memory);
}

void niryo_one_msgs__msg__ToolCommand__rosidl_typesupport_introspection_c__ToolCommand_fini_function(void * message_memory)
{
  niryo_one_msgs__msg__ToolCommand__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember niryo_one_msgs__msg__ToolCommand__rosidl_typesupport_introspection_c__ToolCommand_message_member_array[6] = {
  {
    "tool_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__ToolCommand, tool_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cmd_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__ToolCommand, cmd_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gripper_close_speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__ToolCommand, gripper_close_speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gripper_open_speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__ToolCommand, gripper_open_speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "activate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__ToolCommand, activate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gpio",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__ToolCommand, gpio),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers niryo_one_msgs__msg__ToolCommand__rosidl_typesupport_introspection_c__ToolCommand_message_members = {
  "niryo_one_msgs__msg",  // message namespace
  "ToolCommand",  // message name
  6,  // number of fields
  sizeof(niryo_one_msgs__msg__ToolCommand),
  false,  // has_any_key_member_
  niryo_one_msgs__msg__ToolCommand__rosidl_typesupport_introspection_c__ToolCommand_message_member_array,  // message members
  niryo_one_msgs__msg__ToolCommand__rosidl_typesupport_introspection_c__ToolCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  niryo_one_msgs__msg__ToolCommand__rosidl_typesupport_introspection_c__ToolCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t niryo_one_msgs__msg__ToolCommand__rosidl_typesupport_introspection_c__ToolCommand_message_type_support_handle = {
  0,
  &niryo_one_msgs__msg__ToolCommand__rosidl_typesupport_introspection_c__ToolCommand_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__ToolCommand__get_type_hash,
  &niryo_one_msgs__msg__ToolCommand__get_type_description,
  &niryo_one_msgs__msg__ToolCommand__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_niryo_one_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, msg, ToolCommand)() {
  if (!niryo_one_msgs__msg__ToolCommand__rosidl_typesupport_introspection_c__ToolCommand_message_type_support_handle.typesupport_identifier) {
    niryo_one_msgs__msg__ToolCommand__rosidl_typesupport_introspection_c__ToolCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &niryo_one_msgs__msg__ToolCommand__rosidl_typesupport_introspection_c__ToolCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
