// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from formation_msgs:msg/DroneSetpoint.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRONE_SETPOINT__STRUCT_HPP_
#define FORMATION_MSGS__MSG__DETAIL__DRONE_SETPOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'target_position'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'led_color'
#include "std_msgs/msg/detail/color_rgba__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__formation_msgs__msg__DroneSetpoint __attribute__((deprecated))
#else
# define DEPRECATED__formation_msgs__msg__DroneSetpoint __declspec(deprecated)
#endif

namespace formation_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DroneSetpoint_
{
  using Type = DroneSetpoint_<ContainerAllocator>;

  explicit DroneSetpoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_position(_init),
    led_color(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = 0l;
    }
  }

  explicit DroneSetpoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_position(_alloc, _init),
    led_color(_alloc, _init)
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
  using _target_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _target_position_type target_position;
  using _led_color_type =
    std_msgs::msg::ColorRGBA_<ContainerAllocator>;
  _led_color_type led_color;

  // setters for named parameter idiom
  Type & set__drone_id(
    const int32_t & _arg)
  {
    this->drone_id = _arg;
    return *this;
  }
  Type & set__target_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->target_position = _arg;
    return *this;
  }
  Type & set__led_color(
    const std_msgs::msg::ColorRGBA_<ContainerAllocator> & _arg)
  {
    this->led_color = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    formation_msgs::msg::DroneSetpoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const formation_msgs::msg::DroneSetpoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<formation_msgs::msg::DroneSetpoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<formation_msgs::msg::DroneSetpoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::DroneSetpoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::DroneSetpoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::DroneSetpoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::DroneSetpoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<formation_msgs::msg::DroneSetpoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<formation_msgs::msg::DroneSetpoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__formation_msgs__msg__DroneSetpoint
    std::shared_ptr<formation_msgs::msg::DroneSetpoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__formation_msgs__msg__DroneSetpoint
    std::shared_ptr<formation_msgs::msg::DroneSetpoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneSetpoint_ & other) const
  {
    if (this->drone_id != other.drone_id) {
      return false;
    }
    if (this->target_position != other.target_position) {
      return false;
    }
    if (this->led_color != other.led_color) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneSetpoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneSetpoint_

// alias to use template instance with default allocator
using DroneSetpoint =
  formation_msgs::msg::DroneSetpoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__DRONE_SETPOINT__STRUCT_HPP_
