// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/robot_state.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotState_rpy
{
public:
  explicit Init_RobotState_rpy(::niryo_one_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::RobotState rpy(::niryo_one_msgs::msg::RobotState::_rpy_type arg)
  {
    msg_.rpy = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::RobotState msg_;
};

class Init_RobotState_position
{
public:
  Init_RobotState_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotState_rpy position(::niryo_one_msgs::msg::RobotState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_RobotState_rpy(msg_);
  }

private:
  ::niryo_one_msgs::msg::RobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::RobotState>()
{
  return niryo_one_msgs::msg::builder::Init_RobotState_position();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
