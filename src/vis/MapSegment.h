#ifndef PW_TRAFFICSIMULATION_MAPSEGMENT_H
#define PW_TRAFFICSIMULATION_MAPSEGMENT_H


#include <SFML/Graphics.hpp>
#include "../sim/dispatchers/TrafficDispatcher.h"

namespace vis {
    /**
     * Interface of a part of road infrastructure.
     */
    class MapSegment : public sf::Drawable {
    public:
        /**
         * Updates the segment based on its dispatcher.
         * @param elapsed Time (in seconds) from the last logic update.
         */
        virtual void update(float elapsed) {};

        // getters and setters
        virtual sim::TrafficDispatcher* getDispatcher() = 0;
    };
}


#endif //PW_TRAFFICSIMULATION_MAPSEGMENT_H
