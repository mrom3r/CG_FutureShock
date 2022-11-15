
#include "Game.hpp"

Game::Game(const Graphics &_graphics) {
    graphics = {std::make_shared<Graphics>(_graphics)};

    // map
    map = GameObject{std::vector<Position>{{0.0,  -0.1},
                                           {-1.0, -1.0},
                                           {-1.0, -1.0},
                                           {1.0,  -1.0},
                                           {1.0,  -1.0}}};
    map.type = GameObject::MAP;

    // left triangle
    left_triangle = GameObject{std::vector<Position>{{-0.3, -1.0},
                                                     {-1.0, -0.3},
                                                     {-1.0, -1.0}}};
    left_triangle.type = GameObject::MAP;

    // right triangle
    right_triangle = GameObject{std::vector<Position>{{0.3, -1.0},
                                                      {1.0, -0.3},
                                                      {1.0, -1.0}}};
    right_triangle.type = GameObject::MAP;
}

void Game::update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration) {
    game_objects.clear();

    // player collision with map
    if (CollisionDetection::check_collision(player.get_body(), map)
        || CollisionDetection::check_collision(player.get_body(), left_triangle)
        || CollisionDetection::check_collision(player.get_body(), right_triangle)
            ) {
        player.translation += gravity;
    } else {
        player.translation -= gravity;
    }

    // enemy collision with map
    if (CollisionDetection::check_collision(enemy.get_body(), map)
        || CollisionDetection::check_collision(enemy.get_body(), left_triangle)
        || CollisionDetection::check_collision(enemy.get_body(), right_triangle)
            ) {
        enemy.translation += gravity;
    } else {
        enemy.translation -= gravity;
    }

    // bullet collision
    std::vector<GameObject> active_bullets{BulletManager::get_instance().get_active_bullets_game_objects()};
    std::vector<GameObject> player_game_objects{player.get_game_objects()};
    std::vector<GameObject> enemy_game_objects{enemy.get_game_objects()};
    for (GameObject &bullet: active_bullets) {
        if (bullet.tank_id != player.tank_id) {
            for (GameObject &player_game_object: player_game_objects) {
                if (CollisionDetection::check_collision(bullet, player_game_object)) {
                    player.was_hit();
                    BulletManager::get_instance().deactivate_bullet(bullet.bullet_id);
                }
            }
        }
        if (bullet.tank_id != enemy.tank_id) {
            for (GameObject &enemy_game_object: enemy_game_objects) {
                if (CollisionDetection::check_collision(bullet, enemy_game_object)) {
                    enemy.was_hit();
                    BulletManager::get_instance().deactivate_bullet(bullet.bullet_id);
                }
            }
        }
    }

    // bullets
    game_objects.insert(game_objects.end(), active_bullets.begin(), active_bullets.end());

    // insert map parts
    game_objects.emplace_back(map);
    game_objects.emplace_back(left_triangle);
    game_objects.emplace_back(right_triangle);

    // insert players
    game_objects.insert(game_objects.end(), player_game_objects.begin(), player_game_objects.end());
    game_objects.insert(game_objects.end(), enemy_game_objects.begin(), enemy_game_objects.end());
}

void Game::draw_game() {
    for (const GameObject &game_object: game_objects) {
        graphics->drawGameObject(game_object);
    }
}
