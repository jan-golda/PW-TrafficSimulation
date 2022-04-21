#ifndef PW_TRAFFICSIMULATION_WEIRDTJUNCTION_H
#define PW_TRAFFICSIMULATION_WEIRDTJUNCTION_H


#include "../MapSegment.h"
#include "../../sim/dispatchers/WeirdTripleJunctionDispatcher.h"
#include "../../sim/TrafficNode.h"

namespace vis {

    class WeirdTJunction : public MapSegment {
    public:
        WeirdTJunction(float x, float y, float rotation);

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
        sim::WeirdTripleJunctionDispatcher dispatcher;

        sf::RectangleShape roadShapes[2];
    };

} // vis

#endif //PW_TRAFFICSIMULATION_WEIRDTJUNCTION_H
