from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'niryo_one_bringup'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(
            os.path.join('launch', '*launch.[pxy][yma]*'))),
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml')),
        (os.path.join('share', package_name, 'config', 'v1'), glob('config/v2/*.yaml')),
        (os.path.join('share', package_name, 'config', 'v2'), glob('config/v2/*.yaml'))
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
        ],
    },
)
