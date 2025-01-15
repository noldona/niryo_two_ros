// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/ObjectPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/object_pose.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__OBJECT_POSE__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__OBJECT_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/object_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_ObjectPose_yaw
{
public:
  explicit Init_ObjectPose_yaw(::niryo_one_msgs::msg::ObjectPose & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::ObjectPose yaw(::niryo_one_msgs::msg::ObjectPose::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::ObjectPose msg_;
};

class Init_ObjectPose_pitch
{
public:
  explicit Init_ObjectPose_pitch(::niryo_one_msgs::msg::ObjectPose & msg)
  : msg_(msg)
  {}
  Init_ObjectPose_yaw pitch(::niryo_one_msgs::msg::ObjectPose::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_ObjectPose_yaw(msg_);
  }

private:
  ::niryo_one_msgs::msg::ObjectPose msg_;
};

class Init_ObjectPose_roll
{
public:
  explicit Init_ObjectPose_roll(::niryo_one_msgs::msg::ObjectPose & msg)
  : msg_(msg)
  {}
  Init_ObjectPose_pitch roll(::niryo_one_msgs::msg::ObjectPose::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_ObjectPose_pitch(msg_);
  }

private:
  ::niryo_one_msgs::msg::ObjectPose msg_;
};

class Init_ObjectPose_z
{
public:
  explicit Init_ObjectPose_z(::niryo_one_msgs::msg::ObjectPose & msg)
  : msg_(msg)
  {}
  Init_ObjectPose_roll z(::niryo_one_msgs::msg::ObjectPose::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_ObjectPose_roll(msg_);
  }

private:
  ::niryo_one_msgs::msg::ObjectPose msg_;
};

class Init_ObjectPose_y
{
public:
  explicit Init_ObjectPose_y(::niryo_one_msgs::msg::ObjectPose & msg)
  : msg_(msg)
  {}
  Init_ObjectPose_z y(::niryo_one_msgs::msg::ObjectPose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_ObjectPose_z(msg_);
  }

private:
  ::niryo_one_msgs::msg::ObjectPose msg_;
};

class Init_ObjectPose_x
{
public:
  Init_ObjectPose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectPose_y x(::niryo_one_msgs::msg::ObjectPose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ObjectPose_y(msg_);
  }

private:
  ::niryo_one_msgs::msg::ObjectPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::ObjectPose>()
{
  return niryo_one_msgs::msg::builder::Init_ObjectPose_x();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__OBJECT_POSE__BUILDER_HPP_
