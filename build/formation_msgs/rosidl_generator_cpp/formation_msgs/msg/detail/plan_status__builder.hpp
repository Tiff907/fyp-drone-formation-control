// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from formation_msgs:msg/PlanStatus.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__PLAN_STATUS__BUILDER_HPP_
#define FORMATION_MSGS__MSG__DETAIL__PLAN_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "formation_msgs/msg/detail/plan_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace formation_msgs
{

namespace msg
{

namespace builder
{

class Init_PlanStatus_usable_drone_count
{
public:
  explicit Init_PlanStatus_usable_drone_count(::formation_msgs::msg::PlanStatus & msg)
  : msg_(msg)
  {}
  ::formation_msgs::msg::PlanStatus usable_drone_count(::formation_msgs::msg::PlanStatus::_usable_drone_count_type arg)
  {
    msg_.usable_drone_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::formation_msgs::msg::PlanStatus msg_;
};

class Init_PlanStatus_status_message
{
public:
  explicit Init_PlanStatus_status_message(::formation_msgs::msg::PlanStatus & msg)
  : msg_(msg)
  {}
  Init_PlanStatus_usable_drone_count status_message(::formation_msgs::msg::PlanStatus::_status_message_type arg)
  {
    msg_.status_message = std::move(arg);
    return Init_PlanStatus_usable_drone_count(msg_);
  }

private:
  ::formation_msgs::msg::PlanStatus msg_;
};

class Init_PlanStatus_success
{
public:
  Init_PlanStatus_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlanStatus_status_message success(::formation_msgs::msg::PlanStatus::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_PlanStatus_status_message(msg_);
  }

private:
  ::formation_msgs::msg::PlanStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::formation_msgs::msg::PlanStatus>()
{
  return formation_msgs::msg::builder::Init_PlanStatus_success();
}

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__PLAN_STATUS__BUILDER_HPP_
