from setuptools import find_packages
from setuptools import setup

setup(
    name='niryo_one_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('niryo_one_msgs', 'niryo_one_msgs.*')),
)
