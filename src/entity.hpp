#pragma once
#ifndef   PIXELBOOM_ENTITY
#define   PIXELBOOM_ENTITY

#include "core.hpp"

namespace pb {

    class Entity {
    public:
        Entity(std::string filename, sf::Vector2f multiplier);

        void setPosition(sf::Vector2f pos);
        void update(sf::Vector2f toMove);
        void draw(sf::RenderTarget &target);
        void move(float speed);

        float distance(sf::Vector2f point);

        sf::Vector2f getPosition() { return rect.getPosition(); }

    private:
        sf::Texture texture;
        sf::RectangleShape rect;
    };

};

#endif // PIXELBOOM_ENTITY