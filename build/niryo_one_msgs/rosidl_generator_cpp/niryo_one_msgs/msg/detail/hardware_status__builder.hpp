// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/HardwareStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/hardware_status.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__HARDWARE_STATUS__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__HARDWARE_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/hardware_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_HardwareStatus_hardware_errors
{
public:
  explicit Init_HardwareStatus_hardware_errors(::niryo_one_msgs::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::HardwareStatus hardware_errors(::niryo_one_msgs::msg::HardwareStatus::_hardware_errors_type arg)
  {
    msg_.hardware_errors = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_voltages
{
public:
  explicit Init_HardwareStatus_voltages(::niryo_one_msgs::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  Init_HardwareStatus_hardware_errors voltages(::niryo_one_msgs::msg::HardwareStatus::_voltages_type arg)
  {
    msg_.voltages = std::move(arg);
    return Init_HardwareStatus_hardware_errors(msg_);
  }

private:
  ::niryo_one_msgs::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_temperatures
{
public:
  explicit Init_HardwareStatus_temperatures(::niryo_one_msgs::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  Init_HardwareStatus_voltages temperatures(::niryo_one_msgs::msg::HardwareStatus::_temperatures_type arg)
  {
    msg_.temperatures = std::move(arg);
    return Init_HardwareStatus_voltages(msg_);
  }

private:
  ::niryo_one_msgs::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_motor_types
{
public:
  explicit Init_HardwareStatus_motor_types(::niryo_one_msgs::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  Init_HardwareStatus_temperatures motor_types(::niryo_one_msgs::msg::HardwareStatus::_motor_types_type arg)
  {
    msg_.motor_types = std::move(arg);
    return Init_HardwareStatus_temperatures(msg_);
  }

private:
  ::niryo_one_msgs::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_motor_names
{
public:
  explicit Init_HardwareStatus_motor_names(::niryo_one_msgs::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  Init_HardwareStatus_motor_types motor_names(::niryo_one_msgs::msg::HardwareStatus::_motor_names_type arg)
  {
    msg_.motor_names = std::move(arg);
    return Init_HardwareStatus_motor_types(msg_);
  }

private:
  ::niryo_one_msgs::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_calibration_in_progress
{
public:
  explicit Init_HardwareStatus_calibration_in_progress(::niryo_one_msgs::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  Init_HardwareStatus_motor_names calibration_in_progress(::niryo_one_msgs::msg::HardwareStatus::_calibration_in_progress_type arg)
  {
    msg_.calibration_in_progress = std::move(arg);
    return Init_HardwareStatus_motor_names(msg_);
  }

private:
  ::niryo_one_msgs::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_calibration_needed
{
public:
  explicit Init_HardwareStatus_calibration_needed(::niryo_one_msgs::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  Init_HardwareStatus_calibration_in_progress calibration_needed(::niryo_one_msgs::msg::HardwareStatus::_calibration_needed_type arg)
  {
    msg_.calibration_needed = std::move(arg);
    return Init_HardwareStatus_calibration_in_progress(msg_);
  }

private:
  ::niryo_one_msgs::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_error_message
{
public:
  explicit Init_HardwareStatus_error_message(::niryo_one_msgs::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  Init_HardwareStatus_calibration_needed error_message(::niryo_one_msgs::msg::HardwareStatus::_error_message_type arg)
  {
    msg_.error_message = std::move(arg);
    return Init_HardwareStatus_calibration_needed(msg_);
  }

private:
  ::niryo_one_msgs::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_connection_up
{
public:
  explicit Init_HardwareStatus_connection_up(::niryo_one_msgs::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  Init_HardwareStatus_error_message connection_up(::niryo_one_msgs::msg::HardwareStatus::_connection_up_type arg)
  {
    msg_.connection_up = std::move(arg);
    return Init_HardwareStatus_error_message(msg_);
  }

private:
  ::niryo_one_msgs::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_hardware_version
{
public:
  explicit Init_HardwareStatus_hardware_version(::niryo_one_msgs::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  Init_HardwareStatus_connection_up hardware_version(::niryo_one_msgs::msg::HardwareStatus::_hardware_version_type arg)
  {
    msg_.hardware_version = std::move(arg);
    return Init_HardwareStatus_connection_up(msg_);
  }

private:
  ::niryo_one_msgs::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_rpi_temperature
{
public:
  explicit Init_HardwareStatus_rpi_temperature(::niryo_one_msgs::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  Init_HardwareStatus_hardware_version rpi_temperature(::niryo_one_msgs::msg::HardwareStatus::_rpi_temperature_type arg)
  {
    msg_.rpi_temperature = std::move(arg);
    return Init_HardwareStatus_hardware_version(msg_);
  }

private:
  ::niryo_one_msgs::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_header
{
public:
  Init_HardwareStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HardwareStatus_rpi_temperature header(::niryo_one_msgs::msg::HardwareStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_HardwareStatus_rpi_temperature(msg_);
  }

private:
  ::niryo_one_msgs::msg::HardwareStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::HardwareStatus>()
{
  return niryo_one_msgs::msg::builder::Init_HardwareStatus_header();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__HARDWARE_STATUS__BUILDER_HPP_
