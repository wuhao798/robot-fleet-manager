
#include "RobotManager.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>

int main() {
    RobotManager manager;

    Robot alpha(1, "Alpha", 80, 2.5);
    Robot beta(2, "Beta", 25, 1.8);
    Robot gamma(3, "Gamma", 55, 3.0);

    // Test 1: Add robots successfully.
    manager.addRobot(alpha);
    manager.addRobot(beta);
    manager.addRobot(gamma);

    // Test 2: Find an existing robot.
    Robot* robot = manager.findRobot(2);
    assert(robot != nullptr);
    assert(robot->getName() == "Beta");
    assert(robot->getBattery() == 25);

    // Test 3: Return nullptr when the robot does not exist.
    assert(manager.findRobot(999) == nullptr);

    // Test 4: Adding a duplicate ID should throw.
    bool exceptionThrown = false;

    try {
        Robot duplicate(1, "Duplicate", 50, 2.0);
        manager.addRobot(duplicate);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // Test 5: Sort robots by battery, from low to high.
    manager.sortByBattery();

    // Find robots again after sorting.
    // Do not reuse pointers obtained before sorting.
    Robot* first = manager.findRobot(2);
    Robot* second = manager.findRobot(3);
    Robot* third = manager.findRobot(1);

    assert(first != nullptr);
    assert(second != nullptr);
    assert(third != nullptr);

    assert(first->getBattery() == 25);
    assert(second->getBattery() == 55);
    assert(third->getBattery() == 80);

    std::cout << "All RobotManager tests passed!\n";
    return 0;
}
