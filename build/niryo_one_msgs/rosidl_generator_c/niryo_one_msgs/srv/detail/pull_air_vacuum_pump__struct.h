// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:srv/PullAirVacuumPump.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/pull_air_vacuum_pump.h"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__PULL_AIR_VACUUM_PUMP__STRUCT_H_
#define NIRYO_ONE_MSGS__SRV__DETAIL__PULL_AIR_VACUUM_PUMP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/PullAirVacuumPump in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__PullAirVacuumPump_Request
{
  uint8_t id;
  int16_t pull_air_position;
  int16_t pull_air_hold_torque;
} niryo_one_msgs__srv__PullAirVacuumPump_Request;

// Struct for a sequence of niryo_one_msgs__srv__PullAirVacuumPump_Request.
typedef struct niryo_one_msgs__srv__PullAirVacuumPump_Request__Sequence
{
  niryo_one_msgs__srv__PullAirVacuumPump_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__PullAirVacuumPump_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/PullAirVacuumPump in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__PullAirVacuumPump_Response
{
  uint8_t state;
} niryo_one_msgs__srv__PullAirVacuumPump_Response;

// Struct for a sequence of niryo_one_msgs__srv__PullAirVacuumPump_Response.
typedef struct niryo_one_msgs__srv__PullAirVacuumPump_Response__Sequence
{
  niryo_one_msgs__srv__PullAirVacuumPump_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__PullAirVacuumPump_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__srv__PullAirVacuumPump_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__srv__PullAirVacuumPump_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/PullAirVacuumPump in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__PullAirVacuumPump_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__srv__PullAirVacuumPump_Request__Sequence request;
  niryo_one_msgs__srv__PullAirVacuumPump_Response__Sequence response;
} niryo_one_msgs__srv__PullAirVacuumPump_Event;

// Struct for a sequence of niryo_one_msgs__srv__PullAirVacuumPump_Event.
typedef struct niryo_one_msgs__srv__PullAirVacuumPump_Event__Sequence
{
  niryo_one_msgs__srv__PullAirVacuumPump_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__PullAirVacuumPump_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__PULL_AIR_VACUUM_PUMP__STRUCT_H_
