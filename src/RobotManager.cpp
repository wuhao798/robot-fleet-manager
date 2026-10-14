
#include "RobotManager.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>

void RobotManager::addRobot(const Robot& robot) {
    auto it = std::find_if(
        robots.begin(),
        robots.end(),
        [&](const Robot& r) {
            return r.getId() == robot.getId();
        }
    );

    if (it != robots.end()) {
        throw std::invalid_argument("Duplicate robot ID");
    }

    robots.push_back(robot);
}

Robot* RobotManager::findRobot(int id) {
    auto it = std::find_if(
        robots.begin(),
        robots.end(),
        [id](const Robot& r) {
            return r.getId() == id;
        }
    );

    if (it == robots.end()) {
        return nullptr;
    }

    return &(*it);
}

void RobotManager::showAll() const {
    if (robots.empty()) {
        std::cout << "No robots registered.\n";
        return;
    }

    for (const Robot& robot : robots) {
        robot.printInfo();
    }
}

void RobotManager::sortByBattery() {
    std::sort(
        robots.begin(),
        robots.end(),
        [](const Robot& a, const Robot& b) {
            return a.getBattery() < b.getBattery();
        }
    );
}

void RobotManager::showLowBattery(int threshold) const {
    std::cout << "Low battery robots (< "
              << threshold << "%):\n";

    bool found = false;

    for (const Robot& robot : robots) {
        if (robot.getBattery() < threshold) {
            robot.printInfo();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No low-battery robots found.\n";
    }
}
