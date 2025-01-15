// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:msg/Sequence.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/msg/detail/sequence__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__msg__Sequence__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xbe, 0x6d, 0xd9, 0x67, 0x19, 0x63, 0x34, 0x6a,
      0x01, 0xc6, 0x12, 0x61, 0xe9, 0xec, 0x1a, 0xb7,
      0x32, 0xdb, 0x95, 0x65, 0xc0, 0x59, 0xc3, 0xed,
      0x9a, 0x7a, 0x28, 0x67, 0xe8, 0x0e, 0x29, 0x1b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char niryo_one_msgs__msg__Sequence__TYPE_NAME[] = "niryo_one_msgs/msg/Sequence";

// Define type names, field names, and default values
static char niryo_one_msgs__msg__Sequence__FIELD_NAME__id[] = "id";
static char niryo_one_msgs__msg__Sequence__FIELD_NAME__name[] = "name";
static char niryo_one_msgs__msg__Sequence__FIELD_NAME__description[] = "description";
static char niryo_one_msgs__msg__Sequence__FIELD_NAME__created[] = "created";
static char niryo_one_msgs__msg__Sequence__FIELD_NAME__updated[] = "updated";
static char niryo_one_msgs__msg__Sequence__FIELD_NAME__blockly_xml[] = "blockly_xml";
static char niryo_one_msgs__msg__Sequence__FIELD_NAME__python_code[] = "python_code";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__msg__Sequence__FIELDS[] = {
  {
    {niryo_one_msgs__msg__Sequence__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__Sequence__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__Sequence__FIELD_NAME__description, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__Sequence__FIELD_NAME__created, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__Sequence__FIELD_NAME__updated, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__Sequence__FIELD_NAME__blockly_xml, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__Sequence__FIELD_NAME__python_code, 11, 11},
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
niryo_one_msgs__msg__Sequence__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__msg__Sequence__TYPE_NAME, 27, 27},
      {niryo_one_msgs__msg__Sequence__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 id\n"
  "string name\n"
  "string description\n"
  "\n"
  "int32 created\n"
  "int32 updated\n"
  "\n"
  "string blockly_xml\n"
  "string python_code";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__msg__Sequence__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__msg__Sequence__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 108, 108},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__msg__Sequence__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__msg__Sequence__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
