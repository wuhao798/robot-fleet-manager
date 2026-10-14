
#ifndef ROBOT_MANAGER_HPP
#define ROBOT_MANAGER_HPP

#include "Robot.hpp"

#include <vector>

class RobotManager {
private:
    std::vector<Robot> robots;

public:
    void addRobot(const Robot& robot);
    Robot* findRobot(int id);

    void showAll() const;
    void sortByBattery();
    void showLowBattery(int threshold) const;
};

#endif
