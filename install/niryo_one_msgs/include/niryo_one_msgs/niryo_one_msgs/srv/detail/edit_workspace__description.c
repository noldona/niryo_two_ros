// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:srv/EditWorkspace.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/srv/detail/edit_workspace__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__EditWorkspace__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa3, 0x99, 0x8d, 0x40, 0xab, 0xbe, 0xd8, 0x6e,
      0x98, 0xa7, 0x10, 0x3a, 0x78, 0x39, 0x6a, 0x8d,
      0x7f, 0xb2, 0x2d, 0x47, 0x82, 0x1b, 0x6a, 0x12,
      0xa5, 0xe6, 0xf4, 0xe6, 0x60, 0x66, 0x7d, 0xa8,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__EditWorkspace_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb6, 0xc7, 0x11, 0x18, 0x31, 0xc2, 0x81, 0xa9,
      0x68, 0x05, 0xc6, 0xec, 0x44, 0xfa, 0x99, 0x4d,
      0xf2, 0x43, 0xa7, 0xcd, 0x8c, 0xa0, 0xa8, 0x09,
      0xc8, 0x1b, 0x7d, 0xd3, 0x43, 0xf3, 0x07, 0x70,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__EditWorkspace_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd9, 0x31, 0x34, 0xe1, 0x5c, 0xf9, 0xb8, 0x36,
      0x42, 0xda, 0x17, 0x5d, 0x17, 0xb0, 0xcb, 0x85,
      0x52, 0x47, 0x97, 0xbf, 0x33, 0xfa, 0x9b, 0x96,
      0xf9, 0x47, 0x3d, 0xfd, 0x29, 0x8e, 0x1f, 0x88,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__EditWorkspace_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xbb, 0x05, 0x22, 0x3b, 0x66, 0x40, 0xeb, 0x1b,
      0x59, 0x72, 0xa5, 0xb7, 0xe6, 0x09, 0xef, 0x7e,
      0xa6, 0xb2, 0x09, 0x5d, 0x14, 0x0b, 0x4e, 0xf5,
      0x59, 0x4c, 0xca, 0x60, 0x64, 0xc1, 0xb6, 0x6a,
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

