// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from formation_msgs:msg/RefinementCmd.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CMD__STRUCT_HPP_
#define FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'current_points'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__formation_msgs__msg__RefinementCmd __attribute__((deprecated))
#else
# define DEPRECATED__formation_msgs__msg__RefinementCmd __declspec(deprecated)
#endif

namespace formation_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RefinementCmd_
{
  using Type = RefinementCmd_<ContainerAllocator>;

  explicit RefinementCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->instruction_text = "";
    }
  }

  explicit RefinementCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : instruction_text(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->instruction_text = "";
    }
  }

  // field types and members
  using _instruction_text_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _instruction_text_type instruction_text;
  using _current_points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _current_points_type current_points;

  // setters for named parameter idiom
  Type & set__instruction_text(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->instruction_text = _arg;
    return *this;
  }
  Type & set__current_points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->current_points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    formation_msgs::msg::RefinementCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const formation_msgs::msg::RefinementCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<formation_msgs::msg::RefinementCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<formation_msgs::msg::RefinementCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::RefinementCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::RefinementCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::RefinementCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::RefinementCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<formation_msgs::msg::RefinementCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<formation_msgs::msg::RefinementCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__formation_msgs__msg__RefinementCmd
    std::shared_ptr<formation_msgs::msg::RefinementCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__formation_msgs__msg__RefinementCmd
    std::shared_ptr<formation_msgs::msg::RefinementCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RefinementCmd_ & other) const
  {
    if (this->instruction_text != other.instruction_text) {
      return false;
    }
    if (this->current_points != other.current_points) {
      return false;
    }
    return true;
  }
  bool operator!=(const RefinementCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RefinementCmd_

// alias to use template instance with default allocator
using RefinementCmd =
  formation_msgs::msg::RefinementCmd_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CMD__STRUCT_HPP_
