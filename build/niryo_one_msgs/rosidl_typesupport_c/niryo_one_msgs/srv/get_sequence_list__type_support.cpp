// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from niryo_one_msgs:srv/GetSequenceList.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "niryo_one_msgs/srv/detail/get_sequence_list__struct.h"
#include "niryo_one_msgs/srv/detail/get_sequence_list__type_support.h"
#include "niryo_one_msgs/srv/detail/get_sequence_list__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace niryo_one_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GetSequenceList_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetSequenceList_Request_type_support_ids_t;

static const _GetSequenceList_Request_type_support_ids_t _GetSequenceList_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetSequenceList_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetSequenceList_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetSequenceList_Request_type_support_symbol_names_t _GetSequenceList_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, srv, GetSequenceList_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, GetSequenceList_Request)),
  }
};

typedef struct _GetSequenceList_Request_type_support_data_t
{
  void * data[2];
} _GetSequenceList_Request_type_support_data_t;

static _GetSequenceList_Request_type_support_data_t _GetSequenceList_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetSequenceList_Request_message_typesupport_map = {
  2,
  "niryo_one_msgs",
  &_GetSequenceList_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GetSequenceList_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GetSequenceList_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetSequenceList_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetSequenceList_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &niryo_one_msgs__srv__GetSequenceList_Request__get_type_hash,
  &niryo_one_msgs__srv__GetSequenceList_Request__get_type_description,
  &niryo_one_msgs__srv__GetSequenceList_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace niryo_one_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, niryo_one_msgs, srv, GetSequenceList_Request)() {
  return &::niryo_one_msgs::srv::rosidl_typesupport_c::GetSequenceList_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "niryo_one_msgs/srv/detail/get_sequence_list__struct.h"
// already included above
// #include "niryo_one_msgs/srv/detail/get_sequence_list__type_support.h"
// already included above
// #include "niryo_one_msgs/srv/detail/get_sequence_list__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace niryo_one_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GetSequenceList_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetSequenceList_Response_type_support_ids_t;

static const _GetSequenceList_Response_type_support_ids_t _GetSequenceList_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetSequenceList_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetSequenceList_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetSequenceList_Response_type_support_symbol_names_t _GetSequenceList_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, srv, GetSequenceList_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, GetSequenceList_Response)),
  }
};

typedef struct _GetSequenceList_Response_type_support_data_t
{
  void * data[2];
} _GetSequenceList_Response_type_support_data_t;

static _GetSequenceList_Response_type_support_data_t _GetSequenceList_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetSequenceList_Response_message_typesupport_map = {
  2,
  "niryo_one_msgs",
  &_GetSequenceList_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GetSequenceList_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GetSequenceList_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetSequenceList_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetSequenceList_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &niryo_one_msgs__srv__GetSequenceList_Response__get_type_hash,
  &niryo_one_msgs__srv__GetSequenceList_Response__get_type_description,
  &niryo_one_msgs__srv__GetSequenceList_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace niryo_one_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, niryo_one_msgs, srv, GetSequenceList_Response)() {
  return &::niryo_one_msgs::srv::rosidl_typesupport_c::GetSequenceList_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "niryo_one_msgs/srv/detail/get_sequence_list__struct.h"
// already included above
// #include "niryo_one_msgs/srv/detail/get_sequence_list__type_support.h"
// already included above
// #include "niryo_one_msgs/srv/detail/get_sequence_list__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace niryo_one_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GetSequenceList_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetSequenceList_Event_type_support_ids_t;

static const _GetSequenceList_Event_type_support_ids_t _GetSequenceList_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetSequenceList_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetSequenceList_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetSequenceList_Event_type_support_symbol_names_t _GetSequenceList_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, srv, GetSequenceList_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, GetSequenceList_Event)),
  }
};

typedef struct _GetSequenceList_Event_type_support_data_t
{
  void * data[2];
} _GetSequenceList_Event_type_support_data_t;

static _GetSequenceList_Event_type_support_data_t _GetSequenceList_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetSequenceList_Event_message_typesupport_map = {
  2,
  "niryo_one_msgs",
  &_GetSequenceList_Event_message_typesupport_ids.typesupport_identifier[0],
  &_GetSequenceList_Event_message_typesupport_symbol_names.symbol_name[0],
  &_GetSequenceList_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetSequenceList_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetSequenceList_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &niryo_one_msgs__srv__GetSequenceList_Event__get_type_hash,
  &niryo_one_msgs__srv__GetSequenceList_Event__get_type_description,
  &niryo_one_msgs__srv__GetSequenceList_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace niryo_one_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, niryo_one_msgs, srv, GetSequenceList_Event)() {
  return &::niryo_one_msgs::srv::rosidl_typesupport_c::GetSequenceList_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "niryo_one_msgs/srv/detail/get_sequence_list__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace niryo_one_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _GetSequenceList_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetSequenceList_type_support_ids_t;

static const _GetSequenceList_type_support_ids_t _GetSequenceList_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetSequenceList_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetSequenceList_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetSequenceList_type_support_symbol_names_t _GetSequenceList_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, srv, GetSequenceList)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, GetSequenceList)),
  }
};

typedef struct _GetSequenceList_type_support_data_t
{
  void * data[2];
} _GetSequenceList_type_support_data_t;

static _GetSequenceList_type_support_data_t _GetSequenceList_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetSequenceList_service_typesupport_map = {
  2,
  "niryo_one_msgs",
  &_GetSequenceList_service_typesupport_ids.typesupport_identifier[0],
  &_GetSequenceList_service_typesupport_symbol_names.symbol_name[0],
  &_GetSequenceList_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GetSequenceList_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetSequenceList_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &GetSequenceList_Request_message_type_support_handle,
  &GetSequenceList_Response_message_type_support_handle,
  &GetSequenceList_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    niryo_one_msgs,
    srv,
    GetSequenceList
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    niryo_one_msgs,
    srv,
    GetSequenceList
  ),
  &niryo_one_msgs__srv__GetSequenceList__get_type_hash,
  &niryo_one_msgs__srv__GetSequenceList__get_type_description,
  &niryo_one_msgs__srv__GetSequenceList__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace niryo_one_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, niryo_one_msgs, srv, GetSequenceList)() {
  return &::niryo_one_msgs::srv::rosidl_typesupport_c::GetSequenceList_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
