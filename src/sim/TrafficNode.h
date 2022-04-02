#ifndef PW_TRAFFICSIMULATION_TRAFFICNODE_H
#define PW_TRAFFICSIMULATION_TRAFFICNODE_H

#include <glm/vec2.hpp>
#include <queue>
#include "TrafficEntity.h"

namespace sim {
    class TrafficNode {
    private:
        int queueLimit = 0;
        std::queue<TrafficEntity*> queue;

    public:
        glm::vec2 position;

        void setLimit(int limit);

        [[nodiscard]] int getLimit() const;

        [[nodiscard]] int getSize() const;

        [[nodiscard]] bool isFull() const;

        bool push(TrafficEntity* entity);

        TrafficEntity* pop();

        [[nodiscard]] TrafficEntity* peek() const;
    };
}


#endif //PW_TRAFFICSIMULATION_TRAFFICNODE_H
