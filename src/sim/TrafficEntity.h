#ifndef PW_TRAFFICSIMULATION_TRAFFICENTITY_H
#define PW_TRAFFICSIMULATION_TRAFFICENTITY_H

#include <glm/vec2.hpp>
#include <memory>
#include "TrafficNode.h"

namespace sim {
    // forward declaration
    class TrafficNode;

    /**
     * Represents an entity within the simulation.
     */
    class TrafficEntity {
    public:
        /**
         * Creates the entity.
         * @param maxSpeed maximum speed (units/s) of the entity
         * @param maxRotationSpeed maximum rotation speed (radian/s) of the entity
         */
        TrafficEntity(const float maxSpeed, const float maxRotationSpeed);

        /**
         * Updates the entity speed and position based on the target node.
         * @param elapsed Time (in seconds) from the last logic update.
         */
        void update(float elapsed);

        /**
         * Checks if this entity is near its target node.
         * @param epsilon the maximal distance from the node that is considered as near.
         * @return true if the target node exists and is closer than `epsilon`.
         */
        bool isNearTarget(const float epsilon = 5.0f) const;

        // getters and setters
        const glm::vec2& getPosition() const;
        void setPosition(const glm::vec2& position);

        const glm::vec2& getSpeed() const;

        const std::shared_ptr<TrafficNode>& getTargetNode() const;
        void setTargetNode(const std::shared_ptr<TrafficNode>& targetNode);

    private:
        /**
         * Maximum speed (units/s) of the entity
         */
        const float maxSpeed;

        /**
         * Maximum rotation speed (radian/s) of the entity
         */
        const float maxRotationSpeed;

        /**
         * Position of the entity.
         */
        glm::vec2 position{};

        /**
         * Speed (per second) of the entity.
         */
        glm::vec2 speed{};

        /**
         * Node to which the entity will move.
         * Can be nullptr in which case the entity will stop.
         */
        std::shared_ptr<TrafficNode> targetNode;
    };
}


#endif //PW_TRAFFICSIMULATION_TRAFFICENTITY_H
