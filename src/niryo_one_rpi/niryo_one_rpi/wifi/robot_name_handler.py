import os

#
# Feature to set a name for the robot (different than "Niryp One")
# - Will appear on WiFi and ROS connection (todo)
#

# Default value, will be replaced with value in setup launch file
FILENAME = '/home/niryo/niryo_one_saved_values/robot_name.txt'


def get_filename_robot_name():
    return FILENAME


def set_filename_robot_name(filename):
    global FILENAME
    FILENAME = filename


def read_robot_name():
    if os.path.isfile(FILENAME):
        with open(FILENAME, 'r') as f:
            for line in f:
                if not (line.startswith('#') or len(line) == 0):
                    name = line.rstrip()
                    return name

    return ''


def write_robot_name(name):
    try:
        with open(FILENAME, 'w') as f:
            comment = "# THIS IS A GENERATED FILE\n"
            comment += "# Here is the name the user gave to this robot\n"
            comment += "# This name does not affect anything,\n"
            comment += "# it is only useful for user to easily recognize"
            comment += " the robot on desktop/mobile apps\n"
            f.write(comment)
            f.write(name)
            f.close()
            return True
    except Exception as e:
        print(e)
        return False
