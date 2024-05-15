#include "robot_manager_composition/robot_manager_composition.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "robot_manager_composition_node");

    ros::NodeHandle nh;
    RobotManagerComposition rmc_node(&nh);

    ros::spin();

    return 0;
}