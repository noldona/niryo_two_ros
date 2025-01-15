// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from niryo_one_msgs:msg/HardwareStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "niryo_one_msgs/msg/detail/hardware_status__rosidl_typesupport_introspection_c.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "niryo_one_msgs/msg/detail/hardware_status__functions.h"
#include "niryo_one_msgs/msg/detail/hardware_status__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `error_message`
// Member `motor_names`
// Member `motor_types`
#include "rosidl_runtime_c/string_functions.h"
// Member `temperatures`
// Member `voltages`
// Member `hardware_errors`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  niryo_one_msgs__msg__HardwareStatus__init(message_memory);
}

void niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_fini_function(void * message_memory)
{
  niryo_one_msgs__msg__HardwareStatus__fini(message_memory);
}

size_t niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__size_function__HardwareStatus__motor_names(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__motor_names(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__motor_names(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__fetch_function__HardwareStatus__motor_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__motor_names(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__assign_function__HardwareStatus__motor_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__motor_names(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__resize_function__HardwareStatus__motor_names(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__size_function__HardwareStatus__motor_types(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__motor_types(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__motor_types(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__fetch_function__HardwareStatus__motor_types(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__motor_types(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__assign_function__HardwareStatus__motor_types(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__motor_types(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__resize_function__HardwareStatus__motor_types(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__size_function__HardwareStatus__temperatures(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__temperatures(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__temperatures(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__fetch_function__HardwareStatus__temperatures(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__temperatures(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__assign_function__HardwareStatus__temperatures(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__temperatures(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__resize_function__HardwareStatus__temperatures(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__size_function__HardwareStatus__voltages(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__voltages(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__voltages(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__fetch_function__HardwareStatus__voltages(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__voltages(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__assign_function__HardwareStatus__voltages(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__voltages(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__resize_function__HardwareStatus__voltages(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__size_function__HardwareStatus__hardware_errors(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__hardware_errors(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__hardware_errors(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__fetch_function__HardwareStatus__hardware_errors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__hardware_errors(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__assign_function__HardwareStatus__hardware_errors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__hardware_errors(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__resize_function__HardwareStatus__hardware_errors(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_message_member_array[12] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__HardwareStatus, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rpi_temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__HardwareStatus, rpi_temperature),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hardware_version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__HardwareStatus, hardware_version),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "connection_up",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__HardwareStatus, connection_up),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__HardwareStatus, error_message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "calibration_needed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__HardwareStatus, calibration_needed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "calibration_in_progress",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__HardwareStatus, calibration_in_progress),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "motor_names",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__HardwareStatus, motor_names),  // bytes offset in struct
    NULL,  // default value
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__size_function__HardwareStatus__motor_names,  // size() function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__motor_names,  // get_const(index) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__motor_names,  // get(index) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__fetch_function__HardwareStatus__motor_names,  // fetch(index, &value) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__assign_function__HardwareStatus__motor_names,  // assign(index, value) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__resize_function__HardwareStatus__motor_names  // resize(index) function pointer
  },
  {
    "motor_types",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__HardwareStatus, motor_types),  // bytes offset in struct
    NULL,  // default value
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__size_function__HardwareStatus__motor_types,  // size() function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__motor_types,  // get_const(index) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__motor_types,  // get(index) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__fetch_function__HardwareStatus__motor_types,  // fetch(index, &value) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__assign_function__HardwareStatus__motor_types,  // assign(index, value) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__resize_function__HardwareStatus__motor_types  // resize(index) function pointer
  },
  {
    "temperatures",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__HardwareStatus, temperatures),  // bytes offset in struct
    NULL,  // default value
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__size_function__HardwareStatus__temperatures,  // size() function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__temperatures,  // get_const(index) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__temperatures,  // get(index) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__fetch_function__HardwareStatus__temperatures,  // fetch(index, &value) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__assign_function__HardwareStatus__temperatures,  // assign(index, value) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__resize_function__HardwareStatus__temperatures  // resize(index) function pointer
  },
  {
    "voltages",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__HardwareStatus, voltages),  // bytes offset in struct
    NULL,  // default value
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__size_function__HardwareStatus__voltages,  // size() function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__voltages,  // get_const(index) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__voltages,  // get(index) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__fetch_function__HardwareStatus__voltages,  // fetch(index, &value) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__assign_function__HardwareStatus__voltages,  // assign(index, value) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__resize_function__HardwareStatus__voltages  // resize(index) function pointer
  },
  {
    "hardware_errors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__HardwareStatus, hardware_errors),  // bytes offset in struct
    NULL,  // default value
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__size_function__HardwareStatus__hardware_errors,  // size() function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_const_function__HardwareStatus__hardware_errors,  // get_const(index) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__get_function__HardwareStatus__hardware_errors,  // get(index) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__fetch_function__HardwareStatus__hardware_errors,  // fetch(index, &value) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__assign_function__HardwareStatus__hardware_errors,  // assign(index, value) function pointer
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__resize_function__HardwareStatus__hardware_errors  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_message_members = {
  "niryo_one_msgs__msg",  // message namespace
  "HardwareStatus",  // message name
  12,  // number of fields
  sizeof(niryo_one_msgs__msg__HardwareStatus),
  false,  // has_any_key_member_
  niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_message_member_array,  // message members
  niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_message_type_support_handle = {
  0,
  &niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__HardwareStatus__get_type_hash,
  &niryo_one_msgs__msg__HardwareStatus__get_type_description,
  &niryo_one_msgs__msg__HardwareStatus__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_niryo_one_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, msg, HardwareStatus)() {
  niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_message_type_support_handle.typesupport_identifier) {
    niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &niryo_one_msgs__msg__HardwareStatus__rosidl_typesupport_introspection_c__HardwareStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
