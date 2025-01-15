// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:srv/PushAirVacuumPump.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/srv/detail/push_air_vacuum_pump__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__PushAirVacuumPump__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf5, 0x4e, 0xc7, 0xae, 0x0a, 0xc5, 0x1a, 0xc3,
      0xfa, 0x73, 0x81, 0x82, 0x0e, 0x4f, 0x0f, 0xfe,
      0xfa, 0x7e, 0x85, 0x5f, 0xc2, 0x3d, 0x0f, 0xaa,
      0xba, 0x29, 0xde, 0xcf, 0xbe, 0xd5, 0x59, 0x0e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__PushAirVacuumPump_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x52, 0xd6, 0xd7, 0x59, 0x71, 0x9e, 0x6b, 0xb2,
      0xd6, 0x89, 0x63, 0x2f, 0x67, 0x2f, 0x9e, 0x4a,
      0xec, 0xb1, 0x79, 0x2c, 0x4e, 0x2a, 0xaf, 0xdf,
      0x33, 0xc8, 0x77, 0x21, 0x43, 0x2f, 0x09, 0xe2,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__PushAirVacuumPump_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x19, 0x74, 0x33, 0x46, 0x3b, 0xb8, 0xb9, 0x9f,
      0xa1, 0xd8, 0xe5, 0x0f, 0x9e, 0x99, 0xdb, 0x8a,
      0x7f, 0x8e, 0x95, 0x19, 0x9c, 0xb0, 0x87, 0xb9,
      0xc2, 0xa1, 0xdb, 0xa3, 0x2d, 0xf2, 0x69, 0x13,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__PushAirVacuumPump_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7e, 0x5f, 0xcb, 0xb5, 0x17, 0x13, 0xfa, 0x71,
      0xd9, 0xaf, 0x64, 0xd4, 0x1d, 0xff, 0xd4, 0x4c,
      0xae, 0x27, 0x1b, 0x16, 0xc1, 0xc8, 0x97, 0x8d,
      0x83, 0x44, 0xcf, 0x1c, 0xc1, 0x57, 0xc1, 0xa8,
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

static char niryo_one_msgs__srv__PushAirVacuumPump__TYPE_NAME[] = "niryo_one_msgs/srv/PushAirVacuumPump";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char niryo_one_msgs__srv__PushAirVacuumPump_Event__TYPE_NAME[] = "niryo_one_msgs/srv/PushAirVacuumPump_Event";
static char niryo_one_msgs__srv__PushAirVacuumPump_Request__TYPE_NAME[] = "niryo_one_msgs/srv/PushAirVacuumPump_Request";
static char niryo_one_msgs__srv__PushAirVacuumPump_Response__TYPE_NAME[] = "niryo_one_msgs/srv/PushAirVacuumPump_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char niryo_one_msgs__srv__PushAirVacuumPump__FIELD_NAME__request_message[] = "request_message";
static char niryo_one_msgs__srv__PushAirVacuumPump__FIELD_NAME__response_message[] = "response_message";
static char niryo_one_msgs__srv__PushAirVacuumPump__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__PushAirVacuumPump__FIELDS[] = {
  {
    {niryo_one_msgs__srv__PushAirVacuumPump__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__PushAirVacuumPump_Request__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__PushAirVacuumPump__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__PushAirVacuumPump_Response__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__PushAirVacuumPump__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__PushAirVacuumPump_Event__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__PushAirVacuumPump__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__PushAirVacuumPump_Event__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__PushAirVacuumPump_Request__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__PushAirVacuumPump_Response__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__PushAirVacuumPump__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__PushAirVacuumPump__TYPE_NAME, 36, 36},
      {niryo_one_msgs__srv__PushAirVacuumPump__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__PushAirVacuumPump__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__srv__PushAirVacuumPump_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__srv__PushAirVacuumPump_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__srv__PushAirVacuumPump_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__PushAirVacuumPump_Request__FIELD_NAME__id[] = "id";
static char niryo_one_msgs__srv__PushAirVacuumPump_Request__FIELD_NAME__push_air_position[] = "push_air_position";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__PushAirVacuumPump_Request__FIELDS[] = {
  {
    {niryo_one_msgs__srv__PushAirVacuumPump_Request__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__PushAirVacuumPump_Request__FIELD_NAME__push_air_position, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__PushAirVacuumPump_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__PushAirVacuumPump_Request__TYPE_NAME, 44, 44},
      {niryo_one_msgs__srv__PushAirVacuumPump_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__PushAirVacuumPump_Response__FIELD_NAME__state[] = "state";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__PushAirVacuumPump_Response__FIELDS[] = {
  {
    {niryo_one_msgs__srv__PushAirVacuumPump_Response__FIELD_NAME__state, 5, 5},
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
niryo_one_msgs__srv__PushAirVacuumPump_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__PushAirVacuumPump_Response__TYPE_NAME, 45, 45},
      {niryo_one_msgs__srv__PushAirVacuumPump_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__PushAirVacuumPump_Event__FIELD_NAME__info[] = "info";
static char niryo_one_msgs__srv__PushAirVacuumPump_Event__FIELD_NAME__request[] = "request";
static char niryo_one_msgs__srv__PushAirVacuumPump_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__PushAirVacuumPump_Event__FIELDS[] = {
  {
    {niryo_one_msgs__srv__PushAirVacuumPump_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__PushAirVacuumPump_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__PushAirVacuumPump_Request__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__PushAirVacuumPump_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__PushAirVacuumPump_Response__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__PushAirVacuumPump_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__PushAirVacuumPump_Request__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__PushAirVacuumPump_Response__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__PushAirVacuumPump_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__PushAirVacuumPump_Event__TYPE_NAME, 42, 42},
      {niryo_one_msgs__srv__PushAirVacuumPump_Event__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__PushAirVacuumPump_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__srv__PushAirVacuumPump_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__srv__PushAirVacuumPump_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 id\n"
  "\n"
  "int16 push_air_position\n"
  "---\n"
  "uint8 state";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__PushAirVacuumPump__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__PushAirVacuumPump__TYPE_NAME, 36, 36},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 50, 50},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__PushAirVacuumPump_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__PushAirVacuumPump_Request__TYPE_NAME, 44, 44},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__PushAirVacuumPump_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__PushAirVacuumPump_Response__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__PushAirVacuumPump_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__PushAirVacuumPump_Event__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__PushAirVacuumPump__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__PushAirVacuumPump__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__srv__PushAirVacuumPump_Event__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__srv__PushAirVacuumPump_Request__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__srv__PushAirVacuumPump_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__PushAirVacuumPump_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__PushAirVacuumPump_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__PushAirVacuumPump_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__PushAirVacuumPump_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__PushAirVacuumPump_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__PushAirVacuumPump_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__srv__PushAirVacuumPump_Request__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__srv__PushAirVacuumPump_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
