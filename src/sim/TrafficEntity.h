#ifndef PW_TRAFFICSIMULATION_TRAFFICENTITY_H
#define PW_TRAFFICSIMULATION_TRAFFICENTITY_H

#include <glm/vec2.hpp>
#include "TrafficNode.h"

namespace sim {
    // forward declaration
    class TrafficNode;

    class TrafficEntity {
    public:
        glm::vec2 position;
        glm::vec2 speed;

        void update(float elapsed);

        bool isNear(TrafficNode* node) const;
    };
}


#endif //PW_TRAFFICSIMULATION_TRAFFICENTITY_H
