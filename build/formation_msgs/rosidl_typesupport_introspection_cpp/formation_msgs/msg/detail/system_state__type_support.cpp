// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from formation_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "formation_msgs/msg/detail/system_state__struct.hpp"
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

void SystemState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) formation_msgs::msg::SystemState(_init);
}

void SystemState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<formation_msgs::msg::SystemState *>(message_memory);
  typed_message->~SystemState();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SystemState_message_member_array[1] = {
  {
    "state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs::msg::SystemState, state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SystemState_message_members = {
  "formation_msgs::msg",  // message namespace
  "SystemState",  // message name
  1,  // number of fields
  sizeof(formation_msgs::msg::SystemState),
  SystemState_message_member_array,  // message members
  SystemState_init_function,  // function to initialize message memory (memory has to be allocated)
  SystemState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SystemState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SystemState_message_members,
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
get_message_type_support_handle<formation_msgs::msg::SystemState>()
{
  return &::formation_msgs::msg::rosidl_typesupport_introspection_cpp::SystemState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, formation_msgs, msg, SystemState)() {
  return &::formation_msgs::msg::rosidl_typesupport_introspection_cpp::SystemState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
