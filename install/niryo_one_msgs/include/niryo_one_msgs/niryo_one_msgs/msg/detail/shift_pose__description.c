// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:msg/ShiftPose.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/msg/detail/shift_pose__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__msg__ShiftPose__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf9, 0x0d, 0xdc, 0x12, 0x57, 0xcf, 0xd4, 0x29,
      0x7c, 0x57, 0x39, 0x7d, 0xd8, 0x39, 0x9e, 0x41,
      0xd9, 0x67, 0x34, 0xc0, 0xa5, 0x02, 0xb2, 0x8b,
      0x5e, 0x9c, 0xf6, 0x81, 0x92, 0x5e, 0xe1, 0xa7,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char niryo_one_msgs__msg__ShiftPose__TYPE_NAME[] = "niryo_one_msgs/msg/ShiftPose";

// Define type names, field names, and default values
static char niryo_one_msgs__msg__ShiftPose__FIELD_NAME__axis_number[] = "axis_number";
static char niryo_one_msgs__msg__ShiftPose__FIELD_NAME__value[] = "value";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__msg__ShiftPose__FIELDS[] = {
  {
    {niryo_one_msgs__msg__ShiftPose__FIELD_NAME__axis_number, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ShiftPose__FIELD_NAME__value, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__msg__ShiftPose__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__msg__ShiftPose__TYPE_NAME, 28, 28},
      {niryo_one_msgs__msg__ShiftPose__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 axis_number\n"
  "float64 value";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__msg__ShiftPose__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__msg__ShiftPose__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 32, 32},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__msg__ShiftPose__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__msg__ShiftPose__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
