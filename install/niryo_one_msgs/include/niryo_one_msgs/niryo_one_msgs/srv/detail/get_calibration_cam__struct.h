// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:srv/GetCalibrationCam.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_calibration_cam.h"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_CALIBRATION_CAM__STRUCT_H_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_CALIBRATION_CAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'empty'
#include "std_msgs/msg/detail/empty__struct.h"

/// Struct defined in srv/GetCalibrationCam in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__GetCalibrationCam_Request
{
  std_msgs__msg__Empty empty;
} niryo_one_msgs__srv__GetCalibrationCam_Request;

// Struct for a sequence of niryo_one_msgs__srv__GetCalibrationCam_Request.
typedef struct niryo_one_msgs__srv__GetCalibrationCam_Request__Sequence
{
  niryo_one_msgs__srv__GetCalibrationCam_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__GetCalibrationCam_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'camera_info'
#include "sensor_msgs/msg/detail/camera_info__struct.h"

/// Struct defined in srv/GetCalibrationCam in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__GetCalibrationCam_Response
{
  bool is_set;
  sensor_msgs__msg__CameraInfo camera_info;
} niryo_one_msgs__srv__GetCalibrationCam_Response;

// Struct for a sequence of niryo_one_msgs__srv__GetCalibrationCam_Response.
typedef struct niryo_one_msgs__srv__GetCalibrationCam_Response__Sequence
{
  niryo_one_msgs__srv__GetCalibrationCam_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__GetCalibrationCam_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__srv__GetCalibrationCam_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__srv__GetCalibrationCam_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetCalibrationCam in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__GetCalibrationCam_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__srv__GetCalibrationCam_Request__Sequence request;
  niryo_one_msgs__srv__GetCalibrationCam_Response__Sequence response;
} niryo_one_msgs__srv__GetCalibrationCam_Event;

// Struct for a sequence of niryo_one_msgs__srv__GetCalibrationCam_Event.
typedef struct niryo_one_msgs__srv__GetCalibrationCam_Event__Sequence
{
  niryo_one_msgs__srv__GetCalibrationCam_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__GetCalibrationCam_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_CALIBRATION_CAM__STRUCT_H_
