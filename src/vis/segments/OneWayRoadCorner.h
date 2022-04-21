#ifndef PW_TRAFFICSIMULATION_ONEWAYRoadCorner_H
#define PW_TRAFFICSIMULATION_ONEWAYRoadCorner_H

#include "../MapSegment.h"
#include "../../sim/TrafficNode.h"

namespace vis {

    /**
     * The simplest segment with one input node and one output node.
     */
    class OneWayRoadCorner : public MapSegment {
    public:
        OneWayRoadCorner(float x, float y);

        sim::TrafficDispatcher* getDispatcher() override {return nullptr;};

        std::shared_ptr<sim::TrafficNode> getNode() const;

    protected:
        /**
         * A hook called whenever the map should be displayed by SFML.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        std::shared_ptr<sim::TrafficNode> node;
        sf::CircleShape circleShape;
    };

}


#endif //PW_TRAFFICSIMULATION_ONEWAYRoadCorner_H
