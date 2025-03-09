from setuptools import find_packages, setup

package_name = 'niryo_one_commander'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    package_dir={'': 'src'},
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ericlashley',
    maintainer_email='ericlashley@rocketmail.com',
    description='Interface between user and Moveit! to easily control Niryo One (arm + tools). Validates params, checks if previous trajectory has not finished, ...',
    license='GPL-3.0-only',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'niryo_one_commander_node = niryo_one_commander:main',
        ],
    },
)
