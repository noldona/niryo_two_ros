#include "niryo_one_driver/change_hardware_version.hpp"

int change_hardware_version_and_reboot(int old_version, int new_version) {
#ifdef __arm__

	std::ostringstream text;

	// Get launch file path
	std::string folder_path = ros::package::getPath("niryo_one_bringup");
	std::string file_path = folder_path + "/launch/niryo_one_base.launch";

	std::ifstream in_file(file_path.c_str());

	// Read launch file
	text << in_file.rdbuf();
	std::string str = text.str();
	if (str.size() == 0) {
		RCLCPP_ERROR(rclcpp::get_logger("ChangeHardwareVersion"),
				"Change hardware version : Could not open file %s",
				file_path.c_str());
		return CHANGE_HW_VERSION_FAIL;
	}

	// Replace version in str
	std::string str_search = "<arg name=\"hardware_version\" default=\"" +
			std::to_string(old_version);
	std::string str_replace = "<arg name=\"hardware_version\" default=\"" +
			std::to_string(new_version);

	size_t pos = str.find(str_search);
	if (pos == -1) {
		if (str.find(str_replace) != -1) {
			RCLCPP_WARN(rclcpp::get_logger("ChangeHardwareVersion"),
					"Change hardware version : Version is already correct "
					"(V%d)",
					new_version);
			return CHANGE_HW_VERSION_OK;
		}
		RCLCPP_ERROR(rclcpp::get_logger("ChangeHardwareVersion"),
				"Change hardware_version : Malformed niryo_one_base.launch, "
				"can't find hardware version");
		return CHANGE_HW_VERSION_FAIL;
	}

	try {
		str.replace(pos, str_search.length(), str_replace);
	} catch (const std::out_of_range &e) {
		RCLCPP_INFO(rclcpp::get_logger("ChangeHardwareVersion"),
				"Exception : %s", e.what());
	}

	// Close launch file
	in_file.close();

	// Re-write launch file
	std::ofstream out_file(file_path.c_str());
	out_file << str;

	RCLCPP_INFO(rclcpp::get_logger("ChangeHardwareVersion"),
			"Successfully changed hardware version in launch file (from V%d "
			"to V%d)",
			old_version, new_version);

	bool reboot = rclcpp::Parameters::get_value<bool>(
			"/niryo_one/reboot_when_auto_change_version");

	if (reboot) {
		RCLCPP_INFO(rclcpp::get_logger("ChangeHardwareVersion"),
				"Reboot in 1 second...");
		std::system("sleep 1 && sudo reboot&");
	}

	return CHANGE_HW_VERSION_OK;
#endif

	// This function only works on the Raspberry Pi board (ARM based computers).
	// On other computers, if you run Niryo One ROS packages, it means
	// that you are in simulation mode
	// --> If you want to change the hardware version (but you shouldn't have to)
	// you can do it manually on niryo_one_base.launch
	return CHANGE_HW_VERSION_NOT_ARM;
}
