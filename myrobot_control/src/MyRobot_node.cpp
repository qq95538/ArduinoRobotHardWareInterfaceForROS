#include <ros/ros.h>
#include <MyRobot.h>
#include <controller_manager/controller_manager.h>
int main(int argc, char** argv){
	ros::init(argc, argv, "my_robot");
	MyRobotHardwareInterface::MyRobot robot;
	controller_manager::ControllerManager cm(&robot);
	ros::AsyncSpinner spinner(1);
	spinner.start();
	ros::Time prev_time = ros::Time::now();
	ros::Rate rate(10.0);
	while(ros::ok()){
		const ros::Time time = ros::Time::now();
		const ros::Duration period = time - prev_time;
		robot.read();
		cm.update(time, period);
		prev_time = time;
		robot.write();
		rate.sleep();
	}
	rate.sleep();
}
