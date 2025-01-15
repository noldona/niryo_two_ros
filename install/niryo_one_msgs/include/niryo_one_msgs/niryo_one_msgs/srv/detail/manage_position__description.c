// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:srv/ManagePosition.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/srv/detail/manage_position__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__ManagePosition__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x99, 0xb7, 0x8b, 0xfb, 0xae, 0x50, 0xcc, 0xb9,
      0xaa, 0x57, 0xdd, 0xd7, 0x9b, 0x6c, 0x99, 0xc1,
      0x78, 0x82, 0xbb, 0x99, 0x22, 0x53, 0x30, 0x36,
      0x15, 0x3d, 0x4a, 0x11, 0xee, 0xed, 0x80, 0xdc,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__ManagePosition_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x40, 0xc2, 0x44, 0xcf, 0x59, 0xc5, 0x7c, 0x3b,
      0xf4, 0xf9, 0x20, 0xba, 0x9c, 0xd7, 0x56, 0x7e,
      0x16, 0x3d, 0x82, 0x03, 0x1c, 0x72, 0xc5, 0x67,
      0xe2, 0x48, 0xab, 0x6f, 0xb4, 0x74, 0xef, 0x2b,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__ManagePosition_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xca, 0x70, 0x9c, 0xeb, 0xf9, 0x1a, 0xbf, 0x79,
      0x60, 0xb1, 0x09, 0x32, 0xfb, 0xd8, 0x1e, 0x17,
      0xc7, 0x67, 0x03, 0xb1, 0x73, 0xd4, 0xbc, 0xf4,
      0xe5, 0x7d, 0x1b, 0xa0, 0x86, 0x6b, 0x47, 0xc3,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__ManagePosition_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc3, 0xc2, 0x5a, 0xd8, 0x34, 0x3c, 0xf6, 0x6e,
      0x76, 0x26, 0xad, 0xdb, 0xa4, 0x34, 0x90, 0xe3,
      0x74, 0x31, 0x57, 0x80, 0x1f, 0x34, 0xc4, 0x04,
      0x14, 0x45, 0x5e, 0xbc, 0xfe, 0x2d, 0xfb, 0xaf,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "niryo_one_msgs/msg/detail/position__functions.h"
#include "niryo_one_msgs/msg/detail/rpy__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"
#include "geometry_msgs/msg/detail/quaternion__functions.h"
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
static const rosidl_type_hash_t geometry_msgs__msg__Quaternion__EXPECTED_HASH = {1, {
    0x8a, 0x76, 0x5f, 0x66, 0x77, 0x8c, 0x8f, 0xf7,
    0xc8, 0xab, 0x94, 0xaf, 0xcc, 0x59, 0x0a, 0x2e,
    0xd5, 0x32, 0x5a, 0x1d, 0x9a, 0x07, 0x6f, 0xff,
    0xf3, 0x8f, 0xbc, 0xe3, 0x6f, 0x45, 0x86, 0x84,
  }};
static const rosidl_type_hash_t niryo_one_msgs__msg__Position__EXPECTED_HASH = {1, {
    0x53, 0xaf, 0xe2, 0xec, 0x6c, 0x8f, 0xa6, 0xcc,
    0xaa, 0xb7, 0xc9, 0xce, 0x75, 0x89, 0x36, 0xae,
    0x1b, 0x83, 0xe2, 0xdc, 0x00, 0xb8, 0xb4, 0x17,
    0x95, 0xc3, 0x9d, 0x90, 0xd0, 0xc0, 0x50, 0x2b,
  }};
