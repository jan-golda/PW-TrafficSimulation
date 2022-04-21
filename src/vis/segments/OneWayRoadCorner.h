#ifndef PW_TRAFFICSIMULATION_ONEWAYRoadCorner_H
#define PW_TRAFFICSIMULATION_ONEWAYRoadCorner_H

#include "../MapSegment.h"
#include "../../sim/TrafficNode.h"

namespace vis {
    /**
     * Map segment that represents a corner of a one-way road.
     */
    class OneWayRoadCorner : public MapSegment {
    public:
        /**
         * Initializes the corner.
         * @param x coordinate of the corner center.
         * @param y coordinate of the corner center.
         */
        OneWayRoadCorner(float x, float y);

        /**
         * The dispatcher that manages nodes within this segment.
         * @return pointer to the dispatcher.
         */
        sim::TrafficDispatcher* getDispatcher() override {return nullptr;};

        /**
         * Returns one of the nodes that define this segment.
         * @param i Id of the node within this this segment.
         * @return simulation node.
         */
        std::shared_ptr<sim::TrafficNode> getNode() const;

    protected:
        /**
         * A hook called whenever the segment should be displayed by SFML.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        std::shared_ptr<sim::TrafficNode> node;
        sf::CircleShape circleShape;
    };

}


#endif //PW_TRAFFICSIMULATION_ONEWAYRoadCorner_H
