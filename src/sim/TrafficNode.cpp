#include "TrafficNode.h"

using namespace sim;

int TrafficNode::getLimit() const {
    return queueLimit;
}

void TrafficNode::setLimit(int limit) {
    queueLimit = limit;
}

int TrafficNode::getSize() const {
    return (int) queue.size();
}

bool TrafficNode::isFull() const {
    return getSize() >= getLimit();
}

bool TrafficNode::push(TrafficEntity* entity) {
    if (isFull()) return false;
    queue.push(entity);
    return true;
}

TrafficEntity* TrafficNode::pop() {
    TrafficEntity* e = queue.front();
    queue.pop();
    return e;
}

TrafficEntity* TrafficNode::peek() const {
    return queue.front();
}
