#ifndef PW_TRAFFICSIMULATION_TRAFFICSIMULATION_H
#define PW_TRAFFICSIMULATION_TRAFFICSIMULATION_H

#include <list>
#include "TrafficEntity.h"
#include "TrafficDispatcher.h"

namespace sim {
    class TrafficSimulation {
    private:
        std::list<sim::TrafficEntity*> entities;
        std::list<sim::TrafficDispatcher*> dispatchers;
    public:
        void update(float elapsed);
    };
}


#endif //PW_TRAFFICSIMULATION_TRAFFICSIMULATION_H
