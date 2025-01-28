from niryo_one_rpi.niryo_one_rpi.rpi_ros_utils import create_response
from rclpy.node import Node
from rclpy.duration import Duration
from rclpy.executors import ExternalShutdownException
import rclpy
import subprocess
import os

from niryo_one_msgs.msg import LogStatus
from niryo_one_msgs.srv import SetInt


class RosLogManager(Node):
    def __init__(self):
        super.__init__('ros_log_manager')

        self.log_size_threshold = self.declare_parameter(
            '~ros_log_size_treshold').value
        self.log_path = self.declare_parameter('~ros_log_location').value
        self.should_purge_log_on_startup_file = self.declare_parameter(
            '~should_purge_ros_log_on_startup_file').value
        self.purge_log_on_startup = self.should_purge_log_on_startup()

        # Clean logs on startup if param is true
        if self.purge_log_on_startup:
            self.get_logger().warn('Purging ROS logs on startup')
            self.purge_logs()

        self.purge_log_server = self.create_service(
            SetInt, '/niryo_one/rpi/purge_ros_logs', self.purge_logs_cb)

        self.change_purge_log_on_startup_server = self.create_service(
            SetInt, '/niryo_one/rpi/set_purge_ros_log_on_startup',
            self.change_purge_log_on_startup_cb)

        self.log_status_publisher = self.create_publisher(
            LogStatus, '/niryo_one/rpi/ros_log_status', 10)
        self.timer = self.create_timer(Duration(seconds=3),
                                       self.publish_log_status)

        self.get_logger().info('Init ROS Log Manager OK')

    @staticmethod
    def get_available_disk_size() -> int:
        try:
            process = subprocess.Popen(
                ['df', '--output=avail', '/'], stdout=subprocess.PIPE)
            output, error = process.communicate()
            lines = output.split(os.linesep)
            if len(lines) >= 2:
                return int(lines[1]) / 10024
            return -1
        except subprocess.CalledProcessError:
            return -1

    def get_log_size(self) -> int:
        try:
            if not os.path.exists(self.log_path):
                return -1
            output = subprocess.check_output(['du', '-sBM', self.log_path])
            output_array = output.split()
            if len(output_array) >= 1:
                return int(output_array[0].replace('M', ''))
            return -1
        except subprocess.CalledProcessError:
            return -1

    # ROS Logs wll not be saved after using this method, you will need
    # to restart ROS completely to save new logs
    def purge_log(self) -> bool:
        try:
            subprocess.call(['mkdir', '-p', self.log_path])
            subprocess.call(['rm', '-rf', f"{self.log_path}/*"])
            return True
        except subprocess.CalledProcessError:
            return False

    def should_purge_log_on_startup(self):
        if os.path.isfile(self.should_purge_log_on_startup_file):
            with open(self.should_purge_log_on_startup_file, 'r') as f:
                for line in f:
                    if not (line.startswith('#') or len(line) == 0):
                        condition = line.rstrip()
                        if condition == "true":
                            return True
                        return False
        return False

    def change_purge_log_on_startup(self, condition):
        with open(self.should_purge_log_on_startup_file, 'w') as f:
            if condition:
                value = "true"
            else:
                value = "false"
            f.write(value)

        # After writing, read new value from file
        self.purge_log_on_startup = self.should_purge_log_on_startup()

    #
    # ----- ROS Interface below -----
    #

    def purge_logs_cb(self, req: SetInt.Request, resp: SetInt.Response) -> SetInt.Response:
        self.get_logger().warn('Purge ROS logs on user request')
        if self.purge_log():
            return create_response(resp,
                                   status=200,
                                   message="ROS logs have been purged. Following logs will be discarded. If you want to get logs, you need to restart the robot")
        return create_response(resp,
                               status=400,
                               message="Unable to remove ROS logs")

    def change_purge_log_on_startup_cb(self, req: SetInt.Request, resp: SetInt.Response) -> SetInt.Response:
        if req.value == 1:
            self.change_purge_log_on_startup(True)
        else:
            self.change_purge_log_on_startup(False)
        return create_response(resp,
                               status=200,
                               message="Purge log on startup value has been changed")

    def publish_log_status(self):
        msg = LogStatus()
        msg.header.stamp = self.get_clock().now()
        msg.log_size = self.get_log_size()
        msg.available_disk_size = self.get_available_disk_size()
        msg.purge_log_on_startup = self.purge_log_on_startup
        self.log_status_publisher.publish(msg)


def main():
    rclpy.init()
    ros_log_manager = RosLogManager()

    try:
        rclpy.spin(ros_log_manager)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        ros_log_manager.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
