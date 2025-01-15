// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:srv/ObjDetection.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/srv/detail/obj_detection__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__ObjDetection__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x74, 0xcd, 0x07, 0x0c, 0x15, 0xc8, 0x9d, 0xa5,
      0xfb, 0xa4, 0x7c, 0x64, 0x60, 0xbc, 0x9c, 0xfc,
      0x38, 0x00, 0x42, 0xd4, 0xfa, 0x70, 0xdf, 0x81,
      0x83, 0x0e, 0x53, 0x2f, 0xd7, 0xa8, 0xba, 0xd2,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__ObjDetection_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x32, 0x93, 0x44, 0x20, 0xe4, 0xc0, 0xc3, 0x26,
      0x28, 0x53, 0xa9, 0x15, 0xcb, 0x4f, 0x6d, 0xb5,
      0x6c, 0x7a, 0x7d, 0xa7, 0xd2, 0x4a, 0xf6, 0x1e,
      0x9a, 0x0c, 0x00, 0x79, 0xdf, 0xbb, 0x1a, 0xd1,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__ObjDetection_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xae, 0x82, 0x4d, 0xf4, 0x9b, 0x63, 0x82, 0x50,
      0x81, 0x76, 0x6b, 0xe0, 0xdf, 0xf5, 0x97, 0xb7,
      0xec, 0x7e, 0xf7, 0x15, 0x8e, 0x68, 0xc8, 0x23,
      0xb6, 0x93, 0x81, 0xf3, 0x46, 0x26, 0xc6, 0x1e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__ObjDetection_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x41, 0x3e, 0xf5, 0x01, 0x90, 0x1c, 0x26, 0x50,
      0x94, 0x4e, 0xdf, 0x43, 0x1b, 0x2c, 0x0d, 0x97,
      0x69, 0xee, 0x5d, 0xe3, 0x86, 0xb0, 0xf6, 0x66,
      0x67, 0xc4, 0xf0, 0xfa, 0x4c, 0x02, 0x87, 0x35,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/header__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "niryo_one_msgs/msg/detail/object_pose__functions.h"
#include "sensor_msgs/msg/detail/compressed_image__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t niryo_one_msgs__msg__ObjectPose__EXPECTED_HASH = {1, {
    0x29, 0x33, 0x35, 0xe8, 0xe1, 0xa1, 0x36, 0x03,
    0x3b, 0xd5, 0x30, 0xb9, 0x9b, 0xd6, 0x90, 0xfe,
    0xea, 0xf0, 0x34, 0xa6, 0x38, 0x88, 0x6e, 0xd6,
    0x98, 0xdc, 0x8a, 0x31, 0xb0, 0x3b, 0x4b, 0x92,
  }};