static const rosidl_type_hash_t niryo_one_msgs__msg__RPY__EXPECTED_HASH = {1, {
    0x2a, 0xc7, 0x4f, 0xeb, 0xf3, 0x6f, 0x14, 0x2d,
    0xc0, 0xac, 0x04, 0x3f, 0xbf, 0x70, 0x67, 0xaf,
    0x52, 0x5e, 0xc5, 0x1c, 0x06, 0xb3, 0xbe, 0xe5,
    0xeb, 0x05, 0xc5, 0xc6, 0x77, 0x09, 0xd2, 0xda,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char niryo_one_msgs__srv__ManagePosition__TYPE_NAME[] = "niryo_one_msgs/srv/ManagePosition";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char geometry_msgs__msg__Quaternion__TYPE_NAME[] = "geometry_msgs/msg/Quaternion";
static char niryo_one_msgs__msg__Position__TYPE_NAME[] = "niryo_one_msgs/msg/Position";
static char niryo_one_msgs__msg__RPY__TYPE_NAME[] = "niryo_one_msgs/msg/RPY";
static char niryo_one_msgs__srv__ManagePosition_Event__TYPE_NAME[] = "niryo_one_msgs/srv/ManagePosition_Event";
static char niryo_one_msgs__srv__ManagePosition_Request__TYPE_NAME[] = "niryo_one_msgs/srv/ManagePosition_Request";
static char niryo_one_msgs__srv__ManagePosition_Response__TYPE_NAME[] = "niryo_one_msgs/srv/ManagePosition_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char niryo_one_msgs__srv__ManagePosition__FIELD_NAME__request_message[] = "request_message";
static char niryo_one_msgs__srv__ManagePosition__FIELD_NAME__response_message[] = "response_message";
static char niryo_one_msgs__srv__ManagePosition__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__ManagePosition__FIELDS[] = {
  {
    {niryo_one_msgs__srv__ManagePosition__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__ManagePosition_Request__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__ManagePosition_Response__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__ManagePosition_Event__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__ManagePosition__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Quaternion__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__Position__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RPY__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition_Event__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition_Request__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition_Response__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__ManagePosition__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__ManagePosition__TYPE_NAME, 33, 33},
      {niryo_one_msgs__srv__ManagePosition__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__ManagePosition__REFERENCED_TYPE_DESCRIPTIONS, 9, 9},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__Position__EXPECTED_HASH, niryo_one_msgs__msg__Position__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__msg__Position__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__RPY__EXPECTED_HASH, niryo_one_msgs__msg__RPY__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = niryo_one_msgs__msg__RPY__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = niryo_one_msgs__srv__ManagePosition_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = niryo_one_msgs__srv__ManagePosition_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[7].fields = niryo_one_msgs__srv__ManagePosition_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[8].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__ManagePosition_Request__FIELD_NAME__cmd_type[] = "cmd_type";
static char niryo_one_msgs__srv__ManagePosition_Request__FIELD_NAME__position_name[] = "position_name";
static char niryo_one_msgs__srv__ManagePosition_Request__FIELD_NAME__position[] = "position";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__ManagePosition_Request__FIELDS[] = {
  {
    {niryo_one_msgs__srv__ManagePosition_Request__FIELD_NAME__cmd_type, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition_Request__FIELD_NAME__position_name, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition_Request__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__msg__Position__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__ManagePosition_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Quaternion__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__Position__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RPY__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__ManagePosition_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__ManagePosition_Request__TYPE_NAME, 41, 41},
      {niryo_one_msgs__srv__ManagePosition_Request__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__ManagePosition_Request__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__Position__EXPECTED_HASH, niryo_one_msgs__msg__Position__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__msg__Position__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__RPY__EXPECTED_HASH, niryo_one_msgs__msg__RPY__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__msg__RPY__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__ManagePosition_Response__FIELD_NAME__status[] = "status";
static char niryo_one_msgs__srv__ManagePosition_Response__FIELD_NAME__message[] = "message";
static char niryo_one_msgs__srv__ManagePosition_Response__FIELD_NAME__position[] = "position";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__ManagePosition_Response__FIELDS[] = {
  {
    {niryo_one_msgs__srv__ManagePosition_Response__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition_Response__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__msg__Position__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__ManagePosition_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Quaternion__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__Position__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RPY__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__ManagePosition_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__ManagePosition_Response__TYPE_NAME, 42, 42},
      {niryo_one_msgs__srv__ManagePosition_Response__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__ManagePosition_Response__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__Position__EXPECTED_HASH, niryo_one_msgs__msg__Position__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__msg__Position__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__RPY__EXPECTED_HASH, niryo_one_msgs__msg__RPY__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__msg__RPY__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__ManagePosition_Event__FIELD_NAME__info[] = "info";
static char niryo_one_msgs__srv__ManagePosition_Event__FIELD_NAME__request[] = "request";
static char niryo_one_msgs__srv__ManagePosition_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__ManagePosition_Event__FIELDS[] = {
  {
    {niryo_one_msgs__srv__ManagePosition_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__ManagePosition_Request__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__ManagePosition_Response__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__ManagePosition_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Quaternion__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__Position__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__RPY__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition_Request__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ManagePosition_Response__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__ManagePosition_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__ManagePosition_Event__TYPE_NAME, 39, 39},
      {niryo_one_msgs__srv__ManagePosition_Event__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__ManagePosition_Event__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__Position__EXPECTED_HASH, niryo_one_msgs__msg__Position__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__msg__Position__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__RPY__EXPECTED_HASH, niryo_one_msgs__msg__RPY__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = niryo_one_msgs__msg__RPY__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = niryo_one_msgs__srv__ManagePosition_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = niryo_one_msgs__srv__ManagePosition_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 cmd_type\n"
  "\n"
  "string position_name\n"
  "niryo_one_msgs/Position position\n"
  "---\n"
  "int32 status\n"
  "string message\n"
  "\n"
  "niryo_one_msgs/Position position ";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__ManagePosition__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__ManagePosition__TYPE_NAME, 33, 33},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 137, 137},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__ManagePosition_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__ManagePosition_Request__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__ManagePosition_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__ManagePosition_Response__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__ManagePosition_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__ManagePosition_Event__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__ManagePosition__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[10];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 10, 10};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__ManagePosition__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__msg__Position__get_individual_type_description_source(NULL);
    sources[5] = *niryo_one_msgs__msg__RPY__get_individual_type_description_source(NULL);
    sources[6] = *niryo_one_msgs__srv__ManagePosition_Event__get_individual_type_description_source(NULL);
    sources[7] = *niryo_one_msgs__srv__ManagePosition_Request__get_individual_type_description_source(NULL);
    sources[8] = *niryo_one_msgs__srv__ManagePosition_Response__get_individual_type_description_source(NULL);
    sources[9] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__ManagePosition_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__ManagePosition_Request__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__msg__Position__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__msg__RPY__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__ManagePosition_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__ManagePosition_Response__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__msg__Position__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__msg__RPY__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__ManagePosition_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__ManagePosition_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__msg__Position__get_individual_type_description_source(NULL);
    sources[5] = *niryo_one_msgs__msg__RPY__get_individual_type_description_source(NULL);
    sources[6] = *niryo_one_msgs__srv__ManagePosition_Request__get_individual_type_description_source(NULL);
    sources[7] = *niryo_one_msgs__srv__ManagePosition_Response__get_individual_type_description_source(NULL);
    sources[8] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
