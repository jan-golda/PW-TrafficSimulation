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
}

void OneWayRoad::update(float elapsed) {
    auto pos1 = dispatcher.getInputNode(0)->getPosition();
    auto pos2 = dispatcher.getOutputNode(0)->getPosition();

    // size
    float width = 35;
    float length = glm::distance(pos1, pos2);
    roadShape.setSize(sf::Vector2f(length, width));
    roadShape.setOrigin(0, width/2);

    // rotation
    auto right = glm::vec2(1, 0);
    auto direction = glm::normalize(pos2 - pos1);
    roadShape.setRotation(glm::degrees(glm::orientedAngle(right, direction)));

    // position
    roadShape.setPosition(pos1.x, pos1.y);
}

void OneWayRoad::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(roadShape, states);
}

sim::TrafficDispatcher* OneWayRoad::getDispatcher() {
    return &dispatcher;
}
