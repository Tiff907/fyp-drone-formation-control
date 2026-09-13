// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from formation_msgs:msg/DronePath.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRONE_PATH__BUILDER_HPP_
#define FORMATION_MSGS__MSG__DETAIL__DRONE_PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "formation_msgs/msg/detail/drone_path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace formation_msgs
{

namespace msg
{

namespace builder
{

class Init_DronePath_formation_start_time
{
public:
  explicit Init_DronePath_formation_start_time(::formation_msgs::msg::DronePath & msg)
  : msg_(msg)
  {}
  ::formation_msgs::msg::DronePath formation_start_time(::formation_msgs::msg::DronePath::_formation_start_time_type arg)
  {
    msg_.formation_start_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::formation_msgs::msg::DronePath msg_;
};

class Init_DronePath_waypoint_times
{
public:
  explicit Init_DronePath_waypoint_times(::formation_msgs::msg::DronePath & msg)
  : msg_(msg)
  {}
  Init_DronePath_formation_start_time waypoint_times(::formation_msgs::msg::DronePath::_waypoint_times_type arg)
  {
    msg_.waypoint_times = std::move(arg);
    return Init_DronePath_formation_start_time(msg_);
  }

private:
  ::formation_msgs::msg::DronePath msg_;
};

class Init_DronePath_waypoints
{
public:
  explicit Init_DronePath_waypoints(::formation_msgs::msg::DronePath & msg)
  : msg_(msg)
  {}
  Init_DronePath_waypoint_times waypoints(::formation_msgs::msg::DronePath::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return Init_DronePath_waypoint_times(msg_);
  }

private:
  ::formation_msgs::msg::DronePath msg_;
};

class Init_DronePath_drone_id
{
public:
  Init_DronePath_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DronePath_waypoints drone_id(::formation_msgs::msg::DronePath::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_DronePath_waypoints(msg_);
  }

private:
  ::formation_msgs::msg::DronePath msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::formation_msgs::msg::DronePath>()
{
  return formation_msgs::msg::builder::Init_DronePath_drone_id();
}

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__DRONE_PATH__BUILDER_HPP_
