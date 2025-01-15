// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from niryo_one_msgs:msg/ProcessState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "niryo_one_msgs/msg/detail/process_state__rosidl_typesupport_introspection_c.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "niryo_one_msgs/msg/detail/process_state__functions.h"
#include "niryo_one_msgs/msg/detail/process_state__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `is_active`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__ProcessState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  niryo_one_msgs__msg__ProcessState__init(message_memory);
}

void niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__ProcessState_fini_function(void * message_memory)
{
  niryo_one_msgs__msg__ProcessState__fini(message_memory);
}

size_t niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__size_function__ProcessState__name(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__get_const_function__ProcessState__name(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__get_function__ProcessState__name(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__fetch_function__ProcessState__name(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__get_const_function__ProcessState__name(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__assign_function__ProcessState__name(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__get_function__ProcessState__name(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__resize_function__ProcessState__name(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__size_function__ProcessState__is_active(
  const void * untyped_member)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return member->size;
}

const void * niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__get_const_function__ProcessState__is_active(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void * niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__get_function__ProcessState__is_active(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__fetch_function__ProcessState__is_active(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__get_const_function__ProcessState__is_active(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__assign_function__ProcessState__is_active(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__get_function__ProcessState__is_active(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

bool niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__resize_function__ProcessState__is_active(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  rosidl_runtime_c__boolean__Sequence__fini(member);
  return rosidl_runtime_c__boolean__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__ProcessState_message_member_array[2] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__ProcessState, name),  // bytes offset in struct
    NULL,  // default value
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__size_function__ProcessState__name,  // size() function pointer
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__get_const_function__ProcessState__name,  // get_const(index) function pointer
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__get_function__ProcessState__name,  // get(index) function pointer
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__fetch_function__ProcessState__name,  // fetch(index, &value) function pointer
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__assign_function__ProcessState__name,  // assign(index, value) function pointer
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__resize_function__ProcessState__name  // resize(index) function pointer
  },
  {
    "is_active",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__ProcessState, is_active),  // bytes offset in struct
    NULL,  // default value
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__size_function__ProcessState__is_active,  // size() function pointer
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__get_const_function__ProcessState__is_active,  // get_const(index) function pointer
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__get_function__ProcessState__is_active,  // get(index) function pointer
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__fetch_function__ProcessState__is_active,  // fetch(index, &value) function pointer
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__assign_function__ProcessState__is_active,  // assign(index, value) function pointer
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__resize_function__ProcessState__is_active  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__ProcessState_message_members = {
  "niryo_one_msgs__msg",  // message namespace
  "ProcessState",  // message name
  2,  // number of fields
  sizeof(niryo_one_msgs__msg__ProcessState),
  false,  // has_any_key_member_
  niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__ProcessState_message_member_array,  // message members
  niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__ProcessState_init_function,  // function to initialize message memory (memory has to be allocated)
  niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__ProcessState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__ProcessState_message_type_support_handle = {
  0,
  &niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__ProcessState_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__ProcessState__get_type_hash,
  &niryo_one_msgs__msg__ProcessState__get_type_description,
  &niryo_one_msgs__msg__ProcessState__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_niryo_one_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, msg, ProcessState)() {
  if (!niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__ProcessState_message_type_support_handle.typesupport_identifier) {
    niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__ProcessState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &niryo_one_msgs__msg__ProcessState__rosidl_typesupport_introspection_c__ProcessState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
