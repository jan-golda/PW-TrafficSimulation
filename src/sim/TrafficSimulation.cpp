#include "TrafficSimulation.h"

void sim::TrafficSimulation::update(float elapsed) {
    for(sim::TrafficDispatcher* d : dispatchers)
        d->update(elapsed);
    for(sim::TrafficEntity* e : entities)
        e->update(elapsed);
}
