#include <yak.hpp>

class Square : public Yak::GameObject {
public:
    Square(Yak::Vector2 pos) : GameObject(pos) {}

    void Update() {
        const float speed = 5.0f;
        if (Yak::Input::pressed(Yak::Key::W)) { 
            position.y -= speed;
            std::cout << "Is pressed up" << std::endl;
        }
        if (Yak::Input::pressed(Yak::Key::S)) {
            position.y += speed;
            std::cout << "Moving down" << std::endl;
        }
        if (Yak::Input::pressed(Yak::Key::A)) position.x -= speed;
        if (Yak::Input::pressed(Yak::Key::D)) position.x += speed;
    }

    void Draw(SDL_Renderer* renderer) {
        SDL_Rect rect = {
            (int)position.x, 
            (int)position.y, 
            50, 50
        };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
};

int main() {
    Yak::Config config;
    config.name = "HopeThisWorks";
    config.width = 640;
    config.height = 480; 

    Yak::Game game;
    game.Init(config);

    game.AddObject(new Square({100, 100}));
    game.Start();

    return 0;
}
