// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/GetPositionList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_position_list.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_POSITION_LIST__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_POSITION_LIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/get_position_list__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetPositionList_Request>()
{
  return ::niryo_one_msgs::srv::GetPositionList_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPositionList_Response_positions
{
public:
  Init_GetPositionList_Response_positions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::GetPositionList_Response positions(::niryo_one_msgs::srv::GetPositionList_Response::_positions_type arg)
  {
    msg_.positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetPositionList_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetPositionList_Response>()
{
  return niryo_one_msgs::srv::builder::Init_GetPositionList_Response_positions();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPositionList_Event_response
{
public:
  explicit Init_GetPositionList_Event_response(::niryo_one_msgs::srv::GetPositionList_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::GetPositionList_Event response(::niryo_one_msgs::srv::GetPositionList_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetPositionList_Event msg_;
};

class Init_GetPositionList_Event_request
{
public:
  explicit Init_GetPositionList_Event_request(::niryo_one_msgs::srv::GetPositionList_Event & msg)
  : msg_(msg)
  {}
  Init_GetPositionList_Event_response request(::niryo_one_msgs::srv::GetPositionList_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetPositionList_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetPositionList_Event msg_;
};

class Init_GetPositionList_Event_info
{
public:
  Init_GetPositionList_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetPositionList_Event_request info(::niryo_one_msgs::srv::GetPositionList_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetPositionList_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetPositionList_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetPositionList_Event>()
{
  return niryo_one_msgs::srv::builder::Init_GetPositionList_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_POSITION_LIST__BUILDER_HPP_
