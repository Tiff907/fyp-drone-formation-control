# Touchscreen-Based Multi-Drone Formation Control with MAPF Path Planning and LLM-Assisted Refinement

Final Year Project (EE4080) — Nanyang Technological University, School of Electrical and Electronic Engineering.

## Overview

This project develops a touchscreen-based system for real-time multi-drone formation control. A user draws a desired formation on an HTML canvas; the system samples the drawn shape into a target point set, computes an optimal drone-to-target assignment (Hungarian algorithm), and plans collision-free trajectories (Conflict-Based Search) to the target points in a 3D operating volume. Formations can be iteratively refined through natural language instructions (e.g. "make it smoother", "spread it out more"), processed by an LLM that generates code to transform the current point set, reviewed by the user before being committed.

The system is validated first in Gazebo simulation, with physical deployment on Fylo Edu+ hardware planned for Semester 2.

## Key Design Decisions

- **Control architecture:** centralised — a single ground station handles shape sampling, assignment, and path planning; onboard autopilots execute low-level motor commands only. Formation architecture is a virtual structure with a position-based control law.
- **Shape sampling:** Visvalingam-Whyatt line simplification, reducing a drawn stroke to an exact target point count `N`, with the minimum viable point count `N_min` found via elbow-detection over the algorithm's removed-area sequence.
- **Assignment:** rectangular linear assignment (Hungarian algorithm) via SciPy's `linear_sum_assignment`, since the drone fleet size `M` may exceed the target count `N`.
- **Path planning:** Conflict-Based Search (CBS), adapted for 3D motion, a Makespan objective, and a hard 30 cm inter-agent safety radius (including continuous swap-conflict detection), rather than ORCA or multi-agent RL.
- **Refinement:** an LLM (Claude Sonnet) generates executable code to transform the point set from a natural language instruction, rather than orchestrating a fixed skill library.
- **Coordinate mapping:** canvas (x, y) maps directly to real-world (x, z); canvas x additionally maps to a real-world y-offset via a fixed linear relationship, keeping drones with similar x-coordinates spread in depth to avoid vertical stacking and downwash risk.

## Repository Structure

    fyp_ws/
    └── src/
        ├── formation_msgs/       # Shared message interfaces
        ├── formation_ui/         # Touchscreen canvas <-> ROS2 bridge (WebSocket)
        ├── formation_planner/    # Shape sampling, coordinate mapping, drone validation,
        │                         # assignment, and MAPF planning
        ├── llm_refinement/       # Natural-language shape refinement (Claude Sonnet)
        ├── drone_control/        # Per-drone trajectory execution and sim/hardware bridging
        ├── task_manager/         # Finite-state-machine orchestrator
        └── formation_gazebo/     # Gazebo Fortress simulation assets (world, drone model, spawn/launch)

## Environment

- Ubuntu 22.04
- ROS2 Humble
- Gazebo Fortress (kinematic simulation — no flight dynamics; pose is set directly via Gazebo's `set_pose_vector`/`visual_config` services)

## Progress

- [x] Literature review
- [x] Methodology and system architecture defined
- [x] ROS2 workspace set up (6 packages, all building successfully)
- [x] Gazebo simulation environment: world, kinematic drone model with LED indicator, multi-drone spawning, launch file
- [x] `drone_control`: `drone_controller_node`, `pose_publisher_node`, `sim_bridge_node` implemented and validated (multi-drone pose + LED colour control confirmed working in simulation)
- [ ] `formation_planner`: `shape_sampling_node` (in progress)
- [ ] `formation_planner`: `drone_validator_node` (retry loop)
- [ ] `formation_planner`: `assignment_node`
- [ ] `formation_planner`: `mapf_node` — currently a stub (straight-line paths only); real CBS implementation pending
- [ ] `formation_ui`: touchscreen canvas front-end
- [ ] `llm_refinement`: LLM-based shape refinement
- [ ] `task_manager`: FSM orchestrator
- [ ] Physical hardware deployment (Fylo Edu+)

## License

TBD
