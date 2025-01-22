from rclpy.node import Node
from rclpy.clock import Clock
from rclpy.clock import ClockType
from rclpy.duration import Duration
from rclpy.executors import ExternalShutdownException
import rclpy


class NiryoOneRpi(Node):

    def __init__(self) -> None:
        super().__init__('niryo_one_rpi')

        self.wifi_manager_enabled = self.declare_parameter(
            '~wifi_manager_enabled')
        self.launch_ros_pprocesses = self.declare_parameter(
            '~launch_ros_processes')
        self.modbus_server_enabled = self.declare_parameter(
            '~modbus_server_enabled')
        self.modbus_server_address = self.declare_parameter(
            '~modbus_server_address')
        self.modbus_server_port = self.declare_parameter('~modbus_server_port')
        self.niryo_one_ros_setup = None

        if self.launch_ros_pprocesses:
            self.niryo_one_ros_setup = NiryoOneRosSetup()
            # Let some timme for other processes to launch (does not affect total launch time)
            Clock(ClockType.SYSTEM_TIME).sleep_for(Duration(seconds=10))

        # Start WiFi Manager
        if self.wifi_manager_enabled:
            self.wifi_manager = WifiCconnectionManager()

        self.fans_manager = FansManager()
        self.ros_log_manager = RosLogManager()
        self.shutdown_manager = ShutdownManager()
        self.led_manager = LedManager()
        self.niryo_one_button = NiryoOneButton()
        self.digital_io_panel = DigitalIOPanel()
        self.motor_debug = MotorDebug()

        # Start Modbus Server
        if self.modbus_server_enabled:
            self.modbus_server = ModbusServer(
                self.modbus_server_address, self.modbus_server_port)
            self.context.on_shutdown(self.modbuus_server.stop)
            self.modbus_server.start()


def main():
    rclpy.init()
    niryo_one_rpi = NiryoOneRpi()

    try:
        rclpy.spin(niryo_one_rpi)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        niryo_one_rpi.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
