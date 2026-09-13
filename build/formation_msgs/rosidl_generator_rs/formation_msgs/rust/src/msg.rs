#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to formation_msgs__msg__DrawnShape
/// DrawnShape.msg
/// Raw stroke data captured from the canvas, before sampling.
///
/// Published by : canvas_server_node       (topic: /formation/drawn_shape)
/// Subscribed by: task_manager_node        -> forwarded into formation_planner pipeline
///                shape_sampling_node      (on task_manager dispatch)

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DrawnShape {

    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_points: Vec<geometry_msgs::msg::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stroke_colors: Vec<std_msgs::msg::ColorRGBA>,

}



impl Default for DrawnShape {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DrawnShape::default())
  }
}

impl rosidl_runtime_rs::Message for DrawnShape {
  type RmwMsg = super::msg::rmw::DrawnShape;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        raw_points: msg.raw_points
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        stroke_colors: msg.stroke_colors
          .into_iter()
          .map(|elem| std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        raw_points: msg.raw_points
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        stroke_colors: msg.stroke_colors
          .iter()
          .map(|elem| std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      raw_points: msg.raw_points
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      stroke_colors: msg.stroke_colors
          .into_iter()
          .map(std_msgs::msg::ColorRGBA::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to formation_msgs__msg__FormationGoal
/// FormationGoal.msg
/// Final target points after sampling + coordinate mapping + assignment.
///
/// Published by : assignment_node          (topic: /formation/goal)
/// Subscribed by: mapf_node
///                task_manager_node        (status/logging)

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FormationGoal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target_points: Vec<geometry_msgs::msg::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub assigned_drone_ids: Vec<i32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub point_colors: Vec<std_msgs::msg::ColorRGBA>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub formation_id: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub timestamp: builtin_interfaces::msg::Time,

}



impl Default for FormationGoal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::FormationGoal::default())
  }
}

impl rosidl_runtime_rs::Message for FormationGoal {
  type RmwMsg = super::msg::rmw::FormationGoal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target_points: msg.target_points
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        assigned_drone_ids: msg.assigned_drone_ids.into(),
        point_colors: msg.point_colors
          .into_iter()
          .map(|elem| std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        formation_id: msg.formation_id,
        timestamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.timestamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target_points: msg.target_points
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        assigned_drone_ids: msg.assigned_drone_ids.as_slice().into(),
        point_colors: msg.point_colors
          .iter()
          .map(|elem| std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      formation_id: msg.formation_id,
        timestamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.timestamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      target_points: msg.target_points
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      assigned_drone_ids: msg.assigned_drone_ids
          .into_iter()
          .collect(),
      point_colors: msg.point_colors
          .into_iter()
          .map(std_msgs::msg::ColorRGBA::from_rmw_message)
          .collect(),
      formation_id: msg.formation_id,
      timestamp: builtin_interfaces::msg::Time::from_rmw_message(msg.timestamp),
    }
  }
}


// Corresponds to formation_msgs__msg__DronePath
/// DronePath.msg
/// Collision-free path for a single drone, output by CBS planning.
///
/// Published by : mapf_node                (topic: /formation/drone_path)
/// Subscribed by: drone_controller_node    (one instance per drone; filters by drone_id)
///                task_manager_node        (status/logging)

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DronePath {

    // This member is not documented.
    #[allow(missing_docs)]
    pub drone_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoints: Vec<geometry_msgs::msg::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub waypoint_times: Vec<builtin_interfaces::msg::Time>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub formation_start_time: builtin_interfaces::msg::Time,

}



impl Default for DronePath {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DronePath::default())
  }
}

impl rosidl_runtime_rs::Message for DronePath {
  type RmwMsg = super::msg::rmw::DronePath;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        drone_id: msg.drone_id,
        waypoints: msg.waypoints
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        waypoint_times: msg.waypoint_times
          .into_iter()
          .map(|elem| builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        formation_start_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.formation_start_time)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      drone_id: msg.drone_id,
        waypoints: msg.waypoints
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        waypoint_times: msg.waypoint_times
          .iter()
          .map(|elem| builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        formation_start_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.formation_start_time)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      drone_id: msg.drone_id,
      waypoints: msg.waypoints
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      waypoint_times: msg.waypoint_times
          .into_iter()
          .map(builtin_interfaces::msg::Time::from_rmw_message)
          .collect(),
      formation_start_time: builtin_interfaces::msg::Time::from_rmw_message(msg.formation_start_time),
    }
  }
}


