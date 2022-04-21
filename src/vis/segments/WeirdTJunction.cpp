#include "WeirdTJunction.h"


using namespace vis;

WeirdTJunction::WeirdTJunction(float x, float y, float rotation) {
    const auto junctionPosition = sf::Vector2f(x, y);

    const float laneWidth = 35;
    const float laneLength = 45;

    // setup nodes
    sf::Vector2f points[4] = {
            {+laneLength, 0},
            {+laneWidth/2, +laneLength-laneWidth/2},
            {-laneWidth/2, +laneLength-laneWidth/2},
            {-laneLength, 0}
    };

    sf::Transform transform;
    transform.translate(junctionPosition);
    transform.rotate(rotation);

    for (auto & point : points)
        point = transform.transformPoint(point);

    for (int i = 0; i < 4; ++i)
        nodes[i] = std::make_shared<sim::TrafficNode>(points[i].x, points[i].y);

    dispatcher.setInputNode(0, nodes[3]);
    dispatcher.setInputNode(1, nodes[1]);
    dispatcher.setOutputNode(0, nodes[0]);
    dispatcher.setOutputNode(1, nodes[2]);

    // setup roads
    roadShapes[0].setSize(sf::Vector2f(laneLength * 2, laneWidth));
    roadShapes[0].setOrigin(laneLength, laneWidth/2);
    roadShapes[1].setSize(sf::Vector2f(laneWidth * 2, laneLength-laneWidth));
    roadShapes[1].setOrigin(laneWidth, -laneWidth/2);

    for (auto & road : roadShapes) {
        road.setFillColor(sf::Color(176, 190, 197));
        road.setPosition(junctionPosition);
        road.setRotation(rotation);
    }
}

std::shared_ptr<sim::TrafficNode> WeirdTJunction::getNode(std::size_t i) {
    return nodes[i];
}

sim::TrafficDispatcher* WeirdTJunction::getDispatcher() {
    return &dispatcher;
}

void WeirdTJunction::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto & roadShape : roadShapes)
        target.draw(roadShape, states);
}
