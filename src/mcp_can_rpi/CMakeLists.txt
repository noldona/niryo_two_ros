cmake_minimum_required(VERSION 3.8)
project(mcp_can_rpi)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

include_directories(include)

set(MCP_CAN_RPI_SOURCES
  src/mcp_can_rpi.cpp
)

add_library(mcp_can_rpi SHARED ${MCP_CAN_RPI_SOURCES} src/mcp_can_rpi.cpp)

execute_process(COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE)
message(WARNING "Architecture: $${ARCHITECTURE}")

if(${ARCHITECTURE} MATCHES "aarch64")
  message(WARNING "writingPi library is required - arm processor")
  target_link_libraries(dynamixel_sdk
    -lwiringPi
  )
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
