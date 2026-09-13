#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "formation_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__DrawnShape() -> *const std::ffi::c_void;
}

#[link(name = "formation_msgs__rosidl_generator_c")]
extern "C" {
    fn formation_msgs__msg__DrawnShape__init(msg: *mut DrawnShape) -> bool;
    fn formation_msgs__msg__DrawnShape__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DrawnShape>, size: usize) -> bool;
    fn formation_msgs__msg__DrawnShape__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DrawnShape>);
    fn formation_msgs__msg__DrawnShape__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DrawnShape>, out_seq: *mut rosidl_runtime_rs::Sequence<DrawnShape>) -> bool;
}

// Corresponds to formation_msgs__msg__DrawnShape
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// DrawnShape.msg
/// Raw stroke data captured from the canvas, before sampling.
///
/// Published by : canvas_server_node       (topic: /formation/drawn_shape)
/// Subscribed by: task_manager_node        -> forwarded into formation_planner pipeline
///                shape_sampling_node      (on task_manager dispatch)

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DrawnShape {

    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_points: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stroke_colors: rosidl_runtime_rs::Sequence<std_msgs::msg::rmw::ColorRGBA>,

}



impl Default for DrawnShape {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !formation_msgs__msg__DrawnShape__init(&mut msg as *mut _) {
        panic!("Call to formation_msgs__msg__DrawnShape__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DrawnShape {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__DrawnShape__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__DrawnShape__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__DrawnShape__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DrawnShape {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DrawnShape where Self: Sized {
  const TYPE_NAME: &'static str = "formation_msgs/msg/DrawnShape";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__DrawnShape() }
  }
}


#[link(name = "formation_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__FormationGoal() -> *const std::ffi::c_void;
}

#[link(name = "formation_msgs__rosidl_generator_c")]
extern "C" {
    fn formation_msgs__msg__FormationGoal__init(msg: *mut FormationGoal) -> bool;
    fn formation_msgs__msg__FormationGoal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FormationGoal>, size: usize) -> bool;
    fn formation_msgs__msg__FormationGoal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FormationGoal>);
    fn formation_msgs__msg__FormationGoal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FormationGoal>, out_seq: *mut rosidl_runtime_rs::Sequence<FormationGoal>) -> bool;
}

// Corresponds to formation_msgs__msg__FormationGoal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// FormationGoal.msg
/// Final target points after sampling + coordinate mapping + assignment.
///
/// Published by : assignment_node          (topic: /formation/goal)
/// Subscribed by: mapf_node
///                task_manager_node        (status/logging)

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FormationGoal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target_points: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub assigned_drone_ids: rosidl_runtime_rs::Sequence<i32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub point_colors: rosidl_runtime_rs::Sequence<std_msgs::msg::rmw::ColorRGBA>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub formation_id: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub timestamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for FormationGoal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !formation_msgs__msg__FormationGoal__init(&mut msg as *mut _) {
        panic!("Call to formation_msgs__msg__FormationGoal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FormationGoal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__FormationGoal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__FormationGoal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__FormationGoal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FormationGoal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FormationGoal where Self: Sized {
  const TYPE_NAME: &'static str = "formation_msgs/msg/FormationGoal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__FormationGoal() }
  }
}


#[link(name = "formation_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__DronePath() -> *const std::ffi::c_void;
}

#[link(name = "formation_msgs__rosidl_generator_c")]
extern "C" {
    fn formation_msgs__msg__DronePath__init(msg: *mut DronePath) -> bool;
    fn formation_msgs__msg__DronePath__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DronePath>, size: usize) -> bool;
    fn formation_msgs__msg__DronePath__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DronePath>);
    fn formation_msgs__msg__DronePath__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DronePath>, out_seq: *mut rosidl_runtime_rs::Sequence<DronePath>) -> bool;
}

// Corresponds to formation_msgs__msg__DronePath
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// DronePath.msg
/// Collision-free path for a single drone, output by CBS planning.
///
/// Published by : mapf_node                (topic: /formation/drone_path)
/// Subscribed by: drone_controller_node    (one instance per drone; filters by drone_id)
///                task_manager_node        (status/logging)

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DronePath {

    // This member is not documented.
    #[allow(missing_docs)]
    pub drone_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoints: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoint_times: rosidl_runtime_rs::Sequence<builtin_interfaces::msg::rmw::Time>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub formation_start_time: builtin_interfaces::msg::rmw::Time,

}



