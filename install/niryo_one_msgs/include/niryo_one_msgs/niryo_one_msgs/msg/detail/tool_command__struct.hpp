// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:msg/ToolCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/tool_command.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__TOOL_COMMAND__STRUCT_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__TOOL_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__msg__ToolCommand __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__msg__ToolCommand __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ToolCommand_
{
  using Type = ToolCommand_<ContainerAllocator>;

  explicit ToolCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tool_id = 0;
      this->cmd_type = 0;
      this->gripper_close_speed = 0;
      this->gripper_open_speed = 0;
      this->activate = false;
      this->gpio = 0;
    }
  }

  explicit ToolCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tool_id = 0;
      this->cmd_type = 0;
      this->gripper_close_speed = 0;
      this->gripper_open_speed = 0;
      this->activate = false;
      this->gpio = 0;
    }
  }

  // field types and members
  using _tool_id_type =
    uint8_t;
  _tool_id_type tool_id;
  using _cmd_type_type =
    uint8_t;
  _cmd_type_type cmd_type;
  using _gripper_close_speed_type =
    uint16_t;
  _gripper_close_speed_type gripper_close_speed;
  using _gripper_open_speed_type =
    uint16_t;
  _gripper_open_speed_type gripper_open_speed;
  using _activate_type =
    bool;
  _activate_type activate;
  using _gpio_type =
    uint8_t;
  _gpio_type gpio;

  // setters for named parameter idiom
  Type & set__tool_id(
    const uint8_t & _arg)
  {
    this->tool_id = _arg;
    return *this;
  }
  Type & set__cmd_type(
    const uint8_t & _arg)
  {
    this->cmd_type = _arg;
    return *this;
  }
  Type & set__gripper_close_speed(
    const uint16_t & _arg)
  {
    this->gripper_close_speed = _arg;
    return *this;
  }
  Type & set__gripper_open_speed(
    const uint16_t & _arg)
  {
    this->gripper_open_speed = _arg;
    return *this;
  }
  Type & set__activate(
    const bool & _arg)
  {
    this->activate = _arg;
    return *this;
  }
  Type & set__gpio(
    const uint8_t & _arg)
  {
    this->gpio = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::msg::ToolCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::msg::ToolCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::ToolCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::ToolCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::ToolCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::ToolCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::ToolCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::ToolCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::ToolCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::ToolCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__msg__ToolCommand
    std::shared_ptr<niryo_one_msgs::msg::ToolCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__msg__ToolCommand
    std::shared_ptr<niryo_one_msgs::msg::ToolCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ToolCommand_ & other) const
  {
    if (this->tool_id != other.tool_id) {
      return false;
    }
    if (this->cmd_type != other.cmd_type) {
      return false;
    }
    if (this->gripper_close_speed != other.gripper_close_speed) {
      return false;
    }
    if (this->gripper_open_speed != other.gripper_open_speed) {
      return false;
    }
    if (this->activate != other.activate) {
      return false;
    }
    if (this->gpio != other.gpio) {
      return false;
    }
    return true;
  }
  bool operator!=(const ToolCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ToolCommand_

// alias to use template instance with default allocator
using ToolCommand =
  niryo_one_msgs::msg::ToolCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__TOOL_COMMAND__STRUCT_HPP_
