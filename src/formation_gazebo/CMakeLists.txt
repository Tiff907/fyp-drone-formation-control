cmake_minimum_required(VERSION 3.8)
project(formation_gazebo)

find_package(ament_cmake REQUIRED)

install(DIRECTORY models worlds launch
  DESTINATION share/${PROJECT_NAME}
)

install(PROGRAMS scripts/spawn_drones.sh
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
