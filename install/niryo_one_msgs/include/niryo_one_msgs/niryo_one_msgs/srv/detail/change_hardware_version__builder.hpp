// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/ChangeHardwareVersion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/change_hardware_version.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__CHANGE_HARDWARE_VERSION__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__CHANGE_HARDWARE_VERSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/change_hardware_version__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ChangeHardwareVersion_Request_new_version
{
public:
  explicit Init_ChangeHardwareVersion_Request_new_version(::niryo_one_msgs::srv::ChangeHardwareVersion_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ChangeHardwareVersion_Request new_version(::niryo_one_msgs::srv::ChangeHardwareVersion_Request::_new_version_type arg)
  {
    msg_.new_version = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ChangeHardwareVersion_Request msg_;
};

class Init_ChangeHardwareVersion_Request_old_version
{
public:
  Init_ChangeHardwareVersion_Request_old_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChangeHardwareVersion_Request_new_version old_version(::niryo_one_msgs::srv::ChangeHardwareVersion_Request::_old_version_type arg)
  {
    msg_.old_version = std::move(arg);
    return Init_ChangeHardwareVersion_Request_new_version(msg_);
  }

private:
  ::niryo_one_msgs::srv::ChangeHardwareVersion_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ChangeHardwareVersion_Request>()
{
  return niryo_one_msgs::srv::builder::Init_ChangeHardwareVersion_Request_old_version();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ChangeHardwareVersion_Response_message
{
public:
  explicit Init_ChangeHardwareVersion_Response_message(::niryo_one_msgs::srv::ChangeHardwareVersion_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ChangeHardwareVersion_Response message(::niryo_one_msgs::srv::ChangeHardwareVersion_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ChangeHardwareVersion_Response msg_;
};

class Init_ChangeHardwareVersion_Response_status
{
public:
  Init_ChangeHardwareVersion_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChangeHardwareVersion_Response_message status(::niryo_one_msgs::srv::ChangeHardwareVersion_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ChangeHardwareVersion_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::ChangeHardwareVersion_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ChangeHardwareVersion_Response>()
{
  return niryo_one_msgs::srv::builder::Init_ChangeHardwareVersion_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ChangeHardwareVersion_Event_response
{
public:
  explicit Init_ChangeHardwareVersion_Event_response(::niryo_one_msgs::srv::ChangeHardwareVersion_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ChangeHardwareVersion_Event response(::niryo_one_msgs::srv::ChangeHardwareVersion_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ChangeHardwareVersion_Event msg_;
};

class Init_ChangeHardwareVersion_Event_request
{
public:
  explicit Init_ChangeHardwareVersion_Event_request(::niryo_one_msgs::srv::ChangeHardwareVersion_Event & msg)
  : msg_(msg)
  {}
  Init_ChangeHardwareVersion_Event_response request(::niryo_one_msgs::srv::ChangeHardwareVersion_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ChangeHardwareVersion_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::ChangeHardwareVersion_Event msg_;
};

class Init_ChangeHardwareVersion_Event_info
{
public:
  Init_ChangeHardwareVersion_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChangeHardwareVersion_Event_request info(::niryo_one_msgs::srv::ChangeHardwareVersion_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ChangeHardwareVersion_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::ChangeHardwareVersion_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ChangeHardwareVersion_Event>()
{
  return niryo_one_msgs::srv::builder::Init_ChangeHardwareVersion_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__CHANGE_HARDWARE_VERSION__BUILDER_HPP_
