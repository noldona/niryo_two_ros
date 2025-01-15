import rclpy.exceptions
from time.time import sleep
from enum import Enum

from gpiozero import RGBLED
from colorzero import Color
from std_msgs.msg import Bool
from rclpy.node import Node
import rclpy

from niryo_one_msgs.msg import HardwareStatus
from niryo_one_msgs.srv import SetInt
from niryo_one_msgs.srv import SetLeds

from niryo_one_rpi.rpi_ros_utils import LedState

LED_GPIO_R = 18
LED_GPIO_G = 24
LED_GPIO_B = 22


class LEDManager(Node):

    def __init__(self) -> None:
        super().__init__('led_manager')

        self.led = RGBLED(LED_GPIO_R, LED_GPIO_G, LED_GPIO_B)
        self.state = LedState.OK
        self.set_led_fromState(dxl_leds=True)

        self.set_led_state_server = self.create_service(
            SetInt, 'niryo_one/rpi/set_led_state', self.set_led_state_cb)
        self.set_dxl_leds = self.create_client(
            SetLeds, 'niryo_one/set_dxl_leds')

        # Subscribe to hotspot and hardware status. Those values will override standard state
        self.hotspot_state_subscriber = self.create_subscription(
            Bool, 'niryo_once/wifi/hotspot', self.hotspot_state_cb, 10)
        self.hardware_status_subscriber = self.create_subscription(
            HardwareStatus, 'niryo_one/hardware_status', self.hardware_status_cb, 10)

        self.get_logger().info('--- Niryo One - LED Manager - Started ---')

    def set_dxl_leds(self, color: Color) -> None:
        leds = SetLeds.Request()
        leds.values = [color, color, color, 8]  # Gripper LED will not be used

        while not self.set_dxl_leds.wait_for_service(timeout_sec=1):
            self.get_logger().warn('Niryo ROS LED Service is not up!')
        self.set_dxl_leds.call_async(leds)

    def set_led(self, color: Color, dxl_leds=False):
        self.led.color = color
        self.led.on()

        if dxl_leds:
            self.set_dxl_leds(color)
