// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from formation_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__SYSTEM_STATE__BUILDER_HPP_
#define FORMATION_MSGS__MSG__DETAIL__SYSTEM_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "formation_msgs/msg/detail/system_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace formation_msgs
{

namespace msg
{

namespace builder
{

class Init_SystemState_state
{
public:
  Init_SystemState_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::formation_msgs::msg::SystemState state(::formation_msgs::msg::SystemState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::formation_msgs::msg::SystemState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::formation_msgs::msg::SystemState>()
{
  return formation_msgs::msg::builder::Init_SystemState_state();
}

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__SYSTEM_STATE__BUILDER_HPP_
