from flask import flash, request, jsonify, Response

from niryo_one_rpi.wifi import flask_app as app
from niryo_one_rpi.wifi.robot_name_handler import *
from niryo_one_rpi.wifi import network_manager as niryo_one_wifi
import json

# This ID will be useful to recognize robot type (Niryo One)
ID_NIRYO_ONE = 1

# Default values, will be replaced with values in setup launch file
HOTSPOT_SSID = "Niryo_One"
HOTSPOT_PASSWORD = "password"


def set_hotspot_ssid(ssid: str) -> None:
    global HOTSPOT_SSID
    HOTSPOT_SSID = ssid


def set_hotspot_password(password: str) -> None:
    global HOTSPOT_PASSWORD
    HOTSPOT_PASSWORD = password


def standard_response(status, message):
    response = jsonify({'detail': message})
    response.status_code = status
    return response


@app.route('/')
def index():
    message = "Instructions: \n"
    message += "/addWifi : Connect to a new Wi-Fi (params: [ssid, password])\n"
    message += "/isItTheRealNiryoOne : todo \n"
    return standard_response(200, message)


@app.route('/availableConnections', methods=['GET'])
def get_available_connections():
    connection_list = niryo_one_wifi.get_all_available_wifi()
    connection_list = filter(lambda c: c != HOTSPOT_SSID, connection_list)
    response = jsonify({'connections': connection_list})
    response.status_code = 200
    return response


@app.route('/registerConnections', methods=['GET'])
def get_registered_connections():
    connection_list = niryo_one_wifi.get_all_registered_wifi()
    connection_list = filter(lambda c: c != HOTSPOT_SSID, connection_list)
    response = jsonify({'connections': connection_list})
    response.status_code = 200
    return response


@app.route('/restartWifi', methods=['POST'])
def restart_wifi():
    niryo_one_wifi.deactivate_current_wlan0()
    niryo_one_wifi.activate_current_wlan0()
    return standard_response(200, "Wifi has been restarted")


@app.route('/removeConnection', methods=['POST'])
def delete_connection():
    params = request.get_json()
    if not params:
        return standard_response(400, "No SSID given")
    ssid = params.get('ssid', None)
    if ssid is None:
        return standard_response(400, "No SSID given")

    # Check is SSID = current SSID
    current_ssid = niryo_one_wifi.get_current_ssid()
    if current_ssid == ssid:
        return standard_response(
            400,
            "Niryo One is currently connected to this SSID. Please " +
            "connect the robot to another SSID, or switch to 'hotspot " +
            "mode', and retry")

    if niryo_one_wifi.delete_connection_with_ssid(ssid):
        return standard_response(200, "Connection has been removed")
    else:
        return standard_response(400, "Unable to remove this connection")


@app.route('/switchToHotspot', methods=['POST'])
def switch_to_hotspot_mode():
    if niryo_one_wifi.get_current_ssid() == HOTSPOT_SSID:
        return standard_response(200, "Hotspot mode already activated")
    success = niryo_one_wifi.hard_enable_hotspot_with_ssid(
        HOTSPOT_SSID, HOTSPOT_PASSWORD)
    if success:
        return standard_response(200, "Hotspot mode activated")
    return standard_response(400, "Failed to activate hotspot mode")


@app.route('/addWifi', methods=['POST'])
def add_wifi():
    params = request.get_json()
    if not params:
        return standard_response(400, "No parameters given")
    ssid = params.get('ssid', None)
    password = params.get('password', None)
    name = params.get('name', '')
    if ssid is None or password is None:
        return standard_response(400, "No SSID or password given")

    if niryo_one_wifi.connect_to_wifi(ssid, password):
        write_robot_name(str(name))
    else:
        niryo_one_wifi.hard_enable_hotspot_with_ssid(
            HOTSPOT_SSID, HOTSPOT_PASSWORD)
    return standard_response(200, "Successfully changed Wi-Fi")


@app.route('/isItTheRealNiryoOne', methods=['GET'])
def is_it_the_real_niryo_one():
    response = jsonify({
        'type': ID_NIRYO_ONE,
        'name': read_robot_name()
    })
    response.status_code = 200
    return response
