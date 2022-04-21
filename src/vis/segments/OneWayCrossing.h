#ifndef PW_TRAFFICSIMULATION_ONEWAYCROSSING_H
#define PW_TRAFFICSIMULATION_ONEWAYCROSSING_H


#include "../MapSegment.h"
#include "../../sim/dispatchers/TwoOneCrossingDispatcher.h"
#include "../../sim/TrafficNode.h"

namespace vis {
    /**
     * Map segment that represents a pedestrian crossing on a one-way road.
     */
    class OneWayCrossing : public MapSegment {
    public:
        /**
         * Initializes the crossing.
         * @param x coordinate of the crossing center.
         * @param y coordinate of the crossing center.
         * @param rotation of the junction in degrees.
         */
        OneWayCrossing(float x, float y, float rotation = 0);

        /**
         * Returns one of the nodes that define this segment.
         * @param i Id of the node within this this segment.
         * @return simulation node.
         */
        std::shared_ptr<sim::TrafficNode> getNode(std::size_t i);

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
        std::shared_ptr<sim::TrafficNode> nodes[6];
        sim::TwoOneCrossingDispatcher dispatcher;

        sf::RectangleShape roadShape;
        sf::RectangleShape stripeShapes[3];
    };
}


#endif //PW_TRAFFICSIMULATION_ONEWAYCROSSING_H
