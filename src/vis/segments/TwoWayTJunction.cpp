#include "TwoWayTJunction.h"


using namespace vis;

TwoWayTJunction::TwoWayTJunction(float x, float y, float rotation) {
    const auto junctionPosition = sf::Vector2f(x, y);

    const float laneWidth = 35;
    const float roadWidth = laneWidth * 2;
    const float roadLength = 90;

    // setup nodes
    sf::Vector2f points[6] = {
            {+roadLength/2, -laneWidth/2},
            {+roadLength/2, +laneWidth/2},
            {+laneWidth/2, +roadLength/2},
            {-laneWidth/2, +roadLength/2},
            {-roadLength/2, +laneWidth/2},
            {-roadLength/2, -laneWidth/2},
    };

    sf::Transform transform;
    transform.translate(junctionPosition);
    transform.rotate(rotation);

    for (auto & point : points)
        point = transform.transformPoint(point);

    for (int i = 0; i < 6; ++i)
        nodes[i] = std::make_shared<sim::TrafficNode>(points[i].x, points[i].y);

    dispatcher.setInputNode(0, nodes[0]);
    dispatcher.setInputNode(1, nodes[4]);
    dispatcher.setInputNode(2, nodes[2]);
    dispatcher.setOutputNode(0, nodes[1]);
    dispatcher.setOutputNode(1, nodes[5]);
    dispatcher.setOutputNode(2, nodes[3]);

    // setup roads
    roadShapes[0].setSize(sf::Vector2f(roadLength, roadWidth));
    roadShapes[0].setOrigin(roadLength/2, roadWidth/2);
    roadShapes[1].setSize(sf::Vector2f(roadWidth, (roadLength - roadWidth)/2));
    roadShapes[1].setOrigin(roadWidth/2, -roadWidth/2);

    for (auto & road : roadShapes) {
        road.setFillColor(sf::Color(176, 190, 197));
        road.setPosition(junctionPosition);
        road.setRotation(rotation);
    }
}

std::shared_ptr<sim::TrafficNode> TwoWayTJunction::getNode(std::size_t i) {
    return nodes[i];
}

sim::TrafficDispatcher* TwoWayTJunction::getDispatcher() {
    return &dispatcher;
}

void TwoWayTJunction::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto & roadShape : roadShapes)
        target.draw(roadShape, states);
}
