from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
import rclpy
import threading

from niryo_one_msgs.srv import ChangeMotorConfig
import niryo_one_rpi.rpi_ros_utils as rpi_utils


class MotorDebug(Node):

    def __init__(self):
        super().__init__('motor_debug')

        self.hw_version = self.declare_parameter(
            '/niryo_one/hardware_version', rclpy.Parameter.Type.INTEGER).value
        self.change_motor_config_server = self.create_service(
            ChangeMotorConfig, 'niryo_one/change_motor_config',
            self.change_motor_config_cb)
        self.get_logger().info("Init motor debug OK")

    def change_motor_config_cb(self, req):
        self.get_logger().info('Changing motor config')
        can_ids = list(req.can_required_motor_id_list)
        dxl_ids = list(req.dxl_required_motor_id_list)

        # Step 0: Remove impossible IDs (axis 1-6)
        if self.hw_version == 1:
            for identif in can_ids:
                if identif not in [1, 2, 3, 4]:
                    can_ids.remove(identif)
            for identif in dxl_ids:
                if identif not in [4, 5, 6]:
                    can_ids.remove(identif)
        elif self.hw_version == 2:
            for identif in can_ids:
                if identif not in [1, 2, 3]:
                    can_ids.remove(identif)
            for identif in dxl_ids:
                if identif not in [2, 3, 6]:
                    dxl_ids.remove(identif)

        enable_can_bus = len(can_ids) != 0
        enable_dxl_bus = len(dxl_ids) != 0

        # Step 1: Enable/Disable motor buses
        enable_bus_result = rpi_utils.enable_bus_motors_in_config_file(
            enable_can_bus=enable_can_bus, enable_dxl_bus=enable_dxl_bus)

        if enable_bus_result == rpi_utils.ENABLE_BUS_MOTORS_READ_FAIL:
            return ChangeMotorConfig.Response(
                status=400, message="Failed to read file - see ROS log")
        elif enable_bus_result == rpi_utils.ENABLE_BUS_MOTORS_WRITE_FAIL:
            return ChangeMotorConfig.Response(
                status=400, message="Failed to write file - see ROS log")

        # Step 2: Change motor config file
        motor_config_result = rpi_utils.change_motor_config_in_file(
            self.hw_version, can_ids, dxl_ids)

        if motor_config_result == rpi_utils.CHANGE_MOTOR_CONFIG_READ_FAIL:
            return ChangeMotorConfig.Response(
                status=400, message="Failed to read file - see ROS log")
        elif motor_config_result == rpi_utils.CHANGE_MOTOR_CONFIG_WRITE_FAIL:
            return ChangeMotorConfig.Response(
                status=400, message="Failed to write file - see ROS log")
        elif motor_config_result == rpi_utils.CHANGE_MOTOR_CONFIG_WRONG_VERSION:
            return ChangeMotorConfig.Response(
                status=400, message="Wrong hardware version")

        # Step 3: Reboot
        send_reboot_command_thread = threading.Timer(
            1.0, rpi_utils.send_reboot_command)
        send_reboot_command_thread.start()
        return ChangeMotorConfig.Response(
            status=200,
            message="Motor config successfully changed. Now rebooting...")


def main():
    rclpy.init()
    motor_debug = MotorDebug()

    try:
        rclpy.spin(motor_debug)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        motor_debug.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
