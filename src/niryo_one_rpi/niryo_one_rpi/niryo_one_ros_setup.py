import time
import subprocess
import rclpy

from niryo_one_msgs.msg import ProcessState ManageProcess

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

    def start(self):
        if not self.is_active():
            cmd = self.cmd.split(' ') + self.args
            if self.delay_before_start:
                pass
