#include "OneWaySplitTJunction.h"

using namespace vis;

OneWaySplitTJunction::OneWaySplitTJunction(float x, float y, float rotation, bool left) {
    const auto junctionPosition = sf::Vector2f(x, y);
    const float mirror = (left ? -1.0f : 1.0f);

    const float roadWidth = 35;
    const float roadLength = 60;

    // setup nodes
    sf::Vector2f points[3] = {
            {-roadLength/2, 0},
            {0, roadLength/2 * mirror},
            {+roadLength/2, 0}
    };

    sf::Transform transform;
    transform.translate(junctionPosition);
    transform.rotate(rotation);

    for (auto & point : points)
        point = transform.transformPoint(point);

    for (int i = 0; i < 3; ++i)
        nodes[i] = std::make_shared<sim::TrafficNode>(points[i].x, points[i].y);

    dispatcher.setInputNode(0, nodes[0]);
    dispatcher.setOutputNode(0, nodes[1]);
    dispatcher.setOutputNode(1, nodes[2]);

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

std::shared_ptr<sim::TrafficNode> OneWaySplitTJunction::getNode(std::size_t i) {
    return nodes[i];
}

sim::TrafficDispatcher* OneWaySplitTJunction::getDispatcher() {
    return &dispatcher;
}

void OneWaySplitTJunction::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto & roadShape : roadShapes)
        target.draw(roadShape, states);
}
