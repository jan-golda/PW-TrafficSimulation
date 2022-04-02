#ifndef PW_TRAFFICSIMULATION_SIMULATIONWINDOW_H
#define PW_TRAFFICSIMULATION_SIMULATIONWINDOW_H


#include <SFML/Graphics.hpp>
#include "map/Map.h"

class SimulationWindow {
private:
    sf::RenderWindow window;
    map::Map map;

    void handleEvents();
    void update(float elapsed);
    void draw();

public:
    SimulationWindow();
    void run();
};


#endif //PW_TRAFFICSIMULATION_SIMULATIONWINDOW_H
