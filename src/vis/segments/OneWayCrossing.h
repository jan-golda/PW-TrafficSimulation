#ifndef PW_TRAFFICSIMULATION_ONEWAYCROSSING_H
#define PW_TRAFFICSIMULATION_ONEWAYCROSSING_H


#include "../MapSegment.h"
#include "../../sim/dispatchers/TwoOneCrossingDispatcher.h"
#include "../../sim/TrafficNode.h"

namespace vis {
class OneWayCrossing : public MapSegment {
    public:
        OneWayCrossing(float x, float y, float rotation);

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
        sim::TwoOneCrossingDispatcher dispatcher;

        sf::RectangleShape roadShape;
        sf::RectangleShape stripeShapes[3];
    };
}


#endif //PW_TRAFFICSIMULATION_ONEWAYCROSSING_H
