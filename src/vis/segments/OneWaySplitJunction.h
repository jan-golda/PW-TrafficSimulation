#ifndef PW_TRAFFICSIMULATION_ONEWAYSPLITJUNCTION_H
#define PW_TRAFFICSIMULATION_ONEWAYSPLITJUNCTION_H


#include "../MapSegment.h"
#include "../../sim/dispatchers/OneWaySplitDispatcher.h"
#include "../../sim/TrafficNode.h"

namespace vis {

    class OneWaySplitJunction : public MapSegment {
    public:
        OneWaySplitJunction(float x, float y, float rotation, bool left);

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
        sim::OneWaySplitDispatcher dispatcher;

        sf::RectangleShape roadShapes[2];
    };

} // vis

#endif //PW_TRAFFICSIMULATION_ONEWAYSPLITJUNCTION_H
