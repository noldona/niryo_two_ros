// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/SoftwareVersion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/software_version.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SOFTWARE_VERSION__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SOFTWARE_VERSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/software_version__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_SoftwareVersion_stepper_firmware_versions
{
public:
  explicit Init_SoftwareVersion_stepper_firmware_versions(::niryo_one_msgs::msg::SoftwareVersion & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::SoftwareVersion stepper_firmware_versions(::niryo_one_msgs::msg::SoftwareVersion::_stepper_firmware_versions_type arg)
  {
    msg_.stepper_firmware_versions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::SoftwareVersion msg_;
};

class Init_SoftwareVersion_motor_names
{
public:
  explicit Init_SoftwareVersion_motor_names(::niryo_one_msgs::msg::SoftwareVersion & msg)
  : msg_(msg)
  {}
  Init_SoftwareVersion_stepper_firmware_versions motor_names(::niryo_one_msgs::msg::SoftwareVersion::_motor_names_type arg)
  {
    msg_.motor_names = std::move(arg);
    return Init_SoftwareVersion_stepper_firmware_versions(msg_);
  }

private:
  ::niryo_one_msgs::msg::SoftwareVersion msg_;
};

class Init_SoftwareVersion_ros_niryo_one_version
{
public:
  explicit Init_SoftwareVersion_ros_niryo_one_version(::niryo_one_msgs::msg::SoftwareVersion & msg)
  : msg_(msg)
  {}
  Init_SoftwareVersion_motor_names ros_niryo_one_version(::niryo_one_msgs::msg::SoftwareVersion::_ros_niryo_one_version_type arg)
  {
    msg_.ros_niryo_one_version = std::move(arg);
    return Init_SoftwareVersion_motor_names(msg_);
  }

private:
  ::niryo_one_msgs::msg::SoftwareVersion msg_;
};

class Init_SoftwareVersion_rpi_image_version
{
public:
  Init_SoftwareVersion_rpi_image_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SoftwareVersion_ros_niryo_one_version rpi_image_version(::niryo_one_msgs::msg::SoftwareVersion::_rpi_image_version_type arg)
  {
    msg_.rpi_image_version = std::move(arg);
    return Init_SoftwareVersion_ros_niryo_one_version(msg_);
  }

private:
  ::niryo_one_msgs::msg::SoftwareVersion msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::SoftwareVersion>()
{
  return niryo_one_msgs::msg::builder::Init_SoftwareVersion_rpi_image_version();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SOFTWARE_VERSION__BUILDER_HPP_
