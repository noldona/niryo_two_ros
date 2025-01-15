// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:msg/ProcessState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/process_state.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__PROCESS_STATE__STRUCT_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__PROCESS_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__msg__ProcessState __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__msg__ProcessState __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProcessState_
{
  using Type = ProcessState_<ContainerAllocator>;

  explicit ProcessState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ProcessState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _name_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _name_type name;
  using _is_active_type =
    std::vector<bool, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<bool>>;
  _is_active_type is_active;

  // setters for named parameter idiom
  Type & set__name(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__is_active(
    const std::vector<bool, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<bool>> & _arg)
  {
    this->is_active = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::msg::ProcessState_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::msg::ProcessState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::ProcessState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::ProcessState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::ProcessState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::ProcessState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::ProcessState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::ProcessState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::ProcessState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::ProcessState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__msg__ProcessState
    std::shared_ptr<niryo_one_msgs::msg::ProcessState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__msg__ProcessState
    std::shared_ptr<niryo_one_msgs::msg::ProcessState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessState_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->is_active != other.is_active) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessState_

// alias to use template instance with default allocator
using ProcessState =
  niryo_one_msgs::msg::ProcessState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__PROCESS_STATE__STRUCT_HPP_
