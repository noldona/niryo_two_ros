// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/msg/detail/robot_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__msg__RobotState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x81, 0x77, 0xe1, 0x14, 0xda, 0x9c, 0x57, 0xb7,
      0x08, 0x6e, 0x53, 0x82, 0xf4, 0xbe, 0x6d, 0x7b,
      0x15, 0x62, 0x8e, 0xf4, 0x6e, 0x93, 0xf0, 0x6c,
      0xdf, 0x1b, 0x2a, 0x41, 0x9b, 0x69, 0xaa, 0x95,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "niryo_one_msgs/msg/detail/rpy__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t niryo_one_msgs__msg__RPY__EXPECTED_HASH = {1, {
    0x2a, 0xc7, 0x4f, 0xeb, 0xf3, 0x6f, 0x14, 0x2d,
    0xc0, 0xac, 0x04, 0x3f, 0xbf, 0x70, 0x67, 0xaf,
    0x52, 0x5e, 0xc5, 0x1c, 0x06, 0xb3, 0xbe, 0xe5,
    0xeb, 0x05, 0xc5, 0xc6, 0x77, 0x09, 0xd2, 0xda,
  }};
#endif

static char niryo_one_msgs__msg__RobotState__TYPE_NAME[] = "niryo_one_msgs/msg/RobotState";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char niryo_one_msgs__msg__RPY__TYPE_NAME[] = "niryo_one_msgs/msg/RPY";

// Define type names, field names, and default values
static char niryo_one_msgs__msg__RobotState__FIELD_NAME__position[] = "position";
static char niryo_one_msgs__msg__RobotState__FIELD_NAME__rpy[] = "rpy";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__msg__RobotState__FIELDS[] = {
  {
    {niryo_one_msgs__msg__RobotState__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RobotState__FIELD_NAME__rpy, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__msg__RPY__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__msg__RobotState__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RPY__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__msg__RobotState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__msg__RobotState__TYPE_NAME, 29, 29},
      {niryo_one_msgs__msg__RobotState__FIELDS, 2, 2},
    },
    {niryo_one_msgs__msg__RobotState__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__RPY__EXPECTED_HASH, niryo_one_msgs__msg__RPY__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__msg__RPY__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "geometry_msgs/Point position\n"
  "niryo_one_msgs/RPY rpy";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__msg__RobotState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__msg__RobotState__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 52, 52},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__msg__RobotState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__msg__RobotState__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__msg__RPY__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
