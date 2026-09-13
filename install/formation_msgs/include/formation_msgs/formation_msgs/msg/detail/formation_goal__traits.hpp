// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from formation_msgs:msg/FormationGoal.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__TRAITS_HPP_
#define FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "formation_msgs/msg/detail/formation_goal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'target_points'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'point_colors'
#include "std_msgs/msg/detail/color_rgba__traits.hpp"
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace formation_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FormationGoal & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_points
  {
    if (msg.target_points.size() == 0) {
      out << "target_points: []";
    } else {
      out << "target_points: [";
      size_t pending_items = msg.target_points.size();
      for (auto item : msg.target_points) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: assigned_drone_ids
  {
    if (msg.assigned_drone_ids.size() == 0) {
      out << "assigned_drone_ids: []";
    } else {
      out << "assigned_drone_ids: [";
      size_t pending_items = msg.assigned_drone_ids.size();
      for (auto item : msg.assigned_drone_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: point_colors
  {
    if (msg.point_colors.size() == 0) {
      out << "point_colors: []";
    } else {
      out << "point_colors: [";
      size_t pending_items = msg.point_colors.size();
      for (auto item : msg.point_colors) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: formation_id
  {
    out << "formation_id: ";
    rosidl_generator_traits::value_to_yaml(msg.formation_id, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FormationGoal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_points.size() == 0) {
      out << "target_points: []\n";
    } else {
      out << "target_points:\n";
      for (auto item : msg.target_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: assigned_drone_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.assigned_drone_ids.size() == 0) {
      out << "assigned_drone_ids: []\n";
    } else {
      out << "assigned_drone_ids:\n";
      for (auto item : msg.assigned_drone_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: point_colors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.point_colors.size() == 0) {
      out << "point_colors: []\n";
    } else {
      out << "point_colors:\n";
      for (auto item : msg.point_colors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: formation_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "formation_id: ";
    rosidl_generator_traits::value_to_yaml(msg.formation_id, out);
    out << "\n";
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp:\n";
    to_block_style_yaml(msg.timestamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FormationGoal & msg, bool use_flow_style = false)
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
  const formation_msgs::msg::FormationGoal & msg,
  std::ostream & out, size_t indentation = 0)
{
  formation_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use formation_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const formation_msgs::msg::FormationGoal & msg)
{
  return formation_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<formation_msgs::msg::FormationGoal>()
{
  return "formation_msgs::msg::FormationGoal";
}

template<>
inline const char * name<formation_msgs::msg::FormationGoal>()
{
  return "formation_msgs/msg/FormationGoal";
}

template<>
struct has_fixed_size<formation_msgs::msg::FormationGoal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<formation_msgs::msg::FormationGoal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<formation_msgs::msg::FormationGoal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__TRAITS_HPP_
