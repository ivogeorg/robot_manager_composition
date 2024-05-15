#ifndef ROBOT_MANGER_COMPOSITION_H
#define ROBOT_MANGER_COMPOSITION_H

// #include "system_information.h"
#include "ros/node_handle.h"
#include "ros/service_server.h"
#include <ros/ros.h>
#include <std_srvs/SetBool.h>

class RobotManagerComposition {
    bool output_enabled_ = false;
    ros::NodeHandle nh_;
    ros::ServiceServer enable_srv_;

public:
    RobotManagerComposition(bool enabled);
    ~RobotManagerComposition() = default;

    bool serviceCallback(std_srvs::SetBool::Request &req,
    std_srvs::SetBool::Response &res);
};


#endif