#ifndef MyrobotCPP__JOINT_H
#define MyrobotCPP__JOINT_H

#include <sstream>

#define ACTUATOR_TYPE_NONE -1
#define ACTUATOR_TYPE_SERVO 1



namespace MyRobotHardwareInterface{
	class Joint
	{
		private:
			uint8_t _motorId;
			uint8_t _actuatorType;
			uint8_t _minServoValue;
			uint8_t _maxServoValue;
			int _angleReads;
			static const int _filterPrevious = 3;
			double _previousAngles[_filterPrevious];

		public:
			std::string name;
			Joint();
			Joint(uint8_t motorId);
			~Joint();
			double angleOffset;
			double readRatio;
			uint8_t getMotorId();
			void setMotorId(uint8_t motorId);
			void setActuatorType(uint8_t actuatorType);
			void setServoLimits(uint8_t minValue, uint8_t maxValue);
			int getActuatorType();
			void actuate(double effort);
			double readAngle();
	};
}



#endif
