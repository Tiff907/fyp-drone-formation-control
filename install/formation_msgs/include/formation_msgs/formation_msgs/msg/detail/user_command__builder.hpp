// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from formation_msgs:msg/UserCommand.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__USER_COMMAND__BUILDER_HPP_
#define FORMATION_MSGS__MSG__DETAIL__USER_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "formation_msgs/msg/detail/user_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace formation_msgs
{

namespace msg
{

namespace builder
{

class Init_UserCommand_command
{
public:
  Init_UserCommand_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::formation_msgs::msg::UserCommand command(::formation_msgs::msg::UserCommand::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::formation_msgs::msg::UserCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::formation_msgs::msg::UserCommand>()
{
  return formation_msgs::msg::builder::Init_UserCommand_command();
}

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__USER_COMMAND__BUILDER_HPP_
