#include "niryo_one_hardware/change_hardware_version.hpp"

int change_hardware_version_and_reboot(
		int old_version, int new_version, bool reboot) {
#ifdef __aarch64__

	std::ostringstream text;

	// get launch file path
	std::string folder_path =
			ament_index_cpp::get_package_share_directory("niryo_one_bringup");
	std::string file_path = folder_path + "/launch/niryo_one_base.launch";

	std::ifstream in_file(file_path.c_str());

	// read launch file
	text << in_file.rdbuf();
	std::string str = text.str();
	if (str.size() == 0) {
		RCLCPP_ERROR(rclcpp::get_logger("Change Hardware Version"),
				"Change hardware version : Could not open file %s",
				file_path.c_str());
		return CHANGE_HW_VERSION_FAIL;
	}

	// replace version in str
	std::string str_search = "<arg name=\"hardware_version\" default=\"" +
			std::to_string(old_version);
	std::string str_replace = "<arg name=\"hardware_version\" default=\"" +
			std::to_string(new_version);

	size_t pos = str.find(str_search);
	if (pos == -1) {
		if (str.find(str_replace) != -1) {
			RCLCPP_WARN(rclcpp::get_logger("Change Hardware Version"),
					"Change hardware version : Version is already correct "
					"(V%d)",
					new_version);
			return CHANGE_HW_VERSION_OK;
		}
		RCLCPP_ERROR(rclcpp::get_logger("Change Hardware Version"),
				"Change hardware_version : Malformed niryo_one_base.launch, "
				"can't find hardware version");
		return CHANGE_HW_VERSION_FAIL;
	}

	try {
		str.replace(pos, str_search.length(), str_replace);
	} catch (const std::out_of_range &e) {
		RCLCPP_INFO(rclcpp::get_logger("Change Hardware Version"),
				"Exception : %s", e.what());
	}

	// close launch file
	in_file.close();

	// re-write launch file
	std::ofstream out_file(file_path.c_str());
	out_file << str;

	RCLCPP_INFO(rclcpp::get_logger("Change Hardware Version"),
			"Successfully changed hardware version in launch file (from V%d "
			"to V%d)",
			old_version, new_version);

	if (reboot) {
		RCLCPP_INFO(rclcpp::get_logger("Change Hardware Version"),
				"Reboot in 1 second...");
		std::system("sleep 1 && sudo reboot&");
	}

	return CHANGE_HW_VERSION_OK;
#endif

	// this function only works on Raspberry Pi 3 board.
	// On other computers, if you run Niryo One ROS packages, it means
	// that you are in simulation mode
	// --> if you want to change the hardware version (but you shouldn't have to)
	// you can do it manually on niryo_one_base.launch
	return CHANGE_HW_VERSION_NOT_ARM;
}
