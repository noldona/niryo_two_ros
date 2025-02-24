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
# add_executable(change_hardware_version src/utils/change_hardware_version.cpp)

# add_executable(motor_offset_file_handler src/utils/motor_offset_file_handler.cpp)
# add_executable(niryo_one_can_driver src/hw_driver/niryo_one_can_driver.cpp)
# add_executable(dxl_driver src/hw_driver/dxl_driver.cpp)
# add_executable(xl320_driver src/hw_driver/xl320_driver.cpp)
# add_executable(xl430_driver src/hw_driver/xl430_driver.cpp)
# add_executable(dxl_communication src/hw_comm/dxl_communication.cpp)
# add_executable(can_communication src/hw_comm/can_communication.cpp)
# add_executable(niryo_one_communication src/hw_comm/niryo_one_communication.cpp)
# add_executable(fake_communication src/hw_comm/fake_communication.cpp)

# # add_executable(test_motors src/test_motors.cpp)
# add_executable(ros_interface src/ros_interface.cpp)
# add_executable(rpi_diagnostics src/rpi_diagnostics.cpp)
# add_executable(niryo_one_hardware_interface src/niryo_one_hardware_interface.cpp)
add_executable(niryo_one_driver_node src/niryo_one_driver_node.cpp)

# ament_target_dependencies(change_hardware_version rclcpp ament_index_cpp)

# ament_target_dependencies(motor_offset_file_handler rclcpp)
# ament_target_dependencies(niryo_one_can_driver rclcpp mcp_can_rpi)
# ament_target_dependencies(dxl_driver rclcpp dynamixel_sdk)
# ament_target_dependencies(xl320_driver rclcpp dynamixel_sdk)
# ament_target_dependencies(xl430_driver rclcpp dynamixel_sdk)
# ament_target_dependencies(dxl_communication rclcpp dynamixel_sdk)
# ament_target_dependencies(can_communication rclcpp mcp_can_rpi)
# ament_target_dependencies(niryo_one_communication rclcpp dynamixel_sdk mcp_can_rpi)
# ament_target_dependencies(fake_communication rclcpp)

# # ament_target_dependencies(test_motors rclcpp std_msgs control_msgs sensor_msgs urdf niryo_one_msgs)
# ament_target_dependencies(ros_interface rclcpp dynamixel_sdk mcp_can_rpi niryo_one_msgs std_msgs control_msgs sensor_msgs urdf)
# ament_target_dependencies(rpi_diagnostics rclcpp)
# ament_target_dependencies(niryo_one_hardware_interface rclcpp hardware_interface)
ament_target_dependencies(niryo_one_driver_node rclcpp controller_manager hardware_interface dynamixel_sdk mcp_can_rpi niryo_one_msgs std_msgs control_msgs sensor_msgs urdf)

# target_link_libraries(change_hardware_version
# ament_index_cpp
# )

# target_link_libraries(ros_interface rclcpp)
# target_include_directories(change_hardware_version PRIVATE
# $<BUILD_INTERFACE:${ament_index_cpp_INCLUDE_DIRS}>
# $<INSTALL_INTERFACE:include>)

# Install Cpp executables
install(TARGETS

  # change_hardware_version

  # motor_offset_file_handler
  # niryo_one_can_driver
  # dxl_driver
  # xl320_driver
  # xl430_driver
  # dxl_communication
  # can_communication
  # niryo_one_communication
  # fake_communication

  # # test_motors
  # ros_interface
  # rpi_diagnostics
  # niryo_one_hardware_interface
  niryo_one_driver_node
  DESTINATION lib/${PROJECT_NAME}
)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
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
