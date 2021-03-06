#include "TrafficSimulation.h"

void sim::TrafficSimulation::update(float elapsed) {
    for (sim::TrafficDispatcher* d : dispatchers)
        d->update(elapsed);
}

void sim::TrafficSimulation::registerDispatcher(sim::TrafficDispatcher* dispatcher) {
    dispatchers.push_back(dispatcher);
}
