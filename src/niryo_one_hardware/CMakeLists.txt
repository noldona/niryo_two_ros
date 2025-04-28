cmake_minimum_required(VERSION 3.16)
project(niryo_one_hardware LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
  add_compile_options(-Wall -Wextra)
endif()

# set the same behavior for windows as it is on linux
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# find dependencies
set(HW_IF_INCLUDE_DEPENDS
  pluginlib
  rcpputils
  hardware_interface
  rclcpp
  std_msgs
  control_msgs
  geometry_msgs
  trajectory_msgs
  niryo_one_msgs
  mcp_can_rpi
  dynamixel_sdk
  urdf
  sensor_msgs
  ament_index_cpp
)
set(REF_GEN_INCLUDE_DEPENDS
  kdl_parser
  rclcpp
  trajectory_msgs
  niryo_one_msgs
)
set(CONTROLLER_INCLUDE_DEPENDS
  pluginlib
  rcpputils
  controller_interface
  realtime_tools
  trajectory_msgs
  niryo_one_msgs
)
set(FIX_DEPENDS
  rclcpp
  dynamixel_sdk
)

# Specify the required version of ros2_control
find_package(controller_manager 4.0.0)

# Handle the case where the required version is not found
if(NOT controller_manager_FOUND)
  message(FATAL_ERROR "ros2_control version 4.0.0 or higher is required. "
    "Are you using the correct branch of the ros2_control_demos repository?")
endif()

# find dependencies
find_package(backward_ros REQUIRED)
find_package(ament_cmake REQUIRED)


foreach(Dependency IN ITEMS ${HW_IF_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()

foreach(Dependency IN ITEMS ${REF_GEN_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()

foreach(Dependency IN ITEMS ${CONTROLLER_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()

foreach(Dependency IN ITEMS ${FIX_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()

# # COMPILE
add_executable(send_trajectory reference_generator/send_trajectory.cpp)
add_executable(fix
  hardware/fix.cpp
  hardware/src/hw_driver/dxl_driver.cpp
  hardware/src/hw_driver/xl320_driver.cpp
  hardware/src/hw_driver/xl430_driver.cpp
)
add_executable(fix_id
  hardware/fix_id.cpp
  hardware/src/hw_driver/dxl_driver.cpp
  hardware/src/hw_driver/xl320_driver.cpp
  hardware/src/hw_driver/xl430_driver.cpp
)

ament_target_dependencies(
  send_trajectory PUBLIC
  ${REF_GEN_INCLUDE_DEPENDS}
)

target_include_directories(fix PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/hardware/include>
  $<INSTALL_INTERFACE:include/niryo_one_hardware>
)
ament_target_dependencies(
  fix PUBLIC
  ${FIX_DEPENDS}
)
target_include_directories(fix_id PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/hardware/include>
  $<INSTALL_INTERFACE:include/niryo_one_hardware>
)
ament_target_dependencies(
  fix_id PUBLIC
  ${FIX_DEPENDS}
)


add_library(
  niryo_one_hardware
  SHARED
  hardware/niryo_one_hardware_can.cpp
  hardware/niryo_one_hardware_dxl.cpp
  hardware/src/hw_driver/dxl_driver.cpp
  hardware/src/hw_driver/niryo_one_can_driver.cpp
  hardware/src/hw_driver/xl320_driver.cpp
  hardware/src/hw_driver/xl430_driver.cpp
  hardware/src/utils/change_hardware_version.cpp
  hardware/src/utils/motor_offset_file_handler.cpp
  controller/niryo_one_controller.cpp
  hardware/src/utils/utilities.cpp
  hardware/src/utils/interface_constants.cpp
)

target_compile_features(niryo_one_hardware PUBLIC cxx_std_17)
target_include_directories(niryo_one_hardware PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/hardware/include>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/controller/include>
  $<INSTALL_INTERFACE:include/niryo_one_hardware>
)
ament_target_dependencies(
  niryo_one_hardware PUBLIC
  ${HW_IF_INCLUDE_DEPENDS}
  ${CONTROLLER_INCLUDE_DEPENDS}
)

# Export hardware plugins
pluginlib_export_plugin_description_file(hardware_interface niryo_one_hardware.xml)

# Export controller plugins
pluginlib_export_plugin_description_file(controller_interface niryo_one_hardware.xml)

# INSTALL
install(
  DIRECTORY hardware/include/
  DESTINATION include/niryo_one_hardware
)
install(
  DIRECTORY description/launch description/ros2_control description/urdf
  DESTINATION share/niryo_one_hardware
)
install(
  DIRECTORY bringup/launch bringup/config
  DESTINATION share/niryo_one_hardware
)
install(
  TARGETS send_trajectory
  RUNTIME DESTINATION lib/niryo_one_hardware
)
install(
  TARGETS fix
  RUNTIME DESTINATION lib/niryo_one_hardware
)
install(
  TARGETS fix_id
  RUNTIME DESTINATION lib/niryo_one_hardware
)

install(TARGETS niryo_one_hardware
  EXPORT export_niryo_one_hardware
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

if(BUILD_TESTING)
  find_package(ament_cmake_pytest REQUIRED)

  ament_add_pytest_test(niry_one_urdf_xacro test/test_urdf_xacro.py)
  ament_add_pytest_test(view_niryo_one_launch test/test_view_robot_launch.py)
  ament_add_pytest_test(run_niryo_one_launch test/test_niryo_one_controller_launch.py)
endif()

# # EXPORTS
ament_export_targets(export_niryo_one_hardware HAS_LIBRARY_TARGET)
ament_export_dependencies(${HW_IF_INCLUDE_DEPENDS} ${REF_GEN_INCLUDE_DEPENDS} ${CONTROLLER_INCLUDE_DEPENDS})
ament_package()
