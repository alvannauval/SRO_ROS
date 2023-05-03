#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Int32MultiArray.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

void chatterCallbackInt(const std_msgs::Int32& msg)
{
    ROS_INFO("I heard: [%d]", msg.data);
}

void chatterCallbackMultiArray(const std_msgs::Int32MultiArray& msg)
{
    ROS_INFO("I heard: data[0]=%d data[1]=%d data[2]=%d data[3]=%d data[4]=%d ", msg.data.at(0), msg.data.at(1), msg.data.at(2), msg.data.at(3), msg.data.at(4));
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener_node");

    ros::NodeHandle n;

    ros::Subscriber chatter_sub = n.subscribe("chatter", 1000, chatterCallback);
    ros::Subscriber chatter_int_sub = n.subscribe("chatter_int", 1000, chatterCallbackInt);
    ros::Subscriber chatter_multiarray_sub = n.subscribe("chatter_multiarray", 1000, chatterCallbackMultiArray);

    ros::spin();

    return 0;
}