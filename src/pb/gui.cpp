#include "gui.hpp"

namespace pb {
    Component::Component() {
        rect.setFillColor(sf::Color::Red);
    }

    Component::Component(sf::Vector2f size, sf::Vector2f pos) {
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

    void Component::draw(sf::RenderWindow &target) {
        target.draw(rect);
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