// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/GetSequenceList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_sequence_list.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_SEQUENCE_LIST__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_SEQUENCE_LIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/get_sequence_list__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSequenceList_Request_info_header_only
{
public:
  Init_GetSequenceList_Request_info_header_only()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::GetSequenceList_Request info_header_only(::niryo_one_msgs::srv::GetSequenceList_Request::_info_header_only_type arg)
  {
    msg_.info_header_only = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetSequenceList_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetSequenceList_Request>()
{
  return niryo_one_msgs::srv::builder::Init_GetSequenceList_Request_info_header_only();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSequenceList_Response_sequences
{
public:
  Init_GetSequenceList_Response_sequences()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::GetSequenceList_Response sequences(::niryo_one_msgs::srv::GetSequenceList_Response::_sequences_type arg)
  {
    msg_.sequences = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetSequenceList_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetSequenceList_Response>()
{
  return niryo_one_msgs::srv::builder::Init_GetSequenceList_Response_sequences();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSequenceList_Event_response
{
public:
  explicit Init_GetSequenceList_Event_response(::niryo_one_msgs::srv::GetSequenceList_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::GetSequenceList_Event response(::niryo_one_msgs::srv::GetSequenceList_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetSequenceList_Event msg_;
};

class Init_GetSequenceList_Event_request
{
public:
  explicit Init_GetSequenceList_Event_request(::niryo_one_msgs::srv::GetSequenceList_Event & msg)
  : msg_(msg)
  {}
  Init_GetSequenceList_Event_response request(::niryo_one_msgs::srv::GetSequenceList_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetSequenceList_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetSequenceList_Event msg_;
};

class Init_GetSequenceList_Event_info
{
public:
  Init_GetSequenceList_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSequenceList_Event_request info(::niryo_one_msgs::srv::GetSequenceList_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetSequenceList_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetSequenceList_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetSequenceList_Event>()
{
  return niryo_one_msgs::srv::builder::Init_GetSequenceList_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_SEQUENCE_LIST__BUILDER_HPP_
