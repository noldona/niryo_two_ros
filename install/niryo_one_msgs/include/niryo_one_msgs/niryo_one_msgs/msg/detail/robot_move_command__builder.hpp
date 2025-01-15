// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/RobotMoveCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/robot_move_command.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_MOVE_COMMAND__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_MOVE_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/robot_move_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotMoveCommand_tool_cmd
{
public:
  explicit Init_RobotMoveCommand_tool_cmd(::niryo_one_msgs::msg::RobotMoveCommand & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::RobotMoveCommand tool_cmd(::niryo_one_msgs::msg::RobotMoveCommand::_tool_cmd_type arg)
  {
    msg_.tool_cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::RobotMoveCommand msg_;
};

class Init_RobotMoveCommand_saved_trajectory_id
{
public:
  explicit Init_RobotMoveCommand_saved_trajectory_id(::niryo_one_msgs::msg::RobotMoveCommand & msg)
  : msg_(msg)
  {}
  Init_RobotMoveCommand_tool_cmd saved_trajectory_id(::niryo_one_msgs::msg::RobotMoveCommand::_saved_trajectory_id_type arg)
  {
    msg_.saved_trajectory_id = std::move(arg);
    return Init_RobotMoveCommand_tool_cmd(msg_);
  }

private:
  ::niryo_one_msgs::msg::RobotMoveCommand msg_;
};

class Init_RobotMoveCommand_saved_position_name
{
public:
  explicit Init_RobotMoveCommand_saved_position_name(::niryo_one_msgs::msg::RobotMoveCommand & msg)
  : msg_(msg)
  {}
  Init_RobotMoveCommand_saved_trajectory_id saved_position_name(::niryo_one_msgs::msg::RobotMoveCommand::_saved_position_name_type arg)
  {
    msg_.saved_position_name = std::move(arg);
    return Init_RobotMoveCommand_saved_trajectory_id(msg_);
  }

private:
  ::niryo_one_msgs::msg::RobotMoveCommand msg_;
};

class Init_RobotMoveCommand_pose_quat
{
public:
  explicit Init_RobotMoveCommand_pose_quat(::niryo_one_msgs::msg::RobotMoveCommand & msg)
  : msg_(msg)
  {}
  Init_RobotMoveCommand_saved_position_name pose_quat(::niryo_one_msgs::msg::RobotMoveCommand::_pose_quat_type arg)
  {
    msg_.pose_quat = std::move(arg);
    return Init_RobotMoveCommand_saved_position_name(msg_);
  }

private:
  ::niryo_one_msgs::msg::RobotMoveCommand msg_;
};

class Init_RobotMoveCommand_trajectory
{
public:
  explicit Init_RobotMoveCommand_trajectory(::niryo_one_msgs::msg::RobotMoveCommand & msg)
  : msg_(msg)
  {}
  Init_RobotMoveCommand_pose_quat trajectory(::niryo_one_msgs::msg::RobotMoveCommand::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return Init_RobotMoveCommand_pose_quat(msg_);
  }

private:
  ::niryo_one_msgs::msg::RobotMoveCommand msg_;
};

class Init_RobotMoveCommand_shift
{
public:
  explicit Init_RobotMoveCommand_shift(::niryo_one_msgs::msg::RobotMoveCommand & msg)
  : msg_(msg)
  {}
  Init_RobotMoveCommand_trajectory shift(::niryo_one_msgs::msg::RobotMoveCommand::_shift_type arg)
  {
    msg_.shift = std::move(arg);
    return Init_RobotMoveCommand_trajectory(msg_);
  }

private:
  ::niryo_one_msgs::msg::RobotMoveCommand msg_;
};

class Init_RobotMoveCommand_rpy
{
public:
  explicit Init_RobotMoveCommand_rpy(::niryo_one_msgs::msg::RobotMoveCommand & msg)
  : msg_(msg)
  {}
  Init_RobotMoveCommand_shift rpy(::niryo_one_msgs::msg::RobotMoveCommand::_rpy_type arg)
  {
    msg_.rpy = std::move(arg);
    return Init_RobotMoveCommand_shift(msg_);
  }

private:
  ::niryo_one_msgs::msg::RobotMoveCommand msg_;
};

class Init_RobotMoveCommand_position
{
public:
  explicit Init_RobotMoveCommand_position(::niryo_one_msgs::msg::RobotMoveCommand & msg)
  : msg_(msg)
  {}
  Init_RobotMoveCommand_rpy position(::niryo_one_msgs::msg::RobotMoveCommand::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_RobotMoveCommand_rpy(msg_);
  }

private:
  ::niryo_one_msgs::msg::RobotMoveCommand msg_;
};

class Init_RobotMoveCommand_joints
{
public:
  explicit Init_RobotMoveCommand_joints(::niryo_one_msgs::msg::RobotMoveCommand & msg)
  : msg_(msg)
  {}
  Init_RobotMoveCommand_position joints(::niryo_one_msgs::msg::RobotMoveCommand::_joints_type arg)
  {
    msg_.joints = std::move(arg);
    return Init_RobotMoveCommand_position(msg_);
  }

private:
  ::niryo_one_msgs::msg::RobotMoveCommand msg_;
};

class Init_RobotMoveCommand_cmd_type
{
public:
  Init_RobotMoveCommand_cmd_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMoveCommand_joints cmd_type(::niryo_one_msgs::msg::RobotMoveCommand::_cmd_type_type arg)
  {
    msg_.cmd_type = std::move(arg);
    return Init_RobotMoveCommand_joints(msg_);
  }

private:
  ::niryo_one_msgs::msg::RobotMoveCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::RobotMoveCommand>()
{
  return niryo_one_msgs::msg::builder::Init_RobotMoveCommand_cmd_type();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_MOVE_COMMAND__BUILDER_HPP_
