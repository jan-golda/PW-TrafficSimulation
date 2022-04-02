#include "Map.h"

void vis::Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(const vis::Entity& e : entities)
        target.draw(e);
}

void vis::Map::update(float elapsed) {
    simulation.update(elapsed);
}
