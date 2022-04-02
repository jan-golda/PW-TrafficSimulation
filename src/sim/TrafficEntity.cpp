#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtx/norm.hpp>
#include "TrafficEntity.h"

void sim::TrafficEntity::update(float elapsed) {
    position += speed * elapsed;
}

bool sim::TrafficEntity::isNear(sim::TrafficNode* node) const {
    return glm::length2(position - node->position) < 5.0f;
}
