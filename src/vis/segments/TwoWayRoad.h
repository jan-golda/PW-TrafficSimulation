#ifndef PW_TRAFFICSIMULATION_TWOWAYROAD_H
#define PW_TRAFFICSIMULATION_TWOWAYROAD_H

#include "../MapSegment.h"
#include "../../sim/dispatchers/TwoWayStraightDispatcher.h"

namespace vis {

    /**
     * The simplest segment with two input node and two output node.
     */
    class TwoWayRoad : public MapSegment {
    public:
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

        sim::TrafficDispatcher* getDispatcher() override;

    protected:
        /**
         * A hook called whenever the map should be displayed by SFML.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        /**
         * The dispatcher that manages this segment's logic.
         */
        sim::TwoWayStraightDispatcher dispatcher;

        sf::RectangleShape roadShape;
        sf::RectangleShape lineShape;
    };

}


#endif //PW_TRAFFICSIMULATION_TWOWAYROAD_H
