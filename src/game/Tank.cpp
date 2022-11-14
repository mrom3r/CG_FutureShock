
#include "Tank.hpp"

Tank::Tank() {
    // body
    GameObject player{Game::rectangle_positions({}, 0.1, 0.05)};
    game_objects.push_back(player);
    GameObject player_canon{Game::rectangle_positions({}, 0.05, 0.008), {0.0f, 0.02}, -90};
    game_objects.push_back(player_canon);
}