#include "core.hpp"

pb::Renderer renderer;
namespace pb {
    Timer::Timer() {
        clock.restart();
    }

    Window::Window(int framerate) {
        window = new sf::RenderWindow(sf::VideoMode(1280, 720), "PixelBoom", sf::Style::Titlebar | sf::Style::Close);
        window->setFramerateLimit(framerate);
        pb::HandleError();
    }

    void Window::update() {
        while(window->isOpen()) {
            sf::Event event;
            while(window->pollEvent(event)) {
                if(event.type == sf::Event::Closed) {
                    window->close();
                } else if(event.key.code == sf::Keyboard::Escape && focus) {
                    window->close();
                }

                if(event.type == sf::Event::GainedFocus) {
                    focus = true;
                } else if(event.type == sf::Event::LostFocus) {
                    focus = false;
                }
            }

            window->clear(sf::Color(81.0f, 57.0f, 153.0f, 255.0f));

            renderer.update(*window, PB_SCENE_DEBUG);

            window->display();
        }
    }
};