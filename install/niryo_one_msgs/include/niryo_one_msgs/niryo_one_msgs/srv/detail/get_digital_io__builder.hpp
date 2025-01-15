// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/GetDigitalIO.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_digital_io.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_DIGITAL_IO__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_DIGITAL_IO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/get_digital_io__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetDigitalIO_Request_pin
{
public:
  Init_GetDigitalIO_Request_pin()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::GetDigitalIO_Request pin(::niryo_one_msgs::srv::GetDigitalIO_Request::_pin_type arg)
  {
    msg_.pin = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetDigitalIO_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetDigitalIO_Request>()
{
  return niryo_one_msgs::srv::builder::Init_GetDigitalIO_Request_pin();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetDigitalIO_Response_state
{
public:
  explicit Init_GetDigitalIO_Response_state(::niryo_one_msgs::srv::GetDigitalIO_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::GetDigitalIO_Response state(::niryo_one_msgs::srv::GetDigitalIO_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetDigitalIO_Response msg_;
};

class Init_GetDigitalIO_Response_mode
{
public:
  explicit Init_GetDigitalIO_Response_mode(::niryo_one_msgs::srv::GetDigitalIO_Response & msg)
  : msg_(msg)
  {}
  Init_GetDigitalIO_Response_state mode(::niryo_one_msgs::srv::GetDigitalIO_Response::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_GetDigitalIO_Response_state(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetDigitalIO_Response msg_;
};

class Init_GetDigitalIO_Response_name
{
public:
  explicit Init_GetDigitalIO_Response_name(::niryo_one_msgs::srv::GetDigitalIO_Response & msg)
  : msg_(msg)
  {}
  Init_GetDigitalIO_Response_mode name(::niryo_one_msgs::srv::GetDigitalIO_Response::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_GetDigitalIO_Response_mode(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetDigitalIO_Response msg_;
};

class Init_GetDigitalIO_Response_pin
{
public:
  explicit Init_GetDigitalIO_Response_pin(::niryo_one_msgs::srv::GetDigitalIO_Response & msg)
  : msg_(msg)
  {}
  Init_GetDigitalIO_Response_name pin(::niryo_one_msgs::srv::GetDigitalIO_Response::_pin_type arg)
  {
    msg_.pin = std::move(arg);
    return Init_GetDigitalIO_Response_name(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetDigitalIO_Response msg_;
};

class Init_GetDigitalIO_Response_message
{
public:
  explicit Init_GetDigitalIO_Response_message(::niryo_one_msgs::srv::GetDigitalIO_Response & msg)
  : msg_(msg)
  {}
  Init_GetDigitalIO_Response_pin message(::niryo_one_msgs::srv::GetDigitalIO_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GetDigitalIO_Response_pin(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetDigitalIO_Response msg_;
};

class Init_GetDigitalIO_Response_status
{
public:
  Init_GetDigitalIO_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetDigitalIO_Response_message status(::niryo_one_msgs::srv::GetDigitalIO_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GetDigitalIO_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetDigitalIO_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetDigitalIO_Response>()
{
  return niryo_one_msgs::srv::builder::Init_GetDigitalIO_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetDigitalIO_Event_response
{
public:
  explicit Init_GetDigitalIO_Event_response(::niryo_one_msgs::srv::GetDigitalIO_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::GetDigitalIO_Event response(::niryo_one_msgs::srv::GetDigitalIO_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetDigitalIO_Event msg_;
};

class Init_GetDigitalIO_Event_request
{
public:
  explicit Init_GetDigitalIO_Event_request(::niryo_one_msgs::srv::GetDigitalIO_Event & msg)
  : msg_(msg)
  {}
  Init_GetDigitalIO_Event_response request(::niryo_one_msgs::srv::GetDigitalIO_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetDigitalIO_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetDigitalIO_Event msg_;
};

class Init_GetDigitalIO_Event_info
{
public:
  Init_GetDigitalIO_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetDigitalIO_Event_request info(::niryo_one_msgs::srv::GetDigitalIO_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetDigitalIO_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetDigitalIO_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetDigitalIO_Event>()
{
  return niryo_one_msgs::srv::builder::Init_GetDigitalIO_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_DIGITAL_IO__BUILDER_HPP_
