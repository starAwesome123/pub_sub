#include <ros/ros.h>
#include <std_msgs/Float64.h>

// Import all the necessary ROS libraries from the std_msgs package
int main(int argc, char** argv) {
    
    ros::init(argc, argv, "publisher_node"); // Initiate a Node named 
//It's an interface. like a class that i call to create the node
    ros::NodeHandle nh;
    /* Create a Publisher object, that will // publish on the /counter topic messages 
    */
    ros::Rate loop_rate(2); // Set a publish rate of 2 Hz
    // create a variable to publish mesgs.
    ros::Publisher pub = nh.advertise<std_msgs::Float64>("heading_angle", 1000);
    std_msgs::Float64 count; // Create a variable of type Float64
    count.data = 0.1; // Initialize 'count' variable
    
    while (ros::ok()) // Create a loop that will go until someone stops the program execution
        {
        pub.publish(count); // Publish the message within the 'count' variable
        ROS_INFO_STREAM("Heading angle: " << count);
        ros::spinOnce();
        loop_rate.sleep(); // Make sure the publish rate maintains at 2 Hz
        ++count.data; // Increment 'count' variable
        }
    return 0;
}
