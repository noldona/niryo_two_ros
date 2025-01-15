// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:msg/SoftwareVersion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/software_version.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SOFTWARE_VERSION__STRUCT_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SOFTWARE_VERSION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__msg__SoftwareVersion __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__msg__SoftwareVersion __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SoftwareVersion_
{
  using Type = SoftwareVersion_<ContainerAllocator>;

  explicit SoftwareVersion_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rpi_image_version = "";
      this->ros_niryo_one_version = "";
    }
  }

  explicit SoftwareVersion_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : rpi_image_version(_alloc),
    ros_niryo_one_version(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rpi_image_version = "";
      this->ros_niryo_one_version = "";
    }
  }

  // field types and members
  using _rpi_image_version_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _rpi_image_version_type rpi_image_version;
  using _ros_niryo_one_version_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _ros_niryo_one_version_type ros_niryo_one_version;
  using _motor_names_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _motor_names_type motor_names;
  using _stepper_firmware_versions_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _stepper_firmware_versions_type stepper_firmware_versions;

  // setters for named parameter idiom
  Type & set__rpi_image_version(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->rpi_image_version = _arg;
    return *this;
  }
  Type & set__ros_niryo_one_version(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->ros_niryo_one_version = _arg;
    return *this;
  }
  Type & set__motor_names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->motor_names = _arg;
    return *this;
  }
  Type & set__stepper_firmware_versions(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->stepper_firmware_versions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::msg::SoftwareVersion_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::msg::SoftwareVersion_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::SoftwareVersion_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::SoftwareVersion_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::SoftwareVersion_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::SoftwareVersion_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::SoftwareVersion_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::SoftwareVersion_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::SoftwareVersion_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::SoftwareVersion_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__msg__SoftwareVersion
    std::shared_ptr<niryo_one_msgs::msg::SoftwareVersion_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__msg__SoftwareVersion
    std::shared_ptr<niryo_one_msgs::msg::SoftwareVersion_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SoftwareVersion_ & other) const
  {
    if (this->rpi_image_version != other.rpi_image_version) {
      return false;
    }
    if (this->ros_niryo_one_version != other.ros_niryo_one_version) {
      return false;
    }
    if (this->motor_names != other.motor_names) {
      return false;
    }
    if (this->stepper_firmware_versions != other.stepper_firmware_versions) {
      return false;
    }
    return true;
  }
  bool operator!=(const SoftwareVersion_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SoftwareVersion_

// alias to use template instance with default allocator
using SoftwareVersion =
  niryo_one_msgs::msg::SoftwareVersion_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SOFTWARE_VERSION__STRUCT_HPP_
