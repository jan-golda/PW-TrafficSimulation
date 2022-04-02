#define GLM_ENABLE_EXPERIMENTAL

#include "Entity.h"

#include <glm/gtx/norm.hpp>
#include <glm/gtx/vector_angle.hpp>

void map::Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // transform entity based on traffic entity position
    states.transform.translate(trafficEntity.position.x, trafficEntity.position.y);

    // calculate rotation angle based on traffic entity speed
    if(glm::length2(trafficEntity.speed) > 0.1) {
        glm::vec2 up = glm::vec2(0, -1);
        glm::vec2 heading = glm::normalize(trafficEntity.speed);
        float angle = glm::degrees(glm::orientedAngle(up, heading));

        states.transform.rotate(angle);
    }

    target.draw(*drawable, states);
}

map::Car::Car() {
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

    drawable = &shape;
}

map::Pedestrian::Pedestrian() {
    shape.setRadius(5);
    shape.setOrigin(5, 5);

    shape.setFillColor(ENTITY_COLORS[rand() % ENTITY_COLORS.size()]);
    shape.setOutlineColor(sf::Color(97, 97, 97));
    shape.setOutlineThickness(1);

    drawable = &shape;
}
