# DroneState.msg
# Per-drone status report.
#
# Published by : pose_publisher_node      (topic: /drone/state)
# Subscribed by: drone_validator_node     (checks availability for M count)
#                task_manager_node        (checks reached_target during Executing)

int32 drone_id
geometry_msgs/Point position
bool available
bool reached_target
