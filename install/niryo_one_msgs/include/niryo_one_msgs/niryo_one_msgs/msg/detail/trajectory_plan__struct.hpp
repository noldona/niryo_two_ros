// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:msg/TrajectoryPlan.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/trajectory_plan.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY_PLAN__STRUCT_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY_PLAN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'trajectory_start'
#include "moveit_msgs/msg/detail/robot_state__struct.hpp"
// Member 'trajectory'
#include "moveit_msgs/msg/detail/robot_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__msg__TrajectoryPlan __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__msg__TrajectoryPlan __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrajectoryPlan_
{
  using Type = TrajectoryPlan_<ContainerAllocator>;

  explicit TrajectoryPlan_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory_start(_init),
    trajectory(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->group_name = "";
    }
  }

  explicit TrajectoryPlan_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory_start(_alloc, _init),
    group_name(_alloc),
    trajectory(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->group_name = "";
    }
  }

  // field types and members
  using _trajectory_start_type =
    moveit_msgs::msg::RobotState_<ContainerAllocator>;
  _trajectory_start_type trajectory_start;
  using _group_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _group_name_type group_name;
  using _trajectory_type =
    moveit_msgs::msg::RobotTrajectory_<ContainerAllocator>;
  _trajectory_type trajectory;

  // setters for named parameter idiom
  Type & set__trajectory_start(
    const moveit_msgs::msg::RobotState_<ContainerAllocator> & _arg)
  {
    this->trajectory_start = _arg;
    return *this;
  }
  Type & set__group_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->group_name = _arg;
    return *this;
  }
  Type & set__trajectory(
    const moveit_msgs::msg::RobotTrajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__msg__TrajectoryPlan
    std::shared_ptr<niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__msg__TrajectoryPlan
    std::shared_ptr<niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryPlan_ & other) const
  {
    if (this->trajectory_start != other.trajectory_start) {
      return false;
    }
    if (this->group_name != other.group_name) {
      return false;
    }
    if (this->trajectory != other.trajectory) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryPlan_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryPlan_

// alias to use template instance with default allocator
using TrajectoryPlan =
  niryo_one_msgs::msg::TrajectoryPlan_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__TRAJECTORY_PLAN__STRUCT_HPP_