static const rosidl_type_hash_t sensor_msgs__msg__CompressedImage__EXPECTED_HASH = {1, {
    0x15, 0x64, 0x07, 0x71, 0x53, 0x15, 0x71, 0x18,
    0x5e, 0x2e, 0xfc, 0x8a, 0x10, 0x0b, 0xaf, 0x92,
    0x39, 0x61, 0xa4, 0xd1, 0x5d, 0x55, 0x69, 0x65,
    0x2e, 0x6c, 0xb6, 0x69, 0x1e, 0x8e, 0x37, 0x1a,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char niryo_one_msgs__srv__ObjDetection__TYPE_NAME[] = "niryo_one_msgs/srv/ObjDetection";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char niryo_one_msgs__msg__ObjectPose__TYPE_NAME[] = "niryo_one_msgs/msg/ObjectPose";
static char niryo_one_msgs__srv__ObjDetection_Event__TYPE_NAME[] = "niryo_one_msgs/srv/ObjDetection_Event";
static char niryo_one_msgs__srv__ObjDetection_Request__TYPE_NAME[] = "niryo_one_msgs/srv/ObjDetection_Request";
static char niryo_one_msgs__srv__ObjDetection_Response__TYPE_NAME[] = "niryo_one_msgs/srv/ObjDetection_Response";
static char sensor_msgs__msg__CompressedImage__TYPE_NAME[] = "sensor_msgs/msg/CompressedImage";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char niryo_one_msgs__srv__ObjDetection__FIELD_NAME__request_message[] = "request_message";
static char niryo_one_msgs__srv__ObjDetection__FIELD_NAME__response_message[] = "response_message";
static char niryo_one_msgs__srv__ObjDetection__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__ObjDetection__FIELDS[] = {
  {
    {niryo_one_msgs__srv__ObjDetection__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__ObjDetection_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__ObjDetection_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__ObjDetection_Event__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__ObjDetection__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ObjectPose__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Event__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__CompressedImage__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__ObjDetection__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__ObjDetection__TYPE_NAME, 31, 31},
      {niryo_one_msgs__srv__ObjDetection__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__ObjDetection__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__ObjectPose__EXPECTED_HASH, niryo_one_msgs__msg__ObjectPose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__msg__ObjectPose__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__srv__ObjDetection_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__srv__ObjDetection_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = niryo_one_msgs__srv__ObjDetection_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__CompressedImage__EXPECTED_HASH, sensor_msgs__msg__CompressedImage__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = sensor_msgs__msg__CompressedImage__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__ObjDetection_Request__FIELD_NAME__obj_type[] = "obj_type";
static char niryo_one_msgs__srv__ObjDetection_Request__FIELD_NAME__obj_color[] = "obj_color";
static char niryo_one_msgs__srv__ObjDetection_Request__FIELD_NAME__workspace_ratio[] = "workspace_ratio";
static char niryo_one_msgs__srv__ObjDetection_Request__FIELD_NAME__ret_image[] = "ret_image";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__ObjDetection_Request__FIELDS[] = {
  {
    {niryo_one_msgs__srv__ObjDetection_Request__FIELD_NAME__obj_type, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Request__FIELD_NAME__obj_color, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Request__FIELD_NAME__workspace_ratio, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Request__FIELD_NAME__ret_image, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__ObjDetection_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__ObjDetection_Request__TYPE_NAME, 39, 39},
      {niryo_one_msgs__srv__ObjDetection_Request__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__ObjDetection_Response__FIELD_NAME__status[] = "status";
static char niryo_one_msgs__srv__ObjDetection_Response__FIELD_NAME__obj_pose[] = "obj_pose";
static char niryo_one_msgs__srv__ObjDetection_Response__FIELD_NAME__obj_type[] = "obj_type";
static char niryo_one_msgs__srv__ObjDetection_Response__FIELD_NAME__obj_color[] = "obj_color";
static char niryo_one_msgs__srv__ObjDetection_Response__FIELD_NAME__img[] = "img";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__ObjDetection_Response__FIELDS[] = {
  {
    {niryo_one_msgs__srv__ObjDetection_Response__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Response__FIELD_NAME__obj_pose, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__msg__ObjectPose__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Response__FIELD_NAME__obj_type, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Response__FIELD_NAME__obj_color, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Response__FIELD_NAME__img, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {sensor_msgs__msg__CompressedImage__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__ObjDetection_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ObjectPose__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__CompressedImage__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__ObjDetection_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__ObjDetection_Response__TYPE_NAME, 40, 40},
      {niryo_one_msgs__srv__ObjDetection_Response__FIELDS, 5, 5},
    },
    {niryo_one_msgs__srv__ObjDetection_Response__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__ObjectPose__EXPECTED_HASH, niryo_one_msgs__msg__ObjectPose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__msg__ObjectPose__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__CompressedImage__EXPECTED_HASH, sensor_msgs__msg__CompressedImage__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = sensor_msgs__msg__CompressedImage__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__ObjDetection_Event__FIELD_NAME__info[] = "info";
static char niryo_one_msgs__srv__ObjDetection_Event__FIELD_NAME__request[] = "request";
static char niryo_one_msgs__srv__ObjDetection_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__ObjDetection_Event__FIELDS[] = {
  {
    {niryo_one_msgs__srv__ObjDetection_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__ObjDetection_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__ObjDetection_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__ObjDetection_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__ObjectPose__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__ObjDetection_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__CompressedImage__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__ObjDetection_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__ObjDetection_Event__TYPE_NAME, 37, 37},
      {niryo_one_msgs__srv__ObjDetection_Event__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__ObjDetection_Event__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__ObjectPose__EXPECTED_HASH, niryo_one_msgs__msg__ObjectPose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__msg__ObjectPose__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__srv__ObjDetection_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__srv__ObjDetection_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__CompressedImage__EXPECTED_HASH, sensor_msgs__msg__CompressedImage__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = sensor_msgs__msg__CompressedImage__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string obj_type\n"
  "string obj_color\n"
  "float32 workspace_ratio\n"
  "bool ret_image\n"
  "---\n"
  "int32 status\n"
  "int32 SUCCESSFUL = 1\n"
  "int32 VIDEO_STREAM_NOT_RUNNING = -1\n"
  "int32 OBJECT_NOT_FOUND = -2\n"
  "int32 MARKERS_NOT_FOUND = -3\n"
  "\n"
  "niryo_one_msgs/ObjectPose obj_pose\n"
  "\n"
  "string obj_type\n"
  "string obj_color\n"
  "\n"
  "sensor_msgs/CompressedImage img";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__ObjDetection__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__ObjDetection__TYPE_NAME, 31, 31},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 306, 306},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__ObjDetection_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__ObjDetection_Request__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__ObjDetection_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__ObjDetection_Response__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__ObjDetection_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__ObjDetection_Event__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__ObjDetection__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__ObjDetection__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__msg__ObjectPose__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__srv__ObjDetection_Event__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__srv__ObjDetection_Request__get_individual_type_description_source(NULL);
    sources[5] = *niryo_one_msgs__srv__ObjDetection_Response__get_individual_type_description_source(NULL);
    sources[6] = *sensor_msgs__msg__CompressedImage__get_individual_type_description_source(NULL);
    sources[7] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[8] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__ObjDetection_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__ObjDetection_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__ObjDetection_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__ObjDetection_Response__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__msg__ObjectPose__get_individual_type_description_source(NULL);
    sources[3] = *sensor_msgs__msg__CompressedImage__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__ObjDetection_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__ObjDetection_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__msg__ObjectPose__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__srv__ObjDetection_Request__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__srv__ObjDetection_Response__get_individual_type_description_source(NULL);
    sources[5] = *sensor_msgs__msg__CompressedImage__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[7] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
