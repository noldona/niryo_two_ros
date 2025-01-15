// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:srv/SetSequenceAutorun.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/srv/detail/set_sequence_autorun__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__SetSequenceAutorun__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xda, 0x5b, 0x45, 0x09, 0x7d, 0x1d, 0x30, 0xbf,
      0xb2, 0x5c, 0xf8, 0xf3, 0x0d, 0x81, 0x0e, 0xd8,
      0xb3, 0x9a, 0x64, 0x65, 0xfa, 0x40, 0xab, 0x28,
      0xe7, 0x0e, 0x29, 0x47, 0xfa, 0x71, 0x67, 0xfa,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__SetSequenceAutorun_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0f, 0x28, 0xc2, 0x42, 0xbe, 0x52, 0x75, 0x07,
      0xad, 0x80, 0x85, 0x98, 0x16, 0x4b, 0xcd, 0x2a,
      0x27, 0x4b, 0x86, 0x6c, 0x22, 0xb5, 0xab, 0xc4,
      0x0c, 0xeb, 0xed, 0x66, 0xc5, 0x52, 0x8b, 0x44,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__SetSequenceAutorun_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xab, 0xb7, 0x8e, 0x5b, 0xae, 0x83, 0x53, 0x07,
      0x32, 0x89, 0x10, 0xd6, 0x9d, 0xec, 0xfe, 0x9b,
      0x96, 0xe1, 0xaa, 0x55, 0x36, 0xc6, 0x77, 0x8c,
      0x7d, 0x92, 0x54, 0x61, 0x18, 0x38, 0x17, 0x12,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__SetSequenceAutorun_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x94, 0x22, 0x9a, 0xa8, 0xe3, 0x19, 0x4f, 0xdd,
      0x2e, 0x79, 0x06, 0x5e, 0x11, 0xca, 0x86, 0x52,
      0xbc, 0x8a, 0x01, 0x36, 0xef, 0xf7, 0x84, 0x1c,
      0x3b, 0xc4, 0xda, 0xc0, 0x9c, 0xa3, 0x28, 0x89,
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

static char niryo_one_msgs__srv__SetSequenceAutorun__TYPE_NAME[] = "niryo_one_msgs/srv/SetSequenceAutorun";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char niryo_one_msgs__srv__SetSequenceAutorun_Event__TYPE_NAME[] = "niryo_one_msgs/srv/SetSequenceAutorun_Event";
static char niryo_one_msgs__srv__SetSequenceAutorun_Request__TYPE_NAME[] = "niryo_one_msgs/srv/SetSequenceAutorun_Request";
static char niryo_one_msgs__srv__SetSequenceAutorun_Response__TYPE_NAME[] = "niryo_one_msgs/srv/SetSequenceAutorun_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char niryo_one_msgs__srv__SetSequenceAutorun__FIELD_NAME__request_message[] = "request_message";
static char niryo_one_msgs__srv__SetSequenceAutorun__FIELD_NAME__response_message[] = "response_message";
static char niryo_one_msgs__srv__SetSequenceAutorun__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__SetSequenceAutorun__FIELDS[] = {
  {
    {niryo_one_msgs__srv__SetSequenceAutorun__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__SetSequenceAutorun_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetSequenceAutorun__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__SetSequenceAutorun_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetSequenceAutorun__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__SetSequenceAutorun_Event__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__SetSequenceAutorun__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Event__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__SetSequenceAutorun__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__SetSequenceAutorun__TYPE_NAME, 37, 37},
      {niryo_one_msgs__srv__SetSequenceAutorun__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__SetSequenceAutorun__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__srv__SetSequenceAutorun_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__srv__SetSequenceAutorun_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__srv__SetSequenceAutorun_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__SetSequenceAutorun_Request__FIELD_NAME__enable[] = "enable";
static char niryo_one_msgs__srv__SetSequenceAutorun_Request__FIELD_NAME__mode[] = "mode";
static char niryo_one_msgs__srv__SetSequenceAutorun_Request__FIELD_NAME__sequence_ids[] = "sequence_ids";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__SetSequenceAutorun_Request__FIELDS[] = {
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Request__FIELD_NAME__enable, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Request__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Request__FIELD_NAME__sequence_ids, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__SetSequenceAutorun_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__SetSequenceAutorun_Request__TYPE_NAME, 45, 45},
      {niryo_one_msgs__srv__SetSequenceAutorun_Request__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__SetSequenceAutorun_Response__FIELD_NAME__status[] = "status";
static char niryo_one_msgs__srv__SetSequenceAutorun_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__SetSequenceAutorun_Response__FIELDS[] = {
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Response__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Response__FIELD_NAME__message, 7, 7},
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
niryo_one_msgs__srv__SetSequenceAutorun_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__SetSequenceAutorun_Response__TYPE_NAME, 46, 46},
      {niryo_one_msgs__srv__SetSequenceAutorun_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__SetSequenceAutorun_Event__FIELD_NAME__info[] = "info";
static char niryo_one_msgs__srv__SetSequenceAutorun_Event__FIELD_NAME__request[] = "request";
static char niryo_one_msgs__srv__SetSequenceAutorun_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__SetSequenceAutorun_Event__FIELDS[] = {
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__SetSequenceAutorun_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__SetSequenceAutorun_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__SetSequenceAutorun_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetSequenceAutorun_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__SetSequenceAutorun_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__SetSequenceAutorun_Event__TYPE_NAME, 43, 43},
      {niryo_one_msgs__srv__SetSequenceAutorun_Event__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__SetSequenceAutorun_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__srv__SetSequenceAutorun_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__srv__SetSequenceAutorun_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool enable\n"
  "int32 mode\n"
  "int32[] sequence_ids\n"
  "---\n"
  "int32 status\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__SetSequenceAutorun__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__SetSequenceAutorun__TYPE_NAME, 37, 37},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 76, 76},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__SetSequenceAutorun_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__SetSequenceAutorun_Request__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__SetSequenceAutorun_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__SetSequenceAutorun_Response__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__SetSequenceAutorun_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__SetSequenceAutorun_Event__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__SetSequenceAutorun__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__SetSequenceAutorun__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__srv__SetSequenceAutorun_Event__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__srv__SetSequenceAutorun_Request__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__srv__SetSequenceAutorun_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__SetSequenceAutorun_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__SetSequenceAutorun_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__SetSequenceAutorun_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__SetSequenceAutorun_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__SetSequenceAutorun_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__SetSequenceAutorun_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__srv__SetSequenceAutorun_Request__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__srv__SetSequenceAutorun_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
