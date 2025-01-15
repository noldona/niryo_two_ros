// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/TakePicture.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/take_picture.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__TAKE_PICTURE__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__TAKE_PICTURE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/take_picture__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_TakePicture_Request_path
{
public:
  Init_TakePicture_Request_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::TakePicture_Request path(::niryo_one_msgs::srv::TakePicture_Request::_path_type arg)
  {
    msg_.path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::TakePicture_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::TakePicture_Request>()
{
  return niryo_one_msgs::srv::builder::Init_TakePicture_Request_path();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_TakePicture_Response_success
{
public:
  Init_TakePicture_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::TakePicture_Response success(::niryo_one_msgs::srv::TakePicture_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::TakePicture_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::TakePicture_Response>()
{
  return niryo_one_msgs::srv::builder::Init_TakePicture_Response_success();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_TakePicture_Event_response
{
public:
  explicit Init_TakePicture_Event_response(::niryo_one_msgs::srv::TakePicture_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::TakePicture_Event response(::niryo_one_msgs::srv::TakePicture_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::TakePicture_Event msg_;
};

class Init_TakePicture_Event_request
{
public:
  explicit Init_TakePicture_Event_request(::niryo_one_msgs::srv::TakePicture_Event & msg)
  : msg_(msg)
  {}
  Init_TakePicture_Event_response request(::niryo_one_msgs::srv::TakePicture_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_TakePicture_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::TakePicture_Event msg_;
};

class Init_TakePicture_Event_info
{
public:
  Init_TakePicture_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TakePicture_Event_request info(::niryo_one_msgs::srv::TakePicture_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_TakePicture_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::TakePicture_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::TakePicture_Event>()
{
  return niryo_one_msgs::srv::builder::Init_TakePicture_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__TAKE_PICTURE__BUILDER_HPP_
