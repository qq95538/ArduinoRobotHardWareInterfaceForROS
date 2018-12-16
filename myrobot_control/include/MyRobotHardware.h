#ifndef MyrobotCPP__Myrobot_H
#define MyrobotCPP__Myrobot_H

#include <sstream>
#include <joint.h>

namespace MyRobotHardwareInterface{
	class MyRobotHardware{
		private:
		public:
			MyRobotHardware();
			~MyRobotHardware();
			Joint joints[2];
			Joint getJoint(std::string jointName);
			void setJoint(Joint joint);
	};

}
#endif
