#ifndef PW_TRAFFICSIMULATION_ONEWAYROAD_H
#define PW_TRAFFICSIMULATION_ONEWAYROAD_H

#include "../MapSegment.h"
#include "../../sim/dispatchers/OneWayStraightDispatcher.h"

namespace vis {

    /**
     * The simplest segment with one input node and one output node.
     */
    class OneWayRoad : public MapSegment {
    public:
        OneWayRoad();

        /**
         * Updates the segment based on its dispatcher.
         * @param elapsed Time (in seconds) from the last logic update.
         */
        void update(float elapsed) override;

        // getters and setters
        void setInputNode(const std::shared_ptr<sim::TrafficNode>& node);
        void setOutputNode(const std::shared_ptr<sim::TrafficNode>& node);

        sim::TrafficDispatcher* getDispatcher() override;

    protected:
        /**
         * A hook called whenever the map should be displayed by SFML.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        /**
         * The dispatcher that manages this segment's logic.
         */
        sim::OneWayStraightDispatcher dispatcher;

        sf::RectangleShape roadShape;
    };

}


#endif //PW_TRAFFICSIMULATION_ONEWAYROAD_H
