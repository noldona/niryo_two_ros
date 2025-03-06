#ifndef MOTOR_OFFSET_FILE_HANDLER_H
#define MOTOR_OFFSET_FILE_HANDLER_H

#include "rclcpp/rclcpp.hpp"
#include <string>
#include <unistd.h>
#include <vector>

bool get_motors_calibration_offsets(
		std::vector<int> &motor_id_list, std::vector<int> &steps_list);

bool set_motors_calibration_offsets(
		std::vector<int> &motor_id_list, std::vector<int> &steps_list);

#endif
