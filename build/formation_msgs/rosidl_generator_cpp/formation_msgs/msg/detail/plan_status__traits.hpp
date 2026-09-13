// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from formation_msgs:msg/PlanStatus.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__PLAN_STATUS__TRAITS_HPP_
#define FORMATION_MSGS__MSG__DETAIL__PLAN_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "formation_msgs/msg/detail/plan_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace formation_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PlanStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: status_message
  {
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
    out << ", ";
  }

  // member: usable_drone_count
  {
    out << "usable_drone_count: ";
    rosidl_generator_traits::value_to_yaml(msg.usable_drone_count, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PlanStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: status_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
    out << "\n";
  }

  // member: usable_drone_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "usable_drone_count: ";
    rosidl_generator_traits::value_to_yaml(msg.usable_drone_count, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PlanStatus & msg, bool use_flow_style = false)
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
  const formation_msgs::msg::PlanStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  formation_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use formation_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const formation_msgs::msg::PlanStatus & msg)
{
  return formation_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<formation_msgs::msg::PlanStatus>()
{
  return "formation_msgs::msg::PlanStatus";
}

template<>
inline const char * name<formation_msgs::msg::PlanStatus>()
{
  return "formation_msgs/msg/PlanStatus";
}

template<>
struct has_fixed_size<formation_msgs::msg::PlanStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<formation_msgs::msg::PlanStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<formation_msgs::msg::PlanStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FORMATION_MSGS__MSG__DETAIL__PLAN_STATUS__TRAITS_HPP_
