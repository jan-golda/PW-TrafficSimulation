#ifndef PW_TRAFFICSIMULATION_MAP_H
#define PW_TRAFFICSIMULATION_MAP_H


#include <list>
#include "../sim/TrafficSimulation.h"
#include "MapSegment.h"
#include "entities/Entity.h"
#include "entities/Car.h"
#include "entities/Pedestrian.h"

namespace vis {

    /**
     * The simulated map that coordinates the simulation and visualization components.
     */
    class Map : public sf::Drawable {
    private:
        /**
         * Instance of the simulation engine that runs this map.
         */
        sim::TrafficSimulation simulation;

        /**
         * List of entities present on the simulated map.
         */
        std::list<std::unique_ptr<Entity>> entities;

        /**
         * List of segments that build the simulated map.
         */
        std::list<std::unique_ptr<MapSegment>> segments;

    protected:
        /**
         * A hook called whenever the map should be displayed by SFML.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    public:
        /**
         * Updates the simulation and visualization logic.
         * @param elapsed Time (in seconds) from the last logic update.
         */
        void update(float elapsed);

        /**
         * Spawns a new, random car.
         * @param x initial x coordinate.
         * @param y initial y coordinate.
         * @return Pointer to the created car.
         */
        Car* createCar(float x, float y);

        /**
         * Spawns a new, random pedestrian.
         * @param x initial x coordinate.
         * @param y initial y coordinate.
         * @return Pointer to the created pedestrian.
         */
        Pedestrian* createPedestrian(float x, float y);

    };
}


#endif //PW_TRAFFICSIMULATION_MAP_H
