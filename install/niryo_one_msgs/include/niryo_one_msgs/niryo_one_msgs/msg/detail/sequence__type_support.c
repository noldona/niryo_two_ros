// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from niryo_one_msgs:msg/Sequence.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "niryo_one_msgs/msg/detail/sequence__rosidl_typesupport_introspection_c.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "niryo_one_msgs/msg/detail/sequence__functions.h"
#include "niryo_one_msgs/msg/detail/sequence__struct.h"


// Include directives for member types
// Member `name`
// Member `description`
// Member `blockly_xml`
// Member `python_code`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void niryo_one_msgs__msg__Sequence__rosidl_typesupport_introspection_c__Sequence_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  niryo_one_msgs__msg__Sequence__init(message_memory);
}

void niryo_one_msgs__msg__Sequence__rosidl_typesupport_introspection_c__Sequence_fini_function(void * message_memory)
{
  niryo_one_msgs__msg__Sequence__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember niryo_one_msgs__msg__Sequence__rosidl_typesupport_introspection_c__Sequence_message_member_array[7] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__Sequence, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__Sequence, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "description",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__Sequence, description),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "created",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__Sequence, created),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "updated",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__Sequence, updated),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "blockly_xml",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__Sequence, blockly_xml),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "python_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__Sequence, python_code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers niryo_one_msgs__msg__Sequence__rosidl_typesupport_introspection_c__Sequence_message_members = {
  "niryo_one_msgs__msg",  // message namespace
  "Sequence",  // message name
  7,  // number of fields
  sizeof(niryo_one_msgs__msg__Sequence),
  false,  // has_any_key_member_
  niryo_one_msgs__msg__Sequence__rosidl_typesupport_introspection_c__Sequence_message_member_array,  // message members
  niryo_one_msgs__msg__Sequence__rosidl_typesupport_introspection_c__Sequence_init_function,  // function to initialize message memory (memory has to be allocated)
  niryo_one_msgs__msg__Sequence__rosidl_typesupport_introspection_c__Sequence_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t niryo_one_msgs__msg__Sequence__rosidl_typesupport_introspection_c__Sequence_message_type_support_handle = {
  0,
  &niryo_one_msgs__msg__Sequence__rosidl_typesupport_introspection_c__Sequence_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__Sequence__get_type_hash,
  &niryo_one_msgs__msg__Sequence__get_type_description,
  &niryo_one_msgs__msg__Sequence__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_niryo_one_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, msg, Sequence)() {
  if (!niryo_one_msgs__msg__Sequence__rosidl_typesupport_introspection_c__Sequence_message_type_support_handle.typesupport_identifier) {
    niryo_one_msgs__msg__Sequence__rosidl_typesupport_introspection_c__Sequence_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &niryo_one_msgs__msg__Sequence__rosidl_typesupport_introspection_c__Sequence_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
