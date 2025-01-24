from uuid import getnode as get_mac
import os
import subprocess
import time
import re

HOTSPOT_MODE = False


def is_hotspot_activated():  # WiFi Manager (ROS side) can quickly query hotspot mode
    return HOTSPOT_MODE


def get_mac_address():
    return ':'.join(("%012X" % get_mac())[i:i + 2] for i in range(0, 12, 2))


def deactivate_current_wlan0():
    """Deactive the current wlan0 connection, if it exists"""
    print("Deactivate current wlan0...")
    count = 0
    while count < 4:
        try:
            output = subprocess.check_output([
                'sudo', 'nmcli', 'device', 'disconnect', 'wlan0'
            ])
            print("Successfully deactivated")
            time.sleep(5)  # need delay
            return True
        except subprocess.CalledProcessError as e:
            print("Failed to deactivate wlan0")
        count += 1
    return False


def activate_current_wlan0():
    """Activate the current wlan0 connection"""
    print("Activate current wlan0...")
    output = subprocess.check_output([
        'sudo', 'nmcli', 'device', 'status'
    ])
    print(output)
    count = 0
    while count < 4:
        try:
            output = subprocess.check_output([
                'sudo', 'nmcli', 'device', 'connect', 'wlan0'
            ])
            print(output)
            return True
        except subprocess.CalledProcessError as e:
            print("Failed")
        count += 1
    return False


def delete_connection_with_ssid(ssid):
    """Delete registered connection with corresponding ssid"""
    print(f"Delete connection with SSID: {ssid}")
    ssid_list = get_all_registered_wifi()
    if ssid in ssid_list:
        try:
            output = subprocess.check_output([
                'sudo', 'nmcli', 'connection', 'delete', ssid
            ])
            print("Connection successuffly deleted")
            return True
        except subprocess.CalledProcessError as e:
            print("Failed to delete ssid")
            return False
    print("Can't delete an unregisted ssid")
    return False
