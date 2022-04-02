#include "Map.h"

using namespace vis;

void Map::update(float elapsed) {
    simulation.update(elapsed);
    for (auto&& e : entities)
        e->update(elapsed);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (auto&& e : entities)
        target.draw(*e);
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

sim::TrafficSimulation& Map::getTrafficSimulation() {
    return simulation;
}
