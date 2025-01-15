// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from niryo_one_msgs:msg/SequenceAutorunStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "niryo_one_msgs/msg/detail/sequence_autorun_status__rosidl_typesupport_introspection_c.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "niryo_one_msgs/msg/detail/sequence_autorun_status__functions.h"
#include "niryo_one_msgs/msg/detail/sequence_autorun_status__struct.h"


// Include directives for member types
// Member `sequence_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__SequenceAutorunStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  niryo_one_msgs__msg__SequenceAutorunStatus__init(message_memory);
}

void niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__SequenceAutorunStatus_fini_function(void * message_memory)
{
  niryo_one_msgs__msg__SequenceAutorunStatus__fini(message_memory);
}

size_t niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__size_function__SequenceAutorunStatus__sequence_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__get_const_function__SequenceAutorunStatus__sequence_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__get_function__SequenceAutorunStatus__sequence_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__fetch_function__SequenceAutorunStatus__sequence_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__get_const_function__SequenceAutorunStatus__sequence_ids(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__assign_function__SequenceAutorunStatus__sequence_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__get_function__SequenceAutorunStatus__sequence_ids(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__resize_function__SequenceAutorunStatus__sequence_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__SequenceAutorunStatus_message_member_array[3] = {
  {
    "enabled",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__SequenceAutorunStatus, enabled),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__SequenceAutorunStatus, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sequence_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__SequenceAutorunStatus, sequence_ids),  // bytes offset in struct
    NULL,  // default value
    niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__size_function__SequenceAutorunStatus__sequence_ids,  // size() function pointer
    niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__get_const_function__SequenceAutorunStatus__sequence_ids,  // get_const(index) function pointer
    niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__get_function__SequenceAutorunStatus__sequence_ids,  // get(index) function pointer
    niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__fetch_function__SequenceAutorunStatus__sequence_ids,  // fetch(index, &value) function pointer
    niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__assign_function__SequenceAutorunStatus__sequence_ids,  // assign(index, value) function pointer
    niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__resize_function__SequenceAutorunStatus__sequence_ids  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__SequenceAutorunStatus_message_members = {
  "niryo_one_msgs__msg",  // message namespace
  "SequenceAutorunStatus",  // message name
  3,  // number of fields
  sizeof(niryo_one_msgs__msg__SequenceAutorunStatus),
  false,  // has_any_key_member_
  niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__SequenceAutorunStatus_message_member_array,  // message members
  niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__SequenceAutorunStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__SequenceAutorunStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__SequenceAutorunStatus_message_type_support_handle = {
  0,
  &niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__SequenceAutorunStatus_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__SequenceAutorunStatus__get_type_hash,
  &niryo_one_msgs__msg__SequenceAutorunStatus__get_type_description,
  &niryo_one_msgs__msg__SequenceAutorunStatus__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_niryo_one_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, msg, SequenceAutorunStatus)() {
  if (!niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__SequenceAutorunStatus_message_type_support_handle.typesupport_identifier) {
    niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__SequenceAutorunStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &niryo_one_msgs__msg__SequenceAutorunStatus__rosidl_typesupport_introspection_c__SequenceAutorunStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
