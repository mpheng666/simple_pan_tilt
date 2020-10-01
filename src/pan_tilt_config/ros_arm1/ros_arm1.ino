#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>
#include <sensor_msgs/JointState.h>

ros::NodeHandle  nh;
//Servo base_servo;
Servo pan_servo;
Servo tilt_servo;

//double base_angle=90;
double pan_angle=90;
double tilt_angle=90;

void servo_cb(const sensor_msgs::JointState& cmd_msg){
//  base_angle=radiansToDegrees(cmd_msg.position[0]);
  pan_angle=radiansToDegrees(cmd_msg.position[0]);
  tilt_angle=radiansToDegrees(cmd_msg.position[1]);
  
//  base_servo.write(base_angle);
  pan_servo.write(pan_angle);
  tilt_servo.write(tilt_angle);

}


ros::Subscriber<sensor_msgs::JointState> sub("joint_states", servo_cb);

void setup(){
  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.subscribe(sub);

//  base_servo.attach(2); 
  pan_servo.attach(7); 
  tilt_servo.attach(8);

  delay(1);
//  base_servo.write(90);
  pan_servo.write(90);
  tilt_servo.write(90);

}

void loop(){
  nh.spinOnce();
}

double radiansToDegrees(float position_radians)
{

  position_radians = position_radians + 1.6;

  return position_radians * 57.2958;

}
