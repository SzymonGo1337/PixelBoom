#include "entity.hpp"

namespace pb {
    Entity::Entity() {
        maxSpeed = 4.0f;
        acceleration = 1.5f;
        decelaration = 0.1f;
        position = sf::Vector2f(100.0f, 100.0f);

        rect.setSize(sf::Vector2f(32.0f * 5, 32.0f * 5));
        rect.setFillColor(sf::Color::Red);
        rect.setOrigin(sf::Vector2f(rect.getSize().x / 2, rect.getSize().y / 2));
    }

    Entity::Entity(std::string filename, sf::Vector2f multiplier) {
        maxSpeed = 4.0f;
        acceleration = 1.5f;
        decelaration = 0.1f;
        position = sf::Vector2f(100.0f, 100.0f);

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

    void Entity::move() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            velocity.y -= acceleration;
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            velocity.y += acceleration;
        } else {
            velocity.y *= decelaration;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity.x -= acceleration;
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocity.x += acceleration;
        } else {
            velocity.x *= decelaration;
        }

        if(velocity.x < -maxSpeed) velocity.x = -maxSpeed;
        if(velocity.x > maxSpeed) velocity.x = maxSpeed;
        if(velocity.y < -maxSpeed) velocity.y = -maxSpeed;
        if(velocity.y > maxSpeed) velocity.y = maxSpeed;

        position += velocity;
        rect.setPosition(position);
    }

    void Entity::moveTowards(sf::Vector2f point, float speed) {
        update(point);
        float dx = cos(rect.getRotation()) * speed;
        float dy = sin(rect.getRotation()) * speed;
        rect.setPosition(sf::Vector2f(rect.getPosition().x + dx, rect.getPosition().y + dy));
    }

    float Entity::distance(sf::Vector2f point) {
        return sqrt((rect.getPosition().x - point.x) * (rect.getPosition().x - point.x) + (rect.getPosition().y - point.y) * (rect.getPosition().y - point.y));
    }

};