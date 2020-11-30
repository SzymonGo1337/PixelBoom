#include "renderer.hpp"

pb::Entity player("res/player.png", sf::Vector2f(5.0f, 5.0f));

pb::Entity ent1("res/zombie.png", sf::Vector2f(5.0f, 5.0f));

pb::Component com1(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(0.0f, 0.0f));
pb::GUIManager manager;

namespace pb {
    Renderer::Renderer() {
        player.setPosition(sf::Vector2f(1280.0f / 2, 720.0f / 2));
        ent1.setPosition(sf::Vector2f(200.0f, 200.0f));

        manager.addComponent(com1);
    }

    void Renderer::update(sf::RenderWindow &target, int id) {
        if(id == PB_SCENE_DEBUG) {
            sf::Vector2f mouse = sf::Vector2f(sf::Mouse::getPosition(target));

            player.update(mouse);
            player.move(5.0f);
            player.draw(target);

            ent1.update(player.getPosition());
            ent1.draw(target);

            manager.update(target);
        }

        if(id == PB_SCENE_MENU) {
            
        }
        
        if(id == PB_SCENE_GAME) {
            
        }
    }
};