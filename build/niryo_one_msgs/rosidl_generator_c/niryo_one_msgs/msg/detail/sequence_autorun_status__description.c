// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:msg/SequenceAutorunStatus.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/msg/detail/sequence_autorun_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__msg__SequenceAutorunStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7a, 0x49, 0xcf, 0x7b, 0x0a, 0xe7, 0x2c, 0x07,
      0x50, 0xfd, 0xb6, 0xb6, 0x85, 0x10, 0x5a, 0x3d,
      0xfe, 0x23, 0x97, 0xdb, 0xb4, 0xbe, 0x96, 0x6c,
      0x13, 0xa2, 0x53, 0x8d, 0xc4, 0x3a, 0x55, 0x32,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char niryo_one_msgs__msg__SequenceAutorunStatus__TYPE_NAME[] = "niryo_one_msgs/msg/SequenceAutorunStatus";

// Define type names, field names, and default values
static char niryo_one_msgs__msg__SequenceAutorunStatus__FIELD_NAME__enabled[] = "enabled";
static char niryo_one_msgs__msg__SequenceAutorunStatus__FIELD_NAME__mode[] = "mode";
static char niryo_one_msgs__msg__SequenceAutorunStatus__FIELD_NAME__sequence_ids[] = "sequence_ids";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__msg__SequenceAutorunStatus__FIELDS[] = {
  {
    {niryo_one_msgs__msg__SequenceAutorunStatus__FIELD_NAME__enabled, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__SequenceAutorunStatus__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__SequenceAutorunStatus__FIELD_NAME__sequence_ids, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__msg__SequenceAutorunStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__msg__SequenceAutorunStatus__TYPE_NAME, 40, 40},
      {niryo_one_msgs__msg__SequenceAutorunStatus__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool enabled\n"
  "int32 mode\n"
  "int32[] sequence_ids";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__msg__SequenceAutorunStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__msg__SequenceAutorunStatus__TYPE_NAME, 40, 40},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 45, 45},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__msg__SequenceAutorunStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__msg__SequenceAutorunStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
