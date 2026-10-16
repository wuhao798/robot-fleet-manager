
#include "Robot.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>

int main() {
    // Test 1: Constructor stores the battery correctly.
    Robot robot(1, "Alpha", 80, 2.5);
    assert(robot.getBattery() == 80);

    // Test 2: Charging cannot exceed 100%.
    robot.charge(50);
    assert(robot.getBattery() == 100);

    // Test 3: Invalid charging amount should throw.
    bool exceptionThrown = false;

    try {
        robot.charge(0);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // Test 4: Movement updates the position.
    robot.move(2.0, 3.0);
    assert(robot.getX() == 2.0);
    assert(robot.getY() == 3.0);

    // Test 5: Invalid battery should throw.
    exceptionThrown = false;

    try {
        Robot invalidRobot(2, "Invalid", 101, 2.0);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // Test 6: Invalid maximum speed should throw.
    exceptionThrown = false;

    try {
        Robot invalidRobot(3, "InvalidSpeed", 50, 0.0);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // Test 7: A robot with zero battery cannot move.
    Robot emptyRobot(4, "Empty", 0, 2.0);
    exceptionThrown = false;

    try {
        emptyRobot.move(1.0, 1.0);
    } catch (const std::runtime_error&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);
    assert(emptyRobot.getX() == 0.0);
    assert(emptyRobot.getY() == 0.0);

    std::cout << "All Robot tests passed!\n";
    return 0;
}

