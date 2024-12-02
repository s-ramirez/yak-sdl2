#pragma once
#include <SDL.h>
#include "../utils/vector.hpp"

namespace Yak {

    class GameObject {
    public:
        GameObject(Vector2 pos = {0, 0}) : position(pos) {}
        virtual ~GameObject() = default;

        virtual void Update() {}
        virtual void Draw(SDL_Renderer* renderer) = 0;

        Vector2 position;
    };
} 