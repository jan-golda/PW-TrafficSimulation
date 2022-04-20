#include "Window.h"
#include "Entity.h"

using namespace vis;

Window::Window() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    window.create(sf::VideoMode(800, 600), "PW-TrafficSimulation", sf::Style::Default, settings);
    window.setFramerateLimit(60);
}

void Window::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        float elapsed = clock.restart().asSeconds();

        // inputs
        handleEvents();

        // update
        map.update(elapsed);

        // draw
        window.clear(sf::Color(224, 224, 224));
        window.draw(map);
        window.display();
    }
}

void Window::handleEvents() {
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
