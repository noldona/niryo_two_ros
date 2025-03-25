#ifndef NIRYO_ONE_HARDWARE_H
#define NIRYO_ONE_HARDWARE_H

#include <string>
#include <unordered_map>
#include <vector>

#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"

#include "niryo_one_hardware/communication_base.hpp"
#include "niryo_one_hardware/fake_communication.hpp"
#include "niryo_one_hardware/niryo_one_communication.hpp"

using hardware_interface::return_type;

namespace niryo_one_hardware {
	using CallbackReturn = rclcpp_lifecycle::node_interfaces::
			LifecycleNodeInterface::CallbackReturn;

	struct Config {
		int hardware_version;
		bool use_sim;
		FakeCommunicationConfig fc_cfg;
		NiryoOneCommunicationConfig noc_cfg;
	};

	class NiryoOneHardware: public hardware_interface::SystemInterface {
		public:
		CallbackReturn on_init(
				const hardware_interface::HardwareInfo &info) override;

		CallbackReturn on_configure(
				const rclcpp_lifecycle::State &previous_state) override;

		CallbackReturn on_cleanup(
				const rclcpp_lifecycle::State &previous_state) override;

		CallbackReturn on_activate(
				const rclcpp_lifecycle::State &previous_state) override;

		CallbackReturn on_deactivate(
				const rclcpp_lifecycle::State &previous_state) override;

		CallbackReturn on_shutdown(
				const rclcpp_lifecycle::State &previous_state) override;

		CallbackReturn on_error(
				const rclcpp_lifecycle::State &previous_state) override;

		return_type read(const rclcpp::Time &time,
				const rclcpp::Duration &period) override;

		return_type write(const rclcpp::Time &time,
				const rclcpp::Duration &period) override;

		protected:
		Config cfg_;
		std::shared_ptr<CommunicationBase> comm_;
		bool startup;
	};
}

#endif
