#!/bin/bash
# spawn_drones.sh — spawns 20 namespaced drones into formation_world

MODEL_PATH="$HOME/fyp_ws/src/formation_gazebo/models/drone/model.sdf"
Z=0.05

X_POSITIONS=(-1.8 -1.4 -1 -0.6 -0.2 0.2 0.6 1 1.4 1.8)
Y_POSITIONS=(1.5 0.5)

i=0
for y in "${Y_POSITIONS[@]}"; do
  for x in "${X_POSITIONS[@]}"; do
    ign service -s /world/formation_world/create \
      --reqtype ignition.msgs.EntityFactory \
      --reptype ignition.msgs.Boolean \
      --timeout 1000 \
      --req "sdf_filename: \"$MODEL_PATH\", name: \"drone_$i\", pose: {position: {x: $x, y: $y, z: $Z}}"
    echo "Spawned drone_$i at ($x, $y, $Z)"
    i=$((i+1))
  done
done
