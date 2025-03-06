#include "niryo_one_driver/rpi_diagnostics.hpp"

RpiDiagnostics::RpiDiagnostics(): Node("rpi_diagnostics") {
	this->cpu_temperature = 0;

	this->startReadingData();
}

int RpiDiagnostics::getRpiCpuTemperature() {
	return this->cpu_temperature;
}

void RpiDiagnostics::readCpuTemperature() {
#ifdef __aarch64__
	std::fstream cpu_temp_file(
			"/sys/class/thermal/thermal_zone0/temp", std::ios_base::in);

	int read_temp;
	cpu_temp_file >> read_temp;
	if (read_temp > 0) {
		cpu_temperature = read_temp / 1000;
	}
#endif
}

void RpiDiagnostics::startReadingData() {
	this->read_hardware_data_thread.reset(new std::thread(
			std::bind(&RpiDiagnostics::readHardwareDataLoop, this)));
}

void RpiDiagnostics::readHardwareDataLoop() {
	this->declare_parameter(
			"read_rpi_diagnostics_frequency", rclcpp::PARAMETER_DOUBLE);
	double read_rpi_diagnostics_frequency =
			this->get_parameter("read_rpi_diagnostics_frequency").as_double();
	rclcpp::Rate read_rpi_diagnostics_rate =
			rclcpp::Rate(read_rpi_diagnostics_frequency);

	while (rclcpp::ok()) {
		readCpuTemperature();

		// Check if Rpi is too hot
		if (cpu_temperature > 75) {
			RCLCPP_ERROR(rclcpp::get_logger("RpiDiagnostics"),
					"Rpi temperature is really high !");
		}
		if (cpu_temperature > 85) {
			RCLCPP_ERROR(rclcpp::get_logger("RpiDiagnostics"),
					"Rpi is too hot, shutdown to avoid any damage");
			std::system("sudo shutdown now");
		}

		read_rpi_diagnostics_rate.sleep();
	}
}
