#ifndef PW_TRAFFICSIMULATION_ENTITY_H
#define PW_TRAFFICSIMULATION_ENTITY_H


#include <SFML/Graphics.hpp>
#include "../sim/TrafficEntity.h"

namespace map {
    class Entity : public sf::Drawable {
    protected:
        sf::Drawable *drawable;

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    public:
        sim::TrafficEntity trafficEntity;
    };

    class Car : public Entity {
    private:
        sf::ConvexShape shape;
    public:
        Car();
    };

    class Pedestrian : public Entity {
    private:
        sf::CircleShape shape;
    public:
        Pedestrian();
    };

    const std::array<sf::Color, 16> ENTITY_COLORS = {
        sf::Color(229, 115, 115),
        sf::Color(240, 98, 146),
        sf::Color(186, 104, 200),
        sf::Color(149, 117, 205),
        sf::Color(121, 134, 203),
        sf::Color(100, 181, 246),
        sf::Color(79, 195, 247),
        sf::Color(77, 208, 225),
        sf::Color(77, 182, 172),
        sf::Color(129, 199, 132),
        sf::Color(174, 213, 129),
        sf::Color(220, 231, 117),
        sf::Color(255, 241, 118),
        sf::Color(255, 213, 79),
        sf::Color(255, 183, 77),
        sf::Color(255, 138, 101),
    };
}

#endif //PW_TRAFFICSIMULATION_ENTITY_H
