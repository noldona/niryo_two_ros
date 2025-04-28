from gpiozero import DigitalInputDevice, DigitalOutputDevice
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
import rclpy

from niryo_one_msgs.msg import DigitalIOState
from niryo_one_msgs.srv import GetDigitalIO
from niryo_one_msgs.srv import SetDigitalIO

from niryo_one_rpi.rpi_ros_utils import IoMode, IoState, create_response

GPIO_1_A = 2
GPIO_1_B = 3
GPIO_1_C = 16
GPIO_2_A = 26
GPIO_2_B = 19
GPIO_2_C = 6

SW_1 = 12
SW_2 = 13

GPIO_1_A_NAME = '1A'
GPIO_1_B_NAME = '1B'
GPIO_1_C_NAME = '1C'
GPIO_2_A_NAME = '2A'
GPIO_2_B_NAME = '2B'
GPIO_2_C_NAME = '2C'

SW_1_NAME = 'SW1'
SW_2_NAME = 'SW2'


class DigitalPin:

    def __init__(self, pin: int, name: str, mode=IoMode.IN, state=IoState.LOW) -> None:
        self.pin = pin
        self.name = name
        self.device = None
        self.set_mode(mode)

        if self.mode == IoMode.OUT:
            self.set_state(state)
        else:
            self.get_state()

    def __del__(self) -> None:
        if self.device is not None:
            self.device.close()

    def set_mode(self, mode: IoMode) -> None:
        self.mode = mode
        if self.device is not None:
            self.device.close()

        if mode == IoMode.OUT:
            self.device = DigitalOutputDevice(
                pin=self.pin, initial_value=False)
        else:
            self.device = DigitalInputDevice(pin=self.pin, pull_up=True)

    def get_mode(self) -> IoMode:
        return self.mode

    def set_state(self, state: IoState) -> bool:
        if self.mode != IoMode.OUT:
            return False

        self.state = state
        if self.state == IoState.HIGH:
            self.device.on()
        else:
            self.device.off()

        return True

    def get_state(self) -> bool:
        if self.mode == IoMode.IN:
            self.state = IoState(self.device.value)

        return self.state


class DigitalIOPanel(Node):

    def __init__(self) -> None:
        super().__init__('digital_io_panel')

        self.publish_io_state_frequency = self.declare_parameter(
            'publish_io_state_frequency', rclpy.Parameter.Type.DOUBLE).value

        self.digitalIOs = {
            GPIO_1_A: DigitalPin(GPIO_1_A, GPIO_1_A_NAME),
            GPIO_1_B: DigitalPin(GPIO_1_B, GPIO_1_B_NAME),
            GPIO_1_C: DigitalPin(GPIO_1_C, GPIO_1_C_NAME),
            GPIO_2_A: DigitalPin(GPIO_2_A, GPIO_2_A_NAME),
            GPIO_2_B: DigitalPin(GPIO_2_B, GPIO_2_B_NAME),
            GPIO_2_C: DigitalPin(GPIO_2_C, GPIO_2_C_NAME),
            SW_1: DigitalPin(SW_1, SW_1_NAME, IoMode.OUT),
            SW_2: DigitalPin(SW_2, SW_2_NAME, IoMode.OUT)
        }

        self.digital_io_publisher = self.create_publisher(
            DigitalIOState, '/niryo_one/rpi/digital_io_state', 1)
        timer_period = 1.0 / self.publish_io_state_frequency
        self.timer = self.create_timer(timer_period, self.publish_io_state)

        self.get_io_server = self.create_service(
            GetDigitalIO, '/niryo_one/rpi/get_digital_io', self.get_io_cb)
        self.set_io_mode_server = self.create_service(
            SetDigitalIO, '/niryo_one/rpi/set_digital_io_mode',
            self.set_io_mode_cb)
        self.set_io_state_server = self.create_service(
            SetDigitalIO, '/niryo_one/rpi/set_digital_io_state',
            self.set_io_state_cb)

        self.get_logger().info('--- Niryo One - Digital I/O Panel - Started ---')

    def publish_io_state(self) -> None:
        msg = DigitalIOState()
        pins = []
        names = []
        modes = []
        states = []
        for id, io in self.digitalIOs.items():
            pins.append(io.pin)
            names.append(io.name)
            modes.append(io.mode.value)
            states.append(io.get_state().value)
        msg.pins = pins
        msg.names = names
        msg.modes = modes
        msg.states = states
        self.digital_io_publisher.publish(msg)

    def get_io_cb(self, req: GetDigitalIO.Request, resp: GetDigitalIO.Response) -> GetDigitalIO.Response:
        try:
            io = self.digitalIOs[req.pin]
            return create_response(resp,
                                   status=200,
                                   message='OK',
                                   pin=io.pin,
                                   name=io.name,
                                   mode=io.get_mode(),
                                   state=io.get_state()
                                   )
        except:
            return create_response(resp,
                                   status=400,
                                   message=f'No GPIO found with this pin number ({req.pin})')

    def set_io_mode_cb(self, req: SetDigitalIO.Request, resp: SetDigitalIO.Response) -> SetDigitalIO.Response:
        try:
            io = self.digitalIOs[req.pin]
            if io.name.startswith('SW'):
                return create_response(resp,
                                       status=400,
                                       message="Can't change mode for switch pin")

            # Set mode
            io.set_mode(req.value)

            return create_response(resp,
                                   status=200,
                                   message=f"Successfully set IO mode for Pin {io.pin}")
        except:
            return create_response(resp,
                                   status=400,
                                   message=f"No GPIO found with this pin number ({req.pin})")

    def set_io_state_cb(self, req: SetDigitalIO.Request, resp: SetDigitalIO.Response) -> SetDigitalIO.Response:
        try:
            io = self.digitalIOs[req.pin]
            if io.get_mode() != IoMode.OUT:
                return create_response(resp,
                                       status=400,
                                       message=f"This PIN ({io.pin}) is set as input, you can't change its state")

            # Set state
            success = io.set_state(req.value)

            if success:
                return create_response(resp,
                                       status=200,
                                       message=f"Successfully set IO state for Pin {io.pin}")
            else:
                return create_response(resp,
                                       status=400,
                                       message=f"Error: Could no set IO state for Pin {io.pin}")
        except:
            return create_response(resp,
                                   status=400,
                                   message=f"No GPIO found with this pin number ({req.pin})")


def main():
    rclpy.init()
    digital_io_panel = DigitalIOPanel()

    try:
        rclpy.spin(digital_io_panel)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        digital_io_panel.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
