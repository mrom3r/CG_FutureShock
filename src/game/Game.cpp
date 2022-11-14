
#include "Game.hpp"

Game::Game(const Graphics &_graphics) {
    graphics = {std::make_shared<Graphics>(_graphics)};
}

void Game::update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration) {
    game_objects.clear();

    //background
    GameObject background{{{0.0, -0.6}, {-1.0, -0.4}, {-1.0, -1.0}, {1.0, -1.0}, {1.0, -0.3}}};
    game_objects.emplace_back(background);

    // player
    Tank player{};
    player.translation = {-0.5, 0.0};
    std::vector<GameObject> player_game_objects{player.get_game_objects()};
    game_objects.insert(game_objects.end(), player_game_objects.begin(),  player_game_objects.end());

    // enemy
    Tank enemy{};
    enemy.translation = {0.5, 0.0};
    std::vector<GameObject> enemy_game_objects{enemy.get_game_objects()};
    game_objects.insert(game_objects.end(), enemy_game_objects.begin(),  enemy_game_objects.end());
}

void Game::draw_game() {
    for (const GameObject &game_object: game_objects) {
        graphics->drawGameObject(game_object);
    }
}
