#define GLM_ENABLE_EXPERIMENTAL

#include "Entity.h"

#include <glm/gtx/norm.hpp>
#include <glm/gtx/vector_angle.hpp>

using namespace vis;

Entity::Entity(sf::Drawable* drawable) : drawable(drawable) {}

void Entity::update(float elapsed) {
    // match traffic entity position
    setPosition(trafficEntity.position.x, trafficEntity.position.y);

    // update rotation based on traffic entity speed
    if (glm::length2(trafficEntity.speed) > 0.1) {
        glm::vec2 up = glm::vec2(0, -1);
        glm::vec2 heading = glm::normalize(trafficEntity.speed);
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

Car::Car() : Entity(&shape) {
    shape.setPointCount(6);
    shape.setPoint(0, sf::Vector2f(5, 0));
    shape.setPoint(1, sf::Vector2f(15, 0));
    shape.setPoint(2, sf::Vector2f(20, 5));
    shape.setPoint(3, sf::Vector2f(20, 30));
    shape.setPoint(4, sf::Vector2f(0, 30));
    shape.setPoint(5, sf::Vector2f(0, 5));
    shape.setOrigin(10, 15);

    shape.setFillColor(ENTITY_COLORS[rand() % ENTITY_COLORS.size()]);
    shape.setOutlineColor(sf::Color(97, 97, 97));
    shape.setOutlineThickness(1);
}

Pedestrian::Pedestrian() : Entity(&shape) {
    shape.setRadius(5);
    shape.setOrigin(5, 5);

    shape.setFillColor(ENTITY_COLORS[rand() % ENTITY_COLORS.size()]);
    shape.setOutlineColor(sf::Color(97, 97, 97));
    shape.setOutlineThickness(1);
}
