// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from niryo_one_msgs:srv/SetDigitalIO.idl
// generated code does not contain a copyright notice

#include "niryo_one_msgs/srv/detail/set_digital_io__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__SetDigitalIO__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x83, 0xd8, 0x93, 0xa4, 0xce, 0x91, 0xf8, 0xa1,
      0x5c, 0x04, 0x84, 0x31, 0xc5, 0xf7, 0x36, 0xcc,
      0x83, 0xf8, 0x5e, 0x80, 0x91, 0xab, 0x95, 0x1e,
      0x6d, 0x92, 0x75, 0x03, 0xc2, 0xbc, 0x8a, 0xd2,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__SetDigitalIO_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x4d, 0x2e, 0xe5, 0x2c, 0xca, 0xa6, 0xf6, 0x3f,
      0x24, 0xb5, 0x0d, 0xb0, 0x5e, 0x62, 0xf4, 0x78,
      0x10, 0xee, 0x0d, 0xac, 0x75, 0x7d, 0x12, 0xee,
      0xf0, 0x0a, 0x8d, 0xe4, 0x6a, 0xd8, 0x00, 0x4f,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__SetDigitalIO_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8e, 0x4b, 0x88, 0xf9, 0x08, 0x80, 0x01, 0x93,
      0xce, 0xf4, 0x42, 0xcf, 0x4e, 0xb5, 0xf5, 0x57,
      0xad, 0x7e, 0xe7, 0x11, 0x61, 0xec, 0x0e, 0x70,
      0xa1, 0xed, 0xb9, 0x19, 0xc3, 0xbd, 0xd1, 0x9d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_niryo_one_msgs
const rosidl_type_hash_t *
niryo_one_msgs__srv__SetDigitalIO_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xbd, 0xe5, 0x92, 0x50, 0x1c, 0xcc, 0xae, 0x98,
      0xef, 0xbb, 0x75, 0xde, 0x00, 0x79, 0x40, 0xe7,
      0xb1, 0xa5, 0x40, 0xd6, 0x26, 0x92, 0xfc, 0x17,
      0xef, 0xd6, 0x30, 0xae, 0x9c, 0xe4, 0xd0, 0x9f,
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

static char niryo_one_msgs__srv__SetDigitalIO__TYPE_NAME[] = "niryo_one_msgs/srv/SetDigitalIO";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char niryo_one_msgs__srv__SetDigitalIO_Event__TYPE_NAME[] = "niryo_one_msgs/srv/SetDigitalIO_Event";
static char niryo_one_msgs__srv__SetDigitalIO_Request__TYPE_NAME[] = "niryo_one_msgs/srv/SetDigitalIO_Request";
static char niryo_one_msgs__srv__SetDigitalIO_Response__TYPE_NAME[] = "niryo_one_msgs/srv/SetDigitalIO_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char niryo_one_msgs__srv__SetDigitalIO__FIELD_NAME__request_message[] = "request_message";
static char niryo_one_msgs__srv__SetDigitalIO__FIELD_NAME__response_message[] = "response_message";
static char niryo_one_msgs__srv__SetDigitalIO__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__SetDigitalIO__FIELDS[] = {
  {
    {niryo_one_msgs__srv__SetDigitalIO__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__SetDigitalIO_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetDigitalIO__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__SetDigitalIO_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetDigitalIO__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {niryo_one_msgs__srv__SetDigitalIO_Event__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__SetDigitalIO__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetDigitalIO_Event__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetDigitalIO_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetDigitalIO_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__SetDigitalIO__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__SetDigitalIO__TYPE_NAME, 31, 31},
      {niryo_one_msgs__srv__SetDigitalIO__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__SetDigitalIO__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__srv__SetDigitalIO_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__srv__SetDigitalIO_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = niryo_one_msgs__srv__SetDigitalIO_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__SetDigitalIO_Request__FIELD_NAME__pin[] = "pin";
static char niryo_one_msgs__srv__SetDigitalIO_Request__FIELD_NAME__value[] = "value";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__SetDigitalIO_Request__FIELDS[] = {
  {
    {niryo_one_msgs__srv__SetDigitalIO_Request__FIELD_NAME__pin, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetDigitalIO_Request__FIELD_NAME__value, 5, 5},
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
niryo_one_msgs__srv__SetDigitalIO_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__SetDigitalIO_Request__TYPE_NAME, 39, 39},
      {niryo_one_msgs__srv__SetDigitalIO_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__SetDigitalIO_Response__FIELD_NAME__status[] = "status";
static char niryo_one_msgs__srv__SetDigitalIO_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__SetDigitalIO_Response__FIELDS[] = {
  {
    {niryo_one_msgs__srv__SetDigitalIO_Response__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetDigitalIO_Response__FIELD_NAME__message, 7, 7},
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
niryo_one_msgs__srv__SetDigitalIO_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__SetDigitalIO_Response__TYPE_NAME, 40, 40},
      {niryo_one_msgs__srv__SetDigitalIO_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char niryo_one_msgs__srv__SetDigitalIO_Event__FIELD_NAME__info[] = "info";
static char niryo_one_msgs__srv__SetDigitalIO_Event__FIELD_NAME__request[] = "request";
static char niryo_one_msgs__srv__SetDigitalIO_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field niryo_one_msgs__srv__SetDigitalIO_Event__FIELDS[] = {
  {
    {niryo_one_msgs__srv__SetDigitalIO_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetDigitalIO_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__SetDigitalIO_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetDigitalIO_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {niryo_one_msgs__srv__SetDigitalIO_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription niryo_one_msgs__srv__SetDigitalIO_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetDigitalIO_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {niryo_one_msgs__srv__SetDigitalIO_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
niryo_one_msgs__srv__SetDigitalIO_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {niryo_one_msgs__srv__SetDigitalIO_Event__TYPE_NAME, 37, 37},
      {niryo_one_msgs__srv__SetDigitalIO_Event__FIELDS, 3, 3},
    },
    {niryo_one_msgs__srv__SetDigitalIO_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = niryo_one_msgs__srv__SetDigitalIO_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = niryo_one_msgs__srv__SetDigitalIO_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 pin\n"
  "uint8 value\n"
  "---\n"
  "int32 status\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__SetDigitalIO__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__SetDigitalIO__TYPE_NAME, 31, 31},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 54, 54},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__SetDigitalIO_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__SetDigitalIO_Request__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__SetDigitalIO_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__SetDigitalIO_Response__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
niryo_one_msgs__srv__SetDigitalIO_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {niryo_one_msgs__srv__SetDigitalIO_Event__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__SetDigitalIO__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__SetDigitalIO__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__srv__SetDigitalIO_Event__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__srv__SetDigitalIO_Request__get_individual_type_description_source(NULL);
    sources[4] = *niryo_one_msgs__srv__SetDigitalIO_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__SetDigitalIO_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__SetDigitalIO_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__SetDigitalIO_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__SetDigitalIO_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
niryo_one_msgs__srv__SetDigitalIO_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *niryo_one_msgs__srv__SetDigitalIO_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *niryo_one_msgs__srv__SetDigitalIO_Request__get_individual_type_description_source(NULL);
    sources[3] = *niryo_one_msgs__srv__SetDigitalIO_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
