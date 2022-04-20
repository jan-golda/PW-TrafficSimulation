#include "TrafficNode.h"

using namespace sim;


bool TrafficNode::empty() const {
    return queue.empty();
}

TrafficEntity* TrafficNode::front() const {
    return queue.front();
}

void TrafficNode::pop() {
    queue.pop();
}

void TrafficNode::push(TrafficEntity* entity) {
    queue.push(entity);
}

TrafficNode::TrafficNode() : TrafficNode(0,0) {}

TrafficNode::TrafficNode(float x, float y) : position(x,y) {}

const glm::vec2& TrafficNode::getPosition() const {
    return position;
}
