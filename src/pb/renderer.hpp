#pragma once
#ifndef   PIXELBOOM_RENDERER
#define   PIXELBOOM_RENDERER

#include "core.hpp"
#include "entity.hpp"
#include "gui.hpp"

namespace pb {

    class Renderer {
    public:
        Renderer();

        void update(sf::RenderWindow &target, int id);
    };

};

#endif // PIXELBOOM_RENDERER