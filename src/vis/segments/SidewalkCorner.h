#ifndef PW_TRAFFICSIMULATION_SIDEWALKCORNER_H
#define PW_TRAFFICSIMULATION_SIDEWALKCORNER_H

#include "../MapSegment.h"
#include "../../sim/TrafficNode.h"

namespace vis {
    /**
     * Map segment that represents a corner of a simple two way sidewalk.
     */
    class SidewalkCorner : public MapSegment {
    public:
        /**
         * Initializes the corner.
         * @param x coordinate of the corner center.
         * @param y coordinate of the corner center.
         * @param rotation of the corner in degrees.
         */
        SidewalkCorner(float x, float y, float rotation = 0);

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
        std::shared_ptr<sim::TrafficNode> getNode(std::size_t i) const;

    protected:
        /**
         * A hook called whenever the segment should be displayed by SFML.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        std::shared_ptr<sim::TrafficNode> nodes[2];
        sf::CircleShape circleShape;
    };

}


#endif //PW_TRAFFICSIMULATION_SIDEWALKCORNER_H
