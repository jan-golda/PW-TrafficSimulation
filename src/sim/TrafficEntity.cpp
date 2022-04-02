#include "TrafficEntity.h"

void sim::TrafficEntity::update(float elapsed) {
    position += speed * elapsed;
}
