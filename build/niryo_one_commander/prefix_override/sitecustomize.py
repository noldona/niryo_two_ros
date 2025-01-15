import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/noldona/niryo/niryo_two_ros/install/niryo_one_commander'
