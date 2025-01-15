// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:msg/LogStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/log_status.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__LOG_STATUS__STRUCT_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__LOG_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__msg__LogStatus __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__msg__LogStatus __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LogStatus_
{
  using Type = LogStatus_<ContainerAllocator>;

  explicit LogStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->log_size = 0l;
      this->available_disk_size = 0l;
      this->purge_log_on_startup = false;
    }
  }

  explicit LogStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->log_size = 0l;
      this->available_disk_size = 0l;
      this->purge_log_on_startup = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _log_size_type =
    int32_t;
  _log_size_type log_size;
  using _available_disk_size_type =
    int32_t;
  _available_disk_size_type available_disk_size;
  using _purge_log_on_startup_type =
    bool;
  _purge_log_on_startup_type purge_log_on_startup;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__log_size(
    const int32_t & _arg)
  {
    this->log_size = _arg;
    return *this;
  }
  Type & set__available_disk_size(
    const int32_t & _arg)
  {
    this->available_disk_size = _arg;
    return *this;
  }
  Type & set__purge_log_on_startup(
    const bool & _arg)
  {
    this->purge_log_on_startup = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::msg::LogStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::msg::LogStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::LogStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::LogStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::LogStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::LogStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::LogStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::LogStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::LogStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::LogStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__msg__LogStatus
    std::shared_ptr<niryo_one_msgs::msg::LogStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__msg__LogStatus
    std::shared_ptr<niryo_one_msgs::msg::LogStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LogStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->log_size != other.log_size) {
      return false;
    }
    if (this->available_disk_size != other.available_disk_size) {
      return false;
    }
    if (this->purge_log_on_startup != other.purge_log_on_startup) {
      return false;
    }
    return true;
  }
  bool operator!=(const LogStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LogStatus_

// alias to use template instance with default allocator
using LogStatus =
  niryo_one_msgs::msg::LogStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__LOG_STATUS__STRUCT_HPP_
