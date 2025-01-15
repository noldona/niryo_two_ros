from time.time import sleep

from gpiozero import DigitalOutputDevice
from std_msgs.msg import Bool
from rclpy.node import Node
import rclpy

FAN_1_GPIO = 27
FAN_2_GPIO = 23


class FansManager(Node):

    def __init__(self) -> None:
        super().__init('fans_manager')
        self.setup_fans()
        self.learning_mode_on = True

        # Activate fans for 5 seconds to give an audio signal to the user
        self.set_fans(True)
        sleep(5)
        self.set_fans(not self.learning_mode_on)

        self.learning_mode_subscriber = self.create_subscription(
            Bool, 'niryo_one/learning_mode', self.learning_mode_cb, 10)

    def setup_fans(self) -> None:
        self.fan1 = DigitalOutputDevice(FAN_1_GPIO, inital_value=False)
        self.fan2 = DigitalOutputDevice(FAN_2_GPIO, inital_value=False)
        sleep(0.05)
        self.get_logger().info("------ RPI FANS SETUP OK ------")

    def set_fans(self, activate: bool) -> None:
        if activate:
            self.fan1.on()
            self.fan2.on()
        else:
            self.fan1.off()
            self.fan2.off()

    def learning_mode_cb(self, msg: Bool) -> None:
        if msg.data != self.learning_mode_on:
            self.learning_mode_on = msg.data
            self.set_fans(not self.learning_mode_on)


def main():
    rclpy.init()
    fans_manager = FansManager()

    try:
        rclpy.spin(fans_manager)
    except KeyboardInterrupt:
        pass
    finally:
        fans_manager.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