impl Default for DronePath {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !formation_msgs__msg__DronePath__init(&mut msg as *mut _) {
        panic!("Call to formation_msgs__msg__DronePath__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DronePath {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__DronePath__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__DronePath__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__DronePath__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DronePath {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DronePath where Self: Sized {
  const TYPE_NAME: &'static str = "formation_msgs/msg/DronePath";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__DronePath() }
  }
}


#[link(name = "formation_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__DroneState() -> *const std::ffi::c_void;
}

#[link(name = "formation_msgs__rosidl_generator_c")]
extern "C" {
    fn formation_msgs__msg__DroneState__init(msg: *mut DroneState) -> bool;
    fn formation_msgs__msg__DroneState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DroneState>, size: usize) -> bool;
    fn formation_msgs__msg__DroneState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DroneState>);
    fn formation_msgs__msg__DroneState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DroneState>, out_seq: *mut rosidl_runtime_rs::Sequence<DroneState>) -> bool;
}

// Corresponds to formation_msgs__msg__DroneState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// DroneState.msg
/// Per-drone status report.
///
/// Published by : pose_publisher_node      (topic: /drone/state)
/// Subscribed by: drone_validator_node     (checks availability for M count)
///                task_manager_node        (checks reached_target during Executing)

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DroneState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub drone_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub position: geometry_msgs::msg::rmw::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub available: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reached_target: bool,

}



impl Default for DroneState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !formation_msgs__msg__DroneState__init(&mut msg as *mut _) {
        panic!("Call to formation_msgs__msg__DroneState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DroneState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__DroneState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__DroneState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__DroneState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DroneState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DroneState where Self: Sized {
  const TYPE_NAME: &'static str = "formation_msgs/msg/DroneState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__DroneState() }
  }
}


#[link(name = "formation_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__RefinementCmd() -> *const std::ffi::c_void;
}

#[link(name = "formation_msgs__rosidl_generator_c")]
extern "C" {
    fn formation_msgs__msg__RefinementCmd__init(msg: *mut RefinementCmd) -> bool;
    fn formation_msgs__msg__RefinementCmd__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RefinementCmd>, size: usize) -> bool;
    fn formation_msgs__msg__RefinementCmd__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RefinementCmd>);
    fn formation_msgs__msg__RefinementCmd__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RefinementCmd>, out_seq: *mut rosidl_runtime_rs::Sequence<RefinementCmd>) -> bool;
}

// Corresponds to formation_msgs__msg__RefinementCmd
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// RefinementCmd.msg
/// Natural language refinement instruction plus the point set it applies to.
///
/// Published by : task_manager_node        (topic: /refinement/command)
/// Subscribed by: llm_interface_node

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RefinementCmd {

    // This member is not documented.
    #[allow(missing_docs)]
    pub instruction_text: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_points: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,

}



impl Default for RefinementCmd {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !formation_msgs__msg__RefinementCmd__init(&mut msg as *mut _) {
        panic!("Call to formation_msgs__msg__RefinementCmd__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RefinementCmd {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__RefinementCmd__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__RefinementCmd__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__RefinementCmd__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RefinementCmd {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RefinementCmd where Self: Sized {
  const TYPE_NAME: &'static str = "formation_msgs/msg/RefinementCmd";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__RefinementCmd() }
  }
}


#[link(name = "formation_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__RefinementCandidate() -> *const std::ffi::c_void;
}

#[link(name = "formation_msgs__rosidl_generator_c")]
extern "C" {
    fn formation_msgs__msg__RefinementCandidate__init(msg: *mut RefinementCandidate) -> bool;
    fn formation_msgs__msg__RefinementCandidate__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RefinementCandidate>, size: usize) -> bool;
    fn formation_msgs__msg__RefinementCandidate__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RefinementCandidate>);
    fn formation_msgs__msg__RefinementCandidate__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RefinementCandidate>, out_seq: *mut rosidl_runtime_rs::Sequence<RefinementCandidate>) -> bool;
}

