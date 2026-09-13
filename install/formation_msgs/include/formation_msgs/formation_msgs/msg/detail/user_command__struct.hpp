// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from formation_msgs:msg/UserCommand.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__USER_COMMAND__STRUCT_HPP_
#define FORMATION_MSGS__MSG__DETAIL__USER_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__formation_msgs__msg__UserCommand __attribute__((deprecated))
#else
# define DEPRECATED__formation_msgs__msg__UserCommand __declspec(deprecated)
#endif

namespace formation_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UserCommand_
{
  using Type = UserCommand_<ContainerAllocator>;

  explicit UserCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
    }
  }

  explicit UserCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
    }
  }

  // field types and members
  using _command_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _command_type command;

  // setters for named parameter idiom
  Type & set__command(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->command = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    formation_msgs::msg::UserCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const formation_msgs::msg::UserCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<formation_msgs::msg::UserCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<formation_msgs::msg::UserCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::UserCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::UserCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      formation_msgs::msg::UserCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<formation_msgs::msg::UserCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<formation_msgs::msg::UserCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<formation_msgs::msg::UserCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__formation_msgs__msg__UserCommand
    std::shared_ptr<formation_msgs::msg::UserCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__formation_msgs__msg__UserCommand
    std::shared_ptr<formation_msgs::msg::UserCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UserCommand_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    return true;
  }
  bool operator!=(const UserCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UserCommand_

// alias to use template instance with default allocator
using UserCommand =
  formation_msgs::msg::UserCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__USER_COMMAND__STRUCT_HPP_
