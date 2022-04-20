#ifndef PW_TRAFFICSIMULATION_WINDOW_H
#define PW_TRAFFICSIMULATION_WINDOW_H


#include <SFML/Graphics.hpp>
#include "Map.h"

namespace vis {

    /**
     * Main windows of the simulations.
     * Creates the SFML window and then runs the main update-draw loop.
     */
    class Window {
    private:
        /**
         * SFML simulation window instance.
         */
        sf::RenderWindow window;

        /**
         * Instance of the simulated map.
         */
        Map map;

        /**
         * Part of the `run()` main loop that handles user inputs.
         */
        void handleEvents();

    public:
        /**
         * Creates and opens the visualization window.
         */
        Window();

        /**
         * Starts the simulation and visualization.
         * Implements the main update-draw loop.
         */
        void run();
    };

}


#endif //PW_TRAFFICSIMULATION_WINDOW_H
