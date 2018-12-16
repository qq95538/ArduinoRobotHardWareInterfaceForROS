#include "ros/ros.h"
#include <stdexcept>
#include <MyRobotHardware.h>
#include <joint.h>
namespace MyRobotHardwareInterface{
	MyRobotHardware::MyRobotHardware(){
		joints[0].name = "YOUR_ROBOT_JOINT";
		joints[0].setMotorId(0);
		joints[1].name = "YOUR_OTHER_ROBOT_JOINT";
		joints[1].setMotorId(1);

	}
	MyRobotHardware::~MyRobotHardware(){
	}
	Joint MyRobotHardware::getJoint(std::string jointName){
		for (int i = 0; i < 2; i++){
			if(joints[i].name == jointName){
				return joints[i];
			}
		}
	throw std::runtime_error("Could not find joint with name: " + jointName);
	}
	void MyRobotHardware::setJoint(Joint joint){
		bool foundJoint = false;
		for (int i = 0; i < 2; i++){
			if(joints[i].name == joint.name){
				foundJoint = true;
				joints[i] = joint;
			}
		}
		if (foundJoint == false){
			throw std::runtime_error("Could not find joint with name: " + joint.name);
		}
	}
}
