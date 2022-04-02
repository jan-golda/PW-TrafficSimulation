#include "SimulationWindow.h"

SimulationWindow::SimulationWindow() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    window.create(sf::VideoMode(800, 600), "PW-TrafficSimulation", sf::Style::Default, settings);
    window.setFramerateLimit(60);
}

void SimulationWindow::run() {
    while(window.isOpen()) {
        handleEvents();
        window.clear(sf::Color(224, 224, 224));
        window.display();
    }
}

void SimulationWindow::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            default:
                break;
        }
    }
}
