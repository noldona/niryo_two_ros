#include "dynamixel_sdk/dynamixel_sdk.hpp"
#include "niryo_one_hardware/dxl_motor_state.hpp"
#include "niryo_one_hardware/xl320_driver.hpp"
#include "niryo_one_hardware/xl430_driver.hpp"

#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv) {
	rclcpp::init(argc, argv);
	auto node = std::make_shared<rclcpp::Node>("fix_id");

	node->declare_parameter("old_id", 1);
	node->declare_parameter("new_id", 6);
	auto old_id = node->get_parameter("old_id").as_int();
	auto new_id = node->get_parameter("new_id").as_int();

	auto dxlPortHandler =
			dynamixel::PortHandler::getPortHandler("/dev/ttyAMA0");
	auto dxlPacketHandler = dynamixel::PacketHandler::getPacketHandler(2.0);

	std::shared_ptr<XL320Driver> xl320;
	std::shared_ptr<XL430Driver> xl430;

	xl320.reset(new XL320Driver(dxlPortHandler, dxlPacketHandler));
	xl430.reset(new XL430Driver(dxlPortHandler, dxlPacketHandler));

	dxlPortHandler->setupGpio();
	dxlPortHandler->openPort();
	dxlPortHandler->setBaudRate(1000000);

	std::vector<uint8_t> id_list;
	int result = xl320->scan(id_list);

	if (result != COMM_SUCCESS) {
		if (result == COMM_RX_TIMEOUT) {
			RCLCPP_INFO(node->get_logger(),
					"No Dynamixel motor found. Make sure that motors are "
					"correctly connected and powered on.");
		} else {
			RCLCPP_INFO(node->get_logger(), "Failed to scan Dynamixel bus.");
		}
		RCLCPP_WARN(node->get_logger(),
				"Boradcast ping failed, result: %d (-3001: timeout, -3002: "
				"corrupted packet)",
				result);
		return result;
	}

	RCLCPP_INFO(node->get_logger(), "Dynamixel broadcast ping - Found IDs:");
	if (id_list.size() > 0) {
		for (auto id : id_list) {
			RCLCPP_INFO(node->get_logger(), "- %d", id);
		}
	} else {
		RCLCPP_INFO(node->get_logger(), "No Dynamixels found");
	}

	if (id_list.size() > 0) {
		for (auto id : id_list) {
			RCLCPP_INFO(node->get_logger(), "- %d", id);
			if (xl430->checkModelNumber(id) != PING_WRONG_MODEL_NUMBER) {
				RCLCPP_INFO(node->get_logger(), "XL430");
				result = xl430->changeId(old_id, new_id);
				if (result != COMM_SUCCESS) {
					RCLCPP_INFO(node->get_logger(),
							"Failed to change ID from %d to %d, Result: %d",
							old_id, new_id, result);
				} else {
					RCLCPP_INFO(node->get_logger(), "Changed ID from %d to %d",
							old_id, new_id);
				}
				std::this_thread::sleep_for(std::chrono::seconds(1));
			} else if (xl320->checkModelNumber(id) != PING_WRONG_MODEL_NUMBER) {
				RCLCPP_INFO(node->get_logger(), "XL320");
				result = xl320->changeId(old_id, new_id);
				if (result != COMM_SUCCESS) {
					RCLCPP_INFO(node->get_logger(),
							"Failed to change ID from %d to %d, Result: %d",
							old_id, new_id, result);
				} else {
					RCLCPP_INFO(node->get_logger(), "Changed ID from %d to %d",
							old_id, new_id);
				}
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		}
	} else {
		RCLCPP_INFO(node->get_logger(), "No Dynamixels found");
	}

	id_list.clear();
	result = xl320->scan(id_list);

	if (result != COMM_SUCCESS) {
		if (result == COMM_RX_TIMEOUT) {
			RCLCPP_INFO(node->get_logger(),
					"No Dynamixel motor found. Make sure that motors are "
					"correctly connected and powered on.");
		} else {
			RCLCPP_INFO(node->get_logger(), "Failed to scan Dynamixel bus.");
		}
		RCLCPP_WARN(node->get_logger(),
				"Boradcast ping failed, result: %d (-3001: timeout, -3002: "
				"corrupted packet)",
				result);
		return result;
	}

	RCLCPP_INFO(node->get_logger(), "Dynamixel broadcast ping - Found IDs:");
	if (id_list.size() > 0) {
		for (auto id : id_list) {
			RCLCPP_INFO(node->get_logger(), "- %d", id);
		}
	} else {
		RCLCPP_INFO(node->get_logger(), "No Dynamixels found");
	}

	while (rclcpp::ok()) {
	}

	return 0;
}
