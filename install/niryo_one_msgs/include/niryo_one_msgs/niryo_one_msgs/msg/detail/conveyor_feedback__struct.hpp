// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:msg/ConveyorFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/conveyor_feedback.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__STRUCT_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__msg__ConveyorFeedback __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__msg__ConveyorFeedback __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ConveyorFeedback_
{
  using Type = ConveyorFeedback_<ContainerAllocator>;

  explicit ConveyorFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->conveyor_id = 0;
      this->connection_state = false;
      this->running = false;
      this->speed = 0;
      this->direction = 0;
    }
  }

  explicit ConveyorFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->conveyor_id = 0;
      this->connection_state = false;
      this->running = false;
      this->speed = 0;
      this->direction = 0;
    }
  }

  // field types and members
  using _conveyor_id_type =
    uint8_t;
  _conveyor_id_type conveyor_id;
  using _connection_state_type =
    bool;
  _connection_state_type connection_state;
  using _running_type =
    bool;
  _running_type running;
  using _speed_type =
    int16_t;
  _speed_type speed;
  using _direction_type =
    int8_t;
  _direction_type direction;

  // setters for named parameter idiom
  Type & set__conveyor_id(
    const uint8_t & _arg)
  {
    this->conveyor_id = _arg;
    return *this;
  }
  Type & set__connection_state(
    const bool & _arg)
  {
    this->connection_state = _arg;
    return *this;
  }
  Type & set__running(
    const bool & _arg)
  {
    this->running = _arg;
    return *this;
  }
  Type & set__speed(
    const int16_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__direction(
    const int8_t & _arg)
  {
    this->direction = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::msg::ConveyorFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::msg::ConveyorFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::ConveyorFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::ConveyorFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::ConveyorFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::ConveyorFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::ConveyorFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::ConveyorFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::ConveyorFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::ConveyorFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__msg__ConveyorFeedback
    std::shared_ptr<niryo_one_msgs::msg::ConveyorFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__msg__ConveyorFeedback
    std::shared_ptr<niryo_one_msgs::msg::ConveyorFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConveyorFeedback_ & other) const
  {
    if (this->conveyor_id != other.conveyor_id) {
      return false;
    }
    if (this->connection_state != other.connection_state) {
      return false;
    }
    if (this->running != other.running) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConveyorFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConveyorFeedback_

// alias to use template instance with default allocator
using ConveyorFeedback =
  niryo_one_msgs::msg::ConveyorFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__STRUCT_HPP_
