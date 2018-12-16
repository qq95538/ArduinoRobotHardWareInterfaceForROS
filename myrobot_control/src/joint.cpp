#include <stdlib.h>
#include <math.h>
#include <stdexcept>
#include "ros/ros.h"
#include <joint.h>

#define PI 3.14159

namespace MyRobotHardwareInterface{
	Joint::Joint(){
	}
	Joint::Joint(uint8_t motorId){
		_motorId = 0;
		_actuatorType = ACTUATOR_TYPE_SERVO;
		_minServoValue = 0;
		_maxServoValue = 180;
		_angleReads = 0;
		angleOffset = 0;
		readRatio = 1;
		setMotorId(motorId);
	}
	Joint::~Joint(){
	}
	void Joint::setActuatorType(uint8_t actuatorType){
		this->_actuatorType = actuatorType;
	}
	void Joint::setMotorId(uint8_t motorId){
		this->_motorId = motorId;
	}
	void Joint::setServoLimits(uint8_t minValue, uint8_t maxValue){
		this->_minServoValue = minValue;
		this->_maxServoValue = maxValue;
	}	
	int Joint::getActuatorType(){
		return _actuatorType;
	}
	void Joint::actuate(double effort){
		if (_actuatorType == ACTUATOR_TYPE_SERVO){
				effort = (effort + 1.5708) / PI;
				if (effort > 1.0) effort = 1.0;
				if (effort < 0.0) effort = 0.0;
				double magnitude = effort * 100.0;
				uint8_t servoValue = floor(_minServoValue + ((_maxServoValue - _minServoValue) * (magnitude / 100.0)));
				_angleReads = servoValue;
				ROS_INFO("motorId: [%i]; servoValue: [%i];", _motorId, servoValue);
		}
	}
	double Joint::readAngle(){
		if(_actuatorType == ACTUATOR_TYPE_SERVO){
			return _angleReads;
		}
	}	

}
