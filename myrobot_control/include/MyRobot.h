#ifndef ROS_CONTROL__ROBOT_HARDWARE_H
#define ROS_CONTROL__ROBOT_HARDWARE_H

#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/robot_hw.h>

namespace MyRobotHardwareInterface{
    /// \brief Hardware interface for a robot
    class MyRobot : public hardware_interface::RobotHW {
	public:
		MyRobot();
		~MyRobot();
		void read();
		void write();
	private: 
		// Interfaces
		hardware_interface::JointStateInterface joint_state_interface;
		hardware_interface::PositionJointInterface joint_position_interface;
		double cmd[2];
		double pos[2];
		double vel[2];
		double eff[2];

    }; // class

} // end namespace
#endif
