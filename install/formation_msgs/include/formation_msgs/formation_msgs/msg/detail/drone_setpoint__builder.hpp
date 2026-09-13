// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from formation_msgs:msg/DroneSetpoint.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRONE_SETPOINT__BUILDER_HPP_
#define FORMATION_MSGS__MSG__DETAIL__DRONE_SETPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "formation_msgs/msg/detail/drone_setpoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace formation_msgs
{

namespace msg
{

namespace builder
{

class Init_DroneSetpoint_led_color
{
public:
  explicit Init_DroneSetpoint_led_color(::formation_msgs::msg::DroneSetpoint & msg)
  : msg_(msg)
  {}
  ::formation_msgs::msg::DroneSetpoint led_color(::formation_msgs::msg::DroneSetpoint::_led_color_type arg)
  {
    msg_.led_color = std::move(arg);
    return std::move(msg_);
  }

private:
  ::formation_msgs::msg::DroneSetpoint msg_;
};

class Init_DroneSetpoint_target_position
{
public:
  explicit Init_DroneSetpoint_target_position(::formation_msgs::msg::DroneSetpoint & msg)
  : msg_(msg)
  {}
  Init_DroneSetpoint_led_color target_position(::formation_msgs::msg::DroneSetpoint::_target_position_type arg)
  {
    msg_.target_position = std::move(arg);
    return Init_DroneSetpoint_led_color(msg_);
  }

private:
  ::formation_msgs::msg::DroneSetpoint msg_;
};

class Init_DroneSetpoint_drone_id
{
public:
  Init_DroneSetpoint_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneSetpoint_target_position drone_id(::formation_msgs::msg::DroneSetpoint::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_DroneSetpoint_target_position(msg_);
  }

private:
  ::formation_msgs::msg::DroneSetpoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::formation_msgs::msg::DroneSetpoint>()
{
  return formation_msgs::msg::builder::Init_DroneSetpoint_drone_id();
}

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__DRONE_SETPOINT__BUILDER_HPP_