// Corresponds to formation_msgs__msg__DroneState
/// DroneState.msg
/// Per-drone status report.
///
/// Published by : pose_publisher_node      (topic: /drone/state)
/// Subscribed by: drone_validator_node     (checks availability for M count)
///                task_manager_node        (checks reached_target during Executing)

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DroneState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub drone_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub position: geometry_msgs::msg::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub available: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reached_target: bool,

}



impl Default for DroneState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DroneState::default())
  }
}

impl rosidl_runtime_rs::Message for DroneState {
  type RmwMsg = super::msg::rmw::DroneState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        drone_id: msg.drone_id,
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.position)).into_owned(),
        available: msg.available,
        reached_target: msg.reached_target,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      drone_id: msg.drone_id,
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.position)).into_owned(),
      available: msg.available,
      reached_target: msg.reached_target,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      drone_id: msg.drone_id,
      position: geometry_msgs::msg::Point::from_rmw_message(msg.position),
      available: msg.available,
      reached_target: msg.reached_target,
    }
  }
}


// Corresponds to formation_msgs__msg__RefinementCmd
/// RefinementCmd.msg
/// Natural language refinement instruction plus the point set it applies to.
///
/// Published by : task_manager_node        (topic: /refinement/command)
/// Subscribed by: llm_interface_node

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RefinementCmd {

    // This member is not documented.
    #[allow(missing_docs)]
    pub instruction_text: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_points: Vec<geometry_msgs::msg::Point>,

}



impl Default for RefinementCmd {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RefinementCmd::default())
  }
}

impl rosidl_runtime_rs::Message for RefinementCmd {
  type RmwMsg = super::msg::rmw::RefinementCmd;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        instruction_text: msg.instruction_text.as_str().into(),
        current_points: msg.current_points
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        instruction_text: msg.instruction_text.as_str().into(),
        current_points: msg.current_points
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      instruction_text: msg.instruction_text.to_string(),
      current_points: msg.current_points
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to formation_msgs__msg__RefinementCandidate
/// RefinementCandidate.msg
/// Proposed shape returned by the LLM refinement pipeline, pending user
/// ACCEPT / REJECT / REDRAW INSTEAD review.
///
/// Published by : coords_adjust_node       (topic: /refinement/candidate)
/// Subscribed by: task_manager_node
///                canvas_server_node       (renders dashed overlay to user)

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RefinementCandidate {

    // This member is not documented.
    #[allow(missing_docs)]
    pub candidate_points: Vec<geometry_msgs::msg::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub candidate_colors: Vec<std_msgs::msg::ColorRGBA>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub plan_description: std::string::String,

}



impl Default for RefinementCandidate {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RefinementCandidate::default())
  }
}

impl rosidl_runtime_rs::Message for RefinementCandidate {
  type RmwMsg = super::msg::rmw::RefinementCandidate;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        candidate_points: msg.candidate_points
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        candidate_colors: msg.candidate_colors
          .into_iter()
          .map(|elem| std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        plan_description: msg.plan_description.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        candidate_points: msg.candidate_points
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        candidate_colors: msg.candidate_colors
          .iter()
          .map(|elem| std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        plan_description: msg.plan_description.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      candidate_points: msg.candidate_points
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      candidate_colors: msg.candidate_colors
          .into_iter()
          .map(std_msgs::msg::ColorRGBA::from_rmw_message)
          .collect(),
      plan_description: msg.plan_description.to_string(),
    }
  }
}


// Corresponds to formation_msgs__msg__GeneratedTransform
/// GeneratedTransform.msg
/// Code generated by the LLM to implement a refinement instruction, plus
/// the point set it should be executed against.
///
/// Published by : llm_interface_node       (topic: /refinement/generated_transform)
/// Subscribed by: coords_adjust_node

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GeneratedTransform {

    // This member is not documented.
    #[allow(missing_docs)]
    pub generated_code: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub plan_description: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_points: Vec<geometry_msgs::msg::Point>,

}



impl Default for GeneratedTransform {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GeneratedTransform::default())
  }
}

