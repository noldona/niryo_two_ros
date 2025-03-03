# Niryo One Bringup

This packages provides config and launch files to start Niryo One and ROS packages with various parameters.

Launch files (in _launch_ folder) :

### niryo_one_base

Setup many rosparams, this package should be launched before any other package.

### controllers

Starts Niryo One _driver_, _tools_controller_, _ros_control_ and _robot_state_publisher_ packages.

### robot_commander

Starts robot command utilities to move the arm and tools.

### user_interface

Starts joystick interface (Xbox controller) and Blockly server (Blockly is a graphical programming library, integrated in Niryo One Studio).

### rpi_setup

The main package to launch on a Raspberry Pi 3. Also launches _rosbridge_, _niryo_one_base_, _controllers_, _robot_commander_, and _user_interface_. This package is automatically launched when Niryo One boots (Niryo One RPi3 image).

### desktop_rviz_simulation

This is the main package for simulation mode. It launches _niryo_one_base_, _controllers_, _robot_commander_, _user_interface_, _rosbridge_, and Rviz to see a 3D view of Niryo One. The _controllers_ package is launched with a simulation flag, so the hardware-related stuff is not used.

Note that you need to launch this file on your computer, with 3D packages installed. This will not work on the Niryo One RPI3 image.

---

You can find more info about what the packages do in each package's README.
