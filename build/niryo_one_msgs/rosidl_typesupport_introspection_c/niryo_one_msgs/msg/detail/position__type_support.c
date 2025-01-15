// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from niryo_one_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "niryo_one_msgs/msg/detail/position__rosidl_typesupport_introspection_c.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "niryo_one_msgs/msg/detail/position__functions.h"
#include "niryo_one_msgs/msg/detail/position__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `joints`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `rpy`
#include "niryo_one_msgs/msg/rpy.h"
// Member `rpy`
#include "niryo_one_msgs/msg/detail/rpy__rosidl_typesupport_introspection_c.h"
// Member `point`
#include "geometry_msgs/msg/point.h"
// Member `point`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `quaternion`
#include "geometry_msgs/msg/quaternion.h"
// Member `quaternion`
#include "geometry_msgs/msg/detail/quaternion__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  niryo_one_msgs__msg__Position__init(message_memory);
}

void niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_fini_function(void * message_memory)
{
  niryo_one_msgs__msg__Position__fini(message_memory);
}

size_t niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__size_function__Position__joints(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__get_const_function__Position__joints(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__get_function__Position__joints(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__fetch_function__Position__joints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__get_const_function__Position__joints(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__assign_function__Position__joints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__get_function__Position__joints(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__resize_function__Position__joints(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_message_member_array[5] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__Position, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__Position, joints),  // bytes offset in struct
    NULL,  // default value
    niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__size_function__Position__joints,  // size() function pointer
    niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__get_const_function__Position__joints,  // get_const(index) function pointer
    niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__get_function__Position__joints,  // get(index) function pointer
    niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__fetch_function__Position__joints,  // fetch(index, &value) function pointer
    niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__assign_function__Position__joints,  // assign(index, value) function pointer
    niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__resize_function__Position__joints  // resize(index) function pointer
  },
  {
    "rpy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__Position, rpy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__Position, point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "quaternion",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__Position, quaternion),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_message_members = {
  "niryo_one_msgs__msg",  // message namespace
  "Position",  // message name
  5,  // number of fields
  sizeof(niryo_one_msgs__msg__Position),
  false,  // has_any_key_member_
  niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_message_member_array,  // message members
  niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_init_function,  // function to initialize message memory (memory has to be allocated)
  niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_message_type_support_handle = {
  0,
  &niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__Position__get_type_hash,
  &niryo_one_msgs__msg__Position__get_type_description,
  &niryo_one_msgs__msg__Position__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_niryo_one_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, msg, Position)() {
  niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, msg, RPY)();
  niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Quaternion)();
  if (!niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_message_type_support_handle.typesupport_identifier) {
    niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &niryo_one_msgs__msg__Position__rosidl_typesupport_introspection_c__Position_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
