// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:msg/ObjectPose.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/msg/detail/object_pose__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__msg__ObjectPose__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x29, 0x33, 0x35, 0xe8, 0xe1, 0xa1, 0x36, 0x03,
      0x3b, 0xd5, 0x30, 0xb9, 0x9b, 0xd6, 0x90, 0xfe,
      0xea, 0xf0, 0x34, 0xa6, 0x38, 0x88, 0x6e, 0xd6,
      0x98, 0xdc, 0x8a, 0x31, 0xb0, 0x3b, 0x4b, 0x92,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char niryo_one_msgs__msg__ObjectPose__TYPE_NAME[] = "niryo_one_msgs/msg/ObjectPose";

// Define type names, field names, and default values
static char niryo_one_msgs__msg__ObjectPose__FIELD_NAME__x[] = "x";
static char niryo_one_msgs__msg__ObjectPose__FIELD_NAME__y[] = "y";
static char niryo_one_msgs__msg__ObjectPose__FIELD_NAME__z[] = "z";
static char niryo_one_msgs__msg__ObjectPose__FIELD_NAME__roll[] = "roll";
static char niryo_one_msgs__msg__ObjectPose__FIELD_NAME__pitch[] = "pitch";
static char niryo_one_msgs__msg__ObjectPose__FIELD_NAME__yaw[] = "yaw";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__msg__ObjectPose__FIELDS[] = {
  {
    {niryo_one_msgs__msg__ObjectPose__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ObjectPose__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ObjectPose__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ObjectPose__FIELD_NAME__roll, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ObjectPose__FIELD_NAME__pitch, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ObjectPose__FIELD_NAME__yaw, 3, 3},
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
niryo_one_msgs__msg__ObjectPose__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__msg__ObjectPose__TYPE_NAME, 29, 29},
      {niryo_one_msgs__msg__ObjectPose__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 x\n"
  "float64 y\n"
  "float64 z\n"
  "\n"
  "float64 roll\n"
  "float64 pitch\n"
  "float64 yaw";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__msg__ObjectPose__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__msg__ObjectPose__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 70, 70},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__msg__ObjectPose__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__msg__ObjectPose__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
