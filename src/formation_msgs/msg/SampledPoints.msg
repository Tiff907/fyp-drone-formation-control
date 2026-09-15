# SampledPoints.msg
# Response from shape sampling. If n_min_only is true, points is empty
# and n_min reports the minimum viable point count for the currently
# stored shape. Otherwise, points holds exactly target_n_used points.
#
# Published by : shape_sampling_node    (topic: /formation/sampled_points)
# Subscribed by: drone_validator_node

bool n_min_only
int32 n_min
int32 target_n_used
geometry_msgs/Point[] points
std_msgs/ColorRGBA[] colors
