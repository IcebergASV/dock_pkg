#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <string>
#include <cmath>
#include <iostream>
#include <ros/console.h>


class DockChallenge {
public:

    DockChallenge(): nh_(""), private_nh_("~")
    {
        // Get ROS params
        private_nh_.param<std::string>("scan_topic", scan_topic_, "/scan");
        
        // ROS Subscribers 
        sub_scan_ = nh_.subscribe(scan_topic_, 1, &DockChallenge::scanCallback, this);
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

    ros::Subscriber sub_scan_;

    std::string scan_topic_;

    sensor_msgs::LaserScan scan_msg_;

    std::string TAG = "DOCK_PKG: ";


    void scanCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
    {
        scan_msg_ = *msg;
        ROS_WARN_STREAM(TAG << "Package works");
    }
    
};


int main(int argc, char** argv) 
{
    ros::init(argc, argv, "dock_pkg_node");
    if (ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Info))
        ros::console::notifyLoggerLevelsChanged();
    
    DockChallenge dock_challenge;
    dock_challenge.spin();

    return 0;
}