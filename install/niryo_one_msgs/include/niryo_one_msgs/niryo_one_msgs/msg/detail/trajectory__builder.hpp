// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/trajectory.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_Trajectory_trajectory_plan
{
public:
  explicit Init_Trajectory_trajectory_plan(::niryo_one_msgs::msg::Trajectory & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::Trajectory trajectory_plan(::niryo_one_msgs::msg::Trajectory::_trajectory_plan_type arg)
  {
    msg_.trajectory_plan = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::Trajectory msg_;
};

class Init_Trajectory_description
{
public:
  explicit Init_Trajectory_description(::niryo_one_msgs::msg::Trajectory & msg)
  : msg_(msg)
  {}
  Init_Trajectory_trajectory_plan description(::niryo_one_msgs::msg::Trajectory::_description_type arg)
  {
    msg_.description = std::move(arg);
    return Init_Trajectory_trajectory_plan(msg_);
  }

private:
  ::niryo_one_msgs::msg::Trajectory msg_;
};

class Init_Trajectory_name
{
public:
  explicit Init_Trajectory_name(::niryo_one_msgs::msg::Trajectory & msg)
  : msg_(msg)
  {}
  Init_Trajectory_description name(::niryo_one_msgs::msg::Trajectory::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Trajectory_description(msg_);
  }

private:
  ::niryo_one_msgs::msg::Trajectory msg_;
};

class Init_Trajectory_id
{
public:
  Init_Trajectory_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trajectory_name id(::niryo_one_msgs::msg::Trajectory::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Trajectory_name(msg_);
  }

private:
  ::niryo_one_msgs::msg::Trajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::Trajectory>()
{
  return niryo_one_msgs::msg::builder::Init_Trajectory_id();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
