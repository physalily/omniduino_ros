#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <string>
#include <math.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "lift");
    ros::NodeHandle n;
    ros::NodeHandle pn("~");
    
    // pub
    ros::Publisher pub0 = n.advertise<std_msgs::Float64>("sus0", 10);
    ros::Publisher pub1 = n.advertise<std_msgs::Float64>("sus1", 10);
    ros::Publisher pub2 = n.advertise<std_msgs::Float64>("sus2", 10);
    ros::Publisher pub3 = n.advertise<std_msgs::Float64>("sus3", 10);

    ros::Duration(1.5).sleep();
    ros::Rate loop_rate(50);

    int counter=0;
    int litf_step=50;
    std_msgs::Float64 command_pos;
    command_pos.data = 0;

    ROS_INFO("starting lift up...");
    while (ros::ok())
    {
        pub0.publish(command_pos);
        pub1.publish(command_pos);
        pub2.publish(command_pos);
        pub3.publish(command_pos);

        counter++;

        ros::spinOnce();
        loop_rate.sleep();
    }
    ROS_INFO("ended lift up.");

    return 0;
}