#ifndef PW_TRAFFICSIMULATION_WINDOW_H
#define PW_TRAFFICSIMULATION_WINDOW_H


#include <SFML/Graphics.hpp>
#include "Map.h"

namespace map {
    class Window {
    private:
        sf::RenderWindow window;
        map::Map map;

        void handleEvents();

        void update(float elapsed);

        void draw();

    public:
        Window();

        void run();
    };
}


#endif //PW_TRAFFICSIMULATION_WINDOW_H
