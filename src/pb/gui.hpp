#pragma once
#ifndef   PIXELBOOM_GUI
#define   PIXELBOOM_GUI

#include "core.hpp"
#include "entity.hpp"

namespace pb {
    
    class Component {
    public:
        Component();
        Component(sf::Vector2f size, sf::Vector2f pos);

        void setSize(sf::Vector2f size);
        void setPosition(sf::Vector2f pos);

        void draw(sf::RenderWindow &target);

    private:
        sf::RectangleShape rect;
    };


    class GUIManager {
    public:
        GUIManager();

        void update(sf::RenderWindow &target);

        void addComponent(Component component);
        void deleteComponent(int index);
        void deleteComponents();


    private:
        std::vector<Component> componentList;
        
    };

};

#endif // PIXELBOOM_GUI