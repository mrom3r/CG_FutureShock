
#include "Tank.hpp"

Tank::Tank() {
    GameObject player{Game::rectangle_positions({}, 0.1, 0.05)};
    game_objects.push_back(player);

    GameObject tower{Game::rectangle_positions({}, 0.05, 0.03), {0.0f, 0.04}};
    game_objects.push_back(tower);

    GameObject canon{Game::rectangle_positions({}, 0.12, 0.008), {0.0f, 0.06}, -90};
    game_objects.push_back(canon);
}