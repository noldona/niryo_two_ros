// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:srv/ObjDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/obj_detection.h"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__OBJ_DETECTION__STRUCT_H_
#define NIRYO_ONE_MSGS__SRV__DETAIL__OBJ_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'obj_type'
// Member 'obj_color'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ObjDetection in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__ObjDetection_Request
{
  rosidl_runtime_c__String obj_type;
  rosidl_runtime_c__String obj_color;
  float workspace_ratio;
  bool ret_image;
} niryo_one_msgs__srv__ObjDetection_Request;

// Struct for a sequence of niryo_one_msgs__srv__ObjDetection_Request.
typedef struct niryo_one_msgs__srv__ObjDetection_Request__Sequence
{
  niryo_one_msgs__srv__ObjDetection_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__ObjDetection_Request__Sequence;

// Constants defined in the message

/// Constant 'SUCCESSFUL'.
enum
{
  niryo_one_msgs__srv__ObjDetection_Response__SUCCESSFUL = 1l
};

/// Constant 'VIDEO_STREAM_NOT_RUNNING'.
enum
{
  niryo_one_msgs__srv__ObjDetection_Response__VIDEO_STREAM_NOT_RUNNING = -1l
};

/// Constant 'OBJECT_NOT_FOUND'.
enum
{
  niryo_one_msgs__srv__ObjDetection_Response__OBJECT_NOT_FOUND = -2l
};

/// Constant 'MARKERS_NOT_FOUND'.
enum
{
  niryo_one_msgs__srv__ObjDetection_Response__MARKERS_NOT_FOUND = -3l
};

// Include directives for member types
// Member 'obj_pose'
#include "niryo_one_msgs/msg/detail/object_pose__struct.h"
// Member 'obj_type'
// Member 'obj_color'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'img'
#include "sensor_msgs/msg/detail/compressed_image__struct.h"

/// Struct defined in srv/ObjDetection in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__ObjDetection_Response
{
  int32_t status;
  niryo_one_msgs__msg__ObjectPose obj_pose;
  rosidl_runtime_c__String obj_type;
  rosidl_runtime_c__String obj_color;
  sensor_msgs__msg__CompressedImage img;
} niryo_one_msgs__srv__ObjDetection_Response;

// Struct for a sequence of niryo_one_msgs__srv__ObjDetection_Response.
typedef struct niryo_one_msgs__srv__ObjDetection_Response__Sequence
{
  niryo_one_msgs__srv__ObjDetection_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__ObjDetection_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__srv__ObjDetection_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__srv__ObjDetection_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ObjDetection in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__ObjDetection_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__srv__ObjDetection_Request__Sequence request;
  niryo_one_msgs__srv__ObjDetection_Response__Sequence response;
} niryo_one_msgs__srv__ObjDetection_Event;

// Struct for a sequence of niryo_one_msgs__srv__ObjDetection_Event.
typedef struct niryo_one_msgs__srv__ObjDetection_Event__Sequence
{
  niryo_one_msgs__srv__ObjDetection_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__ObjDetection_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__OBJ_DETECTION__STRUCT_H_
