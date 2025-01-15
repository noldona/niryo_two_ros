// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from niryo_one_msgs:msg/RobotMoveCommand.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/robot_move_command__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "niryo_one_msgs/msg/detail/robot_move_command__struct.h"
#include "niryo_one_msgs/msg/detail/robot_move_command__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/point__functions.h"  // position
#include "geometry_msgs/msg/detail/pose__functions.h"  // pose_quat
#include "niryo_one_msgs/msg/detail/rpy__functions.h"  // rpy
#include "niryo_one_msgs/msg/detail/shift_pose__functions.h"  // shift
#include "niryo_one_msgs/msg/detail/tool_command__functions.h"  // tool_cmd
#include "niryo_one_msgs/msg/detail/trajectory_plan__functions.h"  // trajectory
#include "rosidl_runtime_c/primitives_sequence.h"  // joints
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // joints
#include "rosidl_runtime_c/string.h"  // saved_position_name
#include "rosidl_runtime_c/string_functions.h"  // saved_position_name

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
bool cdr_serialize_geometry_msgs__msg__Point(
  const geometry_msgs__msg__Point * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
bool cdr_deserialize_geometry_msgs__msg__Point(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Point * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
size_t get_serialized_size_geometry_msgs__msg__Point(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
size_t max_serialized_size_geometry_msgs__msg__Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
bool cdr_serialize_key_geometry_msgs__msg__Point(
  const geometry_msgs__msg__Point * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
size_t get_serialized_size_key_geometry_msgs__msg__Point(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
size_t max_serialized_size_key_geometry_msgs__msg__Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
bool cdr_serialize_geometry_msgs__msg__Pose(
  const geometry_msgs__msg__Pose * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
bool cdr_deserialize_geometry_msgs__msg__Pose(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Pose * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
size_t get_serialized_size_geometry_msgs__msg__Pose(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
size_t max_serialized_size_geometry_msgs__msg__Pose(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
bool cdr_serialize_key_geometry_msgs__msg__Pose(
  const geometry_msgs__msg__Pose * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
size_t get_serialized_size_key_geometry_msgs__msg__Pose(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
size_t max_serialized_size_key_geometry_msgs__msg__Pose(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_niryo_one_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose)();

bool cdr_serialize_niryo_one_msgs__msg__RPY(
  const niryo_one_msgs__msg__RPY * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_niryo_one_msgs__msg__RPY(
  eprosima::fastcdr::Cdr & cdr,
  niryo_one_msgs__msg__RPY * ros_message);

size_t get_serialized_size_niryo_one_msgs__msg__RPY(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_niryo_one_msgs__msg__RPY(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_niryo_one_msgs__msg__RPY(
  const niryo_one_msgs__msg__RPY * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_niryo_one_msgs__msg__RPY(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_niryo_one_msgs__msg__RPY(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, msg, RPY)();

bool cdr_serialize_niryo_one_msgs__msg__ShiftPose(
  const niryo_one_msgs__msg__ShiftPose * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_niryo_one_msgs__msg__ShiftPose(
  eprosima::fastcdr::Cdr & cdr,
  niryo_one_msgs__msg__ShiftPose * ros_message);

size_t get_serialized_size_niryo_one_msgs__msg__ShiftPose(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_niryo_one_msgs__msg__ShiftPose(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_niryo_one_msgs__msg__ShiftPose(
  const niryo_one_msgs__msg__ShiftPose * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_niryo_one_msgs__msg__ShiftPose(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_niryo_one_msgs__msg__ShiftPose(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, msg, ShiftPose)();

bool cdr_serialize_niryo_one_msgs__msg__ToolCommand(
  const niryo_one_msgs__msg__ToolCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_niryo_one_msgs__msg__ToolCommand(
  eprosima::fastcdr::Cdr & cdr,
  niryo_one_msgs__msg__ToolCommand * ros_message);

size_t get_serialized_size_niryo_one_msgs__msg__ToolCommand(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_niryo_one_msgs__msg__ToolCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_niryo_one_msgs__msg__ToolCommand(
  const niryo_one_msgs__msg__ToolCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_niryo_one_msgs__msg__ToolCommand(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_niryo_one_msgs__msg__ToolCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, msg, ToolCommand)();

bool cdr_serialize_niryo_one_msgs__msg__TrajectoryPlan(
  const niryo_one_msgs__msg__TrajectoryPlan * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_niryo_one_msgs__msg__TrajectoryPlan(
  eprosima::fastcdr::Cdr & cdr,
  niryo_one_msgs__msg__TrajectoryPlan * ros_message);

size_t get_serialized_size_niryo_one_msgs__msg__TrajectoryPlan(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_niryo_one_msgs__msg__TrajectoryPlan(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_niryo_one_msgs__msg__TrajectoryPlan(
  const niryo_one_msgs__msg__TrajectoryPlan * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_niryo_one_msgs__msg__TrajectoryPlan(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_niryo_one_msgs__msg__TrajectoryPlan(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, msg, TrajectoryPlan)();


using _RobotMoveCommand__ros_msg_type = niryo_one_msgs__msg__RobotMoveCommand;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_serialize_niryo_one_msgs__msg__RobotMoveCommand(
  const niryo_one_msgs__msg__RobotMoveCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: cmd_type
  {
    cdr << ros_message->cmd_type;
  }

  // Field name: joints
  {
    size_t size = ros_message->joints.size;
    auto array_ptr = ros_message->joints.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: position
  {
    cdr_serialize_geometry_msgs__msg__Point(
      &ros_message->position, cdr);
  }

  // Field name: rpy
  {
    cdr_serialize_niryo_one_msgs__msg__RPY(
      &ros_message->rpy, cdr);
  }

  // Field name: shift
  {
    cdr_serialize_niryo_one_msgs__msg__ShiftPose(
      &ros_message->shift, cdr);
  }

  // Field name: trajectory
  {
    cdr_serialize_niryo_one_msgs__msg__TrajectoryPlan(
      &ros_message->trajectory, cdr);
  }

  // Field name: pose_quat
  {
    cdr_serialize_geometry_msgs__msg__Pose(
      &ros_message->pose_quat, cdr);
  }

  // Field name: saved_position_name
  {
    const rosidl_runtime_c__String * str = &ros_message->saved_position_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: saved_trajectory_id
  {
    cdr << ros_message->saved_trajectory_id;
  }

  // Field name: tool_cmd
  {
    cdr_serialize_niryo_one_msgs__msg__ToolCommand(
      &ros_message->tool_cmd, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_deserialize_niryo_one_msgs__msg__RobotMoveCommand(
  eprosima::fastcdr::Cdr & cdr,
  niryo_one_msgs__msg__RobotMoveCommand * ros_message)
{
  // Field name: cmd_type
  {
    cdr >> ros_message->cmd_type;
  }

  // Field name: joints
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->joints.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->joints);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->joints, size)) {
      fprintf(stderr, "failed to create array for field 'joints'");
      return false;
    }
    auto array_ptr = ros_message->joints.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: position
  {
    cdr_deserialize_geometry_msgs__msg__Point(cdr, &ros_message->position);
  }

  // Field name: rpy
  {
    cdr_deserialize_niryo_one_msgs__msg__RPY(cdr, &ros_message->rpy);
  }

  // Field name: shift
  {
    cdr_deserialize_niryo_one_msgs__msg__ShiftPose(cdr, &ros_message->shift);
  }

  // Field name: trajectory
  {
    cdr_deserialize_niryo_one_msgs__msg__TrajectoryPlan(cdr, &ros_message->trajectory);
  }

  // Field name: pose_quat
  {
    cdr_deserialize_geometry_msgs__msg__Pose(cdr, &ros_message->pose_quat);
  }

  // Field name: saved_position_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->saved_position_name.data) {
      rosidl_runtime_c__String__init(&ros_message->saved_position_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->saved_position_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'saved_position_name'\n");
      return false;
    }
  }

  // Field name: saved_trajectory_id
  {
    cdr >> ros_message->saved_trajectory_id;
  }

  // Field name: tool_cmd
  {
    cdr_deserialize_niryo_one_msgs__msg__ToolCommand(cdr, &ros_message->tool_cmd);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t get_serialized_size_niryo_one_msgs__msg__RobotMoveCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RobotMoveCommand__ros_msg_type * ros_message = static_cast<const _RobotMoveCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: cmd_type
  {
    size_t item_size = sizeof(ros_message->cmd_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: joints
  {
    size_t array_size = ros_message->joints.size;
    auto array_ptr = ros_message->joints.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: position
  current_alignment += get_serialized_size_geometry_msgs__msg__Point(
    &(ros_message->position), current_alignment);

  // Field name: rpy
  current_alignment += get_serialized_size_niryo_one_msgs__msg__RPY(
    &(ros_message->rpy), current_alignment);

  // Field name: shift
  current_alignment += get_serialized_size_niryo_one_msgs__msg__ShiftPose(
    &(ros_message->shift), current_alignment);

  // Field name: trajectory
  current_alignment += get_serialized_size_niryo_one_msgs__msg__TrajectoryPlan(
    &(ros_message->trajectory), current_alignment);

  // Field name: pose_quat
  current_alignment += get_serialized_size_geometry_msgs__msg__Pose(
    &(ros_message->pose_quat), current_alignment);

  // Field name: saved_position_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->saved_position_name.size + 1);

  // Field name: saved_trajectory_id
  {
    size_t item_size = sizeof(ros_message->saved_trajectory_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tool_cmd
  current_alignment += get_serialized_size_niryo_one_msgs__msg__ToolCommand(
    &(ros_message->tool_cmd), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t max_serialized_size_niryo_one_msgs__msg__RobotMoveCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: cmd_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: joints
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: position
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: rpy
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_niryo_one_msgs__msg__RPY(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: shift
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_niryo_one_msgs__msg__ShiftPose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: trajectory
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_niryo_one_msgs__msg__TrajectoryPlan(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: pose_quat
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Pose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: saved_position_name
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: saved_trajectory_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: tool_cmd
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_niryo_one_msgs__msg__ToolCommand(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = niryo_one_msgs__msg__RobotMoveCommand;
    is_plain =
      (
      offsetof(DataType, tool_cmd) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_serialize_key_niryo_one_msgs__msg__RobotMoveCommand(
  const niryo_one_msgs__msg__RobotMoveCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: cmd_type
  {
    cdr << ros_message->cmd_type;
  }

  // Field name: joints
  {
    size_t size = ros_message->joints.size;
    auto array_ptr = ros_message->joints.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: position
  {
    cdr_serialize_key_geometry_msgs__msg__Point(
      &ros_message->position, cdr);
  }

  // Field name: rpy
  {
    cdr_serialize_key_niryo_one_msgs__msg__RPY(
      &ros_message->rpy, cdr);
  }

  // Field name: shift
  {
    cdr_serialize_key_niryo_one_msgs__msg__ShiftPose(
      &ros_message->shift, cdr);
  }

  // Field name: trajectory
  {
    cdr_serialize_key_niryo_one_msgs__msg__TrajectoryPlan(
      &ros_message->trajectory, cdr);
  }

  // Field name: pose_quat
  {
    cdr_serialize_key_geometry_msgs__msg__Pose(
      &ros_message->pose_quat, cdr);
  }

  // Field name: saved_position_name
  {
    const rosidl_runtime_c__String * str = &ros_message->saved_position_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: saved_trajectory_id
  {
    cdr << ros_message->saved_trajectory_id;
  }

  // Field name: tool_cmd
  {
    cdr_serialize_key_niryo_one_msgs__msg__ToolCommand(
      &ros_message->tool_cmd, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t get_serialized_size_key_niryo_one_msgs__msg__RobotMoveCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RobotMoveCommand__ros_msg_type * ros_message = static_cast<const _RobotMoveCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: cmd_type
  {
    size_t item_size = sizeof(ros_message->cmd_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: joints
  {
    size_t array_size = ros_message->joints.size;
    auto array_ptr = ros_message->joints.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: position
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Point(
    &(ros_message->position), current_alignment);

  // Field name: rpy
  current_alignment += get_serialized_size_key_niryo_one_msgs__msg__RPY(
    &(ros_message->rpy), current_alignment);

  // Field name: shift
  current_alignment += get_serialized_size_key_niryo_one_msgs__msg__ShiftPose(
    &(ros_message->shift), current_alignment);

  // Field name: trajectory
  current_alignment += get_serialized_size_key_niryo_one_msgs__msg__TrajectoryPlan(
    &(ros_message->trajectory), current_alignment);

  // Field name: pose_quat
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Pose(
    &(ros_message->pose_quat), current_alignment);

  // Field name: saved_position_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->saved_position_name.size + 1);

  // Field name: saved_trajectory_id
  {
    size_t item_size = sizeof(ros_message->saved_trajectory_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tool_cmd
  current_alignment += get_serialized_size_key_niryo_one_msgs__msg__ToolCommand(
    &(ros_message->tool_cmd), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t max_serialized_size_key_niryo_one_msgs__msg__RobotMoveCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: cmd_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: joints
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: position
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: rpy
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_niryo_one_msgs__msg__RPY(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: shift
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_niryo_one_msgs__msg__ShiftPose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: trajectory
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_niryo_one_msgs__msg__TrajectoryPlan(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: pose_quat
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Pose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: saved_position_name
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: saved_trajectory_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: tool_cmd
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_niryo_one_msgs__msg__ToolCommand(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = niryo_one_msgs__msg__RobotMoveCommand;
    is_plain =
      (
      offsetof(DataType, tool_cmd) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _RobotMoveCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const niryo_one_msgs__msg__RobotMoveCommand * ros_message = static_cast<const niryo_one_msgs__msg__RobotMoveCommand *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_niryo_one_msgs__msg__RobotMoveCommand(ros_message, cdr);
}

static bool _RobotMoveCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  niryo_one_msgs__msg__RobotMoveCommand * ros_message = static_cast<niryo_one_msgs__msg__RobotMoveCommand *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_niryo_one_msgs__msg__RobotMoveCommand(cdr, ros_message);
}

static uint32_t _RobotMoveCommand__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_niryo_one_msgs__msg__RobotMoveCommand(
      untyped_ros_message, 0));
}

static size_t _RobotMoveCommand__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_niryo_one_msgs__msg__RobotMoveCommand(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RobotMoveCommand = {
  "niryo_one_msgs::msg",
  "RobotMoveCommand",
  _RobotMoveCommand__cdr_serialize,
  _RobotMoveCommand__cdr_deserialize,
  _RobotMoveCommand__get_serialized_size,
  _RobotMoveCommand__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _RobotMoveCommand__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RobotMoveCommand,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__RobotMoveCommand__get_type_hash,
  &niryo_one_msgs__msg__RobotMoveCommand__get_type_description,
  &niryo_one_msgs__msg__RobotMoveCommand__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, msg, RobotMoveCommand)() {
  return &_RobotMoveCommand__type_support;
}

#if defined(__cplusplus)
}
#endif
