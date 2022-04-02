#ifndef PW_TRAFFICSIMULATION_TRAFFICENTITY_H
#define PW_TRAFFICSIMULATION_TRAFFICENTITY_H

#include <glm/vec2.hpp>

namespace sim {
    class TrafficEntity {
    public:
        glm::vec2 position;
        glm::vec2 speed;
    };
}


#endif //PW_TRAFFICSIMULATION_TRAFFICENTITY_H
