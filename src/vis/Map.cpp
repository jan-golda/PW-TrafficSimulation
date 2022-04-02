#include "Map.h"

using namespace vis;

void Map::update(float elapsed) {
    simulation.update(elapsed);
    for (Entity e : entities)
        e.update(elapsed);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const Entity& e : entities)
        target.draw(e);
}
