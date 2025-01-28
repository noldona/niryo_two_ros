#ifndef RPI_DIAGNOSTICS_H
#define RPI_DIAGNOSTICS_H

#ifdef __arm__
#include <fstream>
#endif

#include <boost/shared_ptr.hpp>
#include <stdlib.h>
#include <thread>

#include <ros/ros.h>

class RpiDiagnostics {
	public:
		RpiDiagnostics();

		int getRpiCpuTemperature();

		void startReadingData();

	private:
		int cpu_temperature;

		void readCpuTemperature();

		void readHardwareDataLoop();

		boost::shared_ptr<std::thread> read_hardware_data_thread;
};

#endif
