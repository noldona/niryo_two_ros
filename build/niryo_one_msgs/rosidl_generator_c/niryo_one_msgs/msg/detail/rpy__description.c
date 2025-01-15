// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:msg/RPY.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/msg/detail/rpy__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__msg__RPY__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2a, 0xc7, 0x4f, 0xeb, 0xf3, 0x6f, 0x14, 0x2d,
      0xc0, 0xac, 0x04, 0x3f, 0xbf, 0x70, 0x67, 0xaf,
      0x52, 0x5e, 0xc5, 0x1c, 0x06, 0xb3, 0xbe, 0xe5,
      0xeb, 0x05, 0xc5, 0xc6, 0x77, 0x09, 0xd2, 0xda,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char niryo_one_msgs__msg__RPY__TYPE_NAME[] = "niryo_one_msgs/msg/RPY";

// Define type names, field names, and default values
static char niryo_one_msgs__msg__RPY__FIELD_NAME__roll[] = "roll";
static char niryo_one_msgs__msg__RPY__FIELD_NAME__pitch[] = "pitch";
static char niryo_one_msgs__msg__RPY__FIELD_NAME__yaw[] = "yaw";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__msg__RPY__FIELDS[] = {
  {
    {niryo_one_msgs__msg__RPY__FIELD_NAME__roll, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RPY__FIELD_NAME__pitch, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RPY__FIELD_NAME__yaw, 3, 3},
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
niryo_one_msgs__msg__RPY__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__msg__RPY__TYPE_NAME, 22, 22},
      {niryo_one_msgs__msg__RPY__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# roll, pitch and yaw\n"
  "float64 roll\n"
  "float64 pitch\n"
  "float64 yaw";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__msg__RPY__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__msg__RPY__TYPE_NAME, 22, 22},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 61, 61},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__msg__RPY__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__msg__RPY__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
