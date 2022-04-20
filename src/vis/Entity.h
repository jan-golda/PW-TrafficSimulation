#ifndef PW_TRAFFICSIMULATION_ENTITY_H
#define PW_TRAFFICSIMULATION_ENTITY_H


#include <SFML/Graphics.hpp>
#include "../sim/TrafficEntity.h"

namespace vis {

    /**
     * Abstract class that represents TrafficEntity in the visualization.
     */
    class Entity : public sf::Drawable, private sf::Transformable {
    public:
        /**
         * Updates the entity position and rotation based on the TrafficEntity position.
         * @param elapsed Time (in seconds) from the last logic update.
         */
        void update(float elapsed);

        /**
         * Returns the TrafficEntity represented by this entity.
         * @return reference to TrafficEntity.
         */
        sim::TrafficEntity& getTrafficEntity();

    protected:

        /**
         * Creates the entity.
         * @param drawable object that will be used in `draw()`.
         * @param maxSpeed maximum speed (units/s) of the entity
         * @param maxRotationSpeed maximum rotation speed (radian/s) of the entity
         */
        Entity(Drawable* drawable, float maxSpeed, float maxRotationSpeed);

        /**
         * A hook called whenever the entity should be displayed by SFML.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        /**
         * Drawable object that will be used in `draw()`.
         */
        sf::Drawable* drawable;

        /**
         * Simulation entity that is represented by this visualization entity.
         */
        sim::TrafficEntity trafficEntity;

    };

    /**
     * Representation of the Entity that looks like a car.
     */
    class Car : public Entity {
    private:
        sf::ConvexShape shape;
    public:
        Car();
    };

    /**
     * Representation of the Entity that looks like a pedestrian.
     */
    class Pedestrian : public Entity {
    private:
        sf::CircleShape shape;
    public:
        Pedestrian();
    };

    /**
     * Possible entity colors.
     */
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
