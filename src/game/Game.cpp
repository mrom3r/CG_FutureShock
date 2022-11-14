
#include "Game.hpp"

Game::Game(const Graphics &_graphics) {
    graphics = {std::make_shared<Graphics>(_graphics)};

    //background
    background = {{{0.0, -0.6}, {-1.0, -0.4}, {-1.0, -1.0}, {1.0, -1.0}, {1.0, -0.3}}};

    // player
    Tank player{{-0.5, 0.0}};
    std::vector<GameObject> player_game_objects{player.get_game_objects()};
    permanent_game_objects.insert(permanent_game_objects.end(), player_game_objects.begin(), player_game_objects.end());

    // enemy
    Tank enemy{{0.5, 0.0}};
    std::vector<GameObject> enemy_game_objects{enemy.get_game_objects()};
    permanent_game_objects.insert(permanent_game_objects.end(), enemy_game_objects.begin(), enemy_game_objects.end());
}

void Game::update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration) {
    game_objects.clear();

    // update gravity
    for (GameObject &gameObject: permanent_game_objects) {
        gameObject.translation += {0.0, gravity};
    }

    // insert all permanent game objects
    game_objects.insert(game_objects.end(), permanent_game_objects.begin(), permanent_game_objects.end());

    // insert background
    game_objects.emplace_back(background);
}

void Game::draw_game() {
    for (const GameObject &game_object: game_objects) {
        graphics->drawGameObject(game_object);
    }
}
