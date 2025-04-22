#include "dynamixel_sdk/dynamixel_sdk.hpp"
#include "niryo_one_hardware/dxl_motor_state.hpp"
#include "niryo_one_hardware/xl320_driver.hpp"
#include "niryo_one_hardware/xl430_driver.hpp"

#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv) {
	rclcpp::init(argc, argv);
	auto node = std::make_shared<rclcpp::Node>("fix");

	auto dxlPortHandler =
			dynamixel::PortHandler::getPortHandler("/dev/ttyAMA0");
	auto dxlPacketHandler = dynamixel::PacketHandler::getPacketHandler(2.0);

	std::shared_ptr<XL320Driver> xl320;
	std::shared_ptr<XL430Driver> xl430;

	xl320.reset(new XL320Driver(dxlPortHandler, dxlPacketHandler));
	xl430.reset(new XL430Driver(dxlPortHandler, dxlPacketHandler));

	dxlPortHandler->setupGpio();
	dxlPortHandler->openPort();
	// dxlPortHandler->setBaudRate(57600);
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

	dxlPortHandler->closePort();

	RCLCPP_INFO(node->get_logger(), "Changing baud rate to 57600...");
	dxlPortHandler->openPort();
	dxlPortHandler->setBaudRate(57600);

	std::this_thread::sleep_for(std::chrono::seconds(1));

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
			if (xl430->checkModelNumber(id) != PING_WRONG_MODEL_NUMBER) {
				RCLCPP_INFO(node->get_logger(), "XL430");
				xl430->setTorqueEnable(id, 0);
				xl430->setLed(id, 0.3);
				uint8_t dxl_error;
				uint32_t baudrate;
				result = dxlPacketHandler->read4ByteTxRx(dxlPortHandler, id,
						XL430_ADDR_BAUDRATE, &baudrate, &dxl_error);
				RCLCPP_INFO(node->get_logger(), "Baudrate: %d", baudrate);
				RCLCPP_INFO(node->get_logger(), "Error: %d", dxl_error);
				result = xl430->changeBaudRate(id, 3);
				if (result != COMM_SUCCESS) {
					RCLCPP_INFO(node->get_logger(),
							"Failed to change baud rate: ID %d, Result: %d", id,
							result);
				} else {
					RCLCPP_INFO(
							node->get_logger(), "Changed baud rate: ID %d", id);
					result = dxlPacketHandler->read4ByteTxRx(dxlPortHandler, id,
							XL430_ADDR_BAUDRATE, &baudrate, &dxl_error);
					RCLCPP_INFO(node->get_logger(), "Baudrate: %d", baudrate);
				}
				std::this_thread::sleep_for(std::chrono::seconds(1));
			} else if (xl320->checkModelNumber(id) != PING_WRONG_MODEL_NUMBER) {
				RCLCPP_INFO(node->get_logger(), "XL320");
				xl320->setTorqueEnable(id, 0);
				xl320->setLed(id, 0.6);
				uint8_t dxl_error;
				uint32_t baudrate;
				result = dxlPacketHandler->read4ByteTxRx(dxlPortHandler, id,
						XL320_ADDR_BAUDRATE, &baudrate, &dxl_error);
				RCLCPP_INFO(node->get_logger(), "Baudrate: %d", baudrate);
				result = xl320->changeBaudRate(id, 3);
				if (result != COMM_SUCCESS) {
					RCLCPP_INFO(node->get_logger(),
							"Failed to change baud rate: ID %d, Result: %d", id,
							result);
				} else {
					RCLCPP_INFO(
							node->get_logger(), "Changed baud rate: ID %d", id);
					result = dxlPacketHandler->read4ByteTxRx(dxlPortHandler, id,
							XL320_ADDR_BAUDRATE, &baudrate, &dxl_error);
					RCLCPP_INFO(node->get_logger(), "Baudrate: %d", baudrate);
				}
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		}
	} else {
		RCLCPP_INFO(node->get_logger(), "No Dynamixels found");
	}

	RCLCPP_INFO(node->get_logger(), "Changing baud rate to 1000000...");
	dxlPortHandler->openPort();
	dxlPortHandler->setBaudRate(1000000);

	std::this_thread::sleep_for(std::chrono::seconds(1));

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
