
#include "Game.hpp"

Game::Game(const Graphics &_graphics) {
    graphics = {std::make_shared<Graphics>(_graphics)};
}

void Game::update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration) {
    game_objects.clear();

    //background
    game_objects.emplace_back(GameObject{
            {{0.0, -0.6}, {-1.0, -0.4}, {-1.0, -1.0}, {1.0, -1.0}, {1.0, -0.3}}}
    );

    // player
    GameObject player{rectangle_positions({}, 0.1, 0.05), {-0.6f, -0.46}, 10};
    game_objects.push_back(player);

    // enemy
    GameObject enemy{rectangle_positions({}, 0.1, 0.05), {0.6f, -0.4}, -16};
    game_objects.push_back(enemy);
}

void Game::draw_game() {
    for (const GameObject &game_object: game_objects) {
        graphics->drawGameObject(game_object);
    }
}
