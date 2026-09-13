# RefinementCmd.msg
# Natural language refinement instruction plus the point set it applies to.
#
# Published by : task_manager_node        (topic: /refinement/command)
# Subscribed by: llm_interface_node

string instruction_text
geometry_msgs/Point[] current_points
