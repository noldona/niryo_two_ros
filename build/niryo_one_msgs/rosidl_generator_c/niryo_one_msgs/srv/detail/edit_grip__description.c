// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:srv/EditGrip.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/srv/detail/edit_grip__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__EditGrip__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x15, 0x0d, 0x9f, 0x1a, 0xc3, 0xcd, 0x8e, 0x55,
      0x64, 0x14, 0xe3, 0x9a, 0xb6, 0x8b, 0xa8, 0x36,
      0x34, 0x35, 0xdf, 0xf4, 0x32, 0xcd, 0x0f, 0x77,
      0xbc, 0x9b, 0xc1, 0x30, 0x8b, 0x58, 0x87, 0x73,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__EditGrip_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfb, 0x8b, 0x59, 0xaf, 0x78, 0x64, 0x46, 0xdd,
      0x3f, 0x15, 0x33, 0xee, 0x0e, 0x20, 0x00, 0x89,
      0xc3, 0xe7, 0xec, 0x8f, 0xf3, 0x5f, 0xca, 0x89,
      0x53, 0xd1, 0x83, 0x6f, 0x23, 0xea, 0x66, 0x2b,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__EditGrip_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5b, 0x18, 0xc7, 0xdb, 0x3e, 0x19, 0x3f, 0xf6,
      0xff, 0x8b, 0x26, 0x65, 0x73, 0x35, 0x7b, 0x06,
      0xab, 0xb7, 0xba, 0x99, 0xbb, 0xbf, 0x36, 0x72,
      0xc7, 0xa0, 0x0a, 0x92, 0x5d, 0x3d, 0xd7, 0xb6,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__EditGrip_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x00, 0x84, 0xc4, 0x8a, 0x24, 0x24, 0x25, 0xef,
      0x45, 0x6b, 0x5b, 0xb2, 0x6c, 0x42, 0x03, 0x23,
      0x78, 0xa6, 0x0e, 0xed, 0xd3, 0xb1, 0x26, 0xfb,
      0xb3, 0x91, 0x5d, 0x4b, 0x85, 0xd0, 0xb8, 0xf2,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "niryo_one_msgs/msg/detail/robot_state__functions.h"
