// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from formation_msgs:msg/DroneSetpoint.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "formation_msgs/msg/detail/drone_setpoint__struct.h"
#include "formation_msgs/msg/detail/drone_setpoint__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace formation_msgs
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _DroneSetpoint_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DroneSetpoint_type_support_ids_t;

static const _DroneSetpoint_type_support_ids_t _DroneSetpoint_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _DroneSetpoint_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DroneSetpoint_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DroneSetpoint_type_support_symbol_names_t _DroneSetpoint_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, formation_msgs, msg, DroneSetpoint)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, formation_msgs, msg, DroneSetpoint)),
  }
};

typedef struct _DroneSetpoint_type_support_data_t
{
  void * data[2];
} _DroneSetpoint_type_support_data_t;

static _DroneSetpoint_type_support_data_t _DroneSetpoint_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DroneSetpoint_message_typesupport_map = {
  2,
  "formation_msgs",
  &_DroneSetpoint_message_typesupport_ids.typesupport_identifier[0],
  &_DroneSetpoint_message_typesupport_symbol_names.symbol_name[0],
  &_DroneSetpoint_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DroneSetpoint_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DroneSetpoint_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace formation_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, formation_msgs, msg, DroneSetpoint)() {
  return &::formation_msgs::msg::rosidl_typesupport_c::DroneSetpoint_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
