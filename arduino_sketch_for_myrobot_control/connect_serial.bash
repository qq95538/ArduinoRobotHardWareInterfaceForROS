sudo chmod 777 /dev/ttyACM0
rosrun rosserial_python serial_node.py /dev/ttyACM0 _baud:=500000
