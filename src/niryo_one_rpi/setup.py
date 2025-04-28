from setuptools import find_packages, setup
from glob import glob
import os

package_name = 'niryo_one_rpi'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='noldona',
    maintainer_email='noldona@gmail.com',
    description='TODO: Package description',
    license='GPL-3.0-only',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "digital_io_panel = niryo_one_rpi.digital_io_panel:main",
            "fans_manager = niryo_one_rpi.fans_manager:main",
            "led_manager = niryo_one_rpi.led_manager:main",
            "niryo_one_button = niryo_one_rpi.niryo_one_button:main",
            "shutdown_manager = niryo_one_rpi.shutdown_manager:main",
            "motor_debug = niryo_one_rpi.motor_debug:main",
            "ros_logs_manager = niryo_one_rpi.ros_logs_manager:main",
            "wifi_conntection = niryo_one_rpi.wifi_connection:main",
        ],
    },
)
