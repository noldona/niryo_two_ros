from enum import Enum
import rclpy
import subprocess
import re

from niryo_one_msgs.srv import SetInt

from ament_index_python.packages import get_package_share_directory

ENABLE_BUS_MOTORS_SUCCESS = 1
ENABLE_BUS_MOTORS_READ_FAIL = -1
ENABLE_BUS_MOTORS_WRITE_FAIL = -2

CHANGE_MOTOR_CONFIG_SUCCESS = 1
CHANGE_MOTOR_CONFIG_READ_FAIL = -1
CHANGE_MOTOR_CONFIG_WRITE_FAIL = -2
CHANGE_MOTOR_CONFIG_WRONG_VERSION = -3


class LedState(Enum):
    SHUTDOWN = 1
    HOTSPOT = 2
    HW_ERROR = 3
    OK = 4
    WAIT_HOTSPOT = 5


class IoMode(Enum):
    OUT = 0
    IN = 1


class IoState(Enum):
    LOW = 0
    HIGH = 1


def create_response(_resp, **kwargs):
    for k, v in kwargs.items():
        setattr(_resp, k, v)

    return _resp

def send_hotspot_command():
    rclpy.get_logger().info("HOTSPOT")
    send_led_state(LedState.WAIT_HOTSPOT)
    rclpy.wait_for_service('/niryo_one/wifi/set_hotspot')
    try:
        set_hotspot = rclpy.create_client(SetInt, '/niryo_one/wifi/set_hotspot')
        set_hotspot()
    except rclpy.ServiceException as e:
        rclpy.get_logger().warn("Could not call set_hotspot service")


def send_trigger_sequence_autorun():
    rclpy.get_logger().info("Trigger sequence autorun from button")
    try:
        rclpy.wait_for_service('/niryo_one/sequences/trigger_sequence_autorun', 0.1)
        trigger = rclpy.create_client(SetInt, '/niryo_one/sequences/trigger_sequence_autorun')
        trigger(1)  # value doesn't matter, it will switch state on the server
    except (rclpy.ServiceException, rclpy.ROSException) as e:
        return


def send_reboot_motors_command():
    rclpy.get_logger().info("Send reboot motor command")
    try:
        rclpy.wait_for_service('/niryo_one/reboot_motors', 1)
    except rclpy.ROSException as e:
        pass
    try:
        reboot_motors = rclpy.create_client(SetInt, '/niryo_one/reboot_motors')
        reboot_motors(1)
    except rclpy.ServiceException as e:
        pass


def send_shutdown_command():
    rclpy.get_logger().info("SHUTDOWN")
    send_led_state(LedState.SHUTDOWN)
    rclpy.get_logger().info("Activate learning mode")
    try:
        rclpy.wait_for_service('/niryo_one/activate_learning_mode', 1)
    except rclpy.ROSException as e:
        pass
    try:
        activate_learning_mode = rclpy.create_client(SetInt, '/niryo_one/activate_learning_mode')
        activate_learning_mode(1)
    except rclpy.ServiceException as e:
        pass
    send_reboot_motors_command()
    rclpy.sleep(0.2)
    rclpy.get_logger().info("Command 'sudo shutdown now'")
    try:
        output = subprocess.check_output(['sudo', 'shutdown', 'now'])
    except subprocess.CalledProcessError:
        rclpy.get_logger().info("Can't exec shutdown cmd")


def send_reboot_command():
    rclpy.get_logger().info("REBOOT")
    send_led_state(LedState.SHUTDOWN)
    rclpy.get_logger().info("Activate learning mode")
    try:
        rclpy.wait_for_service('/niryo_one/activate_learning_mode', 1)
    except rclpy.ServiceException as e:
        pass
    try:
        activate_learning_mode = rclpy.create_client(SetInt, '/niryo_one/activate_learning_mode')
        activate_learning_mode(1)
    except rclpy.ServiceException as e:
        pass
    send_reboot_motors_command()
    rclpy.sleep(0.2)
    rclpy.get_logger().info("Command 'sudo reboot'")
    try:
        output = subprocess.check_output(['sudo', 'reboot'])
    except subprocess.CalledProcessError:
        rclpy.get_logger().info("Can't exec reboot cmd")


