#ifndef PW_TRAFFICSIMULATION_TRAFFICNODE_H
#define PW_TRAFFICSIMULATION_TRAFFICNODE_H

#include <glm/vec2.hpp>
#include <queue>
#include "TrafficEntity.h"

namespace sim {
    // forward declaration
    class TrafficEntity;

    /**
     * Node in a traffic graph.
     * Stores its position and entities that await in it.
     */
    class TrafficNode {
    private:
        /**
         * Queue of entities that await in this node.
         */
        std::queue<TrafficEntity*> queue;

        /**
         * Position of this node in the simulation space.
         */
        glm::vec2 position;

    public:
        /**
         * Create node at coordinates (0, 0).
         */
        TrafficNode();

        /**
         * Create node at given coordinates.
         * @param x coordinate of the node
         * @param y coordinate of the node
         */
        TrafficNode(float x, float y);

        /**
         * Checks if there is an entity awaiting in this node.
         * @return if entity queue is empty.
         */
        bool empty() const;

        /**
         * Returns the first entity in queue. Should be called only if `!empty()`.
         * @return entity from the front of the queue.
         */
        TrafficEntity* front() const;

        /**
         * Removes the first entity from the queue.
         */
        void pop();

        /**
         * Adds the given entity to the back of the queue.
         * @param entity to add to the queue.
         */
        void push(TrafficEntity* entity);

        /**
         * Returns the node position within simulation world.
         * @return node position as 2d vector.
         */
        const glm::vec2& getPosition() const;
    };
}


#endif //PW_TRAFFICSIMULATION_TRAFFICNODE_H
