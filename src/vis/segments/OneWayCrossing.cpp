#include "OneWayCrossing.h"

using namespace vis;

OneWayCrossing::OneWayCrossing(float x, float y, float rotation) {
    const auto crossingPosition = sf::Vector2f(x, y);

    const float roadWidth = 35;
    const float roadLength = 60;
    const float crossingLength = roadWidth + 2 * 5;
    const float crossingWidth = 30;
    const float crossingOffset = 7;

    // setup nodes
    sf::Vector2f points[6] = {
            {0, -roadLength / 2},
            {+crossingLength / 2, -crossingOffset},
            {+crossingLength / 2, +crossingOffset},
            {0, +roadLength / 2},
            {-crossingLength / 2, +crossingOffset},
            {-crossingLength / 2, -crossingOffset},
    };

    sf::Transform transform;
    transform.translate(crossingPosition);
    transform.rotate(rotation);

    for (auto & point : points)
        point = transform.transformPoint(point);

    for (int i = 0; i < 6; ++i)
        nodes[i] = std::make_shared<sim::TrafficNode>(points[i].x, points[i].y);

    dispatcher.setInputNode(0, nodes[0]);
    dispatcher.setInputNode(1, nodes[1]);
    dispatcher.setInputNode(2, nodes[4]);
    dispatcher.setOutputNode(0, nodes[3]);
    dispatcher.setOutputNode(1, nodes[5]);
    dispatcher.setOutputNode(2, nodes[2]);

    // setup road
    roadShape.setFillColor(sf::Color(176, 190, 197));
    roadShape.setSize(sf::Vector2f(roadWidth, roadLength));
    roadShape.setOrigin(roadWidth/2, roadLength/2);
    roadShape.setPosition(crossingPosition);
    roadShape.setRotation(rotation);

    // setup crossing stripes
    const float stripeWidth = roadWidth / 7;
    for (int i = 0; i < 3; ++i) {
        stripeShapes[i].setFillColor(sf::Color(207, 216, 220));
        stripeShapes[i].setSize(sf::Vector2f(stripeWidth, crossingWidth * 0.8f));
        stripeShapes[i].setOrigin(roadWidth/2.0f - stripeWidth * (1.0f+2.0f*i), crossingWidth * 0.4f);
        stripeShapes[i].setPosition(crossingPosition);
        stripeShapes[i].setRotation(rotation);
    }
}

void OneWayCrossing::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(roadShape, states);
    for (const auto & stripeShape : stripeShapes)
        target.draw(stripeShape, states);
}

sim::TrafficDispatcher* OneWayCrossing::getDispatcher() {
    return &dispatcher;
}

std::shared_ptr<sim::TrafficNode> OneWayCrossing::getNode(std::size_t i) {
    return nodes[i];
}
