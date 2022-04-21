#ifndef PW_TRAFFICSIMULATION_ONEWAYROAD_H
#define PW_TRAFFICSIMULATION_ONEWAYROAD_H

#include "../MapSegment.h"
#include "../../sim/dispatchers/OneWayStraightDispatcher.h"

namespace vis {
    /**
     * Map segment that represents a simple one-way road.
     */
    class OneWayRoad : public MapSegment {
    public:
        /**
         * Initializes the road.
         * @param inputNode input node at one end.
         * @param outputNode output node at the other end.
         */
        OneWayRoad(const std::shared_ptr<sim::TrafficNode>& inputNode, const std::shared_ptr<sim::TrafficNode>& outputNode);

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
        sim::OneWayStraightDispatcher dispatcher;

        sf::RectangleShape roadShape;
        sf::CircleShape arrowShape;
    };

}


#endif //PW_TRAFFICSIMULATION_ONEWAYROAD_H
