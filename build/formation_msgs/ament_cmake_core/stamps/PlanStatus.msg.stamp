# PlanStatus.msg
# Pass/fail + diagnostic report from any formation_planner stage back to
# task_manager (e.g. shape rejected, safety check failed and retrying,
# drone count decremented due to hardware fault).
#
# Published by : drone_validator_node     (topic: /formation/plan_status)
#                assignment_node
#                mapf_node
# Subscribed by: task_manager_node

bool success
string status_message
int32 usable_drone_count
