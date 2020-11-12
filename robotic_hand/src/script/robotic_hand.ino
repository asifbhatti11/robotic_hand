#include <ros.h>
#include <std_msgs/Int32.h>
#include <Servo.h>
Servo myservo0,myservo1,myservo2,myservo3,myservo4;  // create servo object to control a servo
float servo0,servo1,servo2,servo3,servo4;
ros::NodeHandle nh; 
int t;

void servo0Cb(const std_msgs::Int32 &msg0)
{
  servo0=msg0.data;
  myservo0.write(servo0);

}
void servo1Cb(const std_msgs::Int32 &msg1)
{
  servo1=msg1.data;
  myservo1.write(servo1);
}
void servo2Cb(const std_msgs::Int32 &msg2)
{
  servo2=msg2.data;
  myservo2.write(servo2);
}
void servo3Cb(const std_msgs::Int32 &msg3)
{
  servo3=msg3.data;
  myservo3.write(servo3);
}
void servo4Cb(const std_msgs::Int32 &msg4)
{
  servo4=msg4.data;
  myservo4.write(servo4);
}

 
ros::Subscriber<std_msgs::Int32> sub0("talker0", &servo0Cb);
ros::Subscriber<std_msgs::Int32> sub1("talker1", &servo1Cb);
ros::Subscriber<std_msgs::Int32> sub2("talker2", &servo2Cb);
ros::Subscriber<std_msgs::Int32> sub3("talker3", &servo3Cb);
ros::Subscriber<std_msgs::Int32> sub4("talker4", &servo4Cb);

std_msgs::Int32 fsr0;
ros::Publisher chatter0("chatter0", &fsr0);
std_msgs::Int32 fsr1;
ros::Publisher chatter1("chatter1", &fsr1);
std_msgs::Int32 fsr2;
ros::Publisher chatter2("chatter2", &fsr2);
std_msgs::Int32 fsr3;
ros::Publisher chatter3("chatter3", &fsr3);
std_msgs::Int32 fsr4;
ros::Publisher chatter4("chatter4", &fsr4);
void setup()
{
  Serial.begin(57600);
  myservo0.attach(2);
  myservo1.attach(3);
  myservo2.attach(4);
  myservo3.attach(5);
  myservo4.attach(6);
  nh.initNode();
  nh.subscribe(sub0);
  nh.subscribe(sub1);
  nh.subscribe(sub2);
  nh.subscribe(sub3);
  nh.subscribe(sub4);
  nh.advertise(chatter0);
  nh.advertise(chatter1);
  nh.advertise(chatter2);
  nh.advertise(chatter3);
  nh.advertise(chatter4);
}
 
void loop()
{
  
  fsr0.data = analogRead(A0);
  fsr1.data = analogRead(A1);
  fsr2.data = analogRead(A2);
  fsr3.data = analogRead(A3);
  fsr4.data = analogRead(A4);
  chatter0.publish(&fsr0);
  nh.spinOnce();
  chatter1.publish(&fsr1);
  nh.spinOnce();
  chatter2.publish(&fsr2);
  nh.spinOnce();
  chatter3.publish(&fsr3);
  nh.spinOnce();
  chatter4.publish(&fsr4);
  nh.spinOnce();
  delay(100);
}
