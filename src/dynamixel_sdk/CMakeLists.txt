cmake_minimum_required(VERSION 3.8)
project(dynamixel_sdk)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

include_directories(include)

set(DYNAMIXEL_SDK_SOURCES
  src/group_bulk_read.cpp
  src/group_bulk_write.cpp
  src/group_sync_read.cpp
  src/group_sync_write.cpp
  src/packet_handler.cpp
  src/port_handler.cpp
  src/protocol1_packet_handler.cpp
  src/protocol2_packet_handler.cpp
)

if(WIN32)
  add_library(dynamixel_sdk SHARED ${DYNAMIXEL_SDK_SOURCES} src/port_handler_windows.cpp)
else()
  add_library(dynamixel_sdk SHARED ${DYNAMIXEL_SDK_SOURCES} src/port_handler_linux.cpp)
endif()

execute_process(COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE)
message(WARNING "Architecture: ${ARCHITECTURE}")

if(${ARCHITECTURE} MATCHES "aarch64")
  message(WARNING "wiringPi library is required - arm processor")
  target_link_libraries(${PROJECT_NAME} -lwiringPi)
else()
  message(WARNING "wiringPi library not required")
endif()

install(
  DIRECTORY include/
  DESTINATION include/
)

install(
  TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
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

ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_package()
