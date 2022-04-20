#define GLM_ENABLE_EXPERIMENTAL

#include <glm/geometric.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "OneWayRoad.h"

using namespace vis;

OneWayRoad::OneWayRoad(const std::shared_ptr<sim::TrafficNode>& inputNode, const std::shared_ptr<sim::TrafficNode>& outputNode) {
    dispatcher.setInputNode(0, inputNode);
    dispatcher.setOutputNode(0, outputNode);

    roadShape.setFillColor(sf::Color(176, 190, 197));

    arrowShape.setPointCount(3);
    arrowShape.setFillColor(sf::Color(207, 216, 220));
}

void OneWayRoad::update(float elapsed) {
    const auto pos1 = dispatcher.getInputNode(0)->getPosition();
    const auto pos2 = dispatcher.getOutputNode(0)->getPosition();

    // size
    const float width = 35;
    const float length = glm::distance(pos1, pos2);
    roadShape.setSize(sf::Vector2f(length, width));
    roadShape.setOrigin(0, width/2);

    // rotation
    const auto right = glm::vec2(1, 0);
    const auto direction = glm::normalize(pos2 - pos1);
    const auto rotation = glm::degrees(glm::orientedAngle(right, direction));
    roadShape.setRotation(rotation);

    // position
    roadShape.setPosition(pos1.x, pos1.y);

    // arrow
    const auto posArrow = (pos1 + pos2) / 2.0f;
    arrowShape.setRadius(width/5);
    arrowShape.setOrigin(width/5, width/5);
    arrowShape.setPosition(posArrow.x, posArrow.y);
    arrowShape.setRotation(rotation + 90);
}

void OneWayRoad::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(roadShape, states);
    target.draw(arrowShape, states);
}

sim::TrafficDispatcher* OneWayRoad::getDispatcher() {
    return &dispatcher;
}
