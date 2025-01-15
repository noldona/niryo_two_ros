// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/SetLeds.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/set_leds.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__SET_LEDS__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__SET_LEDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/set_leds__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SetLeds_Request_values
{
public:
  Init_SetLeds_Request_values()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::SetLeds_Request values(::niryo_one_msgs::srv::SetLeds_Request::_values_type arg)
  {
    msg_.values = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetLeds_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SetLeds_Request>()
{
  return niryo_one_msgs::srv::builder::Init_SetLeds_Request_values();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SetLeds_Response_message
{
public:
  explicit Init_SetLeds_Response_message(::niryo_one_msgs::srv::SetLeds_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::SetLeds_Response message(::niryo_one_msgs::srv::SetLeds_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetLeds_Response msg_;
};

class Init_SetLeds_Response_status
{
public:
  Init_SetLeds_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetLeds_Response_message status(::niryo_one_msgs::srv::SetLeds_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_SetLeds_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetLeds_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SetLeds_Response>()
{
  return niryo_one_msgs::srv::builder::Init_SetLeds_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SetLeds_Event_response
{
public:
  explicit Init_SetLeds_Event_response(::niryo_one_msgs::srv::SetLeds_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::SetLeds_Event response(::niryo_one_msgs::srv::SetLeds_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetLeds_Event msg_;
};

class Init_SetLeds_Event_request
{
public:
  explicit Init_SetLeds_Event_request(::niryo_one_msgs::srv::SetLeds_Event & msg)
  : msg_(msg)
  {}
  Init_SetLeds_Event_response request(::niryo_one_msgs::srv::SetLeds_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetLeds_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetLeds_Event msg_;
};

class Init_SetLeds_Event_info
{
public:
  Init_SetLeds_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetLeds_Event_request info(::niryo_one_msgs::srv::SetLeds_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetLeds_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetLeds_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SetLeds_Event>()
{
  return niryo_one_msgs::srv::builder::Init_SetLeds_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__SET_LEDS__BUILDER_HPP_
