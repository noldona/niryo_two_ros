// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:srv/GetCalibrationCam.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_calibration_cam.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_CALIBRATION_CAM__STRUCT_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_CALIBRATION_CAM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'empty'
#include "std_msgs/msg/detail/empty__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__GetCalibrationCam_Request __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__GetCalibrationCam_Request __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetCalibrationCam_Request_
{
  using Type = GetCalibrationCam_Request_<ContainerAllocator>;

  explicit GetCalibrationCam_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : empty(_init)
  {
    (void)_init;
  }

  explicit GetCalibrationCam_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : empty(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _empty_type =
    std_msgs::msg::Empty_<ContainerAllocator>;
  _empty_type empty;

  // setters for named parameter idiom
  Type & set__empty(
    const std_msgs::msg::Empty_<ContainerAllocator> & _arg)
  {
    this->empty = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__GetCalibrationCam_Request
    std::shared_ptr<niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__GetCalibrationCam_Request
    std::shared_ptr<niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetCalibrationCam_Request_ & other) const
  {
    if (this->empty != other.empty) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetCalibrationCam_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetCalibrationCam_Request_

// alias to use template instance with default allocator
using GetCalibrationCam_Request =
  niryo_one_msgs::srv::GetCalibrationCam_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs


// Include directives for member types
// Member 'camera_info'
#include "sensor_msgs/msg/detail/camera_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__GetCalibrationCam_Response __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__GetCalibrationCam_Response __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetCalibrationCam_Response_
{
  using Type = GetCalibrationCam_Response_<ContainerAllocator>;

  explicit GetCalibrationCam_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : camera_info(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_set = false;
    }
  }

  explicit GetCalibrationCam_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : camera_info(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_set = false;
    }
  }

  // field types and members
  using _is_set_type =
    bool;
  _is_set_type is_set;
  using _camera_info_type =
    sensor_msgs::msg::CameraInfo_<ContainerAllocator>;
  _camera_info_type camera_info;

  // setters for named parameter idiom
  Type & set__is_set(
    const bool & _arg)
  {
    this->is_set = _arg;
    return *this;
  }
  Type & set__camera_info(
    const sensor_msgs::msg::CameraInfo_<ContainerAllocator> & _arg)
  {
    this->camera_info = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__GetCalibrationCam_Response
    std::shared_ptr<niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__GetCalibrationCam_Response
    std::shared_ptr<niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetCalibrationCam_Response_ & other) const
  {
    if (this->is_set != other.is_set) {
      return false;
    }
    if (this->camera_info != other.camera_info) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetCalibrationCam_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetCalibrationCam_Response_

// alias to use template instance with default allocator
using GetCalibrationCam_Response =
  niryo_one_msgs::srv::GetCalibrationCam_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__GetCalibrationCam_Event __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__GetCalibrationCam_Event __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetCalibrationCam_Event_
{
  using Type = GetCalibrationCam_Event_<ContainerAllocator>;

  explicit GetCalibrationCam_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetCalibrationCam_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::GetCalibrationCam_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::GetCalibrationCam_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::GetCalibrationCam_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::GetCalibrationCam_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetCalibrationCam_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetCalibrationCam_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetCalibrationCam_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetCalibrationCam_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetCalibrationCam_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetCalibrationCam_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetCalibrationCam_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetCalibrationCam_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__GetCalibrationCam_Event
    std::shared_ptr<niryo_one_msgs::srv::GetCalibrationCam_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__GetCalibrationCam_Event
    std::shared_ptr<niryo_one_msgs::srv::GetCalibrationCam_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetCalibrationCam_Event_ & other) const
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
  bool operator!=(const GetCalibrationCam_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetCalibrationCam_Event_

// alias to use template instance with default allocator
using GetCalibrationCam_Event =
  niryo_one_msgs::srv::GetCalibrationCam_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs

namespace niryo_one_msgs
{

namespace srv
{

struct GetCalibrationCam
{
  using Request = niryo_one_msgs::srv::GetCalibrationCam_Request;
  using Response = niryo_one_msgs::srv::GetCalibrationCam_Response;
  using Event = niryo_one_msgs::srv::GetCalibrationCam_Event;
};

}  // namespace srv

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_CALIBRATION_CAM__STRUCT_HPP_
