// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from formation_msgs:msg/RefinementCandidate.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CANDIDATE__TRAITS_HPP_
#define FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CANDIDATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "formation_msgs/msg/detail/refinement_candidate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'candidate_points'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'candidate_colors'
#include "std_msgs/msg/detail/color_rgba__traits.hpp"

namespace formation_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RefinementCandidate & msg,
  std::ostream & out)
{
  out << "{";
  // member: candidate_points
  {
    if (msg.candidate_points.size() == 0) {
      out << "candidate_points: []";
    } else {
      out << "candidate_points: [";
      size_t pending_items = msg.candidate_points.size();
      for (auto item : msg.candidate_points) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: candidate_colors
  {
    if (msg.candidate_colors.size() == 0) {
      out << "candidate_colors: []";
    } else {
      out << "candidate_colors: [";
      size_t pending_items = msg.candidate_colors.size();
      for (auto item : msg.candidate_colors) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: plan_description
  {
    out << "plan_description: ";
    rosidl_generator_traits::value_to_yaml(msg.plan_description, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RefinementCandidate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: candidate_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.candidate_points.size() == 0) {
      out << "candidate_points: []\n";
    } else {
      out << "candidate_points:\n";
      for (auto item : msg.candidate_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: candidate_colors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.candidate_colors.size() == 0) {
      out << "candidate_colors: []\n";
    } else {
      out << "candidate_colors:\n";
      for (auto item : msg.candidate_colors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: plan_description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "plan_description: ";
    rosidl_generator_traits::value_to_yaml(msg.plan_description, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RefinementCandidate & msg, bool use_flow_style = false)
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
  const formation_msgs::msg::RefinementCandidate & msg,
  std::ostream & out, size_t indentation = 0)
{
  formation_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use formation_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const formation_msgs::msg::RefinementCandidate & msg)
{
  return formation_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<formation_msgs::msg::RefinementCandidate>()
{
  return "formation_msgs::msg::RefinementCandidate";
}

template<>
inline const char * name<formation_msgs::msg::RefinementCandidate>()
{
  return "formation_msgs/msg/RefinementCandidate";
}

template<>
struct has_fixed_size<formation_msgs::msg::RefinementCandidate>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<formation_msgs::msg::RefinementCandidate>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<formation_msgs::msg::RefinementCandidate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CANDIDATE__TRAITS_HPP_
