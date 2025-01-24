from niryo_one_rpi.niryo_one_rpi.rpi_ros_utils import create_response
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
import rclpy
import threading

from niryo_one_rpi.rpi_ros_utils import send_shutdown_command, send_reboot_command
from niryo_one_msgs.srv import SetInt


class ShutdownManager(Node):
    def __init__(self):
        super().__init__('niryo_one_shutdown_manager')

        self.shutdown_service = self.create_service(
            SetInt, '/niryo_one/rpi/shutdown_rpi', self.shutdown_cb)

        self.get_logger().info('Shutdown Manager OK')

    @staticmethod
    def shutdown_cb(req: SetInt.Request, resp: SetInt.Response) -> SetInt.Response:
        if req.value == 1:
            send_shutdown_command_thread = threading.Thread(
                target=send_shutdown_command)
            send_shutdown_command_thread.start()
            return create_response(resp, status=200, message='Robot is shutting down')
        elif req.value == 2:
            send_reboot_command_thread = threading.Thread(
                target=send_reboot_command)
            send_reboot_command_thread.start()
            return create_response(resp, status=200, message='Robot is rebooting')
        else:
            return create_response(resp, status=400, message='Incorrect value: 1 for shutdown, 2 for reboot')


def main():
    rclpy.init()
    shutdown_manager = ShutdownManager()

    try:
        rclpy.spin(shutdown_manager)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        shutdown_manager.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
