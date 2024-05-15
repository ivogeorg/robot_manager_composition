#include "robot_manager_composition/robot_manager_composition.h"
#include <ros/ros.h>
#include <std_srvs/SetBool.h>
#include <string>

RobotManagerComposition::RobotManagerComposition(bool enabled) :
    output_enabled_{enabled},
    enable_srv_{nh_.advertiseService("robot_manager_output", &RobotManagerComposition::serviceCallback, this)} {

    ROS_INFO("/robot_manager_output service: READY");
}

bool RobotManagerComposition::serviceCallback(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res) {
    output_enabled_ = req.data;

    std::string msg{"/robot_manager_output service: robot output "};
    if (output_enabled_)
        msg += "enabled";
    else
        msg += "disabled";
    ROS_INFO("%s", msg.c_str());

    res.success = true;
    res.message = msg;

    return true;
}