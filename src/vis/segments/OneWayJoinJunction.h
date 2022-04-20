#ifndef PW_TRAFFICSIMULATION_ONEWAYJOINJUNCTION_H
#define PW_TRAFFICSIMULATION_ONEWAYJOINJUNCTION_H


#include "../MapSegment.h"
#include "../../sim/dispatchers/OneWayJoinDispatcher.h"
#include "../../sim/TrafficNode.h"

namespace vis {

    class OneWayJoinJunction : public MapSegment {
    public:
        OneWayJoinJunction(float x, float y, float rotation, bool left);

        // getters and setters
        std::shared_ptr<sim::TrafficNode> getNode(std::size_t i);

        sim::TrafficDispatcher* getDispatcher() override;

    protected:
        /**
         * A hook called whenever the map should be displayed by SFML.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        /**
         * Nodes of this segment.
         */
        std::shared_ptr<sim::TrafficNode> nodes[3];

        /**
         * The dispatcher that manages this segment's logic.
         */
        sim::OneWayJoinDispatcher dispatcher;

        sf::RectangleShape roadShapes[2];
    };

} // vis

#endif //PW_TRAFFICSIMULATION_ONEWAYJOINJUNCTION_H
