// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:msg/HardwareStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/hardware_status.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__HARDWARE_STATUS__STRUCT_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__HARDWARE_STATUS__STRUCT_HPP_

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
# define DEPRECATED__niryo_one_msgs__msg__HardwareStatus __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__msg__HardwareStatus __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HardwareStatus_
{
  using Type = HardwareStatus_<ContainerAllocator>;

  explicit HardwareStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rpi_temperature = 0l;
      this->hardware_version = 0l;
      this->connection_up = false;
      this->error_message = "";
      this->calibration_needed = 0l;
      this->calibration_in_progress = false;
    }
  }

  explicit HardwareStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    error_message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rpi_temperature = 0l;
      this->hardware_version = 0l;
      this->connection_up = false;
      this->error_message = "";
      this->calibration_needed = 0l;
      this->calibration_in_progress = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _rpi_temperature_type =
    int32_t;
  _rpi_temperature_type rpi_temperature;
  using _hardware_version_type =
    int32_t;
  _hardware_version_type hardware_version;
  using _connection_up_type =
    bool;
  _connection_up_type connection_up;
  using _error_message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_message_type error_message;
  using _calibration_needed_type =
    int32_t;
  _calibration_needed_type calibration_needed;
  using _calibration_in_progress_type =
    bool;
  _calibration_in_progress_type calibration_in_progress;
  using _motor_names_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _motor_names_type motor_names;
  using _motor_types_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _motor_types_type motor_types;
  using _temperatures_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _temperatures_type temperatures;
  using _voltages_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _voltages_type voltages;
  using _hardware_errors_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _hardware_errors_type hardware_errors;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__rpi_temperature(
    const int32_t & _arg)
  {
    this->rpi_temperature = _arg;
    return *this;
  }
  Type & set__hardware_version(
    const int32_t & _arg)
  {
    this->hardware_version = _arg;
    return *this;
  }
  Type & set__connection_up(
    const bool & _arg)
  {
    this->connection_up = _arg;
    return *this;
  }
  Type & set__error_message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error_message = _arg;
    return *this;
  }
  Type & set__calibration_needed(
    const int32_t & _arg)
  {
    this->calibration_needed = _arg;
    return *this;
  }
  Type & set__calibration_in_progress(
    const bool & _arg)
  {
    this->calibration_in_progress = _arg;
    return *this;
  }
  Type & set__motor_names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->motor_names = _arg;
    return *this;
  }
  Type & set__motor_types(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->motor_types = _arg;
    return *this;
  }
  Type & set__temperatures(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->temperatures = _arg;
    return *this;
  }
  Type & set__voltages(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->voltages = _arg;
    return *this;
  }
  Type & set__hardware_errors(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->hardware_errors = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::msg::HardwareStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::msg::HardwareStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::HardwareStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::HardwareStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::HardwareStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::HardwareStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::HardwareStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::HardwareStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::HardwareStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::HardwareStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__msg__HardwareStatus
    std::shared_ptr<niryo_one_msgs::msg::HardwareStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__msg__HardwareStatus
    std::shared_ptr<niryo_one_msgs::msg::HardwareStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HardwareStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->rpi_temperature != other.rpi_temperature) {
      return false;
    }
    if (this->hardware_version != other.hardware_version) {
      return false;
    }
    if (this->connection_up != other.connection_up) {
      return false;
    }
    if (this->error_message != other.error_message) {
      return false;
    }
    if (this->calibration_needed != other.calibration_needed) {
      return false;
    }
    if (this->calibration_in_progress != other.calibration_in_progress) {
      return false;
    }
    if (this->motor_names != other.motor_names) {
      return false;
    }
    if (this->motor_types != other.motor_types) {
      return false;
    }
    if (this->temperatures != other.temperatures) {
      return false;
    }
    if (this->voltages != other.voltages) {
      return false;
    }
    if (this->hardware_errors != other.hardware_errors) {
      return false;
    }
    return true;
  }
  bool operator!=(const HardwareStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HardwareStatus_

// alias to use template instance with default allocator
using HardwareStatus =
  niryo_one_msgs::msg::HardwareStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__HARDWARE_STATUS__STRUCT_HPP_
