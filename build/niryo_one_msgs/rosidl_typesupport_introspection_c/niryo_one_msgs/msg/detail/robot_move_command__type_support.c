// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from niryo_one_msgs:msg/RobotMoveCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "niryo_one_msgs/msg/detail/robot_move_command__rosidl_typesupport_introspection_c.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "niryo_one_msgs/msg/detail/robot_move_command__functions.h"
#include "niryo_one_msgs/msg/detail/robot_move_command__struct.h"


// Include directives for member types
// Member `joints`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `rpy`
#include "niryo_one_msgs/msg/rpy.h"
// Member `rpy`
#include "niryo_one_msgs/msg/detail/rpy__rosidl_typesupport_introspection_c.h"
// Member `shift`
#include "niryo_one_msgs/msg/shift_pose.h"
// Member `shift`
#include "niryo_one_msgs/msg/detail/shift_pose__rosidl_typesupport_introspection_c.h"
// Member `trajectory`
#include "niryo_one_msgs/msg/trajectory_plan.h"
// Member `trajectory`
#include "niryo_one_msgs/msg/detail/trajectory_plan__rosidl_typesupport_introspection_c.h"
// Member `pose_quat`
#include "geometry_msgs/msg/pose.h"
// Member `pose_quat`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `saved_position_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `tool_cmd`
#include "niryo_one_msgs/msg/tool_command.h"
// Member `tool_cmd`
#include "niryo_one_msgs/msg/detail/tool_command__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  niryo_one_msgs__msg__RobotMoveCommand__init(message_memory);
}

void niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_fini_function(void * message_memory)
{
  niryo_one_msgs__msg__RobotMoveCommand__fini(message_memory);
}

size_t niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__size_function__RobotMoveCommand__joints(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__get_const_function__RobotMoveCommand__joints(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__get_function__RobotMoveCommand__joints(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__fetch_function__RobotMoveCommand__joints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__get_const_function__RobotMoveCommand__joints(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__assign_function__RobotMoveCommand__joints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__get_function__RobotMoveCommand__joints(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__resize_function__RobotMoveCommand__joints(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_member_array[10] = {
  {
    "cmd_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__RobotMoveCommand, cmd_type),  // bytes offset in struct
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
    offsetof(niryo_one_msgs__msg__RobotMoveCommand, joints),  // bytes offset in struct
    NULL,  // default value
    niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__size_function__RobotMoveCommand__joints,  // size() function pointer
    niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__get_const_function__RobotMoveCommand__joints,  // get_const(index) function pointer
    niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__get_function__RobotMoveCommand__joints,  // get(index) function pointer
    niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__fetch_function__RobotMoveCommand__joints,  // fetch(index, &value) function pointer
    niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__assign_function__RobotMoveCommand__joints,  // assign(index, value) function pointer
    niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__resize_function__RobotMoveCommand__joints  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__RobotMoveCommand, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
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
    offsetof(niryo_one_msgs__msg__RobotMoveCommand, rpy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "shift",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__RobotMoveCommand, shift),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__RobotMoveCommand, trajectory),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose_quat",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__RobotMoveCommand, pose_quat),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "saved_position_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__RobotMoveCommand, saved_position_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "saved_trajectory_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__RobotMoveCommand, saved_trajectory_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tool_cmd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__msg__RobotMoveCommand, tool_cmd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_members = {
  "niryo_one_msgs__msg",  // message namespace
  "RobotMoveCommand",  // message name
  10,  // number of fields
  sizeof(niryo_one_msgs__msg__RobotMoveCommand),
  false,  // has_any_key_member_
  niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_member_array,  // message members
  niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_type_support_handle = {
  0,
  &niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__RobotMoveCommand__get_type_hash,
  &niryo_one_msgs__msg__RobotMoveCommand__get_type_description,
  &niryo_one_msgs__msg__RobotMoveCommand__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_niryo_one_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, msg, RobotMoveCommand)() {
  niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, msg, RPY)();
  niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, msg, ShiftPose)();
  niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, msg, TrajectoryPlan)();
  niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_member_array[9].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, msg, ToolCommand)();
  if (!niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_type_support_handle.typesupport_identifier) {
    niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &niryo_one_msgs__msg__RobotMoveCommand__rosidl_typesupport_introspection_c__RobotMoveCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
