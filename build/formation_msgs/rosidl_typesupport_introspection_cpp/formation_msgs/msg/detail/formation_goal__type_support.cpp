// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from formation_msgs:msg/FormationGoal.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "formation_msgs/msg/detail/formation_goal__struct.hpp"
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

void FormationGoal_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) formation_msgs::msg::FormationGoal(_init);
}

void FormationGoal_fini_function(void * message_memory)
{
  auto typed_message = static_cast<formation_msgs::msg::FormationGoal *>(message_memory);
  typed_message->~FormationGoal();
}

size_t size_function__FormationGoal__target_points(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FormationGoal__target_points(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__FormationGoal__target_points(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__FormationGoal__target_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__FormationGoal__target_points(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__FormationGoal__target_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__FormationGoal__target_points(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__FormationGoal__target_points(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__FormationGoal__assigned_drone_ids(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FormationGoal__assigned_drone_ids(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__FormationGoal__assigned_drone_ids(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__FormationGoal__assigned_drone_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__FormationGoal__assigned_drone_ids(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__FormationGoal__assigned_drone_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__FormationGoal__assigned_drone_ids(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__FormationGoal__assigned_drone_ids(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__FormationGoal__point_colors(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std_msgs::msg::ColorRGBA> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FormationGoal__point_colors(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std_msgs::msg::ColorRGBA> *>(untyped_member);
  return &member[index];
}

void * get_function__FormationGoal__point_colors(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std_msgs::msg::ColorRGBA> *>(untyped_member);
  return &member[index];
}

void fetch_function__FormationGoal__point_colors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std_msgs::msg::ColorRGBA *>(
    get_const_function__FormationGoal__point_colors(untyped_member, index));
  auto & value = *reinterpret_cast<std_msgs::msg::ColorRGBA *>(untyped_value);
  value = item;
}

void assign_function__FormationGoal__point_colors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std_msgs::msg::ColorRGBA *>(
    get_function__FormationGoal__point_colors(untyped_member, index));
  const auto & value = *reinterpret_cast<const std_msgs::msg::ColorRGBA *>(untyped_value);
  item = value;
}

void resize_function__FormationGoal__point_colors(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std_msgs::msg::ColorRGBA> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FormationGoal_message_member_array[5] = {
  {
    "target_points",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs::msg::FormationGoal, target_points),  // bytes offset in struct
    nullptr,  // default value
    size_function__FormationGoal__target_points,  // size() function pointer
    get_const_function__FormationGoal__target_points,  // get_const(index) function pointer
    get_function__FormationGoal__target_points,  // get(index) function pointer
    fetch_function__FormationGoal__target_points,  // fetch(index, &value) function pointer
    assign_function__FormationGoal__target_points,  // assign(index, value) function pointer
    resize_function__FormationGoal__target_points  // resize(index) function pointer
  },
  {
    "assigned_drone_ids",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs::msg::FormationGoal, assigned_drone_ids),  // bytes offset in struct
    nullptr,  // default value
    size_function__FormationGoal__assigned_drone_ids,  // size() function pointer
    get_const_function__FormationGoal__assigned_drone_ids,  // get_const(index) function pointer
    get_function__FormationGoal__assigned_drone_ids,  // get(index) function pointer
    fetch_function__FormationGoal__assigned_drone_ids,  // fetch(index, &value) function pointer
    assign_function__FormationGoal__assigned_drone_ids,  // assign(index, value) function pointer
    resize_function__FormationGoal__assigned_drone_ids  // resize(index) function pointer
  },
  {
    "point_colors",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::ColorRGBA>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs::msg::FormationGoal, point_colors),  // bytes offset in struct
    nullptr,  // default value
    size_function__FormationGoal__point_colors,  // size() function pointer
    get_const_function__FormationGoal__point_colors,  // get_const(index) function pointer
    get_function__FormationGoal__point_colors,  // get(index) function pointer
    fetch_function__FormationGoal__point_colors,  // fetch(index, &value) function pointer
    assign_function__FormationGoal__point_colors,  // assign(index, value) function pointer
    resize_function__FormationGoal__point_colors  // resize(index) function pointer
  },
  {
    "formation_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs::msg::FormationGoal, formation_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs::msg::FormationGoal, timestamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FormationGoal_message_members = {
  "formation_msgs::msg",  // message namespace
  "FormationGoal",  // message name
  5,  // number of fields
  sizeof(formation_msgs::msg::FormationGoal),
  FormationGoal_message_member_array,  // message members
  FormationGoal_init_function,  // function to initialize message memory (memory has to be allocated)
  FormationGoal_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FormationGoal_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FormationGoal_message_members,
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
get_message_type_support_handle<formation_msgs::msg::FormationGoal>()
{
  return &::formation_msgs::msg::rosidl_typesupport_introspection_cpp::FormationGoal_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, formation_msgs, msg, FormationGoal)() {
  return &::formation_msgs::msg::rosidl_typesupport_introspection_cpp::FormationGoal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
