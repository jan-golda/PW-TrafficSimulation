#ifndef PW_TRAFFICSIMULATION_SIMULATIONWINDOW_H
#define PW_TRAFFICSIMULATION_SIMULATIONWINDOW_H


#include <SFML/Graphics.hpp>

class SimulationWindow {
private:
    sf::RenderWindow window;
    void handleEvents();
public:
    SimulationWindow();
    void run();
};


#endif //PW_TRAFFICSIMULATION_SIMULATIONWINDOW_H
