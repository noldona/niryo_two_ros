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


def deactivate_current_wlan0() -> bool:
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


def activate_current_wlan0() -> bool:
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


def delete_connection_with_ssid(ssid: str) -> bool:
    """Delete registered connection with corresponding SSID"""
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
            print("Failed to delete SSID")
            return False
    print("Can't delete an unregisted SSID")
    return False


def hard_enable_hotspot_with_ssid(ssid: str, password: str) -> bool:
    """Create and start Hotspot with ssid and password"""
    delete_connection_with_ssid(ssid)  # Will avoid duplicate
    deactivate_current_wlan0()
    activate_current_wlan0()
    retries = 4
    while retries > 0:
        output1 = subprocess.check_output([
            'sudo', 'nmcli', 'connection', 'add',
            'type', 'wifi', 'ifname', 'wlan0', 'con-name', ssid,
            'autoconnect', 'no', 'ssid', ssid, 'ip4', '10.10.10.10/24'
        ])
        # All user devices will use 10.10.10.10 when in hotspot mode
        print("Hotspot create with IP: 10.10.10.10")

        output2 = subprocess.check_output([
            'sudo', 'nmcli', 'connection', 'modify', ssid,
            '802-11-wireless.mode', 'ap', '802-11-wireless.band', 'bg',
            'ipv4.method', 'shared'
        ])

        output3 = subprocess.check_output([
            'sudo', 'nmcli', 'connection', 'modify', ssid,
            'wifi-sec.key-mgmt', 'wpa-psk'
        ])
        print("Security set to WPA password")

        output4 = subprocess.check_output([
            'sudo', 'nmcli', 'connection', 'modify', ssid,
            'wifi-sec.psk', password
        ])
        print("Password set")

        count = 0
        print("Trying to start the hotspot")
        while count < 4:
            print(f"Attempt {str(count)}")
            try:
                output5 = subprocess.check_output([
                    'sudo', 'nmcli', 'connection', 'up', 'id', ssid
                ])
                print("Hotspot successfully activated")
                global HOTSPOT_MODE
                HOTSPOT_MODE = True
                return True
            except subprocess.CalledProcessError as e:
                print("Error, retrying...")
                count += 1
        retries -= 1
    return False


def delete_all_duplicate_connections(ssid: str) -> None:
    registered_connections = get_all_registered_wifi()
    for i, c in enumerate(registered_connections):
        if c == ssid or re.match(str(ssid) + ' ' + '\\d+', str(c)):
            delete_connection_with_ssid(c)


def connect_to_wifi(ssid: str, password: str) -> bool:
    """Connect to the wifi"""
    # For each connection, network manager will create a new registered
    # SSID with incremential number
    delete_all_duplicate_connections(ssid)
    deactivate_current_wlan0()
    count = 0
    print(f"Trying to connect to the wifi {ssid}")
    while count < 4:
        print(f"Attempt {str(count + 1)}")
        try:
            output = subprocess.check_output([
                'sudo', 'nmcli', 'device', 'wifi', 'connect', ssid,
                'password', password
            ])
            print("Connection successuffly started")
            if is_connected_to_wifi():
                global HOTSPOT_MODE
                HOTSPOT_MODE = False
                return True
            return False
        except subprocess.CalledProcessError as e:
            print("Error, retrying...")
            count += 1
    return False


def is_connected_to_wifi() -> bool:
    """Check if robot is already connected to a wifi"""
    list_enabled_connection = subprocess.Popen([
        'sudo', 'nmcli', 'connection', 'show', '--active'],
        stdout=subprocess.PIPE)
    output, error = list_enabled_connection.communicate()
    # Print output
    for line in output.decode('utf-8').split(os.linesep):
        if 'wlan0' in line:
            return True
    return False


def get_current_ssid() -> str:
    """Get the SSID of the current Connection ('' if no connection)"""
    list_enabled_connection = subprocess.Popen([
        'sudo', 'nmcli', 'connection', 'show', '--active'],
        stdout=subprocess.PIPE)
    output, error = list_enabled_connection.communicate()
    # Print output
    for line in output.decode('utf-8').split(os.linesep):
        if 'wlan0' in line:
            return line.split('  ')[0]
    return ''


def get_all_registered_wifi() -> list:
    """Get a list of all registered SSID"""
    list_ssid = []
    list_registered_connection = subprocess.Popen([
        'sudo', 'nmcli', 'connection', 'show'],
        stdout=subprocess.PIPE)
    output, error = list_registered_connection.communicate()
    for line in output.decode('utf-8').split(os.linesep):
        if 'wireless' in line:
            list_ssid.append(line.split('  ')[0])
    return list_ssid


def is_ssid_registered(ssid: str) -> bool:
    """Check if the SSID is already registered"""
    list_ssid = get_all_registered_wifi()
    return ssid in list_ssid


def get_all_available_wifi() -> list:
    """Get all currently available wifi"""
    list_available_wifi = []
    subprocess.check_output(['sudo', 'nmcli', 'device', 'wifi', 'rescan'])
    output, error = subprocess.Popen([
        'sudo', 'nmcli', 'device', 'wifi', 'list'],
        stdout=subprocess.PIPE).communicate()
    for line in output.decode('utf-8').split(os.linesep):
        line = line[3:]
        if line != '':
            if (line.split('  ', 2)[0] != "SSID" and
                    line.split('  ', 2)[0] != '--'):
                # Print line
                list_available_wifi.append(line.split('  ', 2)[0])
    # Print list_available_wifi
    list_available_wifi = list(set(list_available_wifi))  # Remove duplicates
    return list_available_wifi


def is_ssid_available(ssid: str) -> bool:
    """Check if the SSID is available"""
    list_available_wifi = get_all_available_wifi()
    return ssid in list_available_wifi


def get_registered_and_available_connection():
    """Get a list of all registered and available WiFi"""
    available_wifi_list = get_all_available_wifi()
    registered_wifi_list = get_all_registered_wifi()
    return [item for item in registered_wifi_list
            if item in available_wifi_list]
