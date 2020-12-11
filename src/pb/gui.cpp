#include "gui.hpp"

namespace pb {
    Component::Component() {
        isButton = false;
        rect.setFillColor(sf::Color::Red);
    }

    Component::Component(sf::Vector2f size, sf::Vector2f pos) {
        isButton = false;
        rect.setFillColor(sf::Color::Red);
        rect.setSize(size);
        rect.setPosition(pos);
    }

    void Component::setSize(sf::Vector2f size) {
        rect.setSize(size);
    }

    void Component::setPosition(sf::Vector2f pos) {
        rect.setPosition(pos);
    }

    void Component::setColor(sf::Color color) {
        rect.setFillColor(color);
    }

    void Component::setText(std::string toText, int fontSize, sf::Font font, sf::Color color) {
        text.setFont(font);
        text.setString(toText);

        sf::FloatRect textRect = text.getGlobalBounds();
        sf::FloatRect centerRect = sf::FloatRect(textRect.left, textRect.top, textRect.width / 2, textRect.height / 2);

        text.setPosition(centerRect.left, centerRect.top);
        text.setFillColor(color);
    }

    void Component::draw(sf::RenderWindow &target) {
        target.draw(rect);
        target.draw(text);
    }

    void Component::update(sf::RenderWindow &target, void (*run)()) {
        if(rect.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(target))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && isButton) {
            run();
        }
    }

    GUIManager::GUIManager() {
        
    }

    void GUIManager::update(sf::RenderWindow &target) {
        for(int i = 0; i < componentList.size(); i++) {
            componentList[i].draw(target);
        }
    }

    void GUIManager::addComponent(Component component) {
        componentList.push_back(component);
    }
        
    void GUIManager::deleteComponent(int index) {
        componentList.erase(componentList.begin() + index);
    }
    
    void GUIManager::deleteComponents() {
        componentList.erase(componentList.begin(), componentList.begin() + componentList.size());
    }
};