#include "renderer.hpp"

pb::Entity player("res/player.png", sf::Vector2f(5.0f, 5.0f));

pb::Entity ent1("res/zombie.png", sf::Vector2f(5.0f, 5.0f));

namespace pb {
    Renderer::Renderer() {
        player.setPosition(sf::Vector2f(1280.0f / 2, 720.0f / 2));
        ent1.setPosition(sf::Vector2f(200.0f, 200.0f));
    }

    void Renderer::update(sf::RenderWindow &target, int id) {
        if(id == PB_SCENE_DEBUG) {
            sf::Vector2f mouse = sf::Vector2f(sf::Mouse::getPosition(target));

            //ent1.update(player.getPosition());
            ent1.moveTowards(player.getPosition(), 2.0f);
            ent1.draw(target);

            player.update(mouse);
            player.move();
            player.draw(target);
        }

        if(id == PB_SCENE_MENU) {
            
        }
        
        if(id == PB_SCENE_GAME) {
            
        }
    }
};