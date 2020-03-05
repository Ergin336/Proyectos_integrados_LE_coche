#!/usr/bin/env python
# license removed for brevity

import rospy
from std_msgs.msg import Float64

def callback(msg):
	distancia = rospy.loginfo("{}".format(msg.data))
	return distancia

def memory_subscriber():
	rospy.init_node("subscriptor", anonymous=True)
	rospy.Subscriber("chatter", Float64, callback)
	rospy.spin()

if __name__ == "__main__":
	try:
		memory_subscriber()
	except rospy.ROSInterruptException:
		pass