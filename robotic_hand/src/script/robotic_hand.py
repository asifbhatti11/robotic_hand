#!/usr/bin/env python
import rospy
from std_msgs.msg import Int32

last_msg0 = 0
last_msg1 = 0
last_msg2 = 0
last_msg3 = 0
last_msg4 = 0
y0=90
y1=26
y2=65
y3=20
y4=35

def callback0(data):
    global last_msg0,y0
    a=data.data
    if abs(a - last_msg0)>=2:
        last_msg0 = a
	y0=y0-1
	pub0.publish(y0)
    else:
	y0=y0+1
	if y0>=130:
	     y0=130
	if a>=750:
	     y0=90
	pub0.publish(y0)
g
def callback1(data):
    global last_msg1,y1
    a=data.data
    if abs(a - last_msg1)>=2:
        last_msg1 = a
	y1=y1-1
	pub1.publish(y1)
    else:
	y1=y1+2
	if y1>=130:
	     y1=130
	if a>=750:
	     y1=26
	pub1.publish(y1)

def callback2(data):
    global last_msg2,y2
    a=data.data
    if abs(a - last_msg2)>=2:
        last_msg2 = a
	y2=y2-1
	pub2.publish(y2)
    else:
	y2=y2+2
	if y2>=130:
	     y2=130
	if a>=750:
	     y2=65
	pub2.publish(y2)

def callback3(data):
    global last_msg3,y3
    a=data.data
    if abs(a - last_msg3)>=2:
        last_msg3 = a
	y3=y3-1
	pub3.publish(y3)
    else:
	y3=y3+1
	if y3>=130:
	     y3=130
	if a>=750:
	     y3=20
	pub3.publish(y3)

def callback4(data):
    global last_msg4,y4
    a=data.data
    if abs(a - last_msg4)>=2:
        last_msg4 = a
	y4=y4-1
	pub4.publish(y4)
    else:
	y4=y4+1
	if y4>=130:
	     y4=130
	if a>=750:
	     y4=35
	pub4.publish(y4)


rospy.init_node('hand', anonymous=True)
pub0 = rospy.Publisher('talker0', Int32,queue_size=10)
rospy.Subscriber("chatter0", Int32, callback0)
pub1 = rospy.Publisher('talker1', Int32,queue_size=10)
rospy.Subscriber("chatter1", Int32, callback1)
pub2 = rospy.Publisher('talker2', Int32,queue_size=10)
rospy.Subscriber("chatter2", Int32, callback2)
pub3 = rospy.Publisher('talker3', Int32,queue_size=10)
rospy.Subscriber("chatter3", Int32, callback3)
pub4 = rospy.Publisher('talker4', Int32,queue_size=10)
rospy.Subscriber("chatter4", Int32, callback4)
    
rospy.spin()


