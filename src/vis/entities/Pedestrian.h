#ifndef PW_TRAFFICSIMULATION_PEDESTRIAN_H
#define PW_TRAFFICSIMULATION_PEDESTRIAN_H

#include "Entity.h"

namespace vis {

    /**
     * Representation of the Entity that looks like a pedestrian.
     */
    class Pedestrian : public Entity {
    private:
        sf::CircleShape shape;
    public:
        /**
         * Create a pedestrian entity at given initial coordinates.
         * @param x initial x coordinate.
         * @param y initial y coordinate.
         */
        Pedestrian(float x, float y) : Entity(&shape, x, y, 10, 0.8) {
            shape.setRadius(5);
            shape.setOrigin(5, 5);

            shape.setFillColor(ENTITY_COLORS[rand() % ENTITY_COLORS.size()]);
            shape.setOutlineColor(sf::Color(97, 97, 97));
            shape.setOutlineThickness(1);
        }
    };

}

#endif //PW_TRAFFICSIMULATION_PEDESTRIAN_H
