#include "robot_manager_composition/robot_manager_composition.h"
#include "robot_manager_composition/system_information.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "robot_manager_composition_node");

    ros::NodeHandle nh;
    ComputerUnit cm;
    RobotManagerComposition rmc_node(&nh, cm);

    ros::spin();

    return 0;
}