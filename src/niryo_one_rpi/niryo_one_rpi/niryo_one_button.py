from gpiozero import Button
from rclpy.node import Node
from rclpy.clock import Clock
from rclpy.clock import ClockType
from rclpy.duration import Duration
from rclpy.executors import ExternalShutdownException
import rclpy

from niryo_one_rpi.rpi_ros_utils import *

from std_msgs.msg import Bool, Int32
from niryo_one_msgs.srv import SetInt
from niryo_one_rpi.rpi_ros_utils import create_response

BUTTON_GPIO = 4


class ButtonMode(Enum):
    DO_NOTHING = 0
    TRIGGER_SEQUENCE_AUTORUN = 1
    BLOCKLY_SAVE_POINT = 2


class NiryoButton(Node):

    def __init__(self) -> None:
        super().__init__('niryo_button')

        self.pin = BUTTON_GPIO
        self.button = Button(BUTTON_GPIO, pull_up=True)
        self.button.when_pressed = self.button_pressed_cb
        self.button.when_released = self.button_released_cb
        self.button.when_held = self.button_held_cb

        Clock(ClockType.SYSTEM_TIME).sleep_for(Duration(seconds=0.1))

        self.last_state = self.read_value()
        self.consecutive_pressed = 0
        self.activated = True

        self.timer_frequency = 20.0
        self.shutdown_action = False
        self.hotspot_action = False

        self.button_mode = ButtonMode.TRIGGER_SEQUENCE_AUTORUN
        self.change_button_mode_server = self.create_service(
            SetInt, '/niryo_one/rpi/change_button_mode',
            self.change_button_mode_cb)
        self.monitor_button_mode_timer = self.create_timer(
            Duration(seconds=3), self.monitor_button_mode)
        self.last_time_button_mode_changed = self.get_clock().now()

        # Publisher used to send info to Niryp One Studio, so the user
        # can add a move block by pressing the button
        self.save_point_publisher = self.create_publisher(
            Int32, '/niryo_one/blockly/save_current_point', 10)
        self.button_state_publisher = self.create_publisher(
            Bool, '/niryo_one/rpi/is_button_pressed', 10)

        self.context.on_shutdown(self.shutdown)

    def shutdown(self):
        rclpy.get_logger().info("Shutdown button, cleanup GPIO")
        self.button.close()

    def blockly_save_current_point(self):
        msg = Int32()
        msg.data = 1
        self.save_point_publisher.publsih(msg)

    def change_button_mode_cb(self, req: SetInt.Request, resp: SetInt.Response) -> SetInt.Response:
        msg = ""
        if req.value == ButtonMode.TRIGGER_SEQUENCE_AUTORUN.value:
            msg = "Successfully changed button mode to trigger sequence autorun"
        elif req.value == ButtonMode.BLOCKLY_SAVE_POINT.value:
            msg = "Successfully changed button mode to save point"
        elif req.value == ButtonMode.DO_NOTHING.value:
            msg = "Successfully changed button mode to disabled"
        else:
            return create_response(resp, status=400, message='Invalid button mode')

        self.button_mode = ButtonMode(req.value)
        self.last_time_button_mode_changed = self.get_clock().now()
        return create_response(resp, status=200, message=msg)

    def monitor_button_mode(self):
        duration = self.get_clock().now() - self.last_time_button_mode_changed

        # Make sure the button's behavior goes back to default if no news
        # from the Blockly interface
        # This is to prevent the button from being stuck in BLOCKLY_SAVE_POINT
        # mode in case of a disconnect or broken communication
        # --> To keep the non-default mode, you have to call the
        # change_button_mode service at least once every 3 seconds
        if self.button_mode == ButtonMode.BLOCKLY_SAVE_POINT and duration.seconds > 3:
            self.button_mode = ButtonMode.TRIGGER_SEQUENCE_AUTORUN

    def read_value(self) -> bool:
        return self.button.is_pressed

    def button_pressed_cb(self, button: Button) -> None:
        if not self.activated:
            return

        msg = Bool()
        msg.data = True
        self.button_state_publisher.publish(msg)

        self.consecutive_pressed = button.active_time
        self.button_set_leds()

    def button_released_cb(self, button: Button) -> None:
        if not self.activated:
            return

        msg = Bool()
        msg.data = False
        self.button_state_publisher.publish(msg)

        if self.consecutive_pressed > 20:  # Held for 20 seconds
            self.activated = False  # Deactivate button if pressed more than 20 seconds
        elif self.consecutive_pressed > 6:  # Held for 6 seconds
            send_hotspot_action()
        elif self.consecutive_pressed > 3:  # Held for 3 seconds
            send_shutdown_action()
        elif self.consecutive_pressed >= 1:  # Held for 1 second
            if self.button_mode == ButtonMode.TRIGGER_SEQUENCE_AUTORUN:
                send_trigger_sequence_autorun_action()
            elif self.button_mode == ButtonMode.BLOCKLY_SAVE_POINT:
                self.blockly_save_current_point()
        self.consecutive_pressed = 0

        self.button_set_leds()

    def button_held_cb(self, button: Button) -> None:
        if not self.activated:
            return

        self.consecutive_pressed = button.active_time
        self.button_set_leds()

    def button_set_leds(self) -> None:
        msg = Bool()
        msg.data = False
        self.button_state_publisher.publish(msg)

        # Use LED to help user know which action to execute
        if self.consecutive_pressed > 20:  # Held for 20 seconds
            send_led_state(LedState.SHUTDOWN)
        elif self.consecutive_pressed > 6:  # Held for 6 seconds
            send_led_state(LedState.WAIT_HOTSPOT)
        elif self.consecutive_pressed > 3:  # Held for 3 seconds
            send_led_state(LedState.SHUTDOWN)


def main():
    rclpy.init()
    niryo_button = NiryoButton()

    try:
        rclpy.spin(niryo_button)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        niryo_button.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
