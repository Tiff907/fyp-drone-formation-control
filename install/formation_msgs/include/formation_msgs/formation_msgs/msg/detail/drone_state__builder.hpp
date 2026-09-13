// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from formation_msgs:msg/DroneState.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRONE_STATE__BUILDER_HPP_
#define FORMATION_MSGS__MSG__DETAIL__DRONE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "formation_msgs/msg/detail/drone_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace formation_msgs
{

namespace msg
{

namespace builder
{

class Init_DroneState_reached_target
{
public:
  explicit Init_DroneState_reached_target(::formation_msgs::msg::DroneState & msg)
  : msg_(msg)
  {}
  ::formation_msgs::msg::DroneState reached_target(::formation_msgs::msg::DroneState::_reached_target_type arg)
  {
    msg_.reached_target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::formation_msgs::msg::DroneState msg_;
};

class Init_DroneState_available
{
public:
  explicit Init_DroneState_available(::formation_msgs::msg::DroneState & msg)
  : msg_(msg)
  {}
  Init_DroneState_reached_target available(::formation_msgs::msg::DroneState::_available_type arg)
  {
    msg_.available = std::move(arg);
    return Init_DroneState_reached_target(msg_);
  }

private:
  ::formation_msgs::msg::DroneState msg_;
};

class Init_DroneState_position
{
public:
  explicit Init_DroneState_position(::formation_msgs::msg::DroneState & msg)
  : msg_(msg)
  {}
  Init_DroneState_available position(::formation_msgs::msg::DroneState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_DroneState_available(msg_);
  }

private:
  ::formation_msgs::msg::DroneState msg_;
};

class Init_DroneState_drone_id
{
public:
  Init_DroneState_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneState_position drone_id(::formation_msgs::msg::DroneState::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_DroneState_position(msg_);
  }

private:
  ::formation_msgs::msg::DroneState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::formation_msgs::msg::DroneState>()
{
  return formation_msgs::msg::builder::Init_DroneState_drone_id();
}

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__DRONE_STATE__BUILDER_HPP_
