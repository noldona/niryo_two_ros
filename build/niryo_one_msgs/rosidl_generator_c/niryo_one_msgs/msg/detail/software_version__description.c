// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:msg/SoftwareVersion.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/msg/detail/software_version__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__msg__SoftwareVersion__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1f, 0x7d, 0x3a, 0xb4, 0x8b, 0x58, 0x48, 0x91,
      0xfa, 0x54, 0x06, 0xf7, 0xf2, 0x33, 0x7b, 0x98,
      0xec, 0x3c, 0x75, 0x51, 0xed, 0x47, 0x2b, 0x66,
      0x36, 0x67, 0x2c, 0x68, 0xb8, 0xd8, 0xcf, 0xef,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char niryo_one_msgs__msg__SoftwareVersion__TYPE_NAME[] = "niryo_one_msgs/msg/SoftwareVersion";

// Define type names, field names, and default values
static char niryo_one_msgs__msg__SoftwareVersion__FIELD_NAME__rpi_image_version[] = "rpi_image_version";
static char niryo_one_msgs__msg__SoftwareVersion__FIELD_NAME__ros_niryo_one_version[] = "ros_niryo_one_version";
static char niryo_one_msgs__msg__SoftwareVersion__FIELD_NAME__motor_names[] = "motor_names";
static char niryo_one_msgs__msg__SoftwareVersion__FIELD_NAME__stepper_firmware_versions[] = "stepper_firmware_versions";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__msg__SoftwareVersion__FIELDS[] = {
  {
    {niryo_one_msgs__msg__SoftwareVersion__FIELD_NAME__rpi_image_version, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__SoftwareVersion__FIELD_NAME__ros_niryo_one_version, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__SoftwareVersion__FIELD_NAME__motor_names, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__SoftwareVersion__FIELD_NAME__stepper_firmware_versions, 25, 25},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__msg__SoftwareVersion__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__msg__SoftwareVersion__TYPE_NAME, 34, 34},
      {niryo_one_msgs__msg__SoftwareVersion__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string rpi_image_version\n"
  "string ros_niryo_one_version\n"
  "\n"
  "string[] motor_names\n"
  "string[] stepper_firmware_versions";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__msg__SoftwareVersion__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__msg__SoftwareVersion__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 111, 111},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__msg__SoftwareVersion__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__msg__SoftwareVersion__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
