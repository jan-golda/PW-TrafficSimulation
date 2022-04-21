#include "SidewalkCorner.h"

using namespace vis;

SidewalkCorner::SidewalkCorner(float x, float y, float rotation) {
    const float sidewalkWidth = 30;
    const float sidewalkOffset = 7;

    // setup nodes
    sf::Vector2f points[2] = {
            {sidewalkOffset, sidewalkOffset},
            {-sidewalkOffset, -sidewalkOffset}
    };

    sf::Transform transform;
    transform.translate(x, y);
    transform.rotate(rotation);

    for (auto & point : points)
        point = transform.transformPoint(point);

    for (int i = 0; i < 2; ++i)
        nodes[i] = std::make_shared<sim::TrafficNode>(points[i].x, points[i].y);

    // setup shape
    circleShape.setFillColor(sf::Color(207, 216, 220));
    circleShape.setRadius(sidewalkWidth / 2);
    circleShape.setOrigin(sidewalkWidth / 2, sidewalkWidth / 2);
    circleShape.setPosition(x, y);
}

void SidewalkCorner::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(circleShape, states);
}

std::shared_ptr<sim::TrafficNode> SidewalkCorner::getNode(std::size_t i) const {
    return nodes[i];
}
