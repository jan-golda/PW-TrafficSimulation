#define GLM_ENABLE_EXPERIMENTAL

#include "Entity.h"

#include <glm/gtx/norm.hpp>
#include <glm/gtx/vector_angle.hpp>

using namespace vis;

Entity::Entity(sf::Drawable* drawable, float maxSpeed, float maxRotationSpeed) :
    drawable(drawable), trafficEntity(maxSpeed, maxRotationSpeed) {}

void Entity::update(float elapsed) {
    auto position = trafficEntity.getPosition();
    auto speed = trafficEntity.getSpeed();

    // match traffic entity position
    setPosition(position.x, position.y);

    // update rotation based on traffic entity speed
    if (glm::length(speed) > glm::epsilon<float>()) {
        glm::vec2 up = glm::vec2(0, -1);
        glm::vec2 heading = glm::normalize(speed);
        setRotation(glm::degrees(glm::orientedAngle(up, heading)));
    }
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(*drawable, states);
}

sim::TrafficEntity& Entity::getTrafficEntity() {
    return trafficEntity;
}
