
#include "Game.hpp"

Game::Game(const Graphics& _graphics) {
    graphics = {std::make_shared<Graphics>(_graphics)};

    // initialize game
    game_objects.emplace_back(Shape{{{-1.0, 0.0}, {-1.0, -1.0}, {0.0, 0.0}}});
}

void Game::update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration) {

}

void Game::draw_game() {
    for (const GameObject& game_object : game_objects) {
       graphics->drawGameObject(game_object);
    }
}
