// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/ToolCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/tool_command.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__TOOL_COMMAND__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__TOOL_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/tool_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_ToolCommand_gpio
{
public:
  explicit Init_ToolCommand_gpio(::niryo_one_msgs::msg::ToolCommand & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::ToolCommand gpio(::niryo_one_msgs::msg::ToolCommand::_gpio_type arg)
  {
    msg_.gpio = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::ToolCommand msg_;
};

class Init_ToolCommand_activate
{
public:
  explicit Init_ToolCommand_activate(::niryo_one_msgs::msg::ToolCommand & msg)
  : msg_(msg)
  {}
  Init_ToolCommand_gpio activate(::niryo_one_msgs::msg::ToolCommand::_activate_type arg)
  {
    msg_.activate = std::move(arg);
    return Init_ToolCommand_gpio(msg_);
  }

private:
  ::niryo_one_msgs::msg::ToolCommand msg_;
};

class Init_ToolCommand_gripper_open_speed
{
public:
  explicit Init_ToolCommand_gripper_open_speed(::niryo_one_msgs::msg::ToolCommand & msg)
  : msg_(msg)
  {}
  Init_ToolCommand_activate gripper_open_speed(::niryo_one_msgs::msg::ToolCommand::_gripper_open_speed_type arg)
  {
    msg_.gripper_open_speed = std::move(arg);
    return Init_ToolCommand_activate(msg_);
  }

private:
  ::niryo_one_msgs::msg::ToolCommand msg_;
};

class Init_ToolCommand_gripper_close_speed
{
public:
  explicit Init_ToolCommand_gripper_close_speed(::niryo_one_msgs::msg::ToolCommand & msg)
  : msg_(msg)
  {}
  Init_ToolCommand_gripper_open_speed gripper_close_speed(::niryo_one_msgs::msg::ToolCommand::_gripper_close_speed_type arg)
  {
    msg_.gripper_close_speed = std::move(arg);
    return Init_ToolCommand_gripper_open_speed(msg_);
  }

private:
  ::niryo_one_msgs::msg::ToolCommand msg_;
};

class Init_ToolCommand_cmd_type
{
public:
  explicit Init_ToolCommand_cmd_type(::niryo_one_msgs::msg::ToolCommand & msg)
  : msg_(msg)
  {}
  Init_ToolCommand_gripper_close_speed cmd_type(::niryo_one_msgs::msg::ToolCommand::_cmd_type_type arg)
  {
    msg_.cmd_type = std::move(arg);
    return Init_ToolCommand_gripper_close_speed(msg_);
  }

private:
  ::niryo_one_msgs::msg::ToolCommand msg_;
};

class Init_ToolCommand_tool_id
{
public:
  Init_ToolCommand_tool_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ToolCommand_cmd_type tool_id(::niryo_one_msgs::msg::ToolCommand::_tool_id_type arg)
  {
    msg_.tool_id = std::move(arg);
    return Init_ToolCommand_cmd_type(msg_);
  }

private:
  ::niryo_one_msgs::msg::ToolCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::ToolCommand>()
{
  return niryo_one_msgs::msg::builder::Init_ToolCommand_tool_id();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__TOOL_COMMAND__BUILDER_HPP_
