// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from formation_msgs:msg/DronePath.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRONE_PATH__TRAITS_HPP_
#define FORMATION_MSGS__MSG__DETAIL__DRONE_PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "formation_msgs/msg/detail/drone_path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'waypoints'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'waypoint_times'
// Member 'formation_start_time'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace formation_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DronePath & msg,
  std::ostream & out)
{
  out << "{";
  // member: drone_id
  {
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << ", ";
  }

  // member: waypoints
  {
    if (msg.waypoints.size() == 0) {
      out << "waypoints: []";
    } else {
      out << "waypoints: [";
      size_t pending_items = msg.waypoints.size();
      for (auto item : msg.waypoints) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: waypoint_times
  {
    if (msg.waypoint_times.size() == 0) {
      out << "waypoint_times: []";
    } else {
      out << "waypoint_times: [";
      size_t pending_items = msg.waypoint_times.size();
      for (auto item : msg.waypoint_times) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: formation_start_time
  {
    out << "formation_start_time: ";
    to_flow_style_yaml(msg.formation_start_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DronePath & msg,
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

  // member: waypoints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoints.size() == 0) {
      out << "waypoints: []\n";
    } else {
      out << "waypoints:\n";
      for (auto item : msg.waypoints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: waypoint_times
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoint_times.size() == 0) {
      out << "waypoint_times: []\n";
    } else {
      out << "waypoint_times:\n";
      for (auto item : msg.waypoint_times) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: formation_start_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "formation_start_time:\n";
    to_block_style_yaml(msg.formation_start_time, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DronePath & msg, bool use_flow_style = false)
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
  const formation_msgs::msg::DronePath & msg,
  std::ostream & out, size_t indentation = 0)
{
  formation_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use formation_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const formation_msgs::msg::DronePath & msg)
{
  return formation_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<formation_msgs::msg::DronePath>()
{
  return "formation_msgs::msg::DronePath";
}

template<>
inline const char * name<formation_msgs::msg::DronePath>()
{
  return "formation_msgs/msg/DronePath";
}

template<>
struct has_fixed_size<formation_msgs::msg::DronePath>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<formation_msgs::msg::DronePath>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<formation_msgs::msg::DronePath>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FORMATION_MSGS__MSG__DETAIL__DRONE_PATH__TRAITS_HPP_
