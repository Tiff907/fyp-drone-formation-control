# DrawnShape.msg
# Raw stroke data captured from the canvas, before sampling.
#
# Published by : canvas_server_node       (topic: /formation/drawn_shape)
# Subscribed by: task_manager_node        -> forwarded into formation_planner pipeline
#                shape_sampling_node      (on task_manager dispatch)

geometry_msgs/Point[] raw_points
std_msgs/ColorRGBA[] stroke_colors
