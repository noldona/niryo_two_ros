// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/OpenGripper.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/open_gripper.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__OPEN_GRIPPER__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__OPEN_GRIPPER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/open_gripper__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_OpenGripper_Request_open_hold_torque
{
public:
  explicit Init_OpenGripper_Request_open_hold_torque(::niryo_one_msgs::srv::OpenGripper_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::OpenGripper_Request open_hold_torque(::niryo_one_msgs::srv::OpenGripper_Request::_open_hold_torque_type arg)
  {
    msg_.open_hold_torque = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::OpenGripper_Request msg_;
};

class Init_OpenGripper_Request_open_speed
{
public:
  explicit Init_OpenGripper_Request_open_speed(::niryo_one_msgs::srv::OpenGripper_Request & msg)
  : msg_(msg)
  {}
  Init_OpenGripper_Request_open_hold_torque open_speed(::niryo_one_msgs::srv::OpenGripper_Request::_open_speed_type arg)
  {
    msg_.open_speed = std::move(arg);
    return Init_OpenGripper_Request_open_hold_torque(msg_);
  }

private:
  ::niryo_one_msgs::srv::OpenGripper_Request msg_;
};

class Init_OpenGripper_Request_open_position
{
public:
  explicit Init_OpenGripper_Request_open_position(::niryo_one_msgs::srv::OpenGripper_Request & msg)
  : msg_(msg)
  {}
  Init_OpenGripper_Request_open_speed open_position(::niryo_one_msgs::srv::OpenGripper_Request::_open_position_type arg)
  {
    msg_.open_position = std::move(arg);
    return Init_OpenGripper_Request_open_speed(msg_);
  }

private:
  ::niryo_one_msgs::srv::OpenGripper_Request msg_;
};

class Init_OpenGripper_Request_id
{
public:
  Init_OpenGripper_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OpenGripper_Request_open_position id(::niryo_one_msgs::srv::OpenGripper_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_OpenGripper_Request_open_position(msg_);
  }

private:
  ::niryo_one_msgs::srv::OpenGripper_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::OpenGripper_Request>()
{
  return niryo_one_msgs::srv::builder::Init_OpenGripper_Request_id();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_OpenGripper_Response_state
{
public:
  Init_OpenGripper_Response_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::OpenGripper_Response state(::niryo_one_msgs::srv::OpenGripper_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::OpenGripper_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::OpenGripper_Response>()
{
  return niryo_one_msgs::srv::builder::Init_OpenGripper_Response_state();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_OpenGripper_Event_response
{
public:
  explicit Init_OpenGripper_Event_response(::niryo_one_msgs::srv::OpenGripper_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::OpenGripper_Event response(::niryo_one_msgs::srv::OpenGripper_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::OpenGripper_Event msg_;
};

class Init_OpenGripper_Event_request
{
public:
  explicit Init_OpenGripper_Event_request(::niryo_one_msgs::srv::OpenGripper_Event & msg)
  : msg_(msg)
  {}
  Init_OpenGripper_Event_response request(::niryo_one_msgs::srv::OpenGripper_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_OpenGripper_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::OpenGripper_Event msg_;
};

class Init_OpenGripper_Event_info
{
public:
  Init_OpenGripper_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OpenGripper_Event_request info(::niryo_one_msgs::srv::OpenGripper_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_OpenGripper_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::OpenGripper_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::OpenGripper_Event>()
{
  return niryo_one_msgs::srv::builder::Init_OpenGripper_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__OPEN_GRIPPER__BUILDER_HPP_
