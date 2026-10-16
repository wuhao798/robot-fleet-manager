
#ifndef ROBOT_MANAGER_HPP
#define ROBOT_MANAGER_HPP

#include "Robot.hpp"

#include <vector>

class RobotManager {
private:
    std::vector<Robot> robots;

public:
    void addRobot(const Robot& robot);

// Returns a pointer to the robot, or nullptr if not found.
// The pointer must not be used after operations that may
// invalidate or change the identity of vector elements,
// such as adding a robot or sorting the collection.
    Robot* findRobot(int id);

    void showAll() const;
    void sortByBattery();
    void showLowBattery(int threshold) const;
};

#endif
