// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/Sequence.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/sequence.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/sequence__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_Sequence_python_code
{
public:
  explicit Init_Sequence_python_code(::niryo_one_msgs::msg::Sequence & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::Sequence python_code(::niryo_one_msgs::msg::Sequence::_python_code_type arg)
  {
    msg_.python_code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::Sequence msg_;
};

class Init_Sequence_blockly_xml
{
public:
  explicit Init_Sequence_blockly_xml(::niryo_one_msgs::msg::Sequence & msg)
  : msg_(msg)
  {}
  Init_Sequence_python_code blockly_xml(::niryo_one_msgs::msg::Sequence::_blockly_xml_type arg)
  {
    msg_.blockly_xml = std::move(arg);
    return Init_Sequence_python_code(msg_);
  }

private:
  ::niryo_one_msgs::msg::Sequence msg_;
};

class Init_Sequence_updated
{
public:
  explicit Init_Sequence_updated(::niryo_one_msgs::msg::Sequence & msg)
  : msg_(msg)
  {}
  Init_Sequence_blockly_xml updated(::niryo_one_msgs::msg::Sequence::_updated_type arg)
  {
    msg_.updated = std::move(arg);
    return Init_Sequence_blockly_xml(msg_);
  }

private:
  ::niryo_one_msgs::msg::Sequence msg_;
};

class Init_Sequence_created
{
public:
  explicit Init_Sequence_created(::niryo_one_msgs::msg::Sequence & msg)
  : msg_(msg)
  {}
  Init_Sequence_updated created(::niryo_one_msgs::msg::Sequence::_created_type arg)
  {
    msg_.created = std::move(arg);
    return Init_Sequence_updated(msg_);
  }

private:
  ::niryo_one_msgs::msg::Sequence msg_;
};

class Init_Sequence_description
{
public:
  explicit Init_Sequence_description(::niryo_one_msgs::msg::Sequence & msg)
  : msg_(msg)
  {}
  Init_Sequence_created description(::niryo_one_msgs::msg::Sequence::_description_type arg)
  {
    msg_.description = std::move(arg);
    return Init_Sequence_created(msg_);
  }

private:
  ::niryo_one_msgs::msg::Sequence msg_;
};

class Init_Sequence_name
{
public:
  explicit Init_Sequence_name(::niryo_one_msgs::msg::Sequence & msg)
  : msg_(msg)
  {}
  Init_Sequence_description name(::niryo_one_msgs::msg::Sequence::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Sequence_description(msg_);
  }

private:
  ::niryo_one_msgs::msg::Sequence msg_;
};

class Init_Sequence_id
{
public:
  Init_Sequence_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sequence_name id(::niryo_one_msgs::msg::Sequence::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Sequence_name(msg_);
  }

private:
  ::niryo_one_msgs::msg::Sequence msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::Sequence>()
{
  return niryo_one_msgs::msg::builder::Init_Sequence_id();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE__BUILDER_HPP_