impl rosidl_runtime_rs::Message for GeneratedTransform {
  type RmwMsg = super::msg::rmw::GeneratedTransform;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        generated_code: msg.generated_code.as_str().into(),
        plan_description: msg.plan_description.as_str().into(),
        current_points: msg.current_points
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        generated_code: msg.generated_code.as_str().into(),
        plan_description: msg.plan_description.as_str().into(),
        current_points: msg.current_points
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      generated_code: msg.generated_code.to_string(),
      plan_description: msg.plan_description.to_string(),
      current_points: msg.current_points
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to formation_msgs__msg__PlanStatus
/// PlanStatus.msg
/// Pass/fail + diagnostic report from any formation_planner stage back to
/// task_manager (e.g. shape rejected, safety check failed and retrying,
/// drone count decremented due to hardware fault).
///
/// Published by : drone_validator_node     (topic: /formation/plan_status)
///                assignment_node
///                mapf_node
/// Subscribed by: task_manager_node

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub status_message: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub usable_drone_count: i32,

}



impl Default for PlanStatus {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::PlanStatus::default())
  }
}

impl rosidl_runtime_rs::Message for PlanStatus {
  type RmwMsg = super::msg::rmw::PlanStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        status_message: msg.status_message.as_str().into(),
        usable_drone_count: msg.usable_drone_count,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        status_message: msg.status_message.as_str().into(),
      usable_drone_count: msg.usable_drone_count,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      status_message: msg.status_message.to_string(),
      usable_drone_count: msg.usable_drone_count,
    }
  }
}


// Corresponds to formation_msgs__msg__SystemState
/// SystemState.msg
/// Current FSM state, broadcast so the UI (and any other interested node)
/// can reflect system status without querying task_manager directly.
/// Expected values: IDLE, HOVERING, PLANNING, EXECUTING, HOLDING,
///                  REFINING, LANDING, ERROR
///
/// Published by : task_manager_node        (topic: /system/state)
/// Subscribed by: canvas_server_node       (enables/disables UI controls)

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SystemState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: std::string::String,

}



impl Default for SystemState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SystemState::default())
  }
}

impl rosidl_runtime_rs::Message for SystemState {
  type RmwMsg = super::msg::rmw::SystemState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        state: msg.state.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        state: msg.state.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      state: msg.state.to_string(),
    }
  }
}


// Corresponds to formation_msgs__msg__UserCommand
/// UserCommand.msg
/// Discrete button-press event from the canvas UI.
/// Expected values: START, SUBMIT, LLM_SUBMIT, ACCEPT, REJECT,
///                   REDRAW_INSTEAD, END
///
/// Published by : canvas_server_node       (topic: /ui/user_command)
/// Subscribed by: task_manager_node

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UserCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub command: std::string::String,

}



impl Default for UserCommand {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::UserCommand::default())
  }
}

impl rosidl_runtime_rs::Message for UserCommand {
  type RmwMsg = super::msg::rmw::UserCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        command: msg.command.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        command: msg.command.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      command: msg.command.to_string(),
    }
  }
}


// Corresponds to formation_msgs__msg__DroneSetpoint
/// DroneSetpoint.msg
/// Current target position for a single drone at this control tick,
/// interpolated from DronePath by drone_controller_node.
///
/// Published by : drone_controller_node    (topic: /drone/setpoint)
/// Subscribed by: sim_bridge_node OR fylo_bridge_node (whichever is active)

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DroneSetpoint {

    // This member is not documented.
    #[allow(missing_docs)]
    pub drone_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_position: geometry_msgs::msg::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub led_color: std_msgs::msg::ColorRGBA,

}



impl Default for DroneSetpoint {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DroneSetpoint::default())
  }
}

impl rosidl_runtime_rs::Message for DroneSetpoint {
  type RmwMsg = super::msg::rmw::DroneSetpoint;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        drone_id: msg.drone_id,
        target_position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.target_position)).into_owned(),
        led_color: std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Owned(msg.led_color)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      drone_id: msg.drone_id,
        target_position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.target_position)).into_owned(),
        led_color: std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Borrowed(&msg.led_color)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      drone_id: msg.drone_id,
      target_position: geometry_msgs::msg::Point::from_rmw_message(msg.target_position),
      led_color: std_msgs::msg::ColorRGBA::from_rmw_message(msg.led_color),
    }
  }
}


