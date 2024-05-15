#include "robot_manager_composition/robot_manager_composition.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "robot_manager_composition_node");

    RobotManagerComposition rmc_node(false);

    ros::spin();

    return 0;
}