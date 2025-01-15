// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:msg/ShiftPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/shift_pose.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SHIFT_POSE__STRUCT_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SHIFT_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__msg__ShiftPose __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__msg__ShiftPose __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ShiftPose_
{
  using Type = ShiftPose_<ContainerAllocator>;

  explicit ShiftPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->axis_number = 0l;
      this->value = 0.0;
    }
  }

  explicit ShiftPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->axis_number = 0l;
      this->value = 0.0;
    }
  }

  // field types and members
  using _axis_number_type =
    int32_t;
  _axis_number_type axis_number;
  using _value_type =
    double;
  _value_type value;

  // setters for named parameter idiom
  Type & set__axis_number(
    const int32_t & _arg)
  {
    this->axis_number = _arg;
    return *this;
  }
  Type & set__value(
    const double & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::msg::ShiftPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::msg::ShiftPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::ShiftPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::ShiftPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::ShiftPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::ShiftPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::ShiftPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::ShiftPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::ShiftPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::ShiftPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__msg__ShiftPose
    std::shared_ptr<niryo_one_msgs::msg::ShiftPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__msg__ShiftPose
    std::shared_ptr<niryo_one_msgs::msg::ShiftPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ShiftPose_ & other) const
  {
    if (this->axis_number != other.axis_number) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const ShiftPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ShiftPose_

// alias to use template instance with default allocator
using ShiftPose =
  niryo_one_msgs::msg::ShiftPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SHIFT_POSE__STRUCT_HPP_
