#ifndef PW_TRAFFICSIMULATION_SIDEWALK_H
#define PW_TRAFFICSIMULATION_SIDEWALK_H

#include "../MapSegment.h"
#include "../../sim/dispatchers/TwoWayStraightDispatcher.h"

namespace vis {
    /**
     * Map segment that represents a simple two-way sidewalk.
     */
    class Sidewalk : public MapSegment {
    public:
        /**
         * Initializes the sidewalk.
         * @param inputNode0 input (right) node of first end.
         * @param outputNode0 output (left) node of first end.
         * @param inputNode1 input (right) node of second end.
         * @param outputNode1 output (left) node of second end.
         */
        Sidewalk(
                const std::shared_ptr<sim::TrafficNode>& inputNode0,
                const std::shared_ptr<sim::TrafficNode>& outputNode0,
                const std::shared_ptr<sim::TrafficNode>& inputNode1,
                const std::shared_ptr<sim::TrafficNode>& outputNode1
        );

        /**
         * Updates the segment based on its dispatcher.
         * @param elapsed Time (in seconds) from the last logic update.
         */
        void update(float elapsed) override;

        /**
         * The dispatcher that manages nodes within this segment.
         * @return pointer to the dispatcher.
         */
        sim::TrafficDispatcher* getDispatcher() override;

    protected:
        /**
         * A hook called whenever the segment should be displayed by SFML.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        sim::TwoWayStraightDispatcher dispatcher;

        sf::RectangleShape sidewalkShape;


    };
}


#endif //PW_TRAFFICSIMULATION_SIDEWALK_H
