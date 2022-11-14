
#include "Game.hpp"

Game::Game(const Graphics &_graphics) {
    graphics = {std::make_shared<Graphics>(_graphics)};

    // map
    map = GameObject{std::vector<Position>{{0.0,  -0.6},
                                           {-1.0, -0.4},
                                           {-1.0, -1.0},
                                           {1.0,  -1.0},
                                           {1.0,  -0.3}}};
    map.collision = true;
}

void Game::update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration) {
    game_objects.clear();

    // insert map
    game_objects.emplace_back(map);

    // bullets
    std::vector<GameObject> active_bullets{BulletManager::get_instance().get_active_bullets_game_objects()};
    game_objects.insert(game_objects.end(), active_bullets.begin(), active_bullets.end());

    // player
    std::vector<GameObject> player_game_objects{player.get_game_objects()};
    game_objects.insert(game_objects.end(), player_game_objects.begin(), player_game_objects.end());

    // enemy
    std::vector<GameObject> enemy_game_objects{enemy.get_game_objects()};
    game_objects.insert(game_objects.end(), enemy_game_objects.begin(), enemy_game_objects.end());

    // update gravity player
    Position old_player_position{player.translation};
    player.translation += {0.0, gravity};
    if (CollisionDetection::check_collision(player.get_body(), map)) {
        player.translation = old_player_position;
    }

    /*
    for (GameObject &game_object : player.get_game_objects()) {
        for (GameObject &other_game_object: game_objects) {
            if (game_object.collision && other_game_object.collision) {
                std::cout << "-------------------------" << std::endl;
                if (CollisionDetection::check_collision(game_object, other_game_object)) {
                    //player.translation = old_player_position + Position{0.0, 0.01};
                    std::cout << "-------------------------" << std::endl;
                    break;
                }
            }
        }
    }
     */

    /*
    enemy.translation += {0.0, gravity};

    // update game objects
    for (GameObject &game_object: game_objects) {
        Position old_translation{game_object.translation};
        // update gravity
        player.translation += {0.0, gravity};
        enemy.translation += {0.0, gravity};
        // check collisions
        for (GameObject &other_game_object: game_objects) {
            if (game_object.id == other_game_object.id || !game_object.collision) continue;
            if (CollisionDetection::check_collision(game_object, other_game_object)) {
                std::cout << "collision" << std::endl;
                game_object.translation = old_translation;
            }
        }
    }
    */
}

void Game::draw_game() {
    for (const GameObject &game_object: game_objects) {
        graphics->drawGameObject(game_object);
    }
}
