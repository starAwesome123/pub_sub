#include <ros/ros.h>
#include <std_msgs/Float64.h>
// Define a function called 'callback' that receives a parameter named 'msg'
//the const is a way tell the tybe of msg wont change and the msg itself from user
void counterCallback(const std_msgs::Float64::ConstPtr& msg)
{
// msg->data pointer
ROS_INFO("%f", msg->data); // Print the value 'data' inside the 'msg' parameter
}
int main(int argc, char **argv) {
ros::init(argc, argv, "subscriber_node"); // Initiate a Node called 'topic_subscriber'
ros::NodeHandle nh;
/* Create a Subscriber object that will listen to the /counter topic and will
call the 'callback' function each time it reads something from the topic */
ros::Subscriber sub = nh.subscribe("heading_angle", 1000, counterCallback);
ros::spin(); // Create a loop that will keep the program in execution
return 0;
}
