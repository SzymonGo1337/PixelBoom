#include <SFML/Graphics.hpp>
#include <math.h>

int main(int argv, char** argc) {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "PixelBoom", sf::Style::Titlebar | sf::Style::Close);

    sf::Texture texture;
    texture.loadFromFile("res/player.png");

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(texture.getSize().x * 5, texture.getSize().y * 5));
    rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
    rect.setTexture(&texture);
    rect.setPosition(sf::Vector2f(1280.0f / 2, 720.0f / 2));

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

        window.clear();

        float rotation = (atan2(toMove.x - rect.getPosition().x, toMove.y - rect.getPosition().y)) * 180 / 3.14159265;
        rect.setRotation(-rotation);

        window.draw(rect);

        window.display();
    }
}