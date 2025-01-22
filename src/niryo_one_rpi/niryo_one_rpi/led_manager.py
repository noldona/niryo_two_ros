from gpiozero import RGBLED
from colorzero import Color
from signal import pause
from std_msgs.msg import Bool
from rclpy.node import Node
from rclpy.clock import Clock
from rclpy.clock import ClockType
from rclpy.duration import Duration
from rclpy.executors import ExternalShutdownException
import rclpy

from niryo_one_msgs.msg import HardwareStatus
from niryo_one_msgs.srv import SetInt
from niryo_one_msgs.srv import SetLeds

from niryo_one_rpi.rpi_ros_utils import LedState, setattrs

LED_GPIO_R = 18
LED_GPIO_G = 24
LED_GPIO_B = 22

LED_OFF = Color('#000000')
LED_BLUE = Color('#0000FF')
LED_GREEN = Color('#00FF00')
LED_BLUE_GREEN = Color('#00FFFF')
LED_RED = Color('#FF0000')
LED_PURPLE = Color('#FF00FF')
LED_RED_GREEN = Color('#FFFF00')
LED_WHITE = Color('#FFFFFF')


class LEDManager(Node):

    def __init__(self) -> None:
        super().__init__('led_manager')

        self.led = RGBLED(LED_GPIO_R, LED_GPIO_G, LED_GPIO_B)

        # Sleep for 0.1 seconds
        Clock(ClockType.SYSTEM_TIME).sleep_for(Duration(seconds=0.1))
        self.state = LedState.OK
        self.set_led_fromState(dxl_leds=True)

        self.set_led_state_server = self.create_service(
            SetInt, '/niryo_one/rpi/set_led_state', self.set_led_state_cb)

        # Subscribe to hotspot and hardware status. Those values will override standard state
        self.hotspot_state_subscriber = self.create_subscription(
            Bool, '/niryo_once/wifi/hotspot', self.hotspot_state_cb, 10)
        self.hardware_status_subscriber = self.create_subscription(
            HardwareStatus, '/niryo_one/hardware_status', self.hardware_status_cb, 10)

        self.get_logger().info('--- Niryo One - LED Manager - Started ---')

    def __del__(self) -> None:
        pause()  # Pause here so the LED will be red after shutdown

    def set_dxl_leds(self, color: Color) -> None:
        leds = SetLeds.Request()
        leds.values = [color, color, color, 8]  # Gripper LED will not be used

        set_dxl_leds = self.create_client(SetLeds, '/niryo_one/set_dxl_leds')
        while not set_dxl_leds.wait_for_service(timeout_sec=1):
            self.get_logger().warn('Niryo ROS LED Service is not up!')
        set_dxl_leds.call_async(leds)

    def set_led(self, color: Color, dxl_leds=False):
        self.leds.off()

        if (color != LED_OFF):
            self.led.color = color
            self.led.on()

        if dxl_leds:
            self.set_dxl_leds(color)

    def set_led_from_state(self, dxl_leds=False):
        if self.state == LedState.SHUTDOWN:
            self.set_led(LED_PURPLE, dxl_leds)
        elif self.state == LedState.HOTSPOT:
            self.set_led(LED_BLUE, dxl_leds)
        elif self.state == LedState.WAIT_HOTSPOT:
            self.set_led(LED_BLUE, dxl_leds)
        elif self.state == LedState.OK:
            self.set_led(LED_GREEN, dxl_leds)
        else:
            self.set_led(LED_OFF, dxl_leds)

    def hotspot_state_cb(self, msg: Bool) -> None:
        if self.state == LedState.SHUTDOWN:
            return

        if msg.data:
            if self.state != LedState.HOTSPOT:
                self.state = LedState.HOTSPOT
        elif self.state == LedState.HOTSPOT:
            self.state = LedState.OK

        self.set_led_from_state(dxl_leds=True)

    def hardware_status_cb(self, msg: HardwareStatus) -> None:
        if not msg.connection_up or msg.error_message != '':
            self.set_led(LED_RED, dxl_leds=True)  # Blink red
            Clock(ClockType.SYSTEM_TIME).sleep_for(Duration(seconds=0.05))
            self.set_led_from_state(dxl_leds=True)

    def set_led_state_cb(self, req: SetInt.Request, resp: SetInt.Response) -> SetInt.Response:
        if req.value == LedState.SHUTDOWN:
            self.state = LedState.SHUTDOWN
        elif req.value == LedState.WAIT_HOTSPOT:
            self.state = LedState.WAIT_HOTSPOT
        else:
            setattrs(resp, status=400, message='Not yet implemented')
            return resp

        self.set_led_from_state(dxl_leds=True)
        setattrs(resp, status=200, message='Set LED OK')
        return resp


def main():
    rclpy.init()
    led_manager = LEDManager()

    try:
        rclpy.spin(led_manager)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        led_manager.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
