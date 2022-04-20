cmake_minimum_required(VERSION 3.21)
project(PW_TrafficSimulation)

set(CMAKE_CXX_STANDARD 17)

find_package(glm REQUIRED)

add_executable(
        PW_TrafficSimulation src/main.cpp
        src/vis/Window.cpp src/vis/Window.h
        src/vis/entities/Entity.cpp src/vis/entities/Entity.h
        src/vis/entities/Car.h
        src/vis/entities/Pedestrian.h
        src/sim/TrafficEntity.cpp src/sim/TrafficEntity.h
        src/vis/Map.cpp src/vis/Map.h
        src/sim/TrafficSimulation.cpp src/sim/TrafficSimulation.h
        src/sim/TrafficNode.cpp src/sim/TrafficNode.h
        src/sim/dispatchers/TrafficDispatcher.h
        src/sim/dispatchers/MatrixDispatcher.h
        src/sim/dispatchers/OneWayStraightDispatcher.h
        src/vis/MapSegment.h
        src/vis/segments/OneWayRoad.cpp src/vis/segments/OneWayRoad.h
)

target_link_libraries(PW_TrafficSimulation sfml-graphics sfml-window sfml-system glm)
