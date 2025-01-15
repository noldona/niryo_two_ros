# Niryo One Raspberry Pi 5

This package handles all the external hardware (everything other than the motors)
of the Niryo One and provides utilities for the Raspberry Pi 5:
* Digital I/O Panel: Get commands and sends the current state of the digital
I/Os. Also controls tools like the electromagnet.
* Fans: Controls the fans.
* LED: Set the LED color.
* Top Button: Executes actions when the button is pressed.
* Wi-Fi: Handles the Raspberry Pi 5 Wi-Fi connection (connected to a local network,
or in hotspot mode).
* ROS Log: Can remove all previous logs on startup to prevent a lack of disk
space in the long run (SD cards do not have infinite storage).
* ROS Setup: Can launch different processes and launch files from code, with the
possibility to add a delay before launching. Practical on the Raspberry Pi where
the computation power is quite low compared to a standard laptop.

Note This package should not be used when you are using Niryon One ROS stack on
your computer in simulation mode.
