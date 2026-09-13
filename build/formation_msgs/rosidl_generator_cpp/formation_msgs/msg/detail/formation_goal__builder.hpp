// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from formation_msgs:msg/FormationGoal.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__BUILDER_HPP_
#define FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "formation_msgs/msg/detail/formation_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace formation_msgs
{

namespace msg
{

namespace builder
{

class Init_FormationGoal_timestamp
{
public:
  explicit Init_FormationGoal_timestamp(::formation_msgs::msg::FormationGoal & msg)
  : msg_(msg)
  {}
  ::formation_msgs::msg::FormationGoal timestamp(::formation_msgs::msg::FormationGoal::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::formation_msgs::msg::FormationGoal msg_;
};

class Init_FormationGoal_formation_id
{
public:
  explicit Init_FormationGoal_formation_id(::formation_msgs::msg::FormationGoal & msg)
  : msg_(msg)
  {}
  Init_FormationGoal_timestamp formation_id(::formation_msgs::msg::FormationGoal::_formation_id_type arg)
  {
    msg_.formation_id = std::move(arg);
    return Init_FormationGoal_timestamp(msg_);
  }

private:
  ::formation_msgs::msg::FormationGoal msg_;
};

class Init_FormationGoal_point_colors
{
public:
  explicit Init_FormationGoal_point_colors(::formation_msgs::msg::FormationGoal & msg)
  : msg_(msg)
  {}
  Init_FormationGoal_formation_id point_colors(::formation_msgs::msg::FormationGoal::_point_colors_type arg)
  {
    msg_.point_colors = std::move(arg);
    return Init_FormationGoal_formation_id(msg_);
  }

private:
  ::formation_msgs::msg::FormationGoal msg_;
};

class Init_FormationGoal_assigned_drone_ids
{
public:
  explicit Init_FormationGoal_assigned_drone_ids(::formation_msgs::msg::FormationGoal & msg)
  : msg_(msg)
  {}
  Init_FormationGoal_point_colors assigned_drone_ids(::formation_msgs::msg::FormationGoal::_assigned_drone_ids_type arg)
  {
    msg_.assigned_drone_ids = std::move(arg);
    return Init_FormationGoal_point_colors(msg_);
  }

private:
  ::formation_msgs::msg::FormationGoal msg_;
};

class Init_FormationGoal_target_points
{
public:
  Init_FormationGoal_target_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FormationGoal_assigned_drone_ids target_points(::formation_msgs::msg::FormationGoal::_target_points_type arg)
  {
    msg_.target_points = std::move(arg);
    return Init_FormationGoal_assigned_drone_ids(msg_);
  }

private:
  ::formation_msgs::msg::FormationGoal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::formation_msgs::msg::FormationGoal>()
{
  return formation_msgs::msg::builder::Init_FormationGoal_target_points();
}

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__BUILDER_HPP_
