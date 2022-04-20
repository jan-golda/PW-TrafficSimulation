#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtx/norm.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "TrafficEntity.h"

using namespace sim;

TrafficEntity::TrafficEntity(const float maxSpeed, const float maxRotationSpeed) :
        maxSpeed(maxSpeed), maxRotationSpeed(maxRotationSpeed) {}

void TrafficEntity::update(float elapsed) {
    if (!targetNode) {
        speed = glm::vec2(0,0);
        return;
    }

    const auto targetDirection = glm::normalize(targetNode->position - position);

    // if stationary assume instant rotation
    if (glm::length(speed) < glm::epsilon<float>())
        speed = targetDirection;

    const auto currentDirection = glm::normalize(speed);

    // rotate speed towards the target node
    float targetAngle = glm::orientedAngle(currentDirection, targetDirection);
    targetAngle = std::min(targetAngle, maxRotationSpeed);
    targetAngle = std::max(targetAngle, -maxRotationSpeed);
    speed = glm::rotate(speed, targetAngle);

    // move!
    speed = glm::normalize(speed) * maxSpeed;
    position += speed * elapsed;
}

bool TrafficEntity::isNearTarget(const float epsilon) const {
    if (!targetNode) return false;
    return glm::length(position - targetNode->position) < epsilon;
}

const glm::vec2& TrafficEntity::getSpeed() const {
    return speed;
}

const glm::vec2& TrafficEntity::getPosition() const {
    return position;
}

void TrafficEntity::setPosition(const glm::vec2& pos) {
    position = pos;
}

const std::shared_ptr<TrafficNode>& TrafficEntity::getTargetNode() const {
    return targetNode;
}

void TrafficEntity::setTargetNode(const std::shared_ptr<TrafficNode>& node) {
    targetNode = node;
}
