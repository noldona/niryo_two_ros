#ifndef RPI_DIAGNOSTICS_H
#define RPI_DIAGNOSTICS_H

#ifdef __arm__
#include <fstream>
#endif

#include <memory>
#include <stdlib.h>
#include <thread>

#include "rclcpp/rclcpp.hpp"

class RpiDiagnostics: public rclcpp::Node {
	public:
	RpiDiagnostics();

	int getRpiCpuTemperature();

	void startReadingData();

	private:
	int cpu_temperature;

	void readCpuTemperature();

	void readHardwareDataLoop();

	std::shared_ptr<std::thread> read_hardware_data_thread;
};

#endif
