// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:srv/GetSequenceList.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/srv/detail/get_sequence_list__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__GetSequenceList__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf1, 0x0b, 0xca, 0x19, 0x69, 0xa9, 0x1c, 0x52,
      0x5b, 0xf6, 0x5a, 0xa8, 0x50, 0x88, 0x5d, 0x45,
      0x0d, 0x4f, 0xb6, 0x6c, 0xdf, 0x6a, 0x28, 0x6d,
      0x7b, 0x88, 0x41, 0xa1, 0xa8, 0x02, 0x1c, 0x51,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__GetSequenceList_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x15, 0xcd, 0x80, 0x41, 0x4e, 0xa3, 0xab, 0x20,
      0x1e, 0xab, 0x07, 0xcf, 0x25, 0xc1, 0x4d, 0x50,
      0xd0, 0xf0, 0x9e, 0x4a, 0xbe, 0x07, 0x2d, 0xc7,
      0xed, 0xcc, 0x58, 0xfc, 0x10, 0x21, 0xfe, 0x73,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__GetSequenceList_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x06, 0x5c, 0xac, 0x42, 0x83, 0x1e, 0x70, 0x48,
      0x15, 0x54, 0xd1, 0x0d, 0x0e, 0xc7, 0xa1, 0x50,
      0xdd, 0x5e, 0x2a, 0x74, 0x48, 0x02, 0x68, 0x6b,
      0xfb, 0x2b, 0x89, 0x0a, 0x0a, 0x21, 0xf0, 0x04,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__GetSequenceList_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x23, 0x99, 0x49, 0x94, 0xf8, 0x98, 0xb5, 0xd3,
      0x22, 0xf6, 0x21, 0xe0, 0x11, 0xd1, 0x59, 0xa0,
      0xc5, 0xff, 0x54, 0xc9, 0x93, 0x64, 0x3f, 0xe9,
      0xea, 0x8e, 0xcc, 0x38, 0x9a, 0xbd, 0x6e, 0xa3,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "niryo_one_msgs/msg/detail/sequence__functions.h"
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
static const rosidl_type_hash_t niryo_one_msgs__msg__Sequence__EXPECTED_HASH = {1, {
    0xbe, 0x6d, 0xd9, 0x67, 0x19, 0x63, 0x34, 0x6a,
    0x01, 0xc6, 0x12, 0x61, 0xe9, 0xec, 0x1a, 0xb7,
    0x32, 0xdb, 0x95, 0x65, 0xc0, 0x59, 0xc3, 0xed,
    0x9a, 0x7a, 0x28, 0x67, 0xe8, 0x0e, 0x29, 0x1b,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char niryo_one_msgs__srv__GetSequenceList__TYPE_NAME[] = "niryo_one_msgs/srv/GetSequenceList";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char niryo_one_msgs__msg__Sequence__TYPE_NAME[] = "niryo_one_msgs/msg/Sequence";
static char niryo_one_msgs__srv__GetSequenceList_Event__TYPE_NAME[] = "niryo_one_msgs/srv/GetSequenceList_Event";
static char niryo_one_msgs__srv__GetSequenceList_Request__TYPE_NAME[] = "niryo_one_msgs/srv/GetSequenceList_Request";
static char niryo_one_msgs__srv__GetSequenceList_Response__TYPE_NAME[] = "niryo_one_msgs/srv/GetSequenceList_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char niryo_one_msgs__srv__GetSequenceList__FIELD_NAME__request_message[] = "request_message";
static char niryo_one_msgs__srv__GetSequenceList__FIELD_NAME__response_message[] = "response_message";
static char niryo_one_msgs__srv__GetSequenceList__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__GetSequenceList__FIELDS[] = {
  {
    {niryo_one_msgs__srv__GetSequenceList__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__GetSequenceList_Request__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetSequenceList__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__GetSequenceList_Response__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetSequenceList__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__GetSequenceList_Event__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__GetSequenceList__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__Sequence__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetSequenceList_Event__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetSequenceList_Request__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetSequenceList_Response__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__GetSequenceList__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__GetSequenceList__TYPE_NAME, 34, 34},
      {niryo_one_msgs__srv__GetSequenceList__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__GetSequenceList__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__Sequence__EXPECTED_HASH, niryo_one_msgs__msg__Sequence__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__msg__Sequence__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__srv__GetSequenceList_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__srv__GetSequenceList_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = niryo_one_msgs__srv__GetSequenceList_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__GetSequenceList_Request__FIELD_NAME__info_header_only[] = "info_header_only";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__GetSequenceList_Request__FIELDS[] = {
  {
    {niryo_one_msgs__srv__GetSequenceList_Request__FIELD_NAME__info_header_only, 16, 16},
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
niryo_one_msgs__srv__GetSequenceList_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__GetSequenceList_Request__TYPE_NAME, 42, 42},
      {niryo_one_msgs__srv__GetSequenceList_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__GetSequenceList_Response__FIELD_NAME__sequences[] = "sequences";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__GetSequenceList_Response__FIELDS[] = {
  {
    {niryo_one_msgs__srv__GetSequenceList_Response__FIELD_NAME__sequences, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {niryo_one_msgs__msg__Sequence__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__GetSequenceList_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {niryo_one_msgs__msg__Sequence__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__GetSequenceList_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__GetSequenceList_Response__TYPE_NAME, 43, 43},
      {niryo_one_msgs__srv__GetSequenceList_Response__FIELDS, 1, 1},
    },
    {niryo_one_msgs__srv__GetSequenceList_Response__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&niryo_one_msgs__msg__Sequence__EXPECTED_HASH, niryo_one_msgs__msg__Sequence__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = niryo_one_msgs__msg__Sequence__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__GetSequenceList_Event__FIELD_NAME__info[] = "info";
static char niryo_one_msgs__srv__GetSequenceList_Event__FIELD_NAME__request[] = "request";
static char niryo_one_msgs__srv__GetSequenceList_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__GetSequenceList_Event__FIELDS[] = {
  {
    {niryo_one_msgs__srv__GetSequenceList_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetSequenceList_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__GetSequenceList_Request__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetSequenceList_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__GetSequenceList_Response__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__GetSequenceList_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__msg__Sequence__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetSequenceList_Request__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__GetSequenceList_Response__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__GetSequenceList_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__GetSequenceList_Event__TYPE_NAME, 40, 40},
      {niryo_one_msgs__srv__GetSequenceList_Event__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__GetSequenceList_Event__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&niryo_one_msgs__msg__Sequence__EXPECTED_HASH, niryo_one_msgs__msg__Sequence__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__msg__Sequence__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__srv__GetSequenceList_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__srv__GetSequenceList_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool info_header_only\n"
  "---\n"
  "niryo_one_msgs/Sequence[] sequences\n"
  "";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__GetSequenceList__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__GetSequenceList__TYPE_NAME, 34, 34},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 63, 63},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__GetSequenceList_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__GetSequenceList_Request__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__GetSequenceList_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__GetSequenceList_Response__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__GetSequenceList_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__GetSequenceList_Event__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__GetSequenceList__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__GetSequenceList__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__msg__Sequence__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__srv__GetSequenceList_Event__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__srv__GetSequenceList_Request__get_individual_type_description_source(NULL);
    sources[5] = *niryo_one_msgs__srv__GetSequenceList_Response__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__GetSequenceList_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__GetSequenceList_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__GetSequenceList_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__GetSequenceList_Response__get_individual_type_description_source(NULL),
    sources[1] = *niryo_one_msgs__msg__Sequence__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__GetSequenceList_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__GetSequenceList_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__msg__Sequence__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__srv__GetSequenceList_Request__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__srv__GetSequenceList_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
