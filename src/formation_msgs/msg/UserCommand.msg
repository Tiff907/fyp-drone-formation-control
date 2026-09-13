# UserCommand.msg
# Discrete button-press event from the canvas UI.
# Expected values: START, SUBMIT, LLM_SUBMIT, ACCEPT, REJECT,
#                   REDRAW_INSTEAD, END
#
# Published by : canvas_server_node       (topic: /ui/user_command)
# Subscribed by: task_manager_node

string command
