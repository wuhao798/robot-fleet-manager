
#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <string>

enum class RobotStatus {
    Idle,
    Working,
    Charging
};

class Robot {
private:
    int id;
    std::string name;
    double x;
    double y;
    int battery;
    double maxSpeed;
    RobotStatus status;

public:
    Robot(int id, std::string name, int battery, double maxSpeed);

    int getId() const;
    std::string getName() const;
    double getX() const;
    double getY() const;
    int getBattery() const;
    double getMaxSpeed() const;
    RobotStatus getStatus() const;

    void move(double dx, double dy);
    void charge(int amount);
    void setIdle();
    void printInfo() const;
};

#endif
