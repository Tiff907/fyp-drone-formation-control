// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from formation_msgs:msg/DrawnShape.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRAWN_SHAPE__STRUCT_HPP_
#define FORMATION_MSGS__MSG__DETAIL__DRAWN_SHAPE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'raw_points'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'stroke_colors'
#include "std_msgs/msg/detail/color_rgba__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__formation_msgs__msg__DrawnShape __attribute__((deprecated))
#else
# define DEPRECATED__formation_msgs__msg__DrawnShape __declspec(deprecated)
#endif

namespace formation_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DrawnShape_
{
  using Type = DrawnShape_<ContainerAllocator>;

  explicit DrawnShape_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit DrawnShape_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _raw_points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _raw_points_type raw_points;
  using _stroke_colors_type =
    std::vector<std_msgs::msg::ColorRGBA_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std_msgs::msg::ColorRGBA_<ContainerAllocator>>>;
  _stroke_colors_type stroke_colors;

  // setters for named parameter idiom
  Type & set__raw_points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->raw_points = _arg;
    return *this;
  }
  Type & set__stroke_colors(
    const std::vector<std_msgs::msg::ColorRGBA_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std_msgs::msg::ColorRGBA_<ContainerAllocator>>> & _arg)
  {
    this->stroke_colors = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    formation_msgs::msg::DrawnShape_<ContainerAllocator> *;
  using ConstRawPtr =
    const formation_msgs::msg::DrawnShape_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<formation_msgs::msg::DrawnShape_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<formation_msgs::msg::DrawnShape_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::DrawnShape_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::DrawnShape_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::DrawnShape_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::DrawnShape_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<formation_msgs::msg::DrawnShape_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<formation_msgs::msg::DrawnShape_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__formation_msgs__msg__DrawnShape
    std::shared_ptr<formation_msgs::msg::DrawnShape_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__formation_msgs__msg__DrawnShape
    std::shared_ptr<formation_msgs::msg::DrawnShape_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DrawnShape_ & other) const
  {
    if (this->raw_points != other.raw_points) {
      return false;
    }
    if (this->stroke_colors != other.stroke_colors) {
      return false;
    }
    return true;
  }
  bool operator!=(const DrawnShape_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DrawnShape_

// alias to use template instance with default allocator
using DrawnShape =
  formation_msgs::msg::DrawnShape_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__DRAWN_SHAPE__STRUCT_HPP_
