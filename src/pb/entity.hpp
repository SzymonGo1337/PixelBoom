#pragma once
#ifndef   PIXELBOOM_ENTITY
#define   PIXELBOOM_ENTITY

#include "core.hpp"

namespace pb {

    class Entity {
    public:
        Entity();
        Entity(std::string filename, sf::Vector2f multiplier);

        void setPosition(sf::Vector2f pos);
        void update(sf::Vector2f toMove);
        void draw(sf::RenderTarget &target);
        void move();

        void normalize(float &x, float &y);
        void moveTowards(sf::Vector2f point, float multiplier);
        float distance(sf::Vector2f point);

        sf::Vector2f getPosition() { return rect.getPosition(); }

    private:
        sf::Texture texture;
        sf::RectangleShape rect;

        sf::Vector2f position;
        sf::Vector2f velocity;
        float maxSpeed;
        float acceleration;
        float decelaration;
    };

};

#endif // PIXELBOOM_ENTITY