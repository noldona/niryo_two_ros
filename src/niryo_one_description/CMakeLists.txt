cmake_minimum_required(VERSION 3.8)
project(niryo_one_description)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

# Config Directory
install(DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
  FILES_MATCHING PATTERN "*.yaml" # or other file extensions
)

# Launch Directory
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
  FILES_MATCHING
  PATTERN "*.launch.py"
  PATTERN "*.launch.yaml"
  PATTERN "*.launch.xml"
)

# Meshes Directory
install(DIRECTORY meshes/v1/collada/
  DESTINATION share/${PROJECT_NAME}/meshes/v1/collada
  FILES_MATCHING PATTERN "*.dae" # or other file extensions
)
install(DIRECTORY meshes/v1/stl/
  DESTINATION share/${PROJECT_NAME}/meshes/v1/stl
  FILES_MATCHING PATTERN "*.stl" # or other file extensions
)
install(DIRECTORY meshes/v2/collada/
  DESTINATION share/${PROJECT_NAME}/meshes/v2/collada
  FILES_MATCHING PATTERN "*.dae" # or other file extensions
)
install(DIRECTORY meshes/v2/stl/
  DESTINATION share/${PROJECT_NAME}/meshes/v2/stl
  FILES_MATCHING PATTERN "*.stl" # or other file extensions
)

# URDF Directory
install(DIRECTORY urdf/v1/
  DESTINATION share/${PROJECT_NAME}/urdf/v1
  FILES_MATCHING PATTERN "*.xacro" # or other file extensions
)
install(DIRECTORY urdf/v2/
  DESTINATION share/${PROJECT_NAME}/urdf/v2
  FILES_MATCHING PATTERN "*.xacro" # or other file extensions
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
