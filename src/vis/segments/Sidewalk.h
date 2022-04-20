#ifndef PW_TRAFFICSIMULATION_SIDEWALK_H
#define PW_TRAFFICSIMULATION_SIDEWALK_H

#include "../MapSegment.h"
#include "../../sim/dispatchers/TwoWayStraightDispatcher.h"

namespace vis {

    class Sidewalk : public MapSegment {
    public:
        Sidewalk();

        /**
         * Updates the segment based on its dispatcher.
         * @param elapsed Time (in seconds) from the last logic update.
         */
        void update(float elapsed) override;

        // getters and setters
        void setInputNode(std::size_t i, const std::shared_ptr<sim::TrafficNode>& node);
        void setOutputNode(std::size_t i, const std::shared_ptr<sim::TrafficNode>& node);

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
        sim::TwoWayStraightDispatcher dispatcher;

        sf::RectangleShape sidewalkShape;


    };
}


#endif //PW_TRAFFICSIMULATION_SIDEWALK_H
