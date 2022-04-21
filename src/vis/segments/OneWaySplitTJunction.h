#ifndef PW_TRAFFICSIMULATION_ONEWAYSPLITTJUNCTION_H
#define PW_TRAFFICSIMULATION_ONEWAYSPLITTJUNCTION_H


#include "../MapSegment.h"
#include "../../sim/dispatchers/OneWaySplitDispatcher.h"
#include "../../sim/TrafficNode.h"

namespace vis {
    /**
     * Map segment that represents a T road junction with the side road splitting from the one-way traffic.
     */
    class OneWaySplitTJunction : public MapSegment {
    public:
        /**
         * Initializes the junction.
         * @param x coordinate of the junction center.
         * @param y coordinate of the junction center.
         * @param rotation of the junction in degrees.
         * @param left if true then the split road is to the left, otherwise to the right.
         */
        OneWaySplitTJunction(float x, float y, float rotation = 0, bool left = false);

        /**
         * Returns one of the nodes that define this segment.
         * @param i Id of the node within this this segment.
         * @return simulation node.
         */
        std::shared_ptr<sim::TrafficNode> getNode(std::size_t i);

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
        std::shared_ptr<sim::TrafficNode> nodes[3];
        sim::OneWaySplitDispatcher dispatcher;

        sf::RectangleShape roadShapes[2];
    };

} // vis

#endif //PW_TRAFFICSIMULATION_ONEWAYSPLITTJUNCTION_H
