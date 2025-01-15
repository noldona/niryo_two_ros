// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/PingDxlTool.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/ping_dxl_tool.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__PING_DXL_TOOL__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__PING_DXL_TOOL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/ping_dxl_tool__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_PingDxlTool_Request_name
{
public:
  explicit Init_PingDxlTool_Request_name(::niryo_one_msgs::srv::PingDxlTool_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::PingDxlTool_Request name(::niryo_one_msgs::srv::PingDxlTool_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::PingDxlTool_Request msg_;
};

class Init_PingDxlTool_Request_id
{
public:
  Init_PingDxlTool_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PingDxlTool_Request_name id(::niryo_one_msgs::srv::PingDxlTool_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_PingDxlTool_Request_name(msg_);
  }

private:
  ::niryo_one_msgs::srv::PingDxlTool_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::PingDxlTool_Request>()
{
  return niryo_one_msgs::srv::builder::Init_PingDxlTool_Request_id();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_PingDxlTool_Response_state
{
public:
  Init_PingDxlTool_Response_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::PingDxlTool_Response state(::niryo_one_msgs::srv::PingDxlTool_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::PingDxlTool_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::PingDxlTool_Response>()
{
  return niryo_one_msgs::srv::builder::Init_PingDxlTool_Response_state();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_PingDxlTool_Event_response
{
public:
  explicit Init_PingDxlTool_Event_response(::niryo_one_msgs::srv::PingDxlTool_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::PingDxlTool_Event response(::niryo_one_msgs::srv::PingDxlTool_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::PingDxlTool_Event msg_;
};

class Init_PingDxlTool_Event_request
{
public:
  explicit Init_PingDxlTool_Event_request(::niryo_one_msgs::srv::PingDxlTool_Event & msg)
  : msg_(msg)
  {}
  Init_PingDxlTool_Event_response request(::niryo_one_msgs::srv::PingDxlTool_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PingDxlTool_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::PingDxlTool_Event msg_;
};

class Init_PingDxlTool_Event_info
{
public:
  Init_PingDxlTool_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PingDxlTool_Event_request info(::niryo_one_msgs::srv::PingDxlTool_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PingDxlTool_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::PingDxlTool_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::PingDxlTool_Event>()
{
  return niryo_one_msgs::srv::builder::Init_PingDxlTool_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__PING_DXL_TOOL__BUILDER_HPP_
