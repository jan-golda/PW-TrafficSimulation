cmake_minimum_required(VERSION 3.21)
project(PW_TrafficSimulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(PW_TrafficSimulation src/main.cpp src/SimulationWindow.cpp src/SimulationWindow.h)
target_link_libraries(PW_TrafficSimulation sfml-graphics sfml-window sfml-system)
