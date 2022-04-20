#include "Map.h"

using namespace vis;

void Map::update(float elapsed) {
    // update simulation
    simulation.update(elapsed);

    // update visualization
    for (auto&& segment : segments)
        segment->update(elapsed);
    for (auto&& entity : entities)
        entity->update(elapsed);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (auto&& segment : segments)
        target.draw(*segment);
    for (auto&& entity : entities)
        target.draw(*entity);
}

Car* Map::createCar() {
    auto* car = new Car();
    entities.emplace_back(std::unique_ptr<Entity>(car));
    simulation.registerEntity(&car->getTrafficEntity());
    return car;
}

Pedestrian* Map::createPedestrian() {
    auto* pedestrian = new Pedestrian();
    entities.emplace_back(std::unique_ptr<Entity>(pedestrian));
    simulation.registerEntity(&pedestrian->getTrafficEntity());
    return pedestrian;
}
