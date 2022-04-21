#ifndef PW_TRAFFICSIMULATION_TWOWAYTJUNCTION_H
#define PW_TRAFFICSIMULATION_TWOWAYTJUNCTION_H


#include "../MapSegment.h"
#include "../../sim/dispatchers/TwoWayTripleJunctionDispatcher.h"
#include "../../sim/TrafficNode.h"

namespace vis {
    /**
     * Map segment that represents a T junction of two-way roads.
     */
    class TwoWayTJunction : public MapSegment {
    public:
        /**
         * Initializes the junction.
         * @param x coordinate of the junction center.
         * @param y coordinate of the junction center.
         * @param rotation of the junction in degrees.
         */
        TwoWayTJunction(float x, float y, float rotation = 0);

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
        sim::TwoWayTripleJunctionDispatcher dispatcher;

        sf::RectangleShape roadShapes[2];
        sf::RectangleShape lineShapes[6];
    };

} // vis

#endif //PW_TRAFFICSIMULATION_TWOWAYTJUNCTION_H
