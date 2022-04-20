#ifndef PW_TRAFFICSIMULATION_CAR_H
#define PW_TRAFFICSIMULATION_CAR_H

#include "Entity.h"

namespace vis {

    /**
     * Representation of the Entity that looks like a car.
     */
    class Car : public Entity {
    private:
        sf::ConvexShape shape;
    public:
        Car(float x, float y) : Entity(&shape, x, y, 40, 0.1) {
            shape.setPointCount(6);
            shape.setPoint(0, sf::Vector2f(5, 0));
            shape.setPoint(1, sf::Vector2f(15, 0));
            shape.setPoint(2, sf::Vector2f(20, 5));
            shape.setPoint(3, sf::Vector2f(20, 30));
            shape.setPoint(4, sf::Vector2f(0, 30));
            shape.setPoint(5, sf::Vector2f(0, 5));
            shape.setOrigin(10, 15);

            shape.setFillColor(ENTITY_COLORS[rand() % ENTITY_COLORS.size()]);
            shape.setOutlineColor(sf::Color(97, 97, 97));
            shape.setOutlineThickness(1);
        }
    };

}

#endif //PW_TRAFFICSIMULATION_CAR_H
