# RefinementCandidate.msg
# Proposed shape returned by the LLM refinement pipeline, pending user
# ACCEPT / REJECT / REDRAW INSTEAD review.
#
# Published by : coords_adjust_node       (topic: /refinement/candidate)
# Subscribed by: task_manager_node
#                canvas_server_node       (renders dashed overlay to user)

geometry_msgs/Point[] candidate_points
std_msgs/ColorRGBA[] candidate_colors
string plan_description
