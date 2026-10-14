
#include "Robot.hpp"
#include "RobotManager.hpp"

#include <exception>
#include <iostream>

int main() {
    try {
        RobotManager manager;

        manager.addRobot(Robot(1, "Alpha", 80, 2.5));
        manager.addRobot(Robot(2, "Beta", 25, 1.8));
        manager.addRobot(Robot(3, "Gamma", 55, 3.0));

        std::cout << "=== All Robots ===\n";
        manager.showAll();

        std::cout << "\n=== Move Robot 1 ===\n";

        Robot* robot = manager.findRobot(1);

        if (robot != nullptr) {
            robot->move(2.0, 3.0);
            robot->printInfo();
        }

        std::cout << "\n=== Charge Robot 2 ===\n";

        robot = manager.findRobot(2);

        if (robot != nullptr) {
            robot->charge(30);
            robot->printInfo();
        }

        std::cout << "\n=== Low Battery ===\n";
        manager.showLowBattery(40);

        std::cout << "\n=== Sort By Battery ===\n";
        manager.sortByBattery();
        manager.showAll();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
