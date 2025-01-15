// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from niryo_one_msgs:srv/SetInt.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "niryo_one_msgs/srv/detail/set_int__functions.h"
#include "niryo_one_msgs/srv/detail/set_int__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace niryo_one_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetInt_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetInt_Request_type_support_ids_t;

static const _SetInt_Request_type_support_ids_t _SetInt_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetInt_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetInt_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetInt_Request_type_support_symbol_names_t _SetInt_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, niryo_one_msgs, srv, SetInt_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, niryo_one_msgs, srv, SetInt_Request)),
  }
};

typedef struct _SetInt_Request_type_support_data_t
{
  void * data[2];
} _SetInt_Request_type_support_data_t;

static _SetInt_Request_type_support_data_t _SetInt_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetInt_Request_message_typesupport_map = {
  2,
  "niryo_one_msgs",
  &_SetInt_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetInt_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetInt_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetInt_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetInt_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &niryo_one_msgs__srv__SetInt_Request__get_type_hash,
  &niryo_one_msgs__srv__SetInt_Request__get_type_description,
  &niryo_one_msgs__srv__SetInt_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace niryo_one_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<niryo_one_msgs::srv::SetInt_Request>()
{
  return &::niryo_one_msgs::srv::rosidl_typesupport_cpp::SetInt_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, niryo_one_msgs, srv, SetInt_Request)() {
  return get_message_type_support_handle<niryo_one_msgs::srv::SetInt_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "niryo_one_msgs/srv/detail/set_int__functions.h"
// already included above
// #include "niryo_one_msgs/srv/detail/set_int__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace niryo_one_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetInt_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetInt_Response_type_support_ids_t;

static const _SetInt_Response_type_support_ids_t _SetInt_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetInt_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetInt_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetInt_Response_type_support_symbol_names_t _SetInt_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, niryo_one_msgs, srv, SetInt_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, niryo_one_msgs, srv, SetInt_Response)),
  }
};

typedef struct _SetInt_Response_type_support_data_t
{
  void * data[2];
} _SetInt_Response_type_support_data_t;

static _SetInt_Response_type_support_data_t _SetInt_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetInt_Response_message_typesupport_map = {
  2,
  "niryo_one_msgs",
  &_SetInt_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetInt_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetInt_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetInt_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetInt_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &niryo_one_msgs__srv__SetInt_Response__get_type_hash,
  &niryo_one_msgs__srv__SetInt_Response__get_type_description,
  &niryo_one_msgs__srv__SetInt_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace niryo_one_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<niryo_one_msgs::srv::SetInt_Response>()
{
  return &::niryo_one_msgs::srv::rosidl_typesupport_cpp::SetInt_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, niryo_one_msgs, srv, SetInt_Response)() {
  return get_message_type_support_handle<niryo_one_msgs::srv::SetInt_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "niryo_one_msgs/srv/detail/set_int__functions.h"
// already included above
// #include "niryo_one_msgs/srv/detail/set_int__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace niryo_one_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetInt_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetInt_Event_type_support_ids_t;

static const _SetInt_Event_type_support_ids_t _SetInt_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetInt_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetInt_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetInt_Event_type_support_symbol_names_t _SetInt_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, niryo_one_msgs, srv, SetInt_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, niryo_one_msgs, srv, SetInt_Event)),
  }
};

typedef struct _SetInt_Event_type_support_data_t
{
  void * data[2];
} _SetInt_Event_type_support_data_t;

static _SetInt_Event_type_support_data_t _SetInt_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetInt_Event_message_typesupport_map = {
  2,
  "niryo_one_msgs",
  &_SetInt_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SetInt_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SetInt_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetInt_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetInt_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &niryo_one_msgs__srv__SetInt_Event__get_type_hash,
  &niryo_one_msgs__srv__SetInt_Event__get_type_description,
  &niryo_one_msgs__srv__SetInt_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace niryo_one_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<niryo_one_msgs::srv::SetInt_Event>()
{
  return &::niryo_one_msgs::srv::rosidl_typesupport_cpp::SetInt_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, niryo_one_msgs, srv, SetInt_Event)() {
  return get_message_type_support_handle<niryo_one_msgs::srv::SetInt_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "niryo_one_msgs/srv/detail/set_int__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace niryo_one_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetInt_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetInt_type_support_ids_t;

static const _SetInt_type_support_ids_t _SetInt_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetInt_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetInt_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetInt_type_support_symbol_names_t _SetInt_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, niryo_one_msgs, srv, SetInt)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, niryo_one_msgs, srv, SetInt)),
  }
};

typedef struct _SetInt_type_support_data_t
{
  void * data[2];
} _SetInt_type_support_data_t;

static _SetInt_type_support_data_t _SetInt_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetInt_service_typesupport_map = {
  2,
  "niryo_one_msgs",
  &_SetInt_service_typesupport_ids.typesupport_identifier[0],
  &_SetInt_service_typesupport_symbol_names.symbol_name[0],
  &_SetInt_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetInt_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetInt_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<niryo_one_msgs::srv::SetInt_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<niryo_one_msgs::srv::SetInt_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<niryo_one_msgs::srv::SetInt_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<niryo_one_msgs::srv::SetInt>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<niryo_one_msgs::srv::SetInt>,
  &niryo_one_msgs__srv__SetInt__get_type_hash,
  &niryo_one_msgs__srv__SetInt__get_type_description,
  &niryo_one_msgs__srv__SetInt__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace niryo_one_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<niryo_one_msgs::srv::SetInt>()
{
  return &::niryo_one_msgs::srv::rosidl_typesupport_cpp::SetInt_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, niryo_one_msgs, srv, SetInt)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<niryo_one_msgs::srv::SetInt>();
}

#ifdef __cplusplus
}
#endif