// Corresponds to formation_msgs__msg__RefinementCandidate
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// RefinementCandidate.msg
/// Proposed shape returned by the LLM refinement pipeline, pending user
/// ACCEPT / REJECT / REDRAW INSTEAD review.
///
/// Published by : coords_adjust_node       (topic: /refinement/candidate)
/// Subscribed by: task_manager_node
///                canvas_server_node       (renders dashed overlay to user)

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RefinementCandidate {

    // This member is not documented.
    #[allow(missing_docs)]
    pub candidate_points: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub candidate_colors: rosidl_runtime_rs::Sequence<std_msgs::msg::rmw::ColorRGBA>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub plan_description: rosidl_runtime_rs::String,

}



impl Default for RefinementCandidate {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !formation_msgs__msg__RefinementCandidate__init(&mut msg as *mut _) {
        panic!("Call to formation_msgs__msg__RefinementCandidate__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RefinementCandidate {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__RefinementCandidate__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__RefinementCandidate__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__RefinementCandidate__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RefinementCandidate {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RefinementCandidate where Self: Sized {
  const TYPE_NAME: &'static str = "formation_msgs/msg/RefinementCandidate";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__RefinementCandidate() }
  }
}


#[link(name = "formation_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__GeneratedTransform() -> *const std::ffi::c_void;
}

#[link(name = "formation_msgs__rosidl_generator_c")]
extern "C" {
    fn formation_msgs__msg__GeneratedTransform__init(msg: *mut GeneratedTransform) -> bool;
    fn formation_msgs__msg__GeneratedTransform__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GeneratedTransform>, size: usize) -> bool;
    fn formation_msgs__msg__GeneratedTransform__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GeneratedTransform>);
    fn formation_msgs__msg__GeneratedTransform__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GeneratedTransform>, out_seq: *mut rosidl_runtime_rs::Sequence<GeneratedTransform>) -> bool;
}

// Corresponds to formation_msgs__msg__GeneratedTransform
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// GeneratedTransform.msg
/// Code generated by the LLM to implement a refinement instruction, plus
/// the point set it should be executed against.
///
/// Published by : llm_interface_node       (topic: /refinement/generated_transform)
/// Subscribed by: coords_adjust_node

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GeneratedTransform {

    // This member is not documented.
    #[allow(missing_docs)]
    pub generated_code: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub plan_description: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_points: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,

}



impl Default for GeneratedTransform {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !formation_msgs__msg__GeneratedTransform__init(&mut msg as *mut _) {
        panic!("Call to formation_msgs__msg__GeneratedTransform__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GeneratedTransform {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__GeneratedTransform__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__GeneratedTransform__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__GeneratedTransform__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GeneratedTransform {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GeneratedTransform where Self: Sized {
  const TYPE_NAME: &'static str = "formation_msgs/msg/GeneratedTransform";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__GeneratedTransform() }
  }
}


#[link(name = "formation_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__PlanStatus() -> *const std::ffi::c_void;
}

#[link(name = "formation_msgs__rosidl_generator_c")]
extern "C" {
    fn formation_msgs__msg__PlanStatus__init(msg: *mut PlanStatus) -> bool;
    fn formation_msgs__msg__PlanStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlanStatus>, size: usize) -> bool;
    fn formation_msgs__msg__PlanStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlanStatus>);
    fn formation_msgs__msg__PlanStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlanStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<PlanStatus>) -> bool;
}

// Corresponds to formation_msgs__msg__PlanStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// PlanStatus.msg
/// Pass/fail + diagnostic report from any formation_planner stage back to
/// task_manager (e.g. shape rejected, safety check failed and retrying,
/// drone count decremented due to hardware fault).
///
/// Published by : drone_validator_node     (topic: /formation/plan_status)
///                assignment_node
///                mapf_node
/// Subscribed by: task_manager_node

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub status_message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub usable_drone_count: i32,

}



impl Default for PlanStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !formation_msgs__msg__PlanStatus__init(&mut msg as *mut _) {
        panic!("Call to formation_msgs__msg__PlanStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlanStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__PlanStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__PlanStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__PlanStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlanStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlanStatus where Self: Sized {
  const TYPE_NAME: &'static str = "formation_msgs/msg/PlanStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__PlanStatus() }
  }
}


#[link(name = "formation_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__SystemState() -> *const std::ffi::c_void;
}

#[link(name = "formation_msgs__rosidl_generator_c")]
extern "C" {
    fn formation_msgs__msg__SystemState__init(msg: *mut SystemState) -> bool;
    fn formation_msgs__msg__SystemState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SystemState>, size: usize) -> bool;
    fn formation_msgs__msg__SystemState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SystemState>);
    fn formation_msgs__msg__SystemState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SystemState>, out_seq: *mut rosidl_runtime_rs::Sequence<SystemState>) -> bool;
}

