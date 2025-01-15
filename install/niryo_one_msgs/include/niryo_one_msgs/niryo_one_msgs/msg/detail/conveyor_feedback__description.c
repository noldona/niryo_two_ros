// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:msg/ConveyorFeedback.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/msg/detail/conveyor_feedback__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__msg__ConveyorFeedback__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf9, 0xb3, 0x89, 0xd5, 0xc6, 0xed, 0x30, 0x3c,
      0x58, 0xbf, 0x6d, 0x65, 0x44, 0x8c, 0x71, 0xa9,
      0x49, 0xff, 0x40, 0x79, 0x0b, 0x1a, 0x8e, 0x5f,
      0xec, 0x80, 0x3c, 0x17, 0x35, 0xec, 0x95, 0x3a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char niryo_one_msgs__msg__ConveyorFeedback__TYPE_NAME[] = "niryo_one_msgs/msg/ConveyorFeedback";

// Define type names, field names, and default values
static char niryo_one_msgs__msg__ConveyorFeedback__FIELD_NAME__conveyor_id[] = "conveyor_id";
static char niryo_one_msgs__msg__ConveyorFeedback__FIELD_NAME__connection_state[] = "connection_state";
static char niryo_one_msgs__msg__ConveyorFeedback__FIELD_NAME__running[] = "running";
static char niryo_one_msgs__msg__ConveyorFeedback__FIELD_NAME__speed[] = "speed";
static char niryo_one_msgs__msg__ConveyorFeedback__FIELD_NAME__direction[] = "direction";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__msg__ConveyorFeedback__FIELDS[] = {
  {
    {niryo_one_msgs__msg__ConveyorFeedback__FIELD_NAME__conveyor_id, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ConveyorFeedback__FIELD_NAME__connection_state, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ConveyorFeedback__FIELD_NAME__running, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ConveyorFeedback__FIELD_NAME__speed, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ConveyorFeedback__FIELD_NAME__direction, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__msg__ConveyorFeedback__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__msg__ConveyorFeedback__TYPE_NAME, 35, 35},
      {niryo_one_msgs__msg__ConveyorFeedback__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 conveyor_id  # Conveyor ID (either 6 or 7)\n"
  "bool connection_state  # Conveyor connection state (if it is enbled)\n"
  "bool running  # Conveyor controls state: ON or OFF\n"
  "int16 speed  # Conveyor speed (1 -> 100%)\n"
  "int8 direction  # Conveyor direction (backwards or forward)";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__msg__ConveyorFeedback__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__msg__ConveyorFeedback__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 271, 271},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__msg__ConveyorFeedback__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__msg__ConveyorFeedback__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
