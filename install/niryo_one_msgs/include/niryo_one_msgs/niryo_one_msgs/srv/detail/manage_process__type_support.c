// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from niryo_one_msgs:srv/ManageProcess.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "niryo_one_msgs/srv/detail/manage_process__rosidl_typesupport_introspection_c.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "niryo_one_msgs/srv/detail/manage_process__functions.h"
#include "niryo_one_msgs/srv/detail/manage_process__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  niryo_one_msgs__srv__ManageProcess_Request__init(message_memory);
}

void niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_fini_function(void * message_memory)
{
  niryo_one_msgs__srv__ManageProcess_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_message_member_array[2] = {
  {
    "action",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__srv__ManageProcess_Request, action),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__srv__ManageProcess_Request, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_message_members = {
  "niryo_one_msgs__srv",  // message namespace
  "ManageProcess_Request",  // message name
  2,  // number of fields
  sizeof(niryo_one_msgs__srv__ManageProcess_Request),
  false,  // has_any_key_member_
  niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_message_member_array,  // message members
  niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_message_type_support_handle = {
  0,
  &niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__srv__ManageProcess_Request__get_type_hash,
  &niryo_one_msgs__srv__ManageProcess_Request__get_type_description,
  &niryo_one_msgs__srv__ManageProcess_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_niryo_one_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, ManageProcess_Request)() {
  if (!niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_message_type_support_handle.typesupport_identifier) {
    niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "niryo_one_msgs/srv/detail/manage_process__rosidl_typesupport_introspection_c.h"
// already included above
// #include "niryo_one_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "niryo_one_msgs/srv/detail/manage_process__functions.h"
// already included above
// #include "niryo_one_msgs/srv/detail/manage_process__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  niryo_one_msgs__srv__ManageProcess_Response__init(message_memory);
}

void niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_fini_function(void * message_memory)
{
  niryo_one_msgs__srv__ManageProcess_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__srv__ManageProcess_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__srv__ManageProcess_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_message_members = {
  "niryo_one_msgs__srv",  // message namespace
  "ManageProcess_Response",  // message name
  2,  // number of fields
  sizeof(niryo_one_msgs__srv__ManageProcess_Response),
  false,  // has_any_key_member_
  niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_message_member_array,  // message members
  niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_message_type_support_handle = {
  0,
  &niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__srv__ManageProcess_Response__get_type_hash,
  &niryo_one_msgs__srv__ManageProcess_Response__get_type_description,
  &niryo_one_msgs__srv__ManageProcess_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_niryo_one_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, ManageProcess_Response)() {
  if (!niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_message_type_support_handle.typesupport_identifier) {
    niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "niryo_one_msgs/srv/detail/manage_process__rosidl_typesupport_introspection_c.h"
// already included above
// #include "niryo_one_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "niryo_one_msgs/srv/detail/manage_process__functions.h"
// already included above
// #include "niryo_one_msgs/srv/detail/manage_process__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "niryo_one_msgs/srv/manage_process.h"
// Member `request`
// Member `response`
// already included above
// #include "niryo_one_msgs/srv/detail/manage_process__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  niryo_one_msgs__srv__ManageProcess_Event__init(message_memory);
}

void niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_fini_function(void * message_memory)
{
  niryo_one_msgs__srv__ManageProcess_Event__fini(message_memory);
}

size_t niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__size_function__ManageProcess_Event__request(
  const void * untyped_member)
{
  const niryo_one_msgs__srv__ManageProcess_Request__Sequence * member =
    (const niryo_one_msgs__srv__ManageProcess_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__get_const_function__ManageProcess_Event__request(
  const void * untyped_member, size_t index)
{
  const niryo_one_msgs__srv__ManageProcess_Request__Sequence * member =
    (const niryo_one_msgs__srv__ManageProcess_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__get_function__ManageProcess_Event__request(
  void * untyped_member, size_t index)
{
  niryo_one_msgs__srv__ManageProcess_Request__Sequence * member =
    (niryo_one_msgs__srv__ManageProcess_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__fetch_function__ManageProcess_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const niryo_one_msgs__srv__ManageProcess_Request * item =
    ((const niryo_one_msgs__srv__ManageProcess_Request *)
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__get_const_function__ManageProcess_Event__request(untyped_member, index));
  niryo_one_msgs__srv__ManageProcess_Request * value =
    (niryo_one_msgs__srv__ManageProcess_Request *)(untyped_value);
  *value = *item;
}

void niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__assign_function__ManageProcess_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  niryo_one_msgs__srv__ManageProcess_Request * item =
    ((niryo_one_msgs__srv__ManageProcess_Request *)
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__get_function__ManageProcess_Event__request(untyped_member, index));
  const niryo_one_msgs__srv__ManageProcess_Request * value =
    (const niryo_one_msgs__srv__ManageProcess_Request *)(untyped_value);
  *item = *value;
}

bool niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__resize_function__ManageProcess_Event__request(
  void * untyped_member, size_t size)
{
  niryo_one_msgs__srv__ManageProcess_Request__Sequence * member =
    (niryo_one_msgs__srv__ManageProcess_Request__Sequence *)(untyped_member);
  niryo_one_msgs__srv__ManageProcess_Request__Sequence__fini(member);
  return niryo_one_msgs__srv__ManageProcess_Request__Sequence__init(member, size);
}

size_t niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__size_function__ManageProcess_Event__response(
  const void * untyped_member)
{
  const niryo_one_msgs__srv__ManageProcess_Response__Sequence * member =
    (const niryo_one_msgs__srv__ManageProcess_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__get_const_function__ManageProcess_Event__response(
  const void * untyped_member, size_t index)
{
  const niryo_one_msgs__srv__ManageProcess_Response__Sequence * member =
    (const niryo_one_msgs__srv__ManageProcess_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__get_function__ManageProcess_Event__response(
  void * untyped_member, size_t index)
{
  niryo_one_msgs__srv__ManageProcess_Response__Sequence * member =
    (niryo_one_msgs__srv__ManageProcess_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__fetch_function__ManageProcess_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const niryo_one_msgs__srv__ManageProcess_Response * item =
    ((const niryo_one_msgs__srv__ManageProcess_Response *)
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__get_const_function__ManageProcess_Event__response(untyped_member, index));
  niryo_one_msgs__srv__ManageProcess_Response * value =
    (niryo_one_msgs__srv__ManageProcess_Response *)(untyped_value);
  *value = *item;
}

void niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__assign_function__ManageProcess_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  niryo_one_msgs__srv__ManageProcess_Response * item =
    ((niryo_one_msgs__srv__ManageProcess_Response *)
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__get_function__ManageProcess_Event__response(untyped_member, index));
  const niryo_one_msgs__srv__ManageProcess_Response * value =
    (const niryo_one_msgs__srv__ManageProcess_Response *)(untyped_value);
  *item = *value;
}

bool niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__resize_function__ManageProcess_Event__response(
  void * untyped_member, size_t size)
{
  niryo_one_msgs__srv__ManageProcess_Response__Sequence * member =
    (niryo_one_msgs__srv__ManageProcess_Response__Sequence *)(untyped_member);
  niryo_one_msgs__srv__ManageProcess_Response__Sequence__fini(member);
  return niryo_one_msgs__srv__ManageProcess_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(niryo_one_msgs__srv__ManageProcess_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(niryo_one_msgs__srv__ManageProcess_Event, request),  // bytes offset in struct
    NULL,  // default value
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__size_function__ManageProcess_Event__request,  // size() function pointer
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__get_const_function__ManageProcess_Event__request,  // get_const(index) function pointer
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__get_function__ManageProcess_Event__request,  // get(index) function pointer
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__fetch_function__ManageProcess_Event__request,  // fetch(index, &value) function pointer
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__assign_function__ManageProcess_Event__request,  // assign(index, value) function pointer
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__resize_function__ManageProcess_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(niryo_one_msgs__srv__ManageProcess_Event, response),  // bytes offset in struct
    NULL,  // default value
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__size_function__ManageProcess_Event__response,  // size() function pointer
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__get_const_function__ManageProcess_Event__response,  // get_const(index) function pointer
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__get_function__ManageProcess_Event__response,  // get(index) function pointer
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__fetch_function__ManageProcess_Event__response,  // fetch(index, &value) function pointer
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__assign_function__ManageProcess_Event__response,  // assign(index, value) function pointer
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__resize_function__ManageProcess_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_message_members = {
  "niryo_one_msgs__srv",  // message namespace
  "ManageProcess_Event",  // message name
  3,  // number of fields
  sizeof(niryo_one_msgs__srv__ManageProcess_Event),
  false,  // has_any_key_member_
  niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_message_member_array,  // message members
  niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_message_type_support_handle = {
  0,
  &niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_message_members,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__srv__ManageProcess_Event__get_type_hash,
  &niryo_one_msgs__srv__ManageProcess_Event__get_type_description,
  &niryo_one_msgs__srv__ManageProcess_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_niryo_one_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, ManageProcess_Event)() {
  niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, ManageProcess_Request)();
  niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, ManageProcess_Response)();
  if (!niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_message_type_support_handle.typesupport_identifier) {
    niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "niryo_one_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "niryo_one_msgs/srv/detail/manage_process__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers niryo_one_msgs__srv__detail__manage_process__rosidl_typesupport_introspection_c__ManageProcess_service_members = {
  "niryo_one_msgs__srv",  // service namespace
  "ManageProcess",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // niryo_one_msgs__srv__detail__manage_process__rosidl_typesupport_introspection_c__ManageProcess_Request_message_type_support_handle,
  NULL,  // response message
  // niryo_one_msgs__srv__detail__manage_process__rosidl_typesupport_introspection_c__ManageProcess_Response_message_type_support_handle
  NULL  // event_message
  // niryo_one_msgs__srv__detail__manage_process__rosidl_typesupport_introspection_c__ManageProcess_Response_message_type_support_handle
};


static rosidl_service_type_support_t niryo_one_msgs__srv__detail__manage_process__rosidl_typesupport_introspection_c__ManageProcess_service_type_support_handle = {
  0,
  &niryo_one_msgs__srv__detail__manage_process__rosidl_typesupport_introspection_c__ManageProcess_service_members,
  get_service_typesupport_handle_function,
  &niryo_one_msgs__srv__ManageProcess_Request__rosidl_typesupport_introspection_c__ManageProcess_Request_message_type_support_handle,
  &niryo_one_msgs__srv__ManageProcess_Response__rosidl_typesupport_introspection_c__ManageProcess_Response_message_type_support_handle,
  &niryo_one_msgs__srv__ManageProcess_Event__rosidl_typesupport_introspection_c__ManageProcess_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    niryo_one_msgs,
    srv,
    ManageProcess
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    niryo_one_msgs,
    srv,
    ManageProcess
  ),
  &niryo_one_msgs__srv__ManageProcess__get_type_hash,
  &niryo_one_msgs__srv__ManageProcess__get_type_description,
  &niryo_one_msgs__srv__ManageProcess__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, ManageProcess_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, ManageProcess_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, ManageProcess_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_niryo_one_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, ManageProcess)(void) {
  if (!niryo_one_msgs__srv__detail__manage_process__rosidl_typesupport_introspection_c__ManageProcess_service_type_support_handle.typesupport_identifier) {
    niryo_one_msgs__srv__detail__manage_process__rosidl_typesupport_introspection_c__ManageProcess_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)niryo_one_msgs__srv__detail__manage_process__rosidl_typesupport_introspection_c__ManageProcess_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, ManageProcess_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, ManageProcess_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, niryo_one_msgs, srv, ManageProcess_Event)()->data;
  }

  return &niryo_one_msgs__srv__detail__manage_process__rosidl_typesupport_introspection_c__ManageProcess_service_type_support_handle;
}