// Corresponds to formation_msgs__msg__SystemState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// SystemState.msg
/// Current FSM state, broadcast so the UI (and any other interested node)
/// can reflect system status without querying task_manager directly.
/// Expected values: IDLE, HOVERING, PLANNING, EXECUTING, HOLDING,
///                  REFINING, LANDING, ERROR
///
/// Published by : task_manager_node        (topic: /system/state)
/// Subscribed by: canvas_server_node       (enables/disables UI controls)

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SystemState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: rosidl_runtime_rs::String,

}



impl Default for SystemState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !formation_msgs__msg__SystemState__init(&mut msg as *mut _) {
        panic!("Call to formation_msgs__msg__SystemState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SystemState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__SystemState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__SystemState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__SystemState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SystemState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SystemState where Self: Sized {
  const TYPE_NAME: &'static str = "formation_msgs/msg/SystemState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__SystemState() }
  }
}


#[link(name = "formation_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__UserCommand() -> *const std::ffi::c_void;
}

#[link(name = "formation_msgs__rosidl_generator_c")]
extern "C" {
    fn formation_msgs__msg__UserCommand__init(msg: *mut UserCommand) -> bool;
    fn formation_msgs__msg__UserCommand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<UserCommand>, size: usize) -> bool;
    fn formation_msgs__msg__UserCommand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<UserCommand>);
    fn formation_msgs__msg__UserCommand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<UserCommand>, out_seq: *mut rosidl_runtime_rs::Sequence<UserCommand>) -> bool;
}

// Corresponds to formation_msgs__msg__UserCommand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// UserCommand.msg
/// Discrete button-press event from the canvas UI.
/// Expected values: START, SUBMIT, LLM_SUBMIT, ACCEPT, REJECT,
///                   REDRAW_INSTEAD, END
///
/// Published by : canvas_server_node       (topic: /ui/user_command)
/// Subscribed by: task_manager_node

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UserCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub command: rosidl_runtime_rs::String,

}



impl Default for UserCommand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !formation_msgs__msg__UserCommand__init(&mut msg as *mut _) {
        panic!("Call to formation_msgs__msg__UserCommand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for UserCommand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__UserCommand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__UserCommand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__UserCommand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for UserCommand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for UserCommand where Self: Sized {
  const TYPE_NAME: &'static str = "formation_msgs/msg/UserCommand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__UserCommand() }
  }
}


#[link(name = "formation_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__DroneSetpoint() -> *const std::ffi::c_void;
}

#[link(name = "formation_msgs__rosidl_generator_c")]
extern "C" {
    fn formation_msgs__msg__DroneSetpoint__init(msg: *mut DroneSetpoint) -> bool;
    fn formation_msgs__msg__DroneSetpoint__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DroneSetpoint>, size: usize) -> bool;
    fn formation_msgs__msg__DroneSetpoint__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DroneSetpoint>);
    fn formation_msgs__msg__DroneSetpoint__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DroneSetpoint>, out_seq: *mut rosidl_runtime_rs::Sequence<DroneSetpoint>) -> bool;
}

// Corresponds to formation_msgs__msg__DroneSetpoint
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// DroneSetpoint.msg
/// Current target position for a single drone at this control tick,
/// interpolated from DronePath by drone_controller_node.
///
/// Published by : drone_controller_node    (topic: /drone/setpoint)
/// Subscribed by: sim_bridge_node OR fylo_bridge_node (whichever is active)

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DroneSetpoint {

    // This member is not documented.
    #[allow(missing_docs)]
    pub drone_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_position: geometry_msgs::msg::rmw::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub led_color: std_msgs::msg::rmw::ColorRGBA,

}



impl Default for DroneSetpoint {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !formation_msgs__msg__DroneSetpoint__init(&mut msg as *mut _) {
        panic!("Call to formation_msgs__msg__DroneSetpoint__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DroneSetpoint {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__DroneSetpoint__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__DroneSetpoint__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { formation_msgs__msg__DroneSetpoint__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DroneSetpoint {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DroneSetpoint where Self: Sized {
  const TYPE_NAME: &'static str = "formation_msgs/msg/DroneSetpoint";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__formation_msgs__msg__DroneSetpoint() }
  }
}


