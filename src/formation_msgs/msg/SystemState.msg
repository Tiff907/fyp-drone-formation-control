# SystemState.msg
# Current FSM state, broadcast so the UI (and any other interested node)
# can reflect system status without querying task_manager directly.
# Expected values: IDLE, HOVERING, PLANNING, EXECUTING, HOLDING,
#                  REFINING, LANDING, ERROR
#
# Published by : task_manager_node        (topic: /system/state)
# Subscribed by: canvas_server_node       (enables/disables UI controls)

string state
