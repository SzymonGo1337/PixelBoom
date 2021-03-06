#pragma once
#ifndef   PIXELBOOM_GUI
#define   PIXELBOOM_GUI

#include "core.hpp"
#include "entity.hpp"

namespace pb {
    
    class Component {
    public:
        bool isButton;
        Component();
        Component(sf::Vector2f size, sf::Vector2f pos);

        void setButton() { isButton = true; };
        void setSize(sf::Vector2f size);
        void setPosition(sf::Vector2f pos);
        void setColor(sf::Color color);
        void setText(std::string toText, int fontSize, sf::Font font, sf::Color color);

        void draw(sf::RenderWindow &target);
        void update(sf::RenderWindow &target, void (*run)());

    private:
        sf::Text text;
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