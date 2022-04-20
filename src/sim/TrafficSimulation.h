#ifndef PW_TRAFFICSIMULATION_TRAFFICSIMULATION_H
#define PW_TRAFFICSIMULATION_TRAFFICSIMULATION_H

#include <list>
#include "TrafficEntity.h"
#include "dispatchers/TrafficDispatcher.h"

namespace sim {
    class TrafficSimulation {
    private:
        std::list<sim::TrafficEntity*> entities;
        std::list<sim::TrafficDispatcher*> dispatchers;
    public:
        void update(float elapsed);

        void registerEntity(TrafficEntity* entity);
        void registerDispatcher(TrafficDispatcher* dispatcher);
    };
}


#endif //PW_TRAFFICSIMULATION_TRAFFICSIMULATION_H
