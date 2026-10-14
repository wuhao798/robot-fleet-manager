
#include "Robot.hpp"

#include <iomanip>
#include <iostream>
#include <stdexcept>

Robot::Robot(int id, std::string name, int battery, double maxSpeed)
    : id(id),
      name(name),
      x(0.0),
      y(0.0),
      battery(battery),
      maxSpeed(maxSpeed),
      status(RobotStatus::Idle) {

    if (battery < 0 || battery > 100) {
        throw std::invalid_argument(
            "Battery must be between 0 and 100"
        );
    }

    if (maxSpeed <= 0) {
        throw std::invalid_argument(
            "Maximum speed must be positive"
        );
    }
}

int Robot::getId() const {
    return id;
}

std::string Robot::getName() const {
    return name;
}

double Robot::getX() const {
    return x;
}

double Robot::getY() const {
    return y;
}

int Robot::getBattery() const {
    return battery;
}

double Robot::getMaxSpeed() const {
    return maxSpeed;
}

RobotStatus Robot::getStatus() const {
    return status;
}

void Robot::move(double dx, double dy) {
    if (battery == 0) {
        throw std::runtime_error("Robot has no battery");
    }

    x += dx;
    y += dy;
    status = RobotStatus::Working;
}

void Robot::charge(int amount) {
    if (amount <= 0) {
        throw std::invalid_argument(
            "Charge amount must be positive"
        );
    }

    battery += amount;

    if (battery > 100) {
        battery = 100;
    }

    status = RobotStatus::Charging;
}

void Robot::setIdle() {
    status = RobotStatus::Idle;
}

void Robot::printInfo() const {
    std::cout << std::fixed << std::setprecision(1);

    std::cout << "ID: " << id
              << " | Name: " << name
              << " | Position: (" << x << ", " << y << ")"
              << " | Battery: " << battery << "%"
              << " | Max Speed: " << maxSpeed
              << " | Status: ";

    switch (status) {
        case RobotStatus::Idle:
            std::cout << "Idle";
            break;

        case RobotStatus::Working:
            std::cout << "Working";
            break;

        case RobotStatus::Charging:
            std::cout << "Charging";
            break;
    }

    std::cout << '\n';
}
