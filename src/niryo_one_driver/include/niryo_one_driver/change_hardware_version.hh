#ifndef CHANGE_HARDWARE_VERSION_H
#define CHANGE_HARDWARE_VERSION_H

#include <fstream>
#include <ros/package.h>
#include <ros/ros.h>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>
#include <string>

#define CHANGE_HW_VERSION_OK 0
#define CHANGE_HW_VERSION_FAIL -1
#define CHANGE_HW_VERSION_NOT_ARM -2

int change_hardware_version_and_reboot(int old_version, int new_version);

#endif
