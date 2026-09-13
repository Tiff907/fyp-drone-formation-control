# DronePath.msg
# Collision-free path for a single drone, output by CBS planning.
#
# Published by : mapf_node                (topic: /formation/drone_path)
# Subscribed by: drone_controller_node    (one instance per drone; filters by drone_id)
#                task_manager_node        (status/logging)

int32 drone_id
geometry_msgs/Point[] waypoints
builtin_interfaces/Time[] waypoint_times
builtin_interfaces/Time formation_start_time
