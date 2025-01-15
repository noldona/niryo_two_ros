// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:srv/ObjDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/obj_detection.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__OBJ_DETECTION__STRUCT_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__OBJ_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__ObjDetection_Request __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__ObjDetection_Request __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ObjDetection_Request_
{
  using Type = ObjDetection_Request_<ContainerAllocator>;

  explicit ObjDetection_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obj_type = "";
      this->obj_color = "";
      this->workspace_ratio = 0.0f;
      this->ret_image = false;
    }
  }

  explicit ObjDetection_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : obj_type(_alloc),
    obj_color(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obj_type = "";
      this->obj_color = "";
      this->workspace_ratio = 0.0f;
      this->ret_image = false;
    }
  }

  // field types and members
  using _obj_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _obj_type_type obj_type;
  using _obj_color_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _obj_color_type obj_color;
  using _workspace_ratio_type =
    float;
  _workspace_ratio_type workspace_ratio;
  using _ret_image_type =
    bool;
  _ret_image_type ret_image;

  // setters for named parameter idiom
  Type & set__obj_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->obj_type = _arg;
    return *this;
  }
  Type & set__obj_color(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->obj_color = _arg;
    return *this;
  }
  Type & set__workspace_ratio(
    const float & _arg)
  {
    this->workspace_ratio = _arg;
    return *this;
  }
  Type & set__ret_image(
    const bool & _arg)
  {
    this->ret_image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__ObjDetection_Request
    std::shared_ptr<niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__ObjDetection_Request
    std::shared_ptr<niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjDetection_Request_ & other) const
  {
    if (this->obj_type != other.obj_type) {
      return false;
    }
    if (this->obj_color != other.obj_color) {
      return false;
    }
    if (this->workspace_ratio != other.workspace_ratio) {
      return false;
    }
    if (this->ret_image != other.ret_image) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjDetection_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjDetection_Request_

// alias to use template instance with default allocator
using ObjDetection_Request =
  niryo_one_msgs::srv::ObjDetection_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs


// Include directives for member types
// Member 'obj_pose'
#include "niryo_one_msgs/msg/detail/object_pose__struct.hpp"
// Member 'img'
#include "sensor_msgs/msg/detail/compressed_image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__ObjDetection_Response __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__ObjDetection_Response __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ObjDetection_Response_
{
  using Type = ObjDetection_Response_<ContainerAllocator>;

  explicit ObjDetection_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : obj_pose(_init),
    img(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
      this->obj_type = "";
      this->obj_color = "";
    }
  }

  explicit ObjDetection_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : obj_pose(_alloc, _init),
    obj_type(_alloc),
    obj_color(_alloc),
    img(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
      this->obj_type = "";
      this->obj_color = "";
    }
  }

  // field types and members
  using _status_type =
    int32_t;
  _status_type status;
  using _obj_pose_type =
    niryo_one_msgs::msg::ObjectPose_<ContainerAllocator>;
  _obj_pose_type obj_pose;
  using _obj_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _obj_type_type obj_type;
  using _obj_color_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _obj_color_type obj_color;
  using _img_type =
    sensor_msgs::msg::CompressedImage_<ContainerAllocator>;
  _img_type img;

  // setters for named parameter idiom
  Type & set__status(
    const int32_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__obj_pose(
    const niryo_one_msgs::msg::ObjectPose_<ContainerAllocator> & _arg)
  {
    this->obj_pose = _arg;
    return *this;
  }
  Type & set__obj_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->obj_type = _arg;
    return *this;
  }
  Type & set__obj_color(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->obj_color = _arg;
    return *this;
  }
  Type & set__img(
    const sensor_msgs::msg::CompressedImage_<ContainerAllocator> & _arg)
  {
    this->img = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int32_t SUCCESSFUL =
    1;
  static constexpr int32_t VIDEO_STREAM_NOT_RUNNING =
    -1;
  static constexpr int32_t OBJECT_NOT_FOUND =
    -2;
  static constexpr int32_t MARKERS_NOT_FOUND =
    -3;

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__ObjDetection_Response
    std::shared_ptr<niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__ObjDetection_Response
    std::shared_ptr<niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjDetection_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->obj_pose != other.obj_pose) {
      return false;
    }
    if (this->obj_type != other.obj_type) {
      return false;
    }
    if (this->obj_color != other.obj_color) {
      return false;
    }
    if (this->img != other.img) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjDetection_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjDetection_Response_

// alias to use template instance with default allocator
using ObjDetection_Response =
  niryo_one_msgs::srv::ObjDetection_Response_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t ObjDetection_Response_<ContainerAllocator>::SUCCESSFUL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t ObjDetection_Response_<ContainerAllocator>::VIDEO_STREAM_NOT_RUNNING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t ObjDetection_Response_<ContainerAllocator>::OBJECT_NOT_FOUND;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t ObjDetection_Response_<ContainerAllocator>::MARKERS_NOT_FOUND;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace niryo_one_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__ObjDetection_Event __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__ObjDetection_Event __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ObjDetection_Event_
{
  using Type = ObjDetection_Event_<ContainerAllocator>;

  explicit ObjDetection_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ObjDetection_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::ObjDetection_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::ObjDetection_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::ObjDetection_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::ObjDetection_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::ObjDetection_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::ObjDetection_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::ObjDetection_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::ObjDetection_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::ObjDetection_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::ObjDetection_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::ObjDetection_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::ObjDetection_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__ObjDetection_Event
    std::shared_ptr<niryo_one_msgs::srv::ObjDetection_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__ObjDetection_Event
    std::shared_ptr<niryo_one_msgs::srv::ObjDetection_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjDetection_Event_ & other) const
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
  bool operator!=(const ObjDetection_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjDetection_Event_

// alias to use template instance with default allocator
using ObjDetection_Event =
  niryo_one_msgs::srv::ObjDetection_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs

namespace niryo_one_msgs
{

namespace srv
{

struct ObjDetection
{
  using Request = niryo_one_msgs::srv::ObjDetection_Request;
  using Response = niryo_one_msgs::srv::ObjDetection_Response;
  using Event = niryo_one_msgs::srv::ObjDetection_Event;
};

}  // namespace srv

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__OBJ_DETECTION__STRUCT_HPP_
