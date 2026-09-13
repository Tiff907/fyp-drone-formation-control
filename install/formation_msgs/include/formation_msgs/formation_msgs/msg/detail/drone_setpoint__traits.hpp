// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from formation_msgs:msg/DroneSetpoint.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRONE_SETPOINT__TRAITS_HPP_
#define FORMATION_MSGS__MSG__DETAIL__DRONE_SETPOINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "formation_msgs/msg/detail/drone_setpoint__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'target_position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'led_color'
#include "std_msgs/msg/detail/color_rgba__traits.hpp"

namespace formation_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DroneSetpoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: drone_id
  {
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << ", ";
  }

  // member: target_position
  {
    out << "target_position: ";
    to_flow_style_yaml(msg.target_position, out);
    out << ", ";
  }

  // member: led_color
  {
    out << "led_color: ";
    to_flow_style_yaml(msg.led_color, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneSetpoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: drone_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << "\n";
  }

  // member: target_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_position:\n";
    to_block_style_yaml(msg.target_position, out, indentation + 2);
  }

  // member: led_color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "led_color:\n";
    to_block_style_yaml(msg.led_color, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneSetpoint & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace formation_msgs

namespace rosidl_generator_traits
{

[[deprecated("use formation_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const formation_msgs::msg::DroneSetpoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  formation_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use formation_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const formation_msgs::msg::DroneSetpoint & msg)
{
  return formation_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<formation_msgs::msg::DroneSetpoint>()
{
  return "formation_msgs::msg::DroneSetpoint";
}

template<>
inline const char * name<formation_msgs::msg::DroneSetpoint>()
{
  return "formation_msgs/msg/DroneSetpoint";
}

template<>
struct has_fixed_size<formation_msgs::msg::DroneSetpoint>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<std_msgs::msg::ColorRGBA>::value> {};

template<>
struct has_bounded_size<formation_msgs::msg::DroneSetpoint>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<std_msgs::msg::ColorRGBA>::value> {};

template<>
struct is_message<formation_msgs::msg::DroneSetpoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FORMATION_MSGS__MSG__DETAIL__DRONE_SETPOINT__TRAITS_HPP_
