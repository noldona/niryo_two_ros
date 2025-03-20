cmake_minimum_required(VERSION 3.8)
project(niryo_one_driver)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(hardware_interface REQUIRED)
find_package(controller_manager REQUIRED)
find_package(control_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(niryo_one_msgs REQUIRED)
find_package(mcp_can_rpi REQUIRED)
find_package(dynamixel_sdk REQUIRED)
find_package(urdf REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(ament_index_cpp REQUIRED)

include_directories(include)
include_directories(/opt/ros/jazzy/include/ament_index_cpp)

# Create Cpp executable
add_executable(${PROJECT_NAME}
  src/utils/change_hardware_version.cpp
  src/utils/motor_offset_file_handler.cpp
  src/hw_driver/niryo_one_can_driver.cpp
  src/hw_driver/dxl_driver.cpp
  src/hw_driver/xl320_driver.cpp
  src/hw_driver/xl430_driver.cpp
  src/hw_comm/dxl_communication.cpp
  src/hw_comm/can_communication.cpp
  src/hw_comm/niryo_one_communication.cpp
  src/hw_comm/fake_communication.cpp
  src/test_motors.cpp
  src/ros_interface.cpp
  src/rpi_diagnostics.cpp
  src/niryo_one_hardware_interface.cpp
  src/niryo_one_driver_node.cpp
)

ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  controller_manager
  hardware_interface
  dynamixel_sdk
  mcp_can_rpi
  niryo_one_msgs
  std_msgs
  control_msgs
  sensor_msgs
  urdf
  ament_index_cpp
)

# target_link_libraries(change_hardware_version
# ament_index_cpp
# )

# target_link_libraries(ros_interface rclcpp)
# target_include_directories(change_hardware_version PRIVATE
# $<BUILD_INTERFACE:${ament_index_cpp_INCLUDE_DIRS}>
# $<INSTALL_INTERFACE:include>)

# Install Cpp executables
install(TARGETS
  ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
  FILES_MATCHING PATTERN "*.yaml" # or other file extensions
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)

  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)

  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
