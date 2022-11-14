
#include "Game.hpp"

Game::Game(const Graphics &_graphics) {
    graphics = {std::make_shared<Graphics>(_graphics)};

    // map
    map = GameObject{std::vector<Position>{{0.0,  -0.1},
                                           {-1.0, -1.0},
                                           {-1.0, -1.0},
                                           {1.0,  -1.0},
                                           {1.0,  -1.0}}};
    map.collision = true;

    // left border
    left_border = GameObject{std::vector<Position>{{-0.3, -1.0},
                                                   {-1.0, -0.3},
                                                   {-1.0, -1.0}}};
    left_border.collision = true;

    // right border
    right_border = GameObject{std::vector<Position>{{0.3, -1.0},
                                                    {1.0, -0.3},
                                                    {1.0, -1.0}}};
    right_border.collision = true;
}

void Game::update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration) {
    game_objects.clear();

    // insert map parts
    game_objects.emplace_back(map);
    game_objects.emplace_back(left_border);
    game_objects.emplace_back(right_border);

    // bullets
    std::vector<GameObject> active_bullets{BulletManager::get_instance().get_active_bullets_game_objects()};
    game_objects.insert(game_objects.end(), active_bullets.begin(), active_bullets.end());

    // player
    std::vector<GameObject> player_game_objects{player.get_game_objects()};
    game_objects.insert(game_objects.end(), player_game_objects.begin(), player_game_objects.end());

    // enemy
    std::vector<GameObject> enemy_game_objects{enemy.get_game_objects()};
    game_objects.insert(game_objects.end(), enemy_game_objects.begin(), enemy_game_objects.end());

    // update player
    if (CollisionDetection::check_collision(player.get_body(), map)
        || CollisionDetection::check_collision(player.get_body(), left_border)
        || CollisionDetection::check_collision(player.get_body(), right_border)
            ) {
        player.translation -= Position{0.0, gravity};
    } else {
        player.translation += Position{0.0, gravity};
    }

    // update enemy
    if (CollisionDetection::check_collision(enemy.get_body(), map)
        || CollisionDetection::check_collision(enemy.get_body(), left_border)
        || CollisionDetection::check_collision(enemy.get_body(), right_border)
            ) {
        enemy.translation -= Position{0.0, gravity};
    } else {
        enemy.translation += Position{0.0, gravity};
    }
}

void Game::draw_game() {
    for (const GameObject &game_object: game_objects) {
        graphics->drawGameObject(game_object);
    }
}
