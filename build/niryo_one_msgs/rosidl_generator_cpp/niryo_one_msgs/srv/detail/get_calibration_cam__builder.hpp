// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/GetCalibrationCam.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_calibration_cam.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_CALIBRATION_CAM__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_CALIBRATION_CAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/get_calibration_cam__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCalibrationCam_Request_empty
{
public:
  Init_GetCalibrationCam_Request_empty()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::GetCalibrationCam_Request empty(::niryo_one_msgs::srv::GetCalibrationCam_Request::_empty_type arg)
  {
    msg_.empty = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetCalibrationCam_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetCalibrationCam_Request>()
{
  return niryo_one_msgs::srv::builder::Init_GetCalibrationCam_Request_empty();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCalibrationCam_Response_camera_info
{
public:
  explicit Init_GetCalibrationCam_Response_camera_info(::niryo_one_msgs::srv::GetCalibrationCam_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::GetCalibrationCam_Response camera_info(::niryo_one_msgs::srv::GetCalibrationCam_Response::_camera_info_type arg)
  {
    msg_.camera_info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetCalibrationCam_Response msg_;
};

class Init_GetCalibrationCam_Response_is_set
{
public:
  Init_GetCalibrationCam_Response_is_set()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetCalibrationCam_Response_camera_info is_set(::niryo_one_msgs::srv::GetCalibrationCam_Response::_is_set_type arg)
  {
    msg_.is_set = std::move(arg);
    return Init_GetCalibrationCam_Response_camera_info(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetCalibrationCam_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetCalibrationCam_Response>()
{
  return niryo_one_msgs::srv::builder::Init_GetCalibrationCam_Response_is_set();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCalibrationCam_Event_response
{
public:
  explicit Init_GetCalibrationCam_Event_response(::niryo_one_msgs::srv::GetCalibrationCam_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::GetCalibrationCam_Event response(::niryo_one_msgs::srv::GetCalibrationCam_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetCalibrationCam_Event msg_;
};

class Init_GetCalibrationCam_Event_request
{
public:
  explicit Init_GetCalibrationCam_Event_request(::niryo_one_msgs::srv::GetCalibrationCam_Event & msg)
  : msg_(msg)
  {}
  Init_GetCalibrationCam_Event_response request(::niryo_one_msgs::srv::GetCalibrationCam_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetCalibrationCam_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetCalibrationCam_Event msg_;
};

class Init_GetCalibrationCam_Event_info
{
public:
  Init_GetCalibrationCam_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetCalibrationCam_Event_request info(::niryo_one_msgs::srv::GetCalibrationCam_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetCalibrationCam_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetCalibrationCam_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetCalibrationCam_Event>()
{
  return niryo_one_msgs::srv::builder::Init_GetCalibrationCam_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_CALIBRATION_CAM__BUILDER_HPP_
