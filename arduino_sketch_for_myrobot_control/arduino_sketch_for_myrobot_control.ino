/* 
 * rosserial Subscriber Example
 * turn a Servo on callback
 * Burn the following sketch to a Arduino 2560 board with a servo connected on Pin6.  
 * Enter a command of "rosrun rosserial_python serial_node.py /dev/ttyUSB__" to create a rosserial node communicating with the Arduino board.  
 * The node subsrcibes Topic 'JointStates' and the arduino board, turns the servo on Pin6 to the joint angle of the topic. 
 */

#include <ros.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/Float64.h>

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  500 // this is the 'maximum' pulse length count (out of 4096)
#define SERVONUM 7
// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

ros::NodeHandle  nh;

void messageCb(const sensor_msgs::JointState& msg){
  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
  uint16_t pulselength[SERVONUM];
  for(int i = 0; i < SERVONUM; i++){
    pulselength[i] = map(msg.position[i] * 1000, -1.57 * 1000, 1.57 * 1000, SERVOMIN, SERVOMAX);
    pwm.setPWM(i, 0, pulselength[i]);
  }  
}

ros::Subscriber<sensor_msgs::JointState> sub("/joint_states", &messageCb );

void setup()
{ 
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(10);

  digitalWrite(13, 1);
  uint16_t pulselength[SERVONUM];
  for(int i = 0; i < SERVONUM; i++){
    pwm.setPWM(i, 0, (SERVOMIN+SERVOMAX)/2);
  }

}

void loop()
{ 
  nh.spinOnce();
  delay(1);
}

