#include "OneWayRoadCorner.h"

using namespace vis;

OneWayRoadCorner::OneWayRoadCorner(float x, float y) {
    const float roadWidth = 35;

    node = std::make_shared<sim::TrafficNode>(x, y);

    circleShape.setFillColor(sf::Color(176, 190, 197));
    circleShape.setRadius(roadWidth/2);
    circleShape.setOrigin(roadWidth/2, roadWidth/2);
    circleShape.setPosition(x, y);
}

void OneWayRoadCorner::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(circleShape, states);
}

std::shared_ptr<sim::TrafficNode> OneWayRoadCorner::getNode() const {
    return node;
}
