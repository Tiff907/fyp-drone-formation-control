// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from formation_msgs:msg/GeneratedTransform.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__GENERATED_TRANSFORM__BUILDER_HPP_
#define FORMATION_MSGS__MSG__DETAIL__GENERATED_TRANSFORM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "formation_msgs/msg/detail/generated_transform__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace formation_msgs
{

namespace msg
{

namespace builder
{

class Init_GeneratedTransform_current_points
{
public:
  explicit Init_GeneratedTransform_current_points(::formation_msgs::msg::GeneratedTransform & msg)
  : msg_(msg)
  {}
  ::formation_msgs::msg::GeneratedTransform current_points(::formation_msgs::msg::GeneratedTransform::_current_points_type arg)
  {
    msg_.current_points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::formation_msgs::msg::GeneratedTransform msg_;
};

class Init_GeneratedTransform_plan_description
{
public:
  explicit Init_GeneratedTransform_plan_description(::formation_msgs::msg::GeneratedTransform & msg)
  : msg_(msg)
  {}
  Init_GeneratedTransform_current_points plan_description(::formation_msgs::msg::GeneratedTransform::_plan_description_type arg)
  {
    msg_.plan_description = std::move(arg);
    return Init_GeneratedTransform_current_points(msg_);
  }

private:
  ::formation_msgs::msg::GeneratedTransform msg_;
};

class Init_GeneratedTransform_generated_code
{
public:
  Init_GeneratedTransform_generated_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GeneratedTransform_plan_description generated_code(::formation_msgs::msg::GeneratedTransform::_generated_code_type arg)
  {
    msg_.generated_code = std::move(arg);
    return Init_GeneratedTransform_plan_description(msg_);
  }

private:
  ::formation_msgs::msg::GeneratedTransform msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::formation_msgs::msg::GeneratedTransform>()
{
  return formation_msgs::msg::builder::Init_GeneratedTransform_generated_code();
}

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__GENERATED_TRANSFORM__BUILDER_HPP_
