// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:srv/GetPositionList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_position_list.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_POSITION_LIST__STRUCT_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_POSITION_LIST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__GetPositionList_Request __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__GetPositionList_Request __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetPositionList_Request_
{
  using Type = GetPositionList_Request_<ContainerAllocator>;

  explicit GetPositionList_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetPositionList_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__GetPositionList_Request
    std::shared_ptr<niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__GetPositionList_Request
    std::shared_ptr<niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetPositionList_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetPositionList_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetPositionList_Request_

// alias to use template instance with default allocator
using GetPositionList_Request =
  niryo_one_msgs::srv::GetPositionList_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs


// Include directives for member types
// Member 'positions'
#include "niryo_one_msgs/msg/detail/position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__GetPositionList_Response __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__GetPositionList_Response __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetPositionList_Response_
{
  using Type = GetPositionList_Response_<ContainerAllocator>;

  explicit GetPositionList_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit GetPositionList_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _positions_type =
    std::vector<niryo_one_msgs::msg::Position_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::msg::Position_<ContainerAllocator>>>;
  _positions_type positions;

  // setters for named parameter idiom
  Type & set__positions(
    const std::vector<niryo_one_msgs::msg::Position_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::msg::Position_<ContainerAllocator>>> & _arg)
  {
    this->positions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__GetPositionList_Response
    std::shared_ptr<niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__GetPositionList_Response
    std::shared_ptr<niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetPositionList_Response_ & other) const
  {
    if (this->positions != other.positions) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetPositionList_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetPositionList_Response_

// alias to use template instance with default allocator
using GetPositionList_Response =
  niryo_one_msgs::srv::GetPositionList_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__GetPositionList_Event __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__GetPositionList_Event __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetPositionList_Event_
{
  using Type = GetPositionList_Event_<ContainerAllocator>;

  explicit GetPositionList_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetPositionList_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::GetPositionList_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::GetPositionList_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::GetPositionList_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::GetPositionList_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetPositionList_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetPositionList_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetPositionList_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetPositionList_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetPositionList_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetPositionList_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetPositionList_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetPositionList_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__GetPositionList_Event
    std::shared_ptr<niryo_one_msgs::srv::GetPositionList_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__GetPositionList_Event
    std::shared_ptr<niryo_one_msgs::srv::GetPositionList_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetPositionList_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetPositionList_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetPositionList_Event_

// alias to use template instance with default allocator
using GetPositionList_Event =
  niryo_one_msgs::srv::GetPositionList_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs

namespace niryo_one_msgs
{

namespace srv
{

struct GetPositionList
{
  using Request = niryo_one_msgs::srv::GetPositionList_Request;
  using Response = niryo_one_msgs::srv::GetPositionList_Response;
  using Event = niryo_one_msgs::srv::GetPositionList_Event;
};

}  // namespace srv

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_POSITION_LIST__STRUCT_HPP_
