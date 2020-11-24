#include "core.hpp"
#include "renderer.hpp"
#include "entity.hpp"

#include <iostream>

int main(int argv, char** argc) {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "PixelBoom", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    pb::Renderer renderer;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            } else if(event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        window.clear();

        renderer.update(window, PB_SCENE_DEBUG);

        window.display();
    }
}