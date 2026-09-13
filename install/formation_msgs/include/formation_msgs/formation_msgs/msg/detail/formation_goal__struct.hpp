// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from formation_msgs:msg/FormationGoal.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__STRUCT_HPP_
#define FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'target_points'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'point_colors'
#include "std_msgs/msg/detail/color_rgba__struct.hpp"
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__formation_msgs__msg__FormationGoal __attribute__((deprecated))
#else
# define DEPRECATED__formation_msgs__msg__FormationGoal __declspec(deprecated)
#endif

namespace formation_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FormationGoal_
{
  using Type = FormationGoal_<ContainerAllocator>;

  explicit FormationGoal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->formation_id = 0ul;
    }
  }

  explicit FormationGoal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->formation_id = 0ul;
    }
  }

  // field types and members
  using _target_points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _target_points_type target_points;
  using _assigned_drone_ids_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _assigned_drone_ids_type assigned_drone_ids;
  using _point_colors_type =
    std::vector<std_msgs::msg::ColorRGBA_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std_msgs::msg::ColorRGBA_<ContainerAllocator>>>;
  _point_colors_type point_colors;
  using _formation_id_type =
    uint32_t;
  _formation_id_type formation_id;
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;

  // setters for named parameter idiom
  Type & set__target_points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->target_points = _arg;
    return *this;
  }
  Type & set__assigned_drone_ids(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->assigned_drone_ids = _arg;
    return *this;
  }
  Type & set__point_colors(
    const std::vector<std_msgs::msg::ColorRGBA_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std_msgs::msg::ColorRGBA_<ContainerAllocator>>> & _arg)
  {
    this->point_colors = _arg;
    return *this;
  }
  Type & set__formation_id(
    const uint32_t & _arg)
  {
    this->formation_id = _arg;
    return *this;
  }
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    formation_msgs::msg::FormationGoal_<ContainerAllocator> *;
  using ConstRawPtr =
    const formation_msgs::msg::FormationGoal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<formation_msgs::msg::FormationGoal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<formation_msgs::msg::FormationGoal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::FormationGoal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::FormationGoal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::FormationGoal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::FormationGoal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<formation_msgs::msg::FormationGoal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<formation_msgs::msg::FormationGoal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__formation_msgs__msg__FormationGoal
    std::shared_ptr<formation_msgs::msg::FormationGoal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__formation_msgs__msg__FormationGoal
    std::shared_ptr<formation_msgs::msg::FormationGoal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FormationGoal_ & other) const
  {
    if (this->target_points != other.target_points) {
      return false;
    }
    if (this->assigned_drone_ids != other.assigned_drone_ids) {
      return false;
    }
    if (this->point_colors != other.point_colors) {
      return false;
    }
    if (this->formation_id != other.formation_id) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const FormationGoal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FormationGoal_

// alias to use template instance with default allocator
using FormationGoal =
  formation_msgs::msg::FormationGoal_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__STRUCT_HPP_
