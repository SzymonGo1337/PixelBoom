#pragma once
#ifndef   PIXELBOOM_CORE
#define   PIXELBOOM_CORE

#ifdef __unix__
#define PIXELBOOM_UNIX
#elif defined(_WIN32) || defined(WIN32)
#define PIXELBOOM_WINDOWS
#endif

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
#include <math.h>

#include "renderer.hpp"
#include "entity.hpp"
#include "error.hpp"

#define PB_SCENE_DEBUG -1
#define PB_SCENE_MENU 0
#define PB_SCENE_GAME 1

namespace pb {

    class Timer {
    public:
        Timer();

        sf::Clock getClock() { return clock; }
        float getDeltaTime() { deltaTime = clock.restart().asSeconds(); return deltaTime; }

    private:
        sf::Clock clock;
        float deltaTime;
    };



    class Window {
    public:
        Window(int framerate);
        void update();

    private:
        sf::RenderWindow* window;
        bool focus;
    };

};

#endif // PIXELBOOM_CORE