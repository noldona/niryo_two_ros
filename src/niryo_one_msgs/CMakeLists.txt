cmake_minimum_required(VERSION 3.8)
project(niryo_one_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/ConveyorFeedback.msg"
  "msg/DigitalIOState.msg"
  "msg/HardwareStatus.msg"
  "msg/LogStatus.msg"
  "msg/MatlabMoveResult.msg"
  "msg/ObjectPose.msg"
  "msg/Position.msg"
  "msg/ProcessState.msg"
  "msg/RobotMoveCommand.msg"
  "msg/RobotState.msg"
  "msg/RPY.msg"
  "msg/Sequence.msg"
  "msg/SequenceAutorunStatus.msg"
  "msg/ShiftPose.msg"
  "msg/SoftwareVersion.msg"
  "msg/ToolCommand.msg"
  "msg/Trajectory.msg"
  "msg/TrajectoryPlan.msg"
  "srv/ChangeHardwareVersion.srv"
  "srv/ControlConveyor.srv"
  "srv/DebugColorDetection.srv"
  "srv/DebugMarkers.srv"
  "srv/EditGrip.srv"
  "srv/EditWorkspace.srv"
  "srv/GetCalibrationCam.srv"
  "srv/GetDigitalIO.srv"
  "srv/GetInt.srv"
  "srv/GetPositionList.srv"
  "srv/GetSequenceList.srv"
  "srv/GetTargetPose.srv"
  "srv/GetTrajectoryList.srv"
  "srv/GetWorkspaceList.srv"
  "srv/GetWorkspaceRatio.srv"
  "srv/GetWorkspaceRobotPoses.srv"
  "srv/ManagePosition.srv"
  "srv/ManageProcess.srv"
  "srv/ManageSequence.srv"
  "srv/ManageTrajectory.srv"
  "srv/ObjDetection.srv"
  "srv/OpenGripper.srv"
  "srv/PingDxlTool.srv"
  "srv/PullAirVacuumPump.srv"
  "srv/PushAirVacuumPump.srv"
  "srv/RobotMove.srv"
  "srv/SendCustomDxlValue.srv"
  "srv/SetBool.srv"
  "srv/SetCalibrationCam.srv"
  "srv/SetConveyor.srv"
  "srv/SetDigitalIO.srv"
  "srv/SetInt.srv"
  "srv/SetLeds.srv"
  "srv/SetSequenceAutorun.srv"
  "srv/SetString.srv"
  "srv/TakePicture.srv"
  "srv/UpdateConveyorId.srv"
  "action/JoystickJoints.action"
  "action/RobotMove.action"
  "action/Sequence.action"
  "action/Tool.action"
  DEPENDENCIES
  std_msgs
  geometry_msgs
  moveit_msgs
  sensor_msgs
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