static char niryo_one_msgs__srv__EditWorkspace__TYPE_NAME[] = "niryo_one_msgs/srv/EditWorkspace";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char niryo_one_msgs__msg__RPY__TYPE_NAME[] = "niryo_one_msgs/msg/RPY";
static char niryo_one_msgs__msg__RobotState__TYPE_NAME[] = "niryo_one_msgs/msg/RobotState";
static char niryo_one_msgs__srv__EditWorkspace_Event__TYPE_NAME[] = "niryo_one_msgs/srv/EditWorkspace_Event";
static char niryo_one_msgs__srv__EditWorkspace_Request__TYPE_NAME[] = "niryo_one_msgs/srv/EditWorkspace_Request";
static char niryo_one_msgs__srv__EditWorkspace_Response__TYPE_NAME[] = "niryo_one_msgs/srv/EditWorkspace_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char niryo_one_msgs__srv__EditWorkspace__FIELD_NAME__request_message[] = "request_message";
static char niryo_one_msgs__srv__EditWorkspace__FIELD_NAME__response_message[] = "response_message";
static char niryo_one_msgs__srv__EditWorkspace__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__EditWorkspace__FIELDS[] = {
  {
    {niryo_one_msgs__srv__EditWorkspace__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__EditWorkspace_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__EditWorkspace_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__EditWorkspace_Event__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__EditWorkspace__REFERENCED_TYPE_DESCRIPTIONS[] = {
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
    {niryo_one_msgs__srv__EditWorkspace_Event__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__EditWorkspace__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__EditWorkspace__TYPE_NAME, 32, 32},
      {niryo_one_msgs__srv__EditWorkspace__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__EditWorkspace__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
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
    description.referenced_type_descriptions.data[4].fields = niryo_one_msgs__srv__EditWorkspace_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = niryo_one_msgs__srv__EditWorkspace_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = niryo_one_msgs__srv__EditWorkspace_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__EditWorkspace_Request__FIELD_NAME__cmd[] = "cmd";
static char niryo_one_msgs__srv__EditWorkspace_Request__FIELD_NAME__name[] = "name";
static char niryo_one_msgs__srv__EditWorkspace_Request__FIELD_NAME__pose_origin[] = "pose_origin";
static char niryo_one_msgs__srv__EditWorkspace_Request__FIELD_NAME__pose_1[] = "pose_1";
static char niryo_one_msgs__srv__EditWorkspace_Request__FIELD_NAME__pose_2[] = "pose_2";
static char niryo_one_msgs__srv__EditWorkspace_Request__FIELD_NAME__pose_3[] = "pose_3";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__EditWorkspace_Request__FIELDS[] = {
  {
    {niryo_one_msgs__srv__EditWorkspace_Request__FIELD_NAME__cmd, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace_Request__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace_Request__FIELD_NAME__pose_origin, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__msg__RobotState__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace_Request__FIELD_NAME__pose_1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__msg__RobotState__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace_Request__FIELD_NAME__pose_2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__msg__RobotState__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace_Request__FIELD_NAME__pose_3, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__msg__RobotState__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__EditWorkspace_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
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
niryo_one_msgs__srv__EditWorkspace_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__EditWorkspace_Request__TYPE_NAME, 40, 40},
      {niryo_one_msgs__srv__EditWorkspace_Request__FIELDS, 6, 6},
    },
    {niryo_one_msgs__srv__EditWorkspace_Request__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
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
static char niryo_one_msgs__srv__EditWorkspace_Response__FIELD_NAME__status[] = "status";
static char niryo_one_msgs__srv__EditWorkspace_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__EditWorkspace_Response__FIELDS[] = {
  {
    {niryo_one_msgs__srv__EditWorkspace_Response__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace_Response__FIELD_NAME__message, 7, 7},
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
niryo_one_msgs__srv__EditWorkspace_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__EditWorkspace_Response__TYPE_NAME, 41, 41},
      {niryo_one_msgs__srv__EditWorkspace_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__EditWorkspace_Event__FIELD_NAME__info[] = "info";
static char niryo_one_msgs__srv__EditWorkspace_Event__FIELD_NAME__request[] = "request";
static char niryo_one_msgs__srv__EditWorkspace_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__EditWorkspace_Event__FIELDS[] = {
  {
    {niryo_one_msgs__srv__EditWorkspace_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__EditWorkspace_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__EditWorkspace_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__EditWorkspace_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
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
    {niryo_one_msgs__srv__EditWorkspace_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__EditWorkspace_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__EditWorkspace_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__EditWorkspace_Event__TYPE_NAME, 38, 38},
      {niryo_one_msgs__srv__EditWorkspace_Event__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__EditWorkspace_Event__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
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
    description.referenced_type_descriptions.data[4].fields = niryo_one_msgs__srv__EditWorkspace_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = niryo_one_msgs__srv__EditWorkspace_Response__get_type_description(NULL)->type_description.fields;
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
  "niryo_one_msgs/RobotState pose_origin\n"
  "niryo_one_msgs/RobotState pose_1\n"
  "niryo_one_msgs/RobotState pose_2\n"
  "niryo_one_msgs/RobotState pose_3\n"
  "---\n"
  "int32 status\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__EditWorkspace__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__EditWorkspace__TYPE_NAME, 32, 32},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 227, 227},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__EditWorkspace_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__EditWorkspace_Request__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__EditWorkspace_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__EditWorkspace_Response__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__EditWorkspace_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__EditWorkspace_Event__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__EditWorkspace__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__EditWorkspace__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__msg__RPY__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__msg__RobotState__get_individual_type_description_source(NULL);
    sources[5] = *niryo_one_msgs__srv__EditWorkspace_Event__get_individual_type_description_source(NULL);
    sources[6] = *niryo_one_msgs__srv__EditWorkspace_Request__get_individual_type_description_source(NULL);
    sources[7] = *niryo_one_msgs__srv__EditWorkspace_Response__get_individual_type_description_source(NULL);
    sources[8] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__EditWorkspace_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__EditWorkspace_Request__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__msg__RPY__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__msg__RobotState__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__EditWorkspace_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__EditWorkspace_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__EditWorkspace_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__EditWorkspace_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__msg__RPY__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__msg__RobotState__get_individual_type_description_source(NULL);
    sources[5] = *niryo_one_msgs__srv__EditWorkspace_Request__get_individual_type_description_source(NULL);
    sources[6] = *niryo_one_msgs__srv__EditWorkspace_Response__get_individual_type_description_source(NULL);
    sources[7] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
