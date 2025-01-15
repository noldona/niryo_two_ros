// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:msg/ProcessState.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/msg/detail/process_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__msg__ProcessState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x29, 0x90, 0xba, 0x63, 0x3b, 0xd8, 0x87, 0xf0,
      0x3d, 0x17, 0x0c, 0x3f, 0x2d, 0xf5, 0xc3, 0xba,
      0x58, 0x5b, 0xd8, 0x5b, 0xca, 0xe4, 0x51, 0xf4,
      0x33, 0x68, 0x0a, 0x5e, 0xcd, 0x19, 0xd8, 0x4f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char niryo_one_msgs__msg__ProcessState__TYPE_NAME[] = "niryo_one_msgs/msg/ProcessState";

// Define type names, field names, and default values
static char niryo_one_msgs__msg__ProcessState__FIELD_NAME__name[] = "name";
static char niryo_one_msgs__msg__ProcessState__FIELD_NAME__is_active[] = "is_active";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__msg__ProcessState__FIELDS[] = {
  {
    {niryo_one_msgs__msg__ProcessState__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ProcessState__FIELD_NAME__is_active, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__msg__ProcessState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__msg__ProcessState__TYPE_NAME, 31, 31},
      {niryo_one_msgs__msg__ProcessState__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string[] name\n"
  "bool[] is_active";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__msg__ProcessState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__msg__ProcessState__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 31, 31},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__msg__ProcessState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__msg__ProcessState__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
