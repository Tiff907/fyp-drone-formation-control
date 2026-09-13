// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from formation_msgs:msg/DronePath.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRONE_PATH__STRUCT_HPP_
#define FORMATION_MSGS__MSG__DETAIL__DRONE_PATH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'waypoints'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'waypoint_times'
// Member 'formation_start_time'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__formation_msgs__msg__DronePath __attribute__((deprecated))
#else
# define DEPRECATED__formation_msgs__msg__DronePath __declspec(deprecated)
#endif

namespace formation_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DronePath_
{
  using Type = DronePath_<ContainerAllocator>;

  explicit DronePath_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : formation_start_time(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = 0l;
    }
  }

  explicit DronePath_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : formation_start_time(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = 0l;
    }
  }

  // field types and members
  using _drone_id_type =
    int32_t;
  _drone_id_type drone_id;
  using _waypoints_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _waypoints_type waypoints;
  using _waypoint_times_type =
    std::vector<builtin_interfaces::msg::Time_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<builtin_interfaces::msg::Time_<ContainerAllocator>>>;
  _waypoint_times_type waypoint_times;
  using _formation_start_time_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _formation_start_time_type formation_start_time;

  // setters for named parameter idiom
  Type & set__drone_id(
    const int32_t & _arg)
  {
    this->drone_id = _arg;
    return *this;
  }
  Type & set__waypoints(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->waypoints = _arg;
    return *this;
  }
  Type & set__waypoint_times(
    const std::vector<builtin_interfaces::msg::Time_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<builtin_interfaces::msg::Time_<ContainerAllocator>>> & _arg)
  {
    this->waypoint_times = _arg;
    return *this;
  }
  Type & set__formation_start_time(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->formation_start_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    formation_msgs::msg::DronePath_<ContainerAllocator> *;
  using ConstRawPtr =
    const formation_msgs::msg::DronePath_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<formation_msgs::msg::DronePath_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<formation_msgs::msg::DronePath_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::DronePath_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::DronePath_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::DronePath_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::DronePath_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<formation_msgs::msg::DronePath_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<formation_msgs::msg::DronePath_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__formation_msgs__msg__DronePath
    std::shared_ptr<formation_msgs::msg::DronePath_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__formation_msgs__msg__DronePath
    std::shared_ptr<formation_msgs::msg::DronePath_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DronePath_ & other) const
  {
    if (this->drone_id != other.drone_id) {
      return false;
    }
    if (this->waypoints != other.waypoints) {
      return false;
    }
    if (this->waypoint_times != other.waypoint_times) {
      return false;
    }
    if (this->formation_start_time != other.formation_start_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const DronePath_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DronePath_

// alias to use template instance with default allocator
using DronePath =
  formation_msgs::msg::DronePath_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__DRONE_PATH__STRUCT_HPP_
