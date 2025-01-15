// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/SetCalibrationCam.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/set_calibration_cam.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__SET_CALIBRATION_CAM__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__SET_CALIBRATION_CAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/set_calibration_cam__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SetCalibrationCam_Request_name
{
public:
  Init_SetCalibrationCam_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::SetCalibrationCam_Request name(::niryo_one_msgs::srv::SetCalibrationCam_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetCalibrationCam_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SetCalibrationCam_Request>()
{
  return niryo_one_msgs::srv::builder::Init_SetCalibrationCam_Request_name();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SetCalibrationCam_Response_status
{
public:
  Init_SetCalibrationCam_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::SetCalibrationCam_Response status(::niryo_one_msgs::srv::SetCalibrationCam_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetCalibrationCam_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SetCalibrationCam_Response>()
{
  return niryo_one_msgs::srv::builder::Init_SetCalibrationCam_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SetCalibrationCam_Event_response
{
public:
  explicit Init_SetCalibrationCam_Event_response(::niryo_one_msgs::srv::SetCalibrationCam_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::SetCalibrationCam_Event response(::niryo_one_msgs::srv::SetCalibrationCam_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetCalibrationCam_Event msg_;
};

class Init_SetCalibrationCam_Event_request
{
public:
  explicit Init_SetCalibrationCam_Event_request(::niryo_one_msgs::srv::SetCalibrationCam_Event & msg)
  : msg_(msg)
  {}
  Init_SetCalibrationCam_Event_response request(::niryo_one_msgs::srv::SetCalibrationCam_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetCalibrationCam_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetCalibrationCam_Event msg_;
};

class Init_SetCalibrationCam_Event_info
{
public:
  Init_SetCalibrationCam_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetCalibrationCam_Event_request info(::niryo_one_msgs::srv::SetCalibrationCam_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetCalibrationCam_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetCalibrationCam_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SetCalibrationCam_Event>()
{
  return niryo_one_msgs::srv::builder::Init_SetCalibrationCam_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__SET_CALIBRATION_CAM__BUILDER_HPP_
