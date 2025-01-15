// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:msg/SequenceAutorunStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/sequence_autorun_status.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE_AUTORUN_STATUS__STRUCT_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE_AUTORUN_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__msg__SequenceAutorunStatus __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__msg__SequenceAutorunStatus __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SequenceAutorunStatus_
{
  using Type = SequenceAutorunStatus_<ContainerAllocator>;

  explicit SequenceAutorunStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enabled = false;
      this->mode = 0l;
    }
  }

  explicit SequenceAutorunStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enabled = false;
      this->mode = 0l;
    }
  }

  // field types and members
  using _enabled_type =
    bool;
  _enabled_type enabled;
  using _mode_type =
    int32_t;
  _mode_type mode;
  using _sequence_ids_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _sequence_ids_type sequence_ids;

  // setters for named parameter idiom
  Type & set__enabled(
    const bool & _arg)
  {
    this->enabled = _arg;
    return *this;
  }
  Type & set__mode(
    const int32_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__sequence_ids(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->sequence_ids = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::msg::SequenceAutorunStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::msg::SequenceAutorunStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::SequenceAutorunStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::SequenceAutorunStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::SequenceAutorunStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::SequenceAutorunStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::SequenceAutorunStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::SequenceAutorunStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::SequenceAutorunStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::SequenceAutorunStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__msg__SequenceAutorunStatus
    std::shared_ptr<niryo_one_msgs::msg::SequenceAutorunStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__msg__SequenceAutorunStatus
    std::shared_ptr<niryo_one_msgs::msg::SequenceAutorunStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SequenceAutorunStatus_ & other) const
  {
    if (this->enabled != other.enabled) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->sequence_ids != other.sequence_ids) {
      return false;
    }
    return true;
  }
  bool operator!=(const SequenceAutorunStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SequenceAutorunStatus_

// alias to use template instance with default allocator
using SequenceAutorunStatus =
  niryo_one_msgs::msg::SequenceAutorunStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE_AUTORUN_STATUS__STRUCT_HPP_
