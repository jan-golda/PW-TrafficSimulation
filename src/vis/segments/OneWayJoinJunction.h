#ifndef PW_TRAFFICSIMULATION_ONEWAYJOINJUNCTION_H
#define PW_TRAFFICSIMULATION_ONEWAYJOINJUNCTION_H


#include "../MapSegment.h"
#include "../../sim/dispatchers/OneWayJoinDispatcher.h"
#include "../../sim/TrafficNode.h"

namespace vis {
    /**
     * Map segment that represents a T road junction with the side road joining the one-way traffic.
     */
    class OneWayJoinJunction : public MapSegment {
    public:
        /**
         * Initializes the junction.
         * @param x coordinate of the junction center.
         * @param y coordinate of the junction center.
         * @param rotation of the junction in degrees.
         * @param left if true then the joining road is from the left, otherwise from the right.
         */
        OneWayJoinJunction(float x, float y, float rotation = 0, bool left = false);

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
        std::shared_ptr<sim::TrafficNode> nodes[3];
        sim::OneWayJoinDispatcher dispatcher;

        sf::RectangleShape roadShapes[2];
    };

} // vis

#endif //PW_TRAFFICSIMULATION_ONEWAYJOINJUNCTION_H
