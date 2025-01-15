from enum import Enum


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
