#pragma once
#ifndef   PIXELBOOM_ENTITY
#define   PIXELBOOM_ENTITY

#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>

namespace pb {

    class Entity {
    public:
        Entity(std::string filename, sf::Vector2f multiplier);

        void set(sf::Vector2f pos);
        void update(sf::Vector2f toMove);
        void draw(sf::RenderTarget &target);
        void move(float speed);

    private:
        sf::Texture texture;
        sf::RectangleShape rect;
    };

};

#endif // PIXELBOOM_ENTITY