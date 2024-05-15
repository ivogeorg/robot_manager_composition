#include "robot_manager_composition/robot_manager_composition.h"
#include <ros/ros.h>
#include <std_srvs/SetBool.h>
#include <string>

RobotManagerComposition::RobotManagerComposition(bool enabled)
    : output_enabled_{enabled}, enable_srv_{nh_.advertiseService(
                                    "robot_manager_output",
                                    &RobotManagerComposition::serviceCallback,
                                    this)} {

  ROS_INFO("/robot_manager_output service: READY");
}

bool RobotManagerComposition::serviceCallback(
    std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res) {
  // Check if the request matches the current
  // state and report service failure
  if (req.data == output_enabled_) {
    std::string msg{"/robot_manager_output service: console output already "};
    if (output_enabled_)
      msg += "enabled";
    else
      msg += "disabled";
    ROS_WARN("%s", msg.c_str());

    res.success = false;
    res.message = msg;

    return false;
  } else { // Request will change the state
    output_enabled_ = req.data;

    std::string msg{"/robot_manager_output service: console output "};
    if (output_enabled_)
      msg += "enabled";
    else
      msg += "disabled";
    ROS_INFO("%s", msg.c_str());

    res.success = true;
    res.message = msg;

    return true;
  }
}