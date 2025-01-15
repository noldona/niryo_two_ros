// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/TrajectoryPlan.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/trajectory_plan.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY_PLAN__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY_PLAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/trajectory_plan__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_TrajectoryPlan_trajectory
{
public:
  explicit Init_TrajectoryPlan_trajectory(::niryo_one_msgs::msg::TrajectoryPlan & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::TrajectoryPlan trajectory(::niryo_one_msgs::msg::TrajectoryPlan::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::TrajectoryPlan msg_;
};

class Init_TrajectoryPlan_group_name
{
public:
  explicit Init_TrajectoryPlan_group_name(::niryo_one_msgs::msg::TrajectoryPlan & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPlan_trajectory group_name(::niryo_one_msgs::msg::TrajectoryPlan::_group_name_type arg)
  {
    msg_.group_name = std::move(arg);
    return Init_TrajectoryPlan_trajectory(msg_);
  }

private:
  ::niryo_one_msgs::msg::TrajectoryPlan msg_;
};

class Init_TrajectoryPlan_trajectory_start
{
public:
  Init_TrajectoryPlan_trajectory_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryPlan_group_name trajectory_start(::niryo_one_msgs::msg::TrajectoryPlan::_trajectory_start_type arg)
  {
    msg_.trajectory_start = std::move(arg);
    return Init_TrajectoryPlan_group_name(msg_);
  }

private:
  ::niryo_one_msgs::msg::TrajectoryPlan msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::TrajectoryPlan>()
{
  return niryo_one_msgs::msg::builder::Init_TrajectoryPlan_trajectory_start();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY_PLAN__BUILDER_HPP_
