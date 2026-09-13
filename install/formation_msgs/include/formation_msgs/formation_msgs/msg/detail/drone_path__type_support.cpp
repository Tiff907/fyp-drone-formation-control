// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from formation_msgs:msg/DronePath.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "formation_msgs/msg/detail/drone_path__struct.hpp"
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

void DronePath_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) formation_msgs::msg::DronePath(_init);
}

void DronePath_fini_function(void * message_memory)
{
  auto typed_message = static_cast<formation_msgs::msg::DronePath *>(message_memory);
  typed_message->~DronePath();
}

size_t size_function__DronePath__waypoints(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DronePath__waypoints(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__DronePath__waypoints(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__DronePath__waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__DronePath__waypoints(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__DronePath__waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__DronePath__waypoints(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__DronePath__waypoints(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DronePath__waypoint_times(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<builtin_interfaces::msg::Time> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DronePath__waypoint_times(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<builtin_interfaces::msg::Time> *>(untyped_member);
  return &member[index];
}

void * get_function__DronePath__waypoint_times(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<builtin_interfaces::msg::Time> *>(untyped_member);
  return &member[index];
}

void fetch_function__DronePath__waypoint_times(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const builtin_interfaces::msg::Time *>(
    get_const_function__DronePath__waypoint_times(untyped_member, index));
  auto & value = *reinterpret_cast<builtin_interfaces::msg::Time *>(untyped_value);
  value = item;
}

void assign_function__DronePath__waypoint_times(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<builtin_interfaces::msg::Time *>(
    get_function__DronePath__waypoint_times(untyped_member, index));
  const auto & value = *reinterpret_cast<const builtin_interfaces::msg::Time *>(untyped_value);
  item = value;
}

void resize_function__DronePath__waypoint_times(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<builtin_interfaces::msg::Time> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DronePath_message_member_array[4] = {
  {
    "drone_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs::msg::DronePath, drone_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "waypoints",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs::msg::DronePath, waypoints),  // bytes offset in struct
    nullptr,  // default value
    size_function__DronePath__waypoints,  // size() function pointer
    get_const_function__DronePath__waypoints,  // get_const(index) function pointer
    get_function__DronePath__waypoints,  // get(index) function pointer
    fetch_function__DronePath__waypoints,  // fetch(index, &value) function pointer
    assign_function__DronePath__waypoints,  // assign(index, value) function pointer
    resize_function__DronePath__waypoints  // resize(index) function pointer
  },
  {
    "waypoint_times",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs::msg::DronePath, waypoint_times),  // bytes offset in struct
    nullptr,  // default value
    size_function__DronePath__waypoint_times,  // size() function pointer
    get_const_function__DronePath__waypoint_times,  // get_const(index) function pointer
    get_function__DronePath__waypoint_times,  // get(index) function pointer
    fetch_function__DronePath__waypoint_times,  // fetch(index, &value) function pointer
    assign_function__DronePath__waypoint_times,  // assign(index, value) function pointer
    resize_function__DronePath__waypoint_times  // resize(index) function pointer
  },
  {
    "formation_start_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs::msg::DronePath, formation_start_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DronePath_message_members = {
  "formation_msgs::msg",  // message namespace
  "DronePath",  // message name
  4,  // number of fields
  sizeof(formation_msgs::msg::DronePath),
  DronePath_message_member_array,  // message members
  DronePath_init_function,  // function to initialize message memory (memory has to be allocated)
  DronePath_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DronePath_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DronePath_message_members,
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
get_message_type_support_handle<formation_msgs::msg::DronePath>()
{
  return &::formation_msgs::msg::rosidl_typesupport_introspection_cpp::DronePath_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, formation_msgs, msg, DronePath)() {
  return &::formation_msgs::msg::rosidl_typesupport_introspection_cpp::DronePath_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
