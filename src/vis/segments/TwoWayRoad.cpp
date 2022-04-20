#define GLM_ENABLE_EXPERIMENTAL

#include <glm/geometric.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "TwoWayRoad.h"

using namespace vis;

TwoWayRoad::TwoWayRoad(
        const std::shared_ptr<sim::TrafficNode>& inputNode0,
        const std::shared_ptr<sim::TrafficNode>& outputNode0,
        const std::shared_ptr<sim::TrafficNode>& inputNode1,
        const std::shared_ptr<sim::TrafficNode>& outputNode1
) {
    dispatcher.setInputNode(0, inputNode0);
    dispatcher.setOutputNode(0, outputNode0);
    dispatcher.setInputNode(1, inputNode1);
    dispatcher.setOutputNode(1, outputNode1);

    roadShape.setFillColor(sf::Color(176, 190, 197));
    lineShape.setFillColor(sf::Color(207, 216, 220));
}

void TwoWayRoad::update(float elapsed) {
    const auto posIn0 = dispatcher.getInputNode(0)->getPosition();
    const auto posIn1 = dispatcher.getInputNode(1)->getPosition();
    const auto posOut0 = dispatcher.getOutputNode(0)->getPosition();
    const auto posOut1 = dispatcher.getOutputNode(1)->getPosition();

    const auto pos1 = (posIn0 + posOut1) / 2.0f;
    const auto pos2 = (posIn1 + posOut0) / 2.0f;

    // size
    const float width = 35 * 2;
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

    // line
    const float lineWidth = 2;
    lineShape.setSize(sf::Vector2f(length, lineWidth));
    lineShape.setOrigin(0, lineWidth/2);
    lineShape.setRotation(rotation);
    lineShape.setPosition(pos1.x, pos1.y);
}

void TwoWayRoad::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(roadShape, states);
    target.draw(lineShape, states);
}

sim::TrafficDispatcher* TwoWayRoad::getDispatcher() {
    return &dispatcher;
}
