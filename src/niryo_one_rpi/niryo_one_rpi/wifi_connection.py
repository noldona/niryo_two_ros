from rclpy.node import Node
from rclpy.clock import Clock
from rclpy.clock import ClockType
from rclpy.duration import Duration
from rclpy.executors import ExternalShutdownException
from threading import Thread
import rclpy

from std_msgs.msg import Bool
from niryo_one_msgs.srv import SetInt, SetString

from niryo_one_rpi.wifi.robot_name_handler import *
from niryo_one_rpi.wifi.broadcast import *
from niryo_one_rpi.wifi import flask_app as app
from niryo_one_rpi.wifi.flask_views import set_hotspot_ssid
from niryo_one_rpi.wifi.flask_views import set_hotspot_password
from niryo_one_rpi.rpi_ros_utils import create_response
import niryo_one_rpi.wifi.network_manager as niryo_one_wifi


class WifiConnectionManager(Node):
    def __init__(self):
        super().__init__('wifi_connection_manager')

        self.get_logger().info('Starting Wifi Manager ...')

        self.hotspot_ssid = self.declare_parameter('~hotspot_ssid').value
        # Add robot unique identifier to ssid to make it unique and recognizable
        self.hotspot_ssid += " "
        self.hotspot_ssid += str(self.get_robot_unique_identifier())
        self.hotspot_password = self.declare_parameter(
            '~hotspot_password').value
        self.filename_robot_name = self.declare_parameter(
            '~filename_robot_name').value

        # Set filename for robot name
        set_filename_robot_name(self.filename_robot_name)

        # Get robot name
        self.robot_name = read_robot_name()
        if self.robot_name != '':
            self.hotspot_ssid += self.robot_name

        # Start set robot name service server
        self.set_robot_name_server = self.create_service(
            SetString, '/niryo_one/wifi/set_robot_name', self.set_robot_name_cb)

        # Set Niryo One hotspot ssid and password
        set_hotspot_ssid(self.hotspot_ssid)
        set_hotspot_password(self.hotspot_password)

        # Start broadcast
        broadcast_thread = Thread(target=self.start_broadcast)
        broadcast_thread.setDaemon(True)
        broadcast_thread.start()

        # Check if connected to Wi-Fi. If not, start hotspot mode
        current_ssid = niryo_one_wifi.get_current_ssid()
        self.get_logger().info(f'Current SSID: {current_ssid}')
        if not niryo_one_wifi.is_connected_to_wifi():
            niryo_one_wifi.hard_enable_hotspot_with_ssid(
                self.hotspot_ssid, self.hotspot_password)
        else:
            self.get_logger().info('Already connected to a WiFi network or in Hotspot mode')

        # Start Flask app
        flask_thread = Thread(target=self.run_flask_server)
        flask_thread.setDaemon(True)
        flask_thread.start()

        # Start WiFi status publisher
        self.hotspot_state_publisher = self.create_publisher(
            Bool, '/niryo_one/wifi/hotspot', 2)

        # Start hotspot subscriber (from button)
        self.activate_hotspot_server = self.create_service(
            SetInt, '/niryo_one/wifi/set_hotspot', self.activate_hotspot_cb)

        self.get_logger().info('WiFi Manager started')

    def send_hotspot_state(self) -> None:
        # Would be better to call get_current_ssid, but takes 0.3 seconds
        activated = niryo_one_wifi.is_hotspot_activated()
        self.publish_hotspot_state(activated)

    def publish_hotspot_state(self, activated: bool) -> None:
        msg = Bool()
        msg.data = activated
        self.hotspot_state_publisher.publish(msg)

    def activate_hotspot_cb(self, req: SetInt.Request, resp: SetInt.Response) -> SetInt.Response:
        self.get_logger().info('Switch to hotspot mode')
        if niryo_one_wifi.get_current_ssid() == self.hotspot_ssid:
            return create_response(resp, status=200, message="Hotspot mode already activated")
        success = niryo_one_wifi.hard_enable_hotspot_with_ssid(
            self.hotspot_ssid, self.hotspot_password)
        if success:
            return create_response(resp, status=200, message="Hotspot mode activated")
        return create_response(resp, status=400, message="Failed to activate hotspot mode")

    @staticmethod
    def start_broadcast():
        start_broadcast_ip_publisher()

    @staticmethod
    def run_flask_server() -> None:
        app.run(host='0.0.0.0')

    @staticmethod
    def get_robot_unique_identifier() -> str:
        identifier = ''
        with open('/proc/cpuinfo', 'r') as f:
            rpi_serial = ''
            for line in f:
                if line.startswith('Serial'):
                    rpi_serial = line[10:26]
                    break
            if rpi_serial != '':
                # Build something readbale and not too long
                identifier = str(
                    rpi_serial[8:10]) + '-' + str(rpi_serial[10:13]) + '-' + str(rpi_serial[13:16])
        return identifier

    def _set_robot_name_cb(self, req: SetString.Request, resp: SetString.Response) -> SetString.Response:
        name = req.value
        self.get_logger().info(f'Setting robot name to {name}')
        if len(name) > 32 or len(name) < 3:
            self.get_logger().error(f'Robot name must be between 3 and 32 characters.')
            return create_response(resp, status=400, message="Name length must be between 3 and 32 characters")

        if not write_robot_name(name):
            self.get_logger().error(f'Could not write robot name to file.')
            return create_response(resp, status=400, message="Could not write robot name to file")

        self.robot_name = name
        return create_response(resp, status=200, message="Successfully saved robot name")


def main():
    rclpy.init()
    wifi_connection_manager = WifiConnectionManager()

    try:
        rclpy.spin(wifi_connection_manager)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        wifi_connection_manager.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
