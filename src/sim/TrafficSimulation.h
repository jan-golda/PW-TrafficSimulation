#ifndef PW_TRAFFICSIMULATION_TRAFFICSIMULATION_H
#define PW_TRAFFICSIMULATION_TRAFFICSIMULATION_H

#include <list>
#include "TrafficEntity.h"
#include "dispatchers/TrafficDispatcher.h"

namespace sim {

    /**
     * Main class of the simulation package that coordinates and runs the simulation.
     */
    class TrafficSimulation {
    private:
        std::list<sim::TrafficDispatcher*> dispatchers;
    public:
        /**
         * Perform a simulation step.
         * @param elapsed time (in seconds) from the last logic update.
         */
        void update(float elapsed);

        /**
         * Make this simulation aware of the given entity.
         * @param entity instance that will be updated as part of this simulation.
         */
        void registerDispatcher(TrafficDispatcher* dispatcher);
    };
}


#endif //PW_TRAFFICSIMULATION_TRAFFICSIMULATION_H