def send_led_state(state):
    rclpy.wait_for_service('/niryo_one/rpi/set_led_state')
    try:
        set_led = rclpy.create_client(SetInt, '/niryo_one/rpi/set_led_state')
        set_led(state)
    except rclpy.ServiceException as e:
        rclpy.get_logger().warn("Could not call set_led_state service")


def enable_bus_motors_in_config_file(enable_can_bus=True, enable_dxl_bus=True):
    folder_path = get_package_share_directory('niryo_one_bringup')
    file_path = folder_path + '/launch/controllers.launch'
    text = ""
    rclpy.get_logger().info("Change launch file (for debug purposes): " + str(file_path))
    rclpy.get_logger().info("Enable can_bus: " + str(enable_can_bus))
    rclpy.get_logger().info("Enable dxl bus: " + str(enable_dxl_bus))

    # Open file and get text
    try:
        with open(file_path, 'r') as f:
            text = f.read()
    except EnvironmentError as e:
        rclpy.get_logger().error(e)
        return ENABLE_BUS_MOTORS_READ_FAIL

    # Change disable_can
    new_line_can_bus = "<arg name=\"disable_can_for_debug\" default=\"false\""
    if not enable_can_bus:
        new_line_can_bus = "<arg name=\"disable_can_for_debug\" default=\"true\""
    text = re.sub(r"\<arg name=\"disable_can_for_debug\" default=\"\w+\"", new_line_can_bus, text)

    # Change disable_dxl
    new_line_dxl_bus = "<arg name=\"disable_dxl_for_debug\" default=\"false\""
    if not enable_dxl_bus:
        new_line_dxl_bus = "<arg name=\"disable_dxl_for_debug\" default=\"true\""
    text = re.sub(r"\<arg name=\"disable_dxl_for_debug\" default=\"\w+\"", new_line_dxl_bus, text)

    # Rewrite file with new text
    try:
        with open(file_path, 'w') as f:
            f.write(text)
    except EnvironmentError as e:
        rclpy.get_logger().error(e)
        return ENABLE_BUS_MOTORS_WRITE_FAIL
    return ENABLE_BUS_MOTORS_SUCCESS


def change_motor_config_file(hw_version, can_id_list, dxl_id_list):
    folder_path = get_package_share_directory('niryo_one_bringup')
    file_path = folder_path + '/config/v' + str(int(hw_version)) + '/niryo_one_motors.yaml'
    lines = []
    can_bus_enabled = len(can_id_list) > 0
    dxl_bus_enabled = len(dxl_id_list) > 0
    rclpy.get_logger().info("Change motor config file (for debug purposes): " + str(file_path))
    rclpy.get_logger().info("Hw version: " + str(hw_version))
    rclpy.get_logger().info("CAN ID list: " + str(can_id_list))
    rclpy.get_logger().info("DXL ID list: " + str(dxl_id_list))

    if hw_version != 1 and hw_version != 2:
        return CHANGE_MOTOR_CONFIG_WRONG_VERSION

    # Open file, get text and split lines
    try:
        with open(file_path, 'r') as f:
            lines = f.read().splitlines()
    except EnvironmentError as e:
        rclpy.get_logger().error(e)
        return CHANGE_MOTOR_CONFIG_READ_FAIL

    text_begin_lines = []
    text_can_lines = []
    text_dxl_lines = []
    text_end_lines = []

    # Get beginning of file (not modified)
    for line in lines:
        if not line.startswith('#'):
            break
        text_begin_lines.append(line)

    # Get end of file (not modified)
    for i, line in enumerate(lines):
        if line.startswith('dxl_authorized_motors'):
            text_end_lines = lines[i:]
            break

    # Fill CAN motor IDs depending on given ID array
    # If CAN bus is already disabled, then don't disable motors here
    if hw_version == 1:
        text_can_lines.append(
            'can_required_motors: # Axis 1-4 of Niryo One (stepper 1 -> id 1, stepper 2 -> id 2, ...)')
    else:
        text_can_lines.append(
            'can_required_motors: # Axis 1-3 of Niryo One (stepper 1 -> id 1, stepper 2 -> id 2, ...)')
    text_can_lines.append(
        '    # Edit only for debug purposes (ex : you want to test some motors separately and detached from the robot)')
    text_can_lines.append(
        '    # --> Commented ids will make associated motor disable (and thus not trigger an error if not connected)')
    text_can_lines.append('    # Before editing, please be sure that you know what you\'re doing')
    if 1 in can_id_list or not can_bus_enabled:
        text_can_lines.append('    - 1 # Axis 1 enabled if not commented')
    else:
        text_can_lines.append('    #- 1 # Axis 1 enabled if not commented')
    if 2 in can_id_list or not can_bus_enabled:
        text_can_lines.append('    - 2 # Axis 2 enabled if not commented')
    else:
        text_can_lines.append('    #- 2 # Axis 2 enabled if not commented')
    if 3 in can_id_list or not can_bus_enabled:
        text_can_lines.append('    - 3 # Axis 3 enabled if not commented')
    else:
        text_can_lines.append('    #- 3 # Axis 3 enabled if not commented')
    if hw_version == 1:
        if 4 in can_id_list or not can_bus_enabled:
            text_can_lines.append('    - 4 # Axis 4 enabled if not commented')
        else:
            text_can_lines.append('    #- 4 # Axis 4 enabled if not commented')

    # Fill DXL motor IDs depending on given ID array
    # If DXL bus is already disabled, then don't disable motors here
    if hw_version == 1:
        text_dxl_lines.append('dxl_required_motors: # axis 5 and 6 of Niryo One.')
    else:
        text_dxl_lines.append('dxl_required_motors: # axis 4, 5 and 6 of Niryo One.')
    text_dxl_lines.append(
        '    # Edit only for debug purposes (ex : you want to test some motors separately and detached from the robot)')
    text_dxl_lines.append(
        '    # --> Commented ids will make associated motor disable (and thus not trigger an error if not connected)')
    text_dxl_lines.append('    # Before editing, please be sure that you know what you\'re doing')
    if hw_version == 1:
        text_dxl_lines.append(
            '    # - Note : Axis 5 has 2 motors, but you can use only one motor for this axis when debugging')
    if hw_version == 1:
        if 4 in dxl_id_list or not dxl_bus_enabled:
            text_dxl_lines.append('    - 4 # -> id of Axis 5_1')
        else:
            text_dxl_lines.append('    #- 4 # -> id of Axis 5_1')
        if 5 in dxl_id_list or not dxl_bus_enabled:
            text_dxl_lines.append('    - 5 # -> id of Axis 5_2')
        else:
            text_dxl_lines.append('    #- 5 # -> id of Axis 5_2')
        if 6 in dxl_id_list or not dxl_bus_enabled:
            text_dxl_lines.append('    - 6 # -> id of Axis 6')
        else:
            text_dxl_lines.append('    #- 6 # -> id of Axis 6')
    else:
        if 2 in dxl_id_list or not dxl_bus_enabled:
            text_dxl_lines.append('    - 2 # -> id of Axis 4')
        else:
            text_dxl_lines.append('    #- 2 # -> id of Axis 4')
        if 3 in dxl_id_list or not dxl_bus_enabled:
            text_dxl_lines.append('    - 3 # -> id of Axis 5')
        else:
            text_dxl_lines.append('    #- 3 # -> id of Axis 5')
        if 6 in dxl_id_list or not dxl_bus_enabled:
            text_dxl_lines.append('    - 6 # -> id of Axis 6')
        else:
            text_dxl_lines.append('    #- 6 # -> id of Axis 6')

    new_text = '\n'.join(
        text_begin_lines + [''] + text_can_lines + [''] + text_dxl_lines + [''] + text_end_lines + [''])

    # Rewrite file with new text
    try:
        with open(file_path, 'w') as f:
            f.write(new_text)
    except EnvironmentError as e:
        rclpy.get_logger().error(e)
        return CHANGE_MOTOR_CONFIG_WRITE_FAIL
    return CHANGE_MOTOR_CONFIG_SUCCESS
