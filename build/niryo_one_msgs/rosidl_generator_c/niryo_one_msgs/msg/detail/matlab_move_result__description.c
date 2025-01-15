// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:msg/MatlabMoveResult.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/msg/detail/matlab_move_result__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__msg__MatlabMoveResult__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9a, 0x1e, 0x7c, 0xdb, 0x65, 0x3c, 0xfe, 0x4f,
      0x30, 0x9c, 0xf9, 0x2e, 0x69, 0x41, 0x4c, 0xec,
      0x38, 0x5c, 0xa3, 0xd4, 0xe6, 0xa7, 0x1b, 0xf3,
      0x7c, 0xd5, 0x96, 0x4c, 0xe0, 0xe0, 0xf5, 0xcf,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char niryo_one_msgs__msg__MatlabMoveResult__TYPE_NAME[] = "niryo_one_msgs/msg/MatlabMoveResult";

// Define type names, field names, and default values
static char niryo_one_msgs__msg__MatlabMoveResult__FIELD_NAME__status[] = "status";
static char niryo_one_msgs__msg__MatlabMoveResult__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__msg__MatlabMoveResult__FIELDS[] = {
  {
    {niryo_one_msgs__msg__MatlabMoveResult__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__MatlabMoveResult__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__msg__MatlabMoveResult__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__msg__MatlabMoveResult__TYPE_NAME, 35, 35},
      {niryo_one_msgs__msg__MatlabMoveResult__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 status \n"
  "string message ";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__msg__MatlabMoveResult__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__msg__MatlabMoveResult__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 30, 30},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__msg__MatlabMoveResult__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__msg__MatlabMoveResult__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
