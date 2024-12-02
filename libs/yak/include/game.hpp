#pragma once
#include <SDL.h>
#include "common/config.hpp"
#include "common/common.hpp"
#include "common/input.hpp"
#include <vector>
#include "components/gameobject.hpp"

/*
Main game engine wrapper
*/

namespace Yak {
    class Game {
    public:
        // Constructors
        Game();
        ~Game();

        // Methods
        void Init(const Config& config);
        void Start();

        // Getters
        bool IsRunning();

        void AddObject(GameObject* obj);
        void RemoveObject(GameObject* obj);

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

        // Game loop
        void Update();
        void Render();
        void HandleEvents(InputState& state);

        // Input
        InputState state;

        // Game objects
        std::vector<GameObject*> objects;

    };
}
