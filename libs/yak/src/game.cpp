#include "game.hpp"

using namespace Yak;

namespace {
    bool is_running = false;
}

Game::Game() {
    this->window = nullptr;
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::Init(const Config& config) {
    YAK_ASSERT(SDL_Init(SDL_INIT_VIDEO) != 0, "SDL_Init Error: " + std::string(SDL_GetError()));
    YAK_ASSERT(is_running, "Game is already running");

    is_running = true;
    this->window = SDL_CreateWindow(
        config.name,
        0,
        2500,
        config.width,
        config.height,
        SDL_WINDOW_SHOWN);
        
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Call on_init callback if not null    
    if(config.on_init) {
        config.on_init();
    }
}

void Game::HandleEvents(InputState& state) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            is_running = false; // Exit the loop if the window is closed
        } else if (event.type == SDL_KEYDOWN) {
            state.keyboard.on_press((Key)event.key.keysym.scancode);
        } else if (event.type == SDL_KEYUP) {
            state.keyboard.on_release((Key)event.key.keysym.scancode);
        }
    }

    // Update input state
    Input::step();
}

void Game::Update() {
    HandleEvents(Input::state);
    
    // Update all objects
    for (auto obj : objects) {
        obj->Update();
    }
}

bool Game::IsRunning() {
    return is_running;
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // Draw all objects
    for (auto obj : objects) {
        obj->Draw(renderer);
    }
    
    SDL_RenderPresent(renderer);
}

void Game::Start() {
    while (is_running) {
        Update();
        Render();
    }
}

void Game::AddObject(GameObject* obj) {
    objects.push_back(obj);
}

void Game::RemoveObject(GameObject* obj) {
    auto it = std::find(objects.begin(), objects.end(), obj);
    if (it != objects.end()) {
        objects.erase(it);
    }
}