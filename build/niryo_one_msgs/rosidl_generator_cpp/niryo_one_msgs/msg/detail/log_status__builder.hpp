// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/LogStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/log_status.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__LOG_STATUS__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__LOG_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/log_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_LogStatus_purge_log_on_startup
{
public:
  explicit Init_LogStatus_purge_log_on_startup(::niryo_one_msgs::msg::LogStatus & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::LogStatus purge_log_on_startup(::niryo_one_msgs::msg::LogStatus::_purge_log_on_startup_type arg)
  {
    msg_.purge_log_on_startup = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::LogStatus msg_;
};

class Init_LogStatus_available_disk_size
{
public:
  explicit Init_LogStatus_available_disk_size(::niryo_one_msgs::msg::LogStatus & msg)
  : msg_(msg)
  {}
  Init_LogStatus_purge_log_on_startup available_disk_size(::niryo_one_msgs::msg::LogStatus::_available_disk_size_type arg)
  {
    msg_.available_disk_size = std::move(arg);
    return Init_LogStatus_purge_log_on_startup(msg_);
  }

private:
  ::niryo_one_msgs::msg::LogStatus msg_;
};

class Init_LogStatus_log_size
{
public:
  explicit Init_LogStatus_log_size(::niryo_one_msgs::msg::LogStatus & msg)
  : msg_(msg)
  {}
  Init_LogStatus_available_disk_size log_size(::niryo_one_msgs::msg::LogStatus::_log_size_type arg)
  {
    msg_.log_size = std::move(arg);
    return Init_LogStatus_available_disk_size(msg_);
  }

private:
  ::niryo_one_msgs::msg::LogStatus msg_;
};

class Init_LogStatus_header
{
public:
  Init_LogStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LogStatus_log_size header(::niryo_one_msgs::msg::LogStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LogStatus_log_size(msg_);
  }

private:
  ::niryo_one_msgs::msg::LogStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::LogStatus>()
{
  return niryo_one_msgs::msg::builder::Init_LogStatus_header();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__LOG_STATUS__BUILDER_HPP_
