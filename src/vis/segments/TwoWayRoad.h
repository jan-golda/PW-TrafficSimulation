#ifndef PW_TRAFFICSIMULATION_TWOWAYROAD_H
#define PW_TRAFFICSIMULATION_TWOWAYROAD_H

#include "../MapSegment.h"
#include "../../sim/dispatchers/TwoWayStraightDispatcher.h"

namespace vis {
    /**
     * Map segment that represents a simple two-way road.
     */
    class TwoWayRoad : public MapSegment {
    public:
        /**
         * Initializes the road.
         * @param inputNode0 input (right) node of first end.
         * @param outputNode0 output (left) node of first end.
         * @param inputNode1 input (right) node of second end.
         * @param outputNode1 output (left) node of second end.
         */
        TwoWayRoad(
                const std::shared_ptr<sim::TrafficNode>& inputNode0,
                const std::shared_ptr<sim::TrafficNode>& outputNode0,
                const std::shared_ptr<sim::TrafficNode>& inputNode1,
                const std::shared_ptr<sim::TrafficNode>& outputNode1
        );

        /**
         * Updates the segment based on its dispatcher.
         * @param elapsed Time (in seconds) from the last logic update.
         */
        void update(float elapsed) override;

        /**
         * The dispatcher that manages nodes within this segment.
         * @return pointer to the dispatcher.
         */
        sim::TrafficDispatcher* getDispatcher() override;

    protected:
        /**
         * A hook called whenever the segment should be displayed by SFML.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        sim::TwoWayStraightDispatcher dispatcher;

        sf::RectangleShape roadShape;
        sf::RectangleShape lineShape;
    };

}


#endif //PW_TRAFFICSIMULATION_TWOWAYROAD_H
