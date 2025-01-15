// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:srv/PullAirVacuumPump.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/pull_air_vacuum_pump.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__PULL_AIR_VACUUM_PUMP__STRUCT_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__PULL_AIR_VACUUM_PUMP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__PullAirVacuumPump_Request __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__PullAirVacuumPump_Request __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PullAirVacuumPump_Request_
{
  using Type = PullAirVacuumPump_Request_<ContainerAllocator>;

  explicit PullAirVacuumPump_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->pull_air_position = 0;
      this->pull_air_hold_torque = 0;
    }
  }

  explicit PullAirVacuumPump_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->pull_air_position = 0;
      this->pull_air_hold_torque = 0;
    }
  }

  // field types and members
  using _id_type =
    uint8_t;
  _id_type id;
  using _pull_air_position_type =
    int16_t;
  _pull_air_position_type pull_air_position;
  using _pull_air_hold_torque_type =
    int16_t;
  _pull_air_hold_torque_type pull_air_hold_torque;

  // setters for named parameter idiom
  Type & set__id(
    const uint8_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__pull_air_position(
    const int16_t & _arg)
  {
    this->pull_air_position = _arg;
    return *this;
  }
  Type & set__pull_air_hold_torque(
    const int16_t & _arg)
  {
    this->pull_air_hold_torque = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__PullAirVacuumPump_Request
    std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__PullAirVacuumPump_Request
    std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PullAirVacuumPump_Request_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->pull_air_position != other.pull_air_position) {
      return false;
    }
    if (this->pull_air_hold_torque != other.pull_air_hold_torque) {
      return false;
    }
    return true;
  }
  bool operator!=(const PullAirVacuumPump_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PullAirVacuumPump_Request_

// alias to use template instance with default allocator
using PullAirVacuumPump_Request =
  niryo_one_msgs::srv::PullAirVacuumPump_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__PullAirVacuumPump_Response __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__PullAirVacuumPump_Response __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PullAirVacuumPump_Response_
{
  using Type = PullAirVacuumPump_Response_<ContainerAllocator>;

  explicit PullAirVacuumPump_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
    }
  }

  explicit PullAirVacuumPump_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
    }
  }

  // field types and members
  using _state_type =
    uint8_t;
  _state_type state;

  // setters for named parameter idiom
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__PullAirVacuumPump_Response
    std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__PullAirVacuumPump_Response
    std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PullAirVacuumPump_Response_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const PullAirVacuumPump_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PullAirVacuumPump_Response_

// alias to use template instance with default allocator
using PullAirVacuumPump_Response =
  niryo_one_msgs::srv::PullAirVacuumPump_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__PullAirVacuumPump_Event __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__PullAirVacuumPump_Event __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PullAirVacuumPump_Event_
{
  using Type = PullAirVacuumPump_Event_<ContainerAllocator>;

  explicit PullAirVacuumPump_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit PullAirVacuumPump_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::PullAirVacuumPump_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::PullAirVacuumPump_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::PullAirVacuumPump_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::PullAirVacuumPump_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::PullAirVacuumPump_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::PullAirVacuumPump_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__PullAirVacuumPump_Event
    std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__PullAirVacuumPump_Event
    std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PullAirVacuumPump_Event_ & other) const
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
  bool operator!=(const PullAirVacuumPump_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PullAirVacuumPump_Event_

// alias to use template instance with default allocator
using PullAirVacuumPump_Event =
  niryo_one_msgs::srv::PullAirVacuumPump_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs

namespace niryo_one_msgs
{

namespace srv
{

struct PullAirVacuumPump
{
  using Request = niryo_one_msgs::srv::PullAirVacuumPump_Request;
  using Response = niryo_one_msgs::srv::PullAirVacuumPump_Response;
  using Event = niryo_one_msgs::srv::PullAirVacuumPump_Event;
};

}  // namespace srv

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__PULL_AIR_VACUUM_PUMP__STRUCT_HPP_
