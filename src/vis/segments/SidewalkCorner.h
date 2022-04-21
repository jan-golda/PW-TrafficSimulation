#ifndef PW_TRAFFICSIMULATION_SIDEWALKCORNER_H
#define PW_TRAFFICSIMULATION_SIDEWALKCORNER_H

#include "../MapSegment.h"
#include "../../sim/TrafficNode.h"

namespace vis {

    /**
     * The simplest segment with one input node and one output node.
     */
    class SidewalkCorner : public MapSegment {
    public:
        SidewalkCorner(float x, float y, float rotation = 0);

        sim::TrafficDispatcher* getDispatcher() override {return nullptr;};

        std::shared_ptr<sim::TrafficNode> getNode(std::size_t i) const;

    protected:
        /**
         * A hook called whenever the map should be displayed by SFML.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        std::shared_ptr<sim::TrafficNode> nodes[2];
        sf::CircleShape circleShape;
    };

}


#endif //PW_TRAFFICSIMULATION_SIDEWALKCORNER_H
