#ifndef PW_TRAFFICSIMULATION_TRAFFICSIMULATION_H
#define PW_TRAFFICSIMULATION_TRAFFICSIMULATION_H

#include <list>
#include "TrafficEntity.h"

namespace sim {
    class TrafficSimulation {
    private:
        std::list<sim::TrafficEntity> entities;
    public:
        void update(float elapsed);
    };
}


#endif //PW_TRAFFICSIMULATION_TRAFFICSIMULATION_H
