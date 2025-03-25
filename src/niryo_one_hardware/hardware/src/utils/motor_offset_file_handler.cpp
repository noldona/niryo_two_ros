#include "niryo_one_hardware/motor_offset_file_handler.hpp"

#include "boost/filesystem.hpp"
#include <exception>
#include <fstream>
#include <iostream>

bool get_motors_calibration_offsets(
		std::vector<int> &motor_id_list, std::vector<int> &steps_list) {
	std::string file_name =
			"/home/niryo/niryo_one_saved_values/"
			"stepper_motor_calibration_offsets.txt";  // Todo rosparam
	std::vector<std::string> lines;
	std::string current_line;

	std::ifstream offset_file(file_name.c_str());
	if (offset_file.is_open()) {
		while (std::getline(offset_file, current_line)) {
			try {
				size_t index = current_line.find(":");
				motor_id_list.push_back(stoi(current_line.substr(0, index)));
				steps_list.push_back(stoi(current_line.erase(0, index + 1)));
			} catch (std::exception &e) {
			}
		}
		offset_file.close();
	} else {
		RCLCPP_WARN(rclcpp::get_logger("Motor Offset File Handler"),
				"Unable to open file : %s", file_name.c_str());
		return false;
	}

	return true;
}

bool set_motors_calibration_offsets(
		std::vector<int> &motor_id_list, std::vector<int> &steps_list) {
	if (motor_id_list.size() != steps_list.size()) {
		return false;
	}

	std::string file_name =
			"/home/niryo/niryo_one_saved_values/"
			"stepper_motor_calibration_offsets.txt";  // Todo rosparam
	size_t found = file_name.find_last_of("/");
	std::string folder_name = file_name.substr(0, found);

	boost::filesystem::path filepath(file_name);
	boost::filesystem::path directory(folder_name);

	// Create dir if not exist
	boost::system::error_code returned_error;
	boost::filesystem::create_directories(directory, returned_error);
	if (returned_error) {
		RCLCPP_WARN(rclcpp::get_logger("Motor Offset File Handler"),
				"Could not create directory : %s", folder_name.c_str());
		return false;
	}

	// Create text to write
	std::string text_to_write = "";
	for (int i = 0; i < motor_id_list.size(); i++) {
		text_to_write += std::to_string(motor_id_list.at(i));
		text_to_write += ":";
		text_to_write += std::to_string(steps_list.at(i));
		if (i < motor_id_list.size() - 1) {
			text_to_write += "\n";
		}
	}

	// Write to file
	std::ofstream offset_file(file_name.c_str());
	if (offset_file.is_open()) {
		RCLCPP_INFO(rclcpp::get_logger("Motor Offset File Handler"),
				"Writing calibration offsets to file : \n%s",
				text_to_write.c_str());
		offset_file << text_to_write.c_str();
		offset_file.close();
	} else {
		RCLCPP_WARN(rclcpp::get_logger("Motor Offset File Handler"),
				"Unable to open file : %s", file_name.c_str());
		return false;
	}

	return true;
}
