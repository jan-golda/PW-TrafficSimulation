#include <memory>
#include <glm/gtc/constants.hpp>
#include "Map.h"
#include "segments/OneWayRoad.h"
#include "segments/Sidewalk.h"
#include "segments/OneWayCrossing.h"
#include "segments/OneWaySplitJunction.h"
#include "segments/OneWayJoinJunction.h"
#include "segments/TwoWayRoad.h"
#include "segments/TwoWayTJunction.h"
#include "segments/WeirdTJunction.h"
#include "segments/OneWayRoadCorner.h"

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

Car* Map::createCar(float x, float y) {
    auto* car = new Car(x, y);
    entities.emplace_back(std::unique_ptr<Entity>(car));
    simulation.registerEntity(&car->getTrafficEntity());
    return car;
}

Pedestrian* Map::createPedestrian(float x, float y) {
    auto* pedestrian = new Pedestrian(x, y);
    entities.emplace_back(std::unique_ptr<Entity>(pedestrian));
    simulation.registerEntity(&pedestrian->getTrafficEntity());
    return pedestrian;
}

Map::Map() {
    // road corners
    auto rCorner1 = new OneWayRoadCorner(100, 100);
    auto rCorner3 = new OneWayRoadCorner(300, 300);
    auto rCorner4 = new OneWayRoadCorner(100, 500);
    auto rCorner7 = new OneWayRoadCorner(650, 100);
    auto rCorner8 = new OneWayRoadCorner(650, 500);

    // sidewalk nodes
    auto sNode1_0 = std::make_shared<sim::TrafficNode>(200+7, 200+7);
    auto sNode1_1 = std::make_shared<sim::TrafficNode>(200-7, 200-7);
    auto sNode2_0 = std::make_shared<sim::TrafficNode>(400-7, 200+7);
    auto sNode2_1 = std::make_shared<sim::TrafficNode>(400+7, 200-7);
    auto sNode3_0 = std::make_shared<sim::TrafficNode>(400-7, 400-7);
    auto sNode3_1 = std::make_shared<sim::TrafficNode>(400+7, 400+7);
    auto sNode4_0 = std::make_shared<sim::TrafficNode>(200+7, 400-7);
    auto sNode4_1 = std::make_shared<sim::TrafficNode>(200-7, 400+7);

    // crossing
    auto crossing1 = new OneWayCrossing(300, 200, 0);
    auto crossing2 = new OneWayCrossing(200, 300, 90);
    auto crossing3 = new OneWayCrossing(200, 500, 90);

    // junctions
    auto junction1 = new OneWaySplitJunction(300, 100, 0, false);
    auto junction2 = new OneWayJoinJunction(100, 300, 270, false);
    auto junction3 = new TwoWayTJunction(500, 300, 270);
    auto junction4 = new WeirdTJunction(500, 100, 0);
    auto junction5 = new WeirdTJunction(650, 300, 90);
    auto junction6 = new WeirdTJunction(500, 500, 180);

    // roads
    auto road1 = new OneWayRoad(rCorner1->getNode(), junction1->getNode(0));
    auto road2 = new OneWayRoad(junction1->getNode(1), crossing1->getNode(0));
    auto road3 = new OneWayRoad(crossing1->getNode(3), rCorner3->getNode());
    auto road4 = new OneWayRoad(rCorner3->getNode(), crossing2->getNode(0));
    auto road5 = new OneWayRoad(crossing2->getNode(3), junction2->getNode(1));
    auto road6 = new OneWayRoad(junction2->getNode(2), rCorner1->getNode());
    auto road7 = new OneWayRoad(junction1->getNode(2), junction4->getNode(3));
    auto road8 = new TwoWayRoad(junction4->getNode(2), junction3->getNode(0), junction3->getNode(1), junction4->getNode(1));
    auto road9 = new OneWayRoad(junction6->getNode(0), crossing3->getNode(0));
    auto road10 = new OneWayRoad(rCorner4->getNode(), junction2->getNode(0));
    auto road11 = new OneWayRoad(crossing3->getNode(3), rCorner4->getNode());
    auto road12 = new TwoWayRoad(junction3->getNode(5), junction6->getNode(1), junction6->getNode(2), junction3->getNode(4));
    auto road13 = new TwoWayRoad(junction3->getNode(3), junction5->getNode(1), junction5->getNode(2), junction3->getNode(2));
    auto road14 = new OneWayRoad(junction4->getNode(0), rCorner7->getNode());
    auto road15 = new OneWayRoad(rCorner7->getNode(), junction5->getNode(3));
    auto road16 = new OneWayRoad(junction5->getNode(0), rCorner8->getNode());
    auto road17 = new OneWayRoad(rCorner8->getNode(), junction6->getNode(3));

    // sidewalks
    auto sidewalk1 = new Sidewalk(sNode1_0, crossing1->getNode(4), crossing1->getNode(5), sNode1_1);
    auto sidewalk2 = new Sidewalk(crossing1->getNode(2), sNode2_0, sNode2_1, crossing1->getNode(1));
    auto sidewalk3 = new Sidewalk(sNode2_0, sNode3_0, sNode3_1, sNode2_1);
    auto sidewalk4 = new Sidewalk(sNode3_0, sNode4_0, sNode4_1, sNode3_1);
    auto sidewalk5 = new Sidewalk(sNode4_0, crossing2->getNode(1), crossing2->getNode(2), sNode4_1);
    auto sidewalk6 = new Sidewalk(crossing2->getNode(5), sNode1_0, sNode1_1, crossing2->getNode(4));

    //cars
    auto car1 = createCar(rCorner1->getNode()->getPosition().x, rCorner1->getNode()->getPosition().y);
    auto car2 = createCar(rCorner8->getNode()->getPosition().x, rCorner8->getNode()->getPosition().y);
    auto car3 = createCar(rCorner3->getNode()->getPosition().x, rCorner3->getNode()->getPosition().y);
    auto car4 = createCar(rCorner4->getNode()->getPosition().x, rCorner4->getNode()->getPosition().y);

    //pedestrians
    auto pedestrian1 = createPedestrian(sNode1_0->getPosition().x, sNode1_0->getPosition().y);
    auto pedestrian2 = createPedestrian(sNode2_0->getPosition().x, sNode2_0->getPosition().y);
    auto pedestrian3 = createPedestrian(sNode3_0->getPosition().x, sNode3_0->getPosition().y);
    auto pedestrian4 = createPedestrian(sNode4_0->getPosition().x, sNode4_0->getPosition().y);
    auto pedestrian5 = createPedestrian(sNode1_1->getPosition().x, sNode1_1->getPosition().y);
    auto pedestrian6 = createPedestrian(sNode2_1->getPosition().x, sNode2_1->getPosition().y);
    auto pedestrian7 = createPedestrian(sNode3_1->getPosition().x, sNode3_1->getPosition().y);
    auto pedestrian8 = createPedestrian(sNode4_1->getPosition().x, sNode4_1->getPosition().y);

    // position entities
    rCorner1->getNode()->push(&car1->getTrafficEntity());
    rCorner8->getNode()->push(&car2->getTrafficEntity());
    rCorner3->getNode()->push(&car3->getTrafficEntity());
    rCorner4->getNode()->push(&car4->getTrafficEntity());
    sNode1_0->push(&pedestrian1->getTrafficEntity());
    sNode2_0->push(&pedestrian2->getTrafficEntity());
    sNode3_0->push(&pedestrian3->getTrafficEntity());
    sNode4_0->push(&pedestrian4->getTrafficEntity());
    sNode1_1->push(&pedestrian5->getTrafficEntity());
    sNode2_1->push(&pedestrian6->getTrafficEntity());
    sNode3_1->push(&pedestrian7->getTrafficEntity());
    sNode4_1->push(&pedestrian8->getTrafficEntity());

    // register segments
    segments.push_back(std::unique_ptr<MapSegment>(crossing1));
    segments.push_back(std::unique_ptr<MapSegment>(crossing2));
    segments.push_back(std::unique_ptr<MapSegment>(crossing3));
    segments.push_back(std::unique_ptr<MapSegment>(junction1));
    segments.push_back(std::unique_ptr<MapSegment>(junction2));
    segments.push_back(std::unique_ptr<MapSegment>(junction3));
    segments.push_back(std::unique_ptr<MapSegment>(junction4));
    segments.push_back(std::unique_ptr<MapSegment>(junction5));
    segments.push_back(std::unique_ptr<MapSegment>(junction6));
    segments.push_back(std::unique_ptr<MapSegment>(road1));
    segments.push_back(std::unique_ptr<MapSegment>(road2));
    segments.push_back(std::unique_ptr<MapSegment>(road3));
    segments.push_back(std::unique_ptr<MapSegment>(road4));
    segments.push_back(std::unique_ptr<MapSegment>(road5));
    segments.push_back(std::unique_ptr<MapSegment>(road6));
    segments.push_back(std::unique_ptr<MapSegment>(road7));
    segments.push_back(std::unique_ptr<MapSegment>(road8));
    segments.push_back(std::unique_ptr<MapSegment>(road9));
    segments.push_back(std::unique_ptr<MapSegment>(road10));
    segments.push_back(std::unique_ptr<MapSegment>(road11));
    segments.push_back(std::unique_ptr<MapSegment>(road12));
    segments.push_back(std::unique_ptr<MapSegment>(road13));
    segments.push_back(std::unique_ptr<MapSegment>(road14));
    segments.push_back(std::unique_ptr<MapSegment>(road15));
    segments.push_back(std::unique_ptr<MapSegment>(road16));
    segments.push_back(std::unique_ptr<MapSegment>(road17));
    segments.push_back(std::unique_ptr<MapSegment>(sidewalk1));
    segments.push_back(std::unique_ptr<MapSegment>(sidewalk2));
    segments.push_back(std::unique_ptr<MapSegment>(sidewalk3));
    segments.push_back(std::unique_ptr<MapSegment>(sidewalk4));
    segments.push_back(std::unique_ptr<MapSegment>(sidewalk5));
    segments.push_back(std::unique_ptr<MapSegment>(sidewalk6));
    segments.push_back(std::unique_ptr<MapSegment>(rCorner1));
    segments.push_back(std::unique_ptr<MapSegment>(rCorner3));
    segments.push_back(std::unique_ptr<MapSegment>(rCorner4));
    segments.push_back(std::unique_ptr<MapSegment>(rCorner7));
    segments.push_back(std::unique_ptr<MapSegment>(rCorner8));

    // register dispatchers
    simulation.registerDispatcher(crossing1->getDispatcher());
    simulation.registerDispatcher(crossing2->getDispatcher());
    simulation.registerDispatcher(crossing3->getDispatcher());
    simulation.registerDispatcher(junction1->getDispatcher());
    simulation.registerDispatcher(junction2->getDispatcher());
    simulation.registerDispatcher(junction3->getDispatcher());
    simulation.registerDispatcher(junction4->getDispatcher());
    simulation.registerDispatcher(junction5->getDispatcher());
    simulation.registerDispatcher(junction6->getDispatcher());
    simulation.registerDispatcher(road1->getDispatcher());
    simulation.registerDispatcher(road2->getDispatcher());
    simulation.registerDispatcher(road3->getDispatcher());
    simulation.registerDispatcher(road4->getDispatcher());
    simulation.registerDispatcher(road5->getDispatcher());
    simulation.registerDispatcher(road6->getDispatcher());
    simulation.registerDispatcher(road7->getDispatcher());
    simulation.registerDispatcher(road8->getDispatcher());
    simulation.registerDispatcher(road9->getDispatcher());
    simulation.registerDispatcher(road10->getDispatcher());
    simulation.registerDispatcher(road11->getDispatcher());
    simulation.registerDispatcher(road12->getDispatcher());
    simulation.registerDispatcher(road13->getDispatcher());
    simulation.registerDispatcher(road14->getDispatcher());
    simulation.registerDispatcher(road15->getDispatcher());
    simulation.registerDispatcher(road16->getDispatcher());
    simulation.registerDispatcher(road17->getDispatcher());
    simulation.registerDispatcher(sidewalk1->getDispatcher());
    simulation.registerDispatcher(sidewalk2->getDispatcher());
    simulation.registerDispatcher(sidewalk3->getDispatcher());
    simulation.registerDispatcher(sidewalk4->getDispatcher());
    simulation.registerDispatcher(sidewalk5->getDispatcher());
    simulation.registerDispatcher(sidewalk6->getDispatcher());
}
