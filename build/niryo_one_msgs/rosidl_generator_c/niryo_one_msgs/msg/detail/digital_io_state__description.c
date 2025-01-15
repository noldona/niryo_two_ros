// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:msg/DigitalIOState.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/msg/detail/digital_io_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__msg__DigitalIOState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe3, 0x0d, 0x75, 0x6a, 0xd9, 0x0b, 0xa7, 0x3d,
      0xf3, 0xad, 0x06, 0x34, 0x14, 0xcb, 0x3f, 0x2f,
      0x5e, 0x01, 0xb9, 0xef, 0xa5, 0x55, 0x04, 0xd8,
      0xcb, 0x20, 0xdc, 0x6a, 0xa8, 0xab, 0x3a, 0x10,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char niryo_one_msgs__msg__DigitalIOState__TYPE_NAME[] = "niryo_one_msgs/msg/DigitalIOState";

// Define type names, field names, and default values
static char niryo_one_msgs__msg__DigitalIOState__FIELD_NAME__pins[] = "pins";
static char niryo_one_msgs__msg__DigitalIOState__FIELD_NAME__names[] = "names";
static char niryo_one_msgs__msg__DigitalIOState__FIELD_NAME__modes[] = "modes";
static char niryo_one_msgs__msg__DigitalIOState__FIELD_NAME__states[] = "states";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__msg__DigitalIOState__FIELDS[] = {
  {
    {niryo_one_msgs__msg__DigitalIOState__FIELD_NAME__pins, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__DigitalIOState__FIELD_NAME__names, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__DigitalIOState__FIELD_NAME__modes, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__DigitalIOState__FIELD_NAME__states, 6, 6},
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
niryo_one_msgs__msg__DigitalIOState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__msg__DigitalIOState__TYPE_NAME, 33, 33},
      {niryo_one_msgs__msg__DigitalIOState__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32[] pins  # GPIO pin\n"
  "string[] names  # PIN names seen by user to make it simpler\n"
  "int32[] modes  # IN/OUT\n"
  "int32[] states  # HIGH/LOW";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__msg__DigitalIOState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__msg__DigitalIOState__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 136, 136},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__msg__DigitalIOState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__msg__DigitalIOState__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
