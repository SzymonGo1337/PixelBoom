#include "entity.hpp"

#include <iostream>

int main(int argv, char** argc) {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "PixelBoom", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    pb::Entity entity("res/player.png", sf::Vector2f(5.0f, 5.0f));
    entity.set(sf::Vector2f(1280.0f / 2, 720.0f / 2));

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            } else if(event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        sf::Vector2f toMove = sf::Vector2f(sf::Mouse::getPosition(window));
        std::cout << entity.distance(toMove) << "\n";

        window.clear();

        entity.update(toMove);
        entity.move(5.0f);
        entity.draw(window);


        window.display();
    }
}