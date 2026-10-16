
cmake_minimum_required(VERSION 3.16)

project(RobotFleetManager
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(robot_fleet_manager
    src/main.cpp
    src/Robot.cpp
    src/RobotManager.cpp
)

target_include_directories(robot_fleet_manager
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(robot_fleet_manager
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

enable_testing()

add_executable(robot_test
    tests/robot_test.cpp
    src/Robot.cpp
)

target_include_directories(robot_test
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(robot_test
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

add_test(NAME RobotTest COMMAND robot_test)
add_executable(robot_manager_test
    tests/robot_manager_test.cpp
    src/Robot.cpp
    src/RobotManager.cpp
)

target_include_directories(robot_manager_test
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(robot_manager_test
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

add_test(
    NAME RobotManagerTest
    COMMAND robot_manager_test
)
