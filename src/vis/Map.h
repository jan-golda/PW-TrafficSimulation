#ifndef PW_TRAFFICSIMULATION_MAP_H
#define PW_TRAFFICSIMULATION_MAP_H


#include <list>
#include "Entity.h"
#include "../sim/TrafficSimulation.h"

namespace vis {
    class Map : public sf::Drawable {
    private:
        sim::TrafficSimulation simulation;
        std::list<std::unique_ptr<Entity>> entities;
    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    public:
        void update(float elapsed);

        Car* createCar();
        Pedestrian* createPedestrian();

        sim::TrafficSimulation& getTrafficSimulation();
    };
}


#endif //PW_TRAFFICSIMULATION_MAP_H
