// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from formation_msgs:msg/RefinementCmd.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CMD__TRAITS_HPP_
#define FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "formation_msgs/msg/detail/refinement_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'current_points'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace formation_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RefinementCmd & msg,
  std::ostream & out)
{
  out << "{";
  // member: instruction_text
  {
    out << "instruction_text: ";
    rosidl_generator_traits::value_to_yaml(msg.instruction_text, out);
    out << ", ";
  }

  // member: current_points
  {
    if (msg.current_points.size() == 0) {
      out << "current_points: []";
    } else {
      out << "current_points: [";
      size_t pending_items = msg.current_points.size();
      for (auto item : msg.current_points) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RefinementCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: instruction_text
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "instruction_text: ";
    rosidl_generator_traits::value_to_yaml(msg.instruction_text, out);
    out << "\n";
  }

  // member: current_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.current_points.size() == 0) {
      out << "current_points: []\n";
    } else {
      out << "current_points:\n";
      for (auto item : msg.current_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RefinementCmd & msg, bool use_flow_style = false)
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
  const formation_msgs::msg::RefinementCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  formation_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use formation_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const formation_msgs::msg::RefinementCmd & msg)
{
  return formation_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<formation_msgs::msg::RefinementCmd>()
{
  return "formation_msgs::msg::RefinementCmd";
}

template<>
inline const char * name<formation_msgs::msg::RefinementCmd>()
{
  return "formation_msgs/msg/RefinementCmd";
}

template<>
struct has_fixed_size<formation_msgs::msg::RefinementCmd>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<formation_msgs::msg::RefinementCmd>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<formation_msgs::msg::RefinementCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CMD__TRAITS_HPP_
