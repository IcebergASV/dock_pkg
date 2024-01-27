#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <string>
#include <iostream>

class DockChallenge {
public:

    DockChallenge(): nh_(""), private_nh_("~")
    {
        // Anything you have to subscribe to come here.
        private_nh_.param<std::string>("scan_topic", scan_topic_, "/laser/scan");
        // prop_sub = nh_.subscribe("/prop_array", 1, &SpeedChallenge::propCallback, this);
    }

    void spin() 
    {
        ros::Rate rate(10); // 10 Hz
        while (ros::ok()) {
            ros::spinOnce();
            rate.sleep();        
        }
    }

private:

    ros::NodeHandle nh_;
    ros::NodeHandle private_nh_;
    // Change subscriber as needed
    // ros::Subscriber prop_sub;

    // Change below too as needed
    /*
    prop_mapper::PropArray prop_array_test;
    prop_mapper::PropArray prop_array;

    void propCallback(const prop_mapper::PropArray msg)
    {
        prop_array_test = msg;
    }
    */
};


int main(int argc, char** argv) 
{
    ros::init(argc, argv, "dock_challenge_node");
    if (ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug))
        ros::console::notifyLoggerLevelsChanged();
    
    DockChallenge dock_challenge;
    dock_challenge.spin();

    return 0;
}