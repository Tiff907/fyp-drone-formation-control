// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from formation_msgs:msg/DroneState.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRONE_STATE__STRUCT_HPP_
#define FORMATION_MSGS__MSG__DETAIL__DRONE_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__formation_msgs__msg__DroneState __attribute__((deprecated))
#else
# define DEPRECATED__formation_msgs__msg__DroneState __declspec(deprecated)
#endif

namespace formation_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DroneState_
{
  using Type = DroneState_<ContainerAllocator>;

  explicit DroneState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = 0l;
      this->available = false;
      this->reached_target = false;
    }
  }

  explicit DroneState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = 0l;
      this->available = false;
      this->reached_target = false;
    }
  }

  // field types and members
  using _drone_id_type =
    int32_t;
  _drone_id_type drone_id;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _available_type =
    bool;
  _available_type available;
  using _reached_target_type =
    bool;
  _reached_target_type reached_target;

  // setters for named parameter idiom
  Type & set__drone_id(
    const int32_t & _arg)
  {
    this->drone_id = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__available(
    const bool & _arg)
  {
    this->available = _arg;
    return *this;
  }
  Type & set__reached_target(
    const bool & _arg)
  {
    this->reached_target = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    formation_msgs::msg::DroneState_<ContainerAllocator> *;
  using ConstRawPtr =
    const formation_msgs::msg::DroneState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<formation_msgs::msg::DroneState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<formation_msgs::msg::DroneState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::DroneState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::DroneState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::DroneState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::DroneState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<formation_msgs::msg::DroneState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<formation_msgs::msg::DroneState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__formation_msgs__msg__DroneState
    std::shared_ptr<formation_msgs::msg::DroneState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__formation_msgs__msg__DroneState
    std::shared_ptr<formation_msgs::msg::DroneState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneState_ & other) const
  {
    if (this->drone_id != other.drone_id) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->available != other.available) {
      return false;
    }
    if (this->reached_target != other.reached_target) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneState_

// alias to use template instance with default allocator
using DroneState =
  formation_msgs::msg::DroneState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__DRONE_STATE__STRUCT_HPP_
