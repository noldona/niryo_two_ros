// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/RobotMove.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/robot_move.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__ROBOT_MOVE__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__ROBOT_MOVE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/robot_move__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_RobotMove_Request_cmd
{
public:
  Init_RobotMove_Request_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::RobotMove_Request cmd(::niryo_one_msgs::srv::RobotMove_Request::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::RobotMove_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::RobotMove_Request>()
{
  return niryo_one_msgs::srv::builder::Init_RobotMove_Request_cmd();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_RobotMove_Response_message
{
public:
  explicit Init_RobotMove_Response_message(::niryo_one_msgs::srv::RobotMove_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::RobotMove_Response message(::niryo_one_msgs::srv::RobotMove_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::RobotMove_Response msg_;
};

class Init_RobotMove_Response_status
{
public:
  Init_RobotMove_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMove_Response_message status(::niryo_one_msgs::srv::RobotMove_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_RobotMove_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::RobotMove_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::RobotMove_Response>()
{
  return niryo_one_msgs::srv::builder::Init_RobotMove_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_RobotMove_Event_response
{
public:
  explicit Init_RobotMove_Event_response(::niryo_one_msgs::srv::RobotMove_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::RobotMove_Event response(::niryo_one_msgs::srv::RobotMove_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::RobotMove_Event msg_;
};

class Init_RobotMove_Event_request
{
public:
  explicit Init_RobotMove_Event_request(::niryo_one_msgs::srv::RobotMove_Event & msg)
  : msg_(msg)
  {}
  Init_RobotMove_Event_response request(::niryo_one_msgs::srv::RobotMove_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_RobotMove_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::RobotMove_Event msg_;
};

class Init_RobotMove_Event_info
{
public:
  Init_RobotMove_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMove_Event_request info(::niryo_one_msgs::srv::RobotMove_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_RobotMove_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::RobotMove_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::RobotMove_Event>()
{
  return niryo_one_msgs::srv::builder::Init_RobotMove_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__ROBOT_MOVE__BUILDER_HPP_
