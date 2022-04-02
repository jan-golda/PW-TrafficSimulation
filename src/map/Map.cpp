#include "Map.h"

void map::Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(const map::Entity& e : entities)
        target.draw(e);
}

void map::Map::update(float elapsed) {
    simulation.update(elapsed);
}
