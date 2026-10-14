
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

    std::cout << "All Robot tests passed!\n";
    return 0;
}