#include "niryo_one_msgs/msg/detail/rpy__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
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
static const rosidl_type_hash_t niryo_one_msgs__msg__RobotState__EXPECTED_HASH = {1, {
    0x81, 0x77, 0xe1, 0x14, 0xda, 0x9c, 0x57, 0xb7,
    0x08, 0x6e, 0x53, 0x82, 0xf4, 0xbe, 0x6d, 0x7b,
    0x15, 0x62, 0x8e, 0xf4, 0x6e, 0x93, 0xf0, 0x6c,
    0xdf, 0x1b, 0x2a, 0x41, 0x9b, 0x69, 0xaa, 0x95,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char niryo_one_msgs__srv__EditGrip__TYPE_NAME[] = "niryo_one_msgs/srv/EditGrip";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char niryo_one_msgs__msg__RPY__TYPE_NAME[] = "niryo_one_msgs/msg/RPY";
static char niryo_one_msgs__msg__RobotState__TYPE_NAME[] = "niryo_one_msgs/msg/RobotState";
static char niryo_one_msgs__srv__EditGrip_Event__TYPE_NAME[] = "niryo_one_msgs/srv/EditGrip_Event";
static char niryo_one_msgs__srv__EditGrip_Request__TYPE_NAME[] = "niryo_one_msgs/srv/EditGrip_Request";
static char niryo_one_msgs__srv__EditGrip_Response__TYPE_NAME[] = "niryo_one_msgs/srv/EditGrip_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char niryo_one_msgs__srv__EditGrip__FIELD_NAME__request_message[] = "request_message";
static char niryo_one_msgs__srv__EditGrip__FIELD_NAME__response_message[] = "response_message";
static char niryo_one_msgs__srv__EditGrip__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__EditGrip__FIELDS[] = {
  {
    {niryo_one_msgs__srv__EditGrip__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__EditGrip_Request__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__EditGrip_Response__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__EditGrip_Event__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__EditGrip__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RPY__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RobotState__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip_Event__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip_Request__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip_Response__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__EditGrip__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__EditGrip__TYPE_NAME, 27, 27},
      {niryo_one_msgs__srv__EditGrip__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__EditGrip__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__RPY__EXPECTED_HASH, niryo_one_msgs__msg__RPY__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__msg__RPY__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__RobotState__EXPECTED_HASH, niryo_one_msgs__msg__RobotState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__msg__RobotState__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = niryo_one_msgs__srv__EditGrip_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = niryo_one_msgs__srv__EditGrip_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = niryo_one_msgs__srv__EditGrip_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__EditGrip_Request__FIELD_NAME__cmd[] = "cmd";
static char niryo_one_msgs__srv__EditGrip_Request__FIELD_NAME__name[] = "name";
static char niryo_one_msgs__srv__EditGrip_Request__FIELD_NAME__workspace[] = "workspace";
static char niryo_one_msgs__srv__EditGrip_Request__FIELD_NAME__robot_pose[] = "robot_pose";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__EditGrip_Request__FIELDS[] = {
  {
    {niryo_one_msgs__srv__EditGrip_Request__FIELD_NAME__cmd, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip_Request__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip_Request__FIELD_NAME__workspace, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip_Request__FIELD_NAME__robot_pose, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__msg__RobotState__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__EditGrip_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RPY__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RobotState__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__EditGrip_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__EditGrip_Request__TYPE_NAME, 35, 35},
      {niryo_one_msgs__srv__EditGrip_Request__FIELDS, 4, 4},
    },
    {niryo_one_msgs__srv__EditGrip_Request__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__RPY__EXPECTED_HASH, niryo_one_msgs__msg__RPY__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__msg__RPY__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__RobotState__EXPECTED_HASH, niryo_one_msgs__msg__RobotState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__msg__RobotState__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__EditGrip_Response__FIELD_NAME__status[] = "status";
static char niryo_one_msgs__srv__EditGrip_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__EditGrip_Response__FIELDS[] = {
  {
    {niryo_one_msgs__srv__EditGrip_Response__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip_Response__FIELD_NAME__message, 7, 7},
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
niryo_one_msgs__srv__EditGrip_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__EditGrip_Response__TYPE_NAME, 36, 36},
      {niryo_one_msgs__srv__EditGrip_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__EditGrip_Event__FIELD_NAME__info[] = "info";
static char niryo_one_msgs__srv__EditGrip_Event__FIELD_NAME__request[] = "request";
static char niryo_one_msgs__srv__EditGrip_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__EditGrip_Event__FIELDS[] = {
  {
    {niryo_one_msgs__srv__EditGrip_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__EditGrip_Request__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__EditGrip_Response__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__EditGrip_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RPY__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RobotState__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip_Request__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditGrip_Response__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__EditGrip_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__EditGrip_Event__TYPE_NAME, 33, 33},
      {niryo_one_msgs__srv__EditGrip_Event__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__EditGrip_Event__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__RPY__EXPECTED_HASH, niryo_one_msgs__msg__RPY__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__msg__RPY__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__RobotState__EXPECTED_HASH, niryo_one_msgs__msg__RobotState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__msg__RobotState__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = niryo_one_msgs__srv__EditGrip_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = niryo_one_msgs__srv__EditGrip_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 CREATE = 1\n"
  "int32 REMOVE = -1\n"
  "\n"
  "int32 cmd\n"
  "string name\n"
  "string workspace\n"
  "niryo_one_msgs/RobotState robot_pose\n"
  "---\n"
  "int32 status\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__EditGrip__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__EditGrip__TYPE_NAME, 27, 27},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 144, 144},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__EditGrip_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__EditGrip_Request__TYPE_NAME, 35, 35},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__EditGrip_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__EditGrip_Response__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__EditGrip_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__EditGrip_Event__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__EditGrip__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__EditGrip__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__msg__RPY__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__msg__RobotState__get_individual_type_description_source(NULL);
    sources[5] = *niryo_one_msgs__srv__EditGrip_Event__get_individual_type_description_source(NULL);
    sources[6] = *niryo_one_msgs__srv__EditGrip_Request__get_individual_type_description_source(NULL);
    sources[7] = *niryo_one_msgs__srv__EditGrip_Response__get_individual_type_description_source(NULL);
    sources[8] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__EditGrip_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__EditGrip_Request__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__msg__RPY__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__msg__RobotState__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__EditGrip_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__EditGrip_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__EditGrip_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__EditGrip_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__msg__RPY__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__msg__RobotState__get_individual_type_description_source(NULL);
    sources[5] = *niryo_one_msgs__srv__EditGrip_Request__get_individual_type_description_source(NULL);
    sources[6] = *niryo_one_msgs__srv__EditGrip_Response__get_individual_type_description_source(NULL);
    sources[7] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
