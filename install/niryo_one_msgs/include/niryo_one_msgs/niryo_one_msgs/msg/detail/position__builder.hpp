// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/Position.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/position.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_Position_quaternion
{
public:
  explicit Init_Position_quaternion(::niryo_one_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::Position quaternion(::niryo_one_msgs::msg::Position::_quaternion_type arg)
  {
    msg_.quaternion = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::Position msg_;
};

class Init_Position_point
{
public:
  explicit Init_Position_point(::niryo_one_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_quaternion point(::niryo_one_msgs::msg::Position::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_Position_quaternion(msg_);
  }

private:
  ::niryo_one_msgs::msg::Position msg_;
};

class Init_Position_rpy
{
public:
  explicit Init_Position_rpy(::niryo_one_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_point rpy(::niryo_one_msgs::msg::Position::_rpy_type arg)
  {
    msg_.rpy = std::move(arg);
    return Init_Position_point(msg_);
  }

private:
  ::niryo_one_msgs::msg::Position msg_;
};

class Init_Position_joints
{
public:
  explicit Init_Position_joints(::niryo_one_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_rpy joints(::niryo_one_msgs::msg::Position::_joints_type arg)
  {
    msg_.joints = std::move(arg);
    return Init_Position_rpy(msg_);
  }

private:
  ::niryo_one_msgs::msg::Position msg_;
};

class Init_Position_name
{
public:
  Init_Position_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Position_joints name(::niryo_one_msgs::msg::Position::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Position_joints(msg_);
  }

private:
  ::niryo_one_msgs::msg::Position msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::Position>()
{
  return niryo_one_msgs::msg::builder::Init_Position_name();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_
