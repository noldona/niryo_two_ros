// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:srv/GetInt.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/srv/detail/get_int__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__GetInt__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x06, 0x36, 0x5c, 0xea, 0x11, 0x17, 0xfa, 0xe5,
      0xa9, 0xae, 0xd6, 0x77, 0x03, 0x12, 0x11, 0x89,
      0x68, 0x55, 0x08, 0xb6, 0x71, 0x49, 0xa3, 0x5c,
      0x10, 0xc8, 0x32, 0x0c, 0x7f, 0xa6, 0x48, 0xa2,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__GetInt_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x27, 0x03, 0xdd, 0xcf, 0x7d, 0x2e, 0x54, 0xa7,
      0x1d, 0x0d, 0xf8, 0x96, 0x52, 0xe3, 0x28, 0xad,
      0xbe, 0x40, 0x70, 0xe6, 0x29, 0x13, 0xe3, 0x3f,
      0x87, 0xe0, 0xbd, 0x92, 0x08, 0xbf, 0x2a, 0xb5,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__GetInt_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x6f, 0x54, 0x79, 0xb8, 0x4c, 0xb3, 0x02, 0xb5,
      0xfb, 0xb4, 0x2c, 0x18, 0x32, 0xb6, 0xce, 0x54,
      0xa7, 0x6c, 0x6e, 0x52, 0xf2, 0xfc, 0xce, 0x84,
      0xfe, 0xd4, 0x06, 0xaf, 0x60, 0x92, 0x98, 0x90,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__GetInt_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x4c, 0x06, 0x02, 0xc7, 0x04, 0x84, 0xb2, 0x2a,
      0xe6, 0x82, 0x21, 0x1b, 0x1a, 0xdf, 0x0f, 0x4c,
      0x44, 0x27, 0x32, 0x2b, 0xb7, 0x47, 0xb4, 0xf1,
      0xa5, 0x05, 0xcf, 0x3a, 0x19, 0x6a, 0x1f, 0x74,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
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
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char niryo_one_msgs__srv__GetInt__TYPE_NAME[] = "niryo_one_msgs/srv/GetInt";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char niryo_one_msgs__srv__GetInt_Event__TYPE_NAME[] = "niryo_one_msgs/srv/GetInt_Event";
static char niryo_one_msgs__srv__GetInt_Request__TYPE_NAME[] = "niryo_one_msgs/srv/GetInt_Request";
static char niryo_one_msgs__srv__GetInt_Response__TYPE_NAME[] = "niryo_one_msgs/srv/GetInt_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char niryo_one_msgs__srv__GetInt__FIELD_NAME__request_message[] = "request_message";
static char niryo_one_msgs__srv__GetInt__FIELD_NAME__response_message[] = "response_message";
static char niryo_one_msgs__srv__GetInt__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__GetInt__FIELDS[] = {
  {
    {niryo_one_msgs__srv__GetInt__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__GetInt_Request__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetInt__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__GetInt_Response__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetInt__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__GetInt_Event__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__GetInt__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetInt_Event__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetInt_Request__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetInt_Response__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__GetInt__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__GetInt__TYPE_NAME, 25, 25},
      {niryo_one_msgs__srv__GetInt__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__GetInt__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__srv__GetInt_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__srv__GetInt_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__srv__GetInt_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__GetInt_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__GetInt_Request__FIELDS[] = {
  {
    {niryo_one_msgs__srv__GetInt_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__GetInt_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__GetInt_Request__TYPE_NAME, 33, 33},
      {niryo_one_msgs__srv__GetInt_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__GetInt_Response__FIELD_NAME__value[] = "value";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__GetInt_Response__FIELDS[] = {
  {
    {niryo_one_msgs__srv__GetInt_Response__FIELD_NAME__value, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__GetInt_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__GetInt_Response__TYPE_NAME, 34, 34},
      {niryo_one_msgs__srv__GetInt_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__GetInt_Event__FIELD_NAME__info[] = "info";
static char niryo_one_msgs__srv__GetInt_Event__FIELD_NAME__request[] = "request";
static char niryo_one_msgs__srv__GetInt_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__GetInt_Event__FIELDS[] = {
  {
    {niryo_one_msgs__srv__GetInt_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetInt_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__GetInt_Request__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetInt_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__GetInt_Response__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__GetInt_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetInt_Request__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetInt_Response__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__GetInt_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__GetInt_Event__TYPE_NAME, 31, 31},
      {niryo_one_msgs__srv__GetInt_Event__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__GetInt_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__srv__GetInt_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__srv__GetInt_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "int32 value";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__GetInt__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__GetInt__TYPE_NAME, 25, 25},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 16, 16},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__GetInt_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__GetInt_Request__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__GetInt_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__GetInt_Response__TYPE_NAME, 34, 34},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__GetInt_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__GetInt_Event__TYPE_NAME, 31, 31},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__GetInt__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__GetInt__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__srv__GetInt_Event__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__srv__GetInt_Request__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__srv__GetInt_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__GetInt_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__GetInt_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__GetInt_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__GetInt_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__GetInt_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__GetInt_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__srv__GetInt_Request__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__srv__GetInt_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
