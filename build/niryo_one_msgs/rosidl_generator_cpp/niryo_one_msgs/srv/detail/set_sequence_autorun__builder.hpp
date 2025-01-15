// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/SetSequenceAutorun.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/set_sequence_autorun.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__SET_SEQUENCE_AUTORUN__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__SET_SEQUENCE_AUTORUN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/set_sequence_autorun__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SetSequenceAutorun_Request_sequence_ids
{
public:
  explicit Init_SetSequenceAutorun_Request_sequence_ids(::niryo_one_msgs::srv::SetSequenceAutorun_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::SetSequenceAutorun_Request sequence_ids(::niryo_one_msgs::srv::SetSequenceAutorun_Request::_sequence_ids_type arg)
  {
    msg_.sequence_ids = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetSequenceAutorun_Request msg_;
};

class Init_SetSequenceAutorun_Request_mode
{
public:
  explicit Init_SetSequenceAutorun_Request_mode(::niryo_one_msgs::srv::SetSequenceAutorun_Request & msg)
  : msg_(msg)
  {}
  Init_SetSequenceAutorun_Request_sequence_ids mode(::niryo_one_msgs::srv::SetSequenceAutorun_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_SetSequenceAutorun_Request_sequence_ids(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetSequenceAutorun_Request msg_;
};

class Init_SetSequenceAutorun_Request_enable
{
public:
  Init_SetSequenceAutorun_Request_enable()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetSequenceAutorun_Request_mode enable(::niryo_one_msgs::srv::SetSequenceAutorun_Request::_enable_type arg)
  {
    msg_.enable = std::move(arg);
    return Init_SetSequenceAutorun_Request_mode(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetSequenceAutorun_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SetSequenceAutorun_Request>()
{
  return niryo_one_msgs::srv::builder::Init_SetSequenceAutorun_Request_enable();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SetSequenceAutorun_Response_message
{
public:
  explicit Init_SetSequenceAutorun_Response_message(::niryo_one_msgs::srv::SetSequenceAutorun_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::SetSequenceAutorun_Response message(::niryo_one_msgs::srv::SetSequenceAutorun_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetSequenceAutorun_Response msg_;
};

class Init_SetSequenceAutorun_Response_status
{
public:
  Init_SetSequenceAutorun_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetSequenceAutorun_Response_message status(::niryo_one_msgs::srv::SetSequenceAutorun_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_SetSequenceAutorun_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetSequenceAutorun_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SetSequenceAutorun_Response>()
{
  return niryo_one_msgs::srv::builder::Init_SetSequenceAutorun_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SetSequenceAutorun_Event_response
{
public:
  explicit Init_SetSequenceAutorun_Event_response(::niryo_one_msgs::srv::SetSequenceAutorun_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::SetSequenceAutorun_Event response(::niryo_one_msgs::srv::SetSequenceAutorun_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetSequenceAutorun_Event msg_;
};

class Init_SetSequenceAutorun_Event_request
{
public:
  explicit Init_SetSequenceAutorun_Event_request(::niryo_one_msgs::srv::SetSequenceAutorun_Event & msg)
  : msg_(msg)
  {}
  Init_SetSequenceAutorun_Event_response request(::niryo_one_msgs::srv::SetSequenceAutorun_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetSequenceAutorun_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetSequenceAutorun_Event msg_;
};

class Init_SetSequenceAutorun_Event_info
{
public:
  Init_SetSequenceAutorun_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetSequenceAutorun_Event_request info(::niryo_one_msgs::srv::SetSequenceAutorun_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetSequenceAutorun_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::SetSequenceAutorun_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SetSequenceAutorun_Event>()
{
  return niryo_one_msgs::srv::builder::Init_SetSequenceAutorun_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__SET_SEQUENCE_AUTORUN__BUILDER_HPP_
