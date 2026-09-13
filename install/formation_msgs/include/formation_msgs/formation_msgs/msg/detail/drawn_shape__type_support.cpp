// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from formation_msgs:msg/DrawnShape.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "formation_msgs/msg/detail/drawn_shape__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace formation_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void DrawnShape_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) formation_msgs::msg::DrawnShape(_init);
}

void DrawnShape_fini_function(void * message_memory)
{
  auto typed_message = static_cast<formation_msgs::msg::DrawnShape *>(message_memory);
  typed_message->~DrawnShape();
}

size_t size_function__DrawnShape__raw_points(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DrawnShape__raw_points(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__DrawnShape__raw_points(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__DrawnShape__raw_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__DrawnShape__raw_points(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__DrawnShape__raw_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__DrawnShape__raw_points(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__DrawnShape__raw_points(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DrawnShape__stroke_colors(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std_msgs::msg::ColorRGBA> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DrawnShape__stroke_colors(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std_msgs::msg::ColorRGBA> *>(untyped_member);
  return &member[index];
}

void * get_function__DrawnShape__stroke_colors(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std_msgs::msg::ColorRGBA> *>(untyped_member);
  return &member[index];
}

void fetch_function__DrawnShape__stroke_colors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std_msgs::msg::ColorRGBA *>(
    get_const_function__DrawnShape__stroke_colors(untyped_member, index));
  auto & value = *reinterpret_cast<std_msgs::msg::ColorRGBA *>(untyped_value);
  value = item;
}

void assign_function__DrawnShape__stroke_colors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std_msgs::msg::ColorRGBA *>(
    get_function__DrawnShape__stroke_colors(untyped_member, index));
  const auto & value = *reinterpret_cast<const std_msgs::msg::ColorRGBA *>(untyped_value);
  item = value;
}

void resize_function__DrawnShape__stroke_colors(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std_msgs::msg::ColorRGBA> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DrawnShape_message_member_array[2] = {
  {
    "raw_points",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs::msg::DrawnShape, raw_points),  // bytes offset in struct
    nullptr,  // default value
    size_function__DrawnShape__raw_points,  // size() function pointer
    get_const_function__DrawnShape__raw_points,  // get_const(index) function pointer
    get_function__DrawnShape__raw_points,  // get(index) function pointer
    fetch_function__DrawnShape__raw_points,  // fetch(index, &value) function pointer
    assign_function__DrawnShape__raw_points,  // assign(index, value) function pointer
    resize_function__DrawnShape__raw_points  // resize(index) function pointer
  },
  {
    "stroke_colors",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::ColorRGBA>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs::msg::DrawnShape, stroke_colors),  // bytes offset in struct
    nullptr,  // default value
    size_function__DrawnShape__stroke_colors,  // size() function pointer
    get_const_function__DrawnShape__stroke_colors,  // get_const(index) function pointer
    get_function__DrawnShape__stroke_colors,  // get(index) function pointer
    fetch_function__DrawnShape__stroke_colors,  // fetch(index, &value) function pointer
    assign_function__DrawnShape__stroke_colors,  // assign(index, value) function pointer
    resize_function__DrawnShape__stroke_colors  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DrawnShape_message_members = {
  "formation_msgs::msg",  // message namespace
  "DrawnShape",  // message name
  2,  // number of fields
  sizeof(formation_msgs::msg::DrawnShape),
  DrawnShape_message_member_array,  // message members
  DrawnShape_init_function,  // function to initialize message memory (memory has to be allocated)
  DrawnShape_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DrawnShape_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DrawnShape_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace formation_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<formation_msgs::msg::DrawnShape>()
{
  return &::formation_msgs::msg::rosidl_typesupport_introspection_cpp::DrawnShape_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, formation_msgs, msg, DrawnShape)() {
  return &::formation_msgs::msg::rosidl_typesupport_introspection_cpp::DrawnShape_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
