// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:msg/RobotMoveCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/robot_move_command.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_MOVE_COMMAND__STRUCT_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_MOVE_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'rpy'
#include "niryo_one_msgs/msg/detail/rpy__struct.hpp"
// Member 'shift'
#include "niryo_one_msgs/msg/detail/shift_pose__struct.hpp"
// Member 'trajectory'
#include "niryo_one_msgs/msg/detail/trajectory_plan__struct.hpp"
// Member 'pose_quat'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'tool_cmd'
#include "niryo_one_msgs/msg/detail/tool_command__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__msg__RobotMoveCommand __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__msg__RobotMoveCommand __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotMoveCommand_
{
  using Type = RobotMoveCommand_<ContainerAllocator>;

  explicit RobotMoveCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init),
    rpy(_init),
    shift(_init),
    trajectory(_init),
    pose_quat(_init),
    tool_cmd(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd_type = 0l;
      this->saved_position_name = "";
      this->saved_trajectory_id = 0l;
    }
  }

  explicit RobotMoveCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_alloc, _init),
    rpy(_alloc, _init),
    shift(_alloc, _init),
    trajectory(_alloc, _init),
    pose_quat(_alloc, _init),
    saved_position_name(_alloc),
    tool_cmd(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd_type = 0l;
      this->saved_position_name = "";
      this->saved_trajectory_id = 0l;
    }
  }

  // field types and members
  using _cmd_type_type =
    int32_t;
  _cmd_type_type cmd_type;
  using _joints_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _joints_type joints;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _rpy_type =
    niryo_one_msgs::msg::RPY_<ContainerAllocator>;
  _rpy_type rpy;
  using _shift_type =
    niryo_one_msgs::msg::ShiftPose_<ContainerAllocator>;
  _shift_type shift;
  using _trajectory_type =
    niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator>;
  _trajectory_type trajectory;
  using _pose_quat_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_quat_type pose_quat;
  using _saved_position_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _saved_position_name_type saved_position_name;
  using _saved_trajectory_id_type =
    int32_t;
  _saved_trajectory_id_type saved_trajectory_id;
  using _tool_cmd_type =
    niryo_one_msgs::msg::ToolCommand_<ContainerAllocator>;
  _tool_cmd_type tool_cmd;

  // setters for named parameter idiom
  Type & set__cmd_type(
    const int32_t & _arg)
  {
    this->cmd_type = _arg;
    return *this;
  }
  Type & set__joints(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->joints = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__rpy(
    const niryo_one_msgs::msg::RPY_<ContainerAllocator> & _arg)
  {
    this->rpy = _arg;
    return *this;
  }
  Type & set__shift(
    const niryo_one_msgs::msg::ShiftPose_<ContainerAllocator> & _arg)
  {
    this->shift = _arg;
    return *this;
  }
  Type & set__trajectory(
    const niryo_one_msgs::msg::TrajectoryPlan_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }
  Type & set__pose_quat(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose_quat = _arg;
    return *this;
  }
  Type & set__saved_position_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->saved_position_name = _arg;
    return *this;
  }
  Type & set__saved_trajectory_id(
    const int32_t & _arg)
  {
    this->saved_trajectory_id = _arg;
    return *this;
  }
  Type & set__tool_cmd(
    const niryo_one_msgs::msg::ToolCommand_<ContainerAllocator> & _arg)
  {
    this->tool_cmd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::msg::RobotMoveCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::msg::RobotMoveCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::RobotMoveCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::RobotMoveCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::RobotMoveCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::RobotMoveCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::RobotMoveCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::RobotMoveCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::RobotMoveCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::RobotMoveCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__msg__RobotMoveCommand
    std::shared_ptr<niryo_one_msgs::msg::RobotMoveCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__msg__RobotMoveCommand
    std::shared_ptr<niryo_one_msgs::msg::RobotMoveCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMoveCommand_ & other) const
  {
    if (this->cmd_type != other.cmd_type) {
      return false;
    }
    if (this->joints != other.joints) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->rpy != other.rpy) {
      return false;
    }
    if (this->shift != other.shift) {
      return false;
    }
    if (this->trajectory != other.trajectory) {
      return false;
    }
    if (this->pose_quat != other.pose_quat) {
      return false;
    }
    if (this->saved_position_name != other.saved_position_name) {
      return false;
    }
    if (this->saved_trajectory_id != other.saved_trajectory_id) {
      return false;
    }
    if (this->tool_cmd != other.tool_cmd) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMoveCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMoveCommand_

// alias to use template instance with default allocator
using RobotMoveCommand =
  niryo_one_msgs::msg::RobotMoveCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_MOVE_COMMAND__STRUCT_HPP_
