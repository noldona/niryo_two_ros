// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:msg/ToolCommand.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/msg/detail/tool_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__msg__ToolCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc9, 0x2e, 0x61, 0x3a, 0x1d, 0xed, 0xa3, 0x3b,
      0x22, 0xda, 0x61, 0x02, 0x0c, 0x59, 0x59, 0x04,
      0xb9, 0x88, 0xb6, 0x59, 0x37, 0xc9, 0x45, 0xae,
      0xbc, 0x37, 0xd3, 0x0b, 0xa9, 0x54, 0xe5, 0x3b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char niryo_one_msgs__msg__ToolCommand__TYPE_NAME[] = "niryo_one_msgs/msg/ToolCommand";

// Define type names, field names, and default values
static char niryo_one_msgs__msg__ToolCommand__FIELD_NAME__tool_id[] = "tool_id";
static char niryo_one_msgs__msg__ToolCommand__FIELD_NAME__cmd_type[] = "cmd_type";
static char niryo_one_msgs__msg__ToolCommand__FIELD_NAME__gripper_close_speed[] = "gripper_close_speed";
static char niryo_one_msgs__msg__ToolCommand__FIELD_NAME__gripper_open_speed[] = "gripper_open_speed";
static char niryo_one_msgs__msg__ToolCommand__FIELD_NAME__activate[] = "activate";
static char niryo_one_msgs__msg__ToolCommand__FIELD_NAME__gpio[] = "gpio";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__msg__ToolCommand__FIELDS[] = {
  {
    {niryo_one_msgs__msg__ToolCommand__FIELD_NAME__tool_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ToolCommand__FIELD_NAME__cmd_type, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ToolCommand__FIELD_NAME__gripper_close_speed, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ToolCommand__FIELD_NAME__gripper_open_speed, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ToolCommand__FIELD_NAME__activate, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ToolCommand__FIELD_NAME__gpio, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__msg__ToolCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__msg__ToolCommand__TYPE_NAME, 30, 30},
      {niryo_one_msgs__msg__ToolCommand__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 tool_id\n"
  "uint8 cmd_type\n"
  "\n"
  "uint16 gripper_close_speed  # if gripper close\n"
  "\n"
  "uint16 gripper_open_speed  # if gripper open\n"
  "\n"
  "bool activate  # if vacuum pump or electromagnet grove\n"
  "\n"
  "uint8 gpio  # if tool is set by digital outputs (electromagnet)";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__msg__ToolCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__msg__ToolCommand__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 244, 244},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__msg__ToolCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__msg__ToolCommand__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
