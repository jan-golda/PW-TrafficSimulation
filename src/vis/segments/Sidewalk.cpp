#define GLM_ENABLE_EXPERIMENTAL

#include <glm/geometric.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "Sidewalk.h"

using namespace vis;

Sidewalk::Sidewalk(
        const std::shared_ptr<sim::TrafficNode>& inputNode0,
        const std::shared_ptr<sim::TrafficNode>& outputNode0,
        const std::shared_ptr<sim::TrafficNode>& inputNode1,
        const std::shared_ptr<sim::TrafficNode>& outputNode1
) {
    dispatcher.setInputNode(0, inputNode0);
    dispatcher.setOutputNode(0, outputNode0);
    dispatcher.setInputNode(1, inputNode1);
    dispatcher.setOutputNode(1, outputNode1);

    sidewalkShape.setFillColor(sf::Color(207, 216, 220));
}

void Sidewalk::update(float elapsed) {
    auto posIn0 = dispatcher.getInputNode(0)->position;
    auto posIn1 = dispatcher.getInputNode(1)->position;
    auto posOut0 = dispatcher.getOutputNode(0)->position;
    auto posOut1 = dispatcher.getOutputNode(1)->position;

    auto pos1 = (posIn0 + posOut1) / 2.0f;
    auto pos2 = (posIn1 + posOut0) / 2.0f;

    // size
    float width = 30;
    float length = glm::distance(pos1, pos2);
    sidewalkShape.setSize(sf::Vector2f(length, width));
    sidewalkShape.setOrigin(0, width/2);

    // rotation
    auto right = glm::vec2(1, 0);
    auto direction = glm::normalize(pos2 - pos1);
    sidewalkShape.setRotation(glm::degrees(glm::orientedAngle(right, direction)));

    // position
    sidewalkShape.setPosition(pos1.x, pos1.y);
}

void Sidewalk::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sidewalkShape, states);
}

sim::TrafficDispatcher* Sidewalk::getDispatcher() {
    return &dispatcher;
}
