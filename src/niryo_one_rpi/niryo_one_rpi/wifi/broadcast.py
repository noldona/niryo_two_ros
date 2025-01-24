from socket import *
import time

from robot_name_handler import *
import socket

#
# Will broadcast own IP address, so users can find the robot on a WiFi network
#


def start_broadcast_ip_publisher():
    robot_name = read_robot_name()

    while True:
        time.sleep(1)
        s = None
        try:
            s = socket(AF_INET, SOCK_DGRAM)
        except Exception as e:
            continue

        try:
            s.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
            s.setsockopt(SOL_SOCKET, SO_BROADCAST, 1)
            s.sendto(robot_name, ('255.255.255.255', 1665))
        except Exception as e:
            s.close()

        s.close()


if __name__ == '__main__':
    start_broadcast_ip_publisher()
