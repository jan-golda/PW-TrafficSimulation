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
