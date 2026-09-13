// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from formation_msgs:msg/DrawnShape.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRAWN_SHAPE__BUILDER_HPP_
#define FORMATION_MSGS__MSG__DETAIL__DRAWN_SHAPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "formation_msgs/msg/detail/drawn_shape__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace formation_msgs
{

namespace msg
{

namespace builder
{

class Init_DrawnShape_stroke_colors
{
public:
  explicit Init_DrawnShape_stroke_colors(::formation_msgs::msg::DrawnShape & msg)
  : msg_(msg)
  {}
  ::formation_msgs::msg::DrawnShape stroke_colors(::formation_msgs::msg::DrawnShape::_stroke_colors_type arg)
  {
    msg_.stroke_colors = std::move(arg);
    return std::move(msg_);
  }

private:
  ::formation_msgs::msg::DrawnShape msg_;
};

class Init_DrawnShape_raw_points
{
public:
  Init_DrawnShape_raw_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DrawnShape_stroke_colors raw_points(::formation_msgs::msg::DrawnShape::_raw_points_type arg)
  {
    msg_.raw_points = std::move(arg);
    return Init_DrawnShape_stroke_colors(msg_);
  }

private:
  ::formation_msgs::msg::DrawnShape msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::formation_msgs::msg::DrawnShape>()
{
  return formation_msgs::msg::builder::Init_DrawnShape_raw_points();
}

}  // namespace formation_msgs

#endif  // FORMATION_MSGS__MSG__DETAIL__DRAWN_SHAPE__BUILDER_HPP_
