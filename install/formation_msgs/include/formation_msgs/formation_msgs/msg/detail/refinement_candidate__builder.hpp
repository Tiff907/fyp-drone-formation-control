// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from formation_msgs:msg/RefinementCandidate.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CANDIDATE__BUILDER_HPP_
#define FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CANDIDATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "formation_msgs/msg/detail/refinement_candidate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace formation_msgs
{

namespace msg
{

namespace builder
{

class Init_RefinementCandidate_plan_description
{
public:
  explicit Init_RefinementCandidate_plan_description(::formation_msgs::msg::RefinementCandidate & msg)
  : msg_(msg)
  {}
  ::formation_msgs::msg::RefinementCandidate plan_description(::formation_msgs::msg::RefinementCandidate::_plan_description_type arg)
  {
    msg_.plan_description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::formation_msgs::msg::RefinementCandidate msg_;
};

class Init_RefinementCandidate_candidate_colors
{
public:
  explicit Init_RefinementCandidate_candidate_colors(::formation_msgs::msg::RefinementCandidate & msg)
  : msg_(msg)
  {}
  Init_RefinementCandidate_plan_description candidate_colors(::formation_msgs::msg::RefinementCandidate::_candidate_colors_type arg)
  {
    msg_.candidate_colors = std::move(arg);
    return Init_RefinementCandidate_plan_description(msg_);
  }

private:
  ::formation_msgs::msg::RefinementCandidate msg_;
};

class Init_RefinementCandidate_candidate_points
{
public:
  Init_RefinementCandidate_candidate_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RefinementCandidate_candidate_colors candidate_points(::formation_msgs::msg::RefinementCandidate::_candidate_points_type arg)
  {
    msg_.candidate_points = std::move(arg);
    return Init_RefinementCandidate_candidate_colors(msg_);
  }

private:
  ::formation_msgs::msg::RefinementCandidate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::formation_msgs::msg::RefinementCandidate>()
{
  return formation_msgs::msg::builder::Init_RefinementCandidate_candidate_points();
}

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CANDIDATE__BUILDER_HPP_
