#include <MyRobot.h>

namespace MyRobotHardwareInterface{
	MyRobot::MyRobot(){
		hardware_interface::JointStateHandle state_handle_a("j1", &pos[0], &vel[0], &eff[0]);
		joint_state_interface.registerHandle(state_handle_a);
		hardware_interface::JointStateHandle state_handle_b("j2", &pos[1], &vel[1], &eff[1]);
		joint_state_interface.registerHandle(state_handle_b);
		registerInterface(&joint_state_interface);
		hardware_interface::JointHandle position_handle_a(joint_state_interface.getHandle("j1"), &cmd[0]);
		joint_position_interface.registerHandle(position_handle_a);
		hardware_interface::JointHandle position_handle_b(joint_state_interface.getHandle("j2"), &cmd[1]);
		joint_position_interface.registerHandle(position_handle_b);
		registerInterface(&joint_position_interface);
	}
	MyRobot::~MyRobot(){
	}
	void MyRobot::read(){
		pos[0] = cmd[0]/3.14;
		pos[1] = cmd[1]/3.14;  
	}
	void MyRobot::write(){
		//ROS_INFO("myrobot_control_hardware_interface write: pos[0], pos[1] %f, %f\n", pos[0], pos[1]);
	}

}
		
