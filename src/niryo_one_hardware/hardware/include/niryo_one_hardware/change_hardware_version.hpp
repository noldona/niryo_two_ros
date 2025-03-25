#ifndef CHANGE_HARDWARE_VERSION_H
#define CHANGE_HARDWARE_VERSION_H

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include <ament_index_cpp/get_package_share_directory.hpp>

#define CHANGE_HW_VERSION_OK 0
#define CHANGE_HW_VERSION_FAIL -1
#define CHANGE_HW_VERSION_NOT_ARM -2

int change_hardware_version_and_reboot(
		int old_version, int new_version, bool reboot);

#endif
