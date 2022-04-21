#ifndef PW_TRAFFICSIMULATION_TWOWAYTJUNCTION_H
#define PW_TRAFFICSIMULATION_TWOWAYTJUNCTION_H


#include "../MapSegment.h"
#include "../../sim/dispatchers/TwoWayTripleJunctionDispatcher.h"
#include "../../sim/TrafficNode.h"

namespace vis {

    class TwoWayTJunction : public MapSegment {
    public:
        TwoWayTJunction(float x, float y, float rotation);

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
        std::shared_ptr<sim::TrafficNode> nodes[6];

        /**
         * The dispatcher that manages this segment's logic.
         */
        sim::TwoWayTripleJunctionDispatcher dispatcher;

        sf::RectangleShape roadShapes[2];
        sf::RectangleShape lineShapes[6];
    };

} // vis

#endif //PW_TRAFFICSIMULATION_TWOWAYTJUNCTION_H
