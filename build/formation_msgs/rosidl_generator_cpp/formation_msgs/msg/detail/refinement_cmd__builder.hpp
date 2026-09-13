// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from formation_msgs:msg/RefinementCmd.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CMD__BUILDER_HPP_
#define FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "formation_msgs/msg/detail/refinement_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace formation_msgs
{

namespace msg
{

namespace builder
{

class Init_RefinementCmd_current_points
{
public:
  explicit Init_RefinementCmd_current_points(::formation_msgs::msg::RefinementCmd & msg)
  : msg_(msg)
  {}
  ::formation_msgs::msg::RefinementCmd current_points(::formation_msgs::msg::RefinementCmd::_current_points_type arg)
  {
    msg_.current_points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::formation_msgs::msg::RefinementCmd msg_;
};

class Init_RefinementCmd_instruction_text
{
public:
  Init_RefinementCmd_instruction_text()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RefinementCmd_current_points instruction_text(::formation_msgs::msg::RefinementCmd::_instruction_text_type arg)
  {
    msg_.instruction_text = std::move(arg);
    return Init_RefinementCmd_current_points(msg_);
  }

private:
  ::formation_msgs::msg::RefinementCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::formation_msgs::msg::RefinementCmd>()
{
  return formation_msgs::msg::builder::Init_RefinementCmd_instruction_text();
}

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CMD__BUILDER_HPP_
