#include "entity.hpp"

namespace pb {
    Entity::Entity() {
        rect.setSize(sf::Vector2f(32.0f * 5, 32.0f * 5));
        rect.setFillColor(sf::Color::Red);
        rect.setOrigin(sf::Vector2f(rect.getSize().x / 2, rect.getSize().y / 2));
    }

    Entity::Entity(std::string filename, sf::Vector2f multiplier) {
        if(!texture.loadFromFile(filename)) {
            HandleError();
        }


        rect.setSize(sf::Vector2f(texture.getSize().x * multiplier.x, texture.getSize().y * multiplier.y));
        rect.setTexture(&texture);
        rect.setOrigin(sf::Vector2f(rect.getSize().x / 2, rect.getSize().y / 2));
    }

    void Entity::setPosition(sf::Vector2f pos) {
        rect.setPosition(pos);
    }

    void Entity::update(sf::Vector2f toMove) {
        float rotation = (atan2(toMove.x - rect.getPosition().x, toMove.y - rect.getPosition().y)) * 180 / 3.14159265;
        rect.setRotation(-rotation);
    }

    void Entity::draw(sf::RenderTarget &target) {
        target.draw(rect);
    }

    void Entity::move(float speed) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            rect.move(sf::Vector2f(0.0f, -speed));
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            rect.move(sf::Vector2f(0.0f, speed));
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            rect.move(sf::Vector2f(-speed, 0.0f));
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            rect.move(sf::Vector2f(speed, 0.0f));
        }
    }

    void Entity::moveTowards(sf::Vector2f point, float speed) {
        float rotation = (atan2(point.x - rect.getPosition().x, point.y - rect.getPosition().y)) * 180 / 3.14159265;
        float dx = cos(-rotation) * speed;
        float dy = sin(-rotation) * speed;
        rect.setPosition(rect.getPosition() + sf::Vector2f(dx, dy));
        rect.setRotation(-rotation);
    }

    float Entity::distance(sf::Vector2f point) {
        return sqrt((rect.getPosition().x - point.x) * (rect.getPosition().x - point.x) + (rect.getPosition().y - point.y) * (rect.getPosition().y - point.y));
    }

};