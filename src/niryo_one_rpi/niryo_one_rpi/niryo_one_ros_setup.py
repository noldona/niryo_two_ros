from rclpy.node import Node
from rclpy.duration import Duration
from rclpy.executors import ExternalShutdownException
import time
import subprocess
import rclpy

from niryo_one_msgs.msg import ProcessState, ManageProcess
from niryo_one_rpi.rpi_ros_utils import create_response

PROCESS_TIMEOUT_RESTART = 5.0  # seconds


class ProcessNotFound(Exception):
    pass


class ProcessActionType(Enum):
    START = 1
    STOP = 2
    RESTART = 3
    KILL = 4
    START_ALL = 5
    STOP_ALL = 6


class Process:
    def __init__(self, name, cmd, args=None, launch_on_startup=False,
                 delay_before_start=0.0, dependencies=None):
        self.name = name
        self.cmd = cmd
        self.args = args if args is not None else []
        self.dependencies = dependencies if dependencies is not None else []
        self.launch_on_startup = launch_on_startup
        self.delay_before_start = delay_before_start
        self.process = None

    def start(self) -> None:
        if not self.is_active():
            cmd = self.cmd.split(' ') + self.args
            if self.delay_before_start:
                time.sleep(self.delay_before_start)
            self.process = subprocess.Popen(cmd)

    def restart(self) -> None:
        self.stop()
        timeout = time.time() + PROCESS_TIMEOUT_RESTART
        while self.is_active():
            if time.time() > timeout:
                break
            time.sleep(0.1)
        self.start()

    def stop(self) -> None:
        if self.process:
            self.process.terminate()

    def kill(self) -> None:
        if self.process:
            self.process.kill()

    def is_active(self) -> bool:
        if not self.process:
            return False

        return_code = self.process.poll()
        if return_code is None or return_code < 0:
            return Tru
        return False


class NiryoOneRosSetup(Node):
    def __init__(self):
        super.__init__('niryo_one_ros_setup')

        self.process_list = []
        self.process_config = self.declare_parameter('~processes').value
        self.create_processes()

        self.context.on_shutdown(self.clean_ros_processes)

        self.process_state_publish_rate = self.declare_paramter(
            '~process_state_publish_rate').value

        self.process_state_publisher = self.create_publisher(
            ProcessState, '/niryo_one/rpi/process_state', 1)
        self.create_timer(
            Duration(seconds=1.0 / self.process_state_publish_rate),
            self.publish_process_state)

        self.manage_process_server = self.create_service(
            ManageProcess, '/niryo_one/rpi/manage_process',
            self.manage_process_cb)

        self.start_init_process()

    def publish_process_state(self):
        msg = ProcessState()
        for p in self.process_list:
            msg.name.append(p.name)
            msg.is_active.append(p.is_active())
        self.process_state_publisher.publish(msg)

    def manage_process_cb(self, req: ManageProcess.Request, resp: ManageProcess.Response) -> ManageProcess.Response:
        process_name = req.name
        action = req.action

        try:
            if action == ProcessActionType.START_ALL:
                self.start_all_processes()
                return create_response(200, "All processes have been started")
            elif action == ProcessActionType.STOP_ALL:
                self.stop_all_processes()
                return create_response(200, "All processes have been stopped")
            elif action == ProcessActionType.START:
                self.start_process_from_name(
                    process_name, start_dependencies=True)
                return create_response(200, "Process has been started")
            elif action == ProcessActionType.STOP:
                self.stop_process_from_name(process_name)
                return create_response(200, "Process has been stopped")
            elif action == ProcessActionType.RESTART:
                self.restart_process_from_name(process_name)
                return create_response(200, "Process has been restarted")
            elif action == ProcessActionType.KILL:
                self.kill_process_from_name(process_name)
                return create_response(200, "Process has been killed")
        except ProcessNotFound as e:
            return create_response(400, str(e))

    def clean_ros_processes(self) -> None:
        self.stop_all_processes()

    def create_processes(self) -> None:
        self.get_logger().info("Start creating processes from rosparams")
        for p in self.process_config:
            self.process_list.append(Process(
                name=p['name'], cmd=p['cmd'], args=p['args'],
                launch_on_startup=p['launch_on_startup'],
                delay_before_start=p['delay_before_start'],
                dependencies=p['dependencies']
            ))

    def start_init_process(self) -> None:
        for p in self.process_list:
            if p.launch_on_startup:
                self.start_process(p, start_dependencies=True)

    def start_all_processes(self) -> None:
        for p in self.process_list:
            self.start_process(p, start_dependencies=True)

    def stop_all_processes(self) -> None:
        for p in self.process_list:
            self.stop_process(p)

    def get_process_from_name(self, name: str) -> Process:
        p = None
        for process in self.process_list:
            if process.name == name:
                p = process
                break
        if p is None:
            raise ProcessNotFound(f"Process not found: {name}")
        return p

    def get_dependency_procecss_list(self, process: Process) -> list:
        dep_name_list = process.dependencies
        try:
            return list(map(lambda dep_name: self.get_process_from_name(dep_name), dep_name_list))
        except ProcessNotFound as e:
            self.get_logger().warn(
                "Some dependency names are incorrect. Check your setup.yaml file to fix it")
            return []

    def are_dependencies_met(self, process: Process) -> bool:
        dep_process_list = self.get_dependency_procecss_list(process)
        for dep_process in dep_process_list:
            if not dep_process.is_active():
                self.get_logger().info(f"Unmet dependency for {
                    str(process.name)} (depends on {str(p.name)})!")
                return False
        return True

    # CAREFUL : recursion - todo set security(no more than 5 depth)
    def check_and_start_dependencies(self, process: Process) -> None:
        dep_process_list = self.get_dependency_procecss_list(process)
        for dep_process in dep_process_list:
            if not dep_process.is_active():
                self.get_logger().info(f"Starting dependency process...")
                self.start_process(dep_process, start_dependencies=True)

    def start_process(self, process: Process, start_dependencies=False) -> None:
        self.get_logger().info(f"Handle process: {str(process.name)}")
        if start_dependencies:
            self.check_and_start_dependencies(process)

        if self.are_dependencies_met(process):
            self.get_logger().info(f"Starting process {str(process.name)}...")
            process.start()

    @staticmethod
    def stop_process(process: Process) -> None:
        process.stop()

    @staticmethod
    def restart_process(process: Process) -> None:
        process.restart()

    @staticmethod
    def kill_process(process: Process) -> None:
        process.kill()

    def start_proccess_from_name(self, name: str, start_dependencies=False) -> None:
        process = self.get_process_from_name(name)
        self.start_process(process, start_dependencies)

    def stop_process_from_name(self, name: str) -> None:
        process = self.get_process_from_name(name)
        self.stop_process(process)

    def restart_process_from_name(self, name: str) -> None:
        process = self.get_process_from_name(name)
        self.restart_process(process)

    def kill_process_from_name(self, name: str) -> None:
        process = self.get_process_from_name(name)
        self.kill_process(process)


def main():
    rclpy.init()
    niryo_one_setup = NiryoOneRosSetup()

    try:
        rclpy.spin(niryo_one_setup)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        niryo_one_setup.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
