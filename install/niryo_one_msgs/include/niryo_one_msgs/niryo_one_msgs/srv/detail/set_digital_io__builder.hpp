// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/SetDigitalIO.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/set_digital_io.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__SET_DIGITAL_IO__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__SET_DIGITAL_IO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/set_digital_io__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SetDigitalIO_Request_value
{
public:
  explicit Init_SetDigitalIO_Request_value(::niryo_one_msgs::srv::SetDigitalIO_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::SetDigitalIO_Request value(::niryo_one_msgs::srv::SetDigitalIO_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetDigitalIO_Request msg_;
};

class Init_SetDigitalIO_Request_pin
{
public:
  Init_SetDigitalIO_Request_pin()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetDigitalIO_Request_value pin(::niryo_one_msgs::srv::SetDigitalIO_Request::_pin_type arg)
  {
    msg_.pin = std::move(arg);
    return Init_SetDigitalIO_Request_value(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetDigitalIO_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SetDigitalIO_Request>()
{
  return niryo_one_msgs::srv::builder::Init_SetDigitalIO_Request_pin();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SetDigitalIO_Response_message
{
public:
  explicit Init_SetDigitalIO_Response_message(::niryo_one_msgs::srv::SetDigitalIO_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::SetDigitalIO_Response message(::niryo_one_msgs::srv::SetDigitalIO_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetDigitalIO_Response msg_;
};

class Init_SetDigitalIO_Response_status
{
public:
  Init_SetDigitalIO_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetDigitalIO_Response_message status(::niryo_one_msgs::srv::SetDigitalIO_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_SetDigitalIO_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetDigitalIO_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SetDigitalIO_Response>()
{
  return niryo_one_msgs::srv::builder::Init_SetDigitalIO_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SetDigitalIO_Event_response
{
public:
  explicit Init_SetDigitalIO_Event_response(::niryo_one_msgs::srv::SetDigitalIO_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::SetDigitalIO_Event response(::niryo_one_msgs::srv::SetDigitalIO_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetDigitalIO_Event msg_;
};

class Init_SetDigitalIO_Event_request
{
public:
  explicit Init_SetDigitalIO_Event_request(::niryo_one_msgs::srv::SetDigitalIO_Event & msg)
  : msg_(msg)
  {}
  Init_SetDigitalIO_Event_response request(::niryo_one_msgs::srv::SetDigitalIO_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetDigitalIO_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetDigitalIO_Event msg_;
};

class Init_SetDigitalIO_Event_info
{
public:
  Init_SetDigitalIO_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetDigitalIO_Event_request info(::niryo_one_msgs::srv::SetDigitalIO_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetDigitalIO_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetDigitalIO_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SetDigitalIO_Event>()
{
  return niryo_one_msgs::srv::builder::Init_SetDigitalIO_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__SET_DIGITAL_IO__BUILDER_HPP_
