// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from formation_msgs:msg/DrawnShape.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRAWN_SHAPE__TRAITS_HPP_
#define FORMATION_MSGS__MSG__DETAIL__DRAWN_SHAPE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "formation_msgs/msg/detail/drawn_shape__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'raw_points'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'stroke_colors'
#include "std_msgs/msg/detail/color_rgba__traits.hpp"

namespace formation_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DrawnShape & msg,
  std::ostream & out)
{
  out << "{";
  // member: raw_points
  {
    if (msg.raw_points.size() == 0) {
      out << "raw_points: []";
    } else {
      out << "raw_points: [";
      size_t pending_items = msg.raw_points.size();
      for (auto item : msg.raw_points) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: stroke_colors
  {
    if (msg.stroke_colors.size() == 0) {
      out << "stroke_colors: []";
    } else {
      out << "stroke_colors: [";
      size_t pending_items = msg.stroke_colors.size();
      for (auto item : msg.stroke_colors) {
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
  const DrawnShape & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: raw_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.raw_points.size() == 0) {
      out << "raw_points: []\n";
    } else {
      out << "raw_points:\n";
      for (auto item : msg.raw_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: stroke_colors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.stroke_colors.size() == 0) {
      out << "stroke_colors: []\n";
    } else {
      out << "stroke_colors:\n";
      for (auto item : msg.stroke_colors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DrawnShape & msg, bool use_flow_style = false)
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
  const formation_msgs::msg::DrawnShape & msg,
  std::ostream & out, size_t indentation = 0)
{
  formation_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use formation_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const formation_msgs::msg::DrawnShape & msg)
{
  return formation_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<formation_msgs::msg::DrawnShape>()
{
  return "formation_msgs::msg::DrawnShape";
}

template<>
inline const char * name<formation_msgs::msg::DrawnShape>()
{
  return "formation_msgs/msg/DrawnShape";
}

template<>
struct has_fixed_size<formation_msgs::msg::DrawnShape>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<formation_msgs::msg::DrawnShape>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<formation_msgs::msg::DrawnShape>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FORMATION_MSGS__MSG__DETAIL__DRAWN_SHAPE__TRAITS_HPP_
