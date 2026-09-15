# SampleRequest.msg
# Requests the currently stored drawn shape be resampled to an exact
# target point count. Sent as part of the M-i retry loop.
#
# Published by : drone_validator_node   (topic: /formation/sample_request)
# Subscribed by: shape_sampling_node

int32 target_n
