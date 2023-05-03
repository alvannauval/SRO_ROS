#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker_int_node");
    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("chatter_int", 1000);

    ros::Rate rate(10);

    int count = 0;

    while(ros::ok())
    {
        std_msgs::Int32 msg;

        msg.data = count;

        ROS_INFO("I sent %d", msg.data);

        chatter_pub.publish(msg);

        ros::spinOnce();

        rate.sleep();
        
        count++;
    }

    return 0;
}