#include "ros/ros.h"
#include "std_msgs/Int32MultiArray.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker_multiarray_node");
    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<std_msgs::Int32MultiArray>("chatter_multiarray", 1000);

    ros::Rate rate(10);

    int count[5] = {0, 1, 2, 3, 4};

    while(ros::ok())
    {
        std_msgs::Int32MultiArray msg;

        msg.data = {0, 0, 0, 0, 0};

        for (int i = 0; i < 5; i++)
        {
            msg.data.at(i) = count[i];

            // msg.data.push_back(count[i]);
            count[i]++;
        }

        ROS_INFO("I sent data[0]=%d data[1]=%d data[2]=%d data[3]=%d data[4]=%d", msg.data.at(0), msg.data.at(1), msg.data.at(2), msg.data.at(3), msg.data.at(4));

        chatter_pub.publish(msg);

        ros::spinOnce();

        rate.sleep();
    }

    return 0;
}