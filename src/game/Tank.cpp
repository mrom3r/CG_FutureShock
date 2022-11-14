
#include "Tank.hpp"

Tank::Tank(Position _translation) : translation(_translation) {
    GameObject body{Game::rectangle_positions({}, 0.1, 0.05)};
    body.collision = true;
    game_objects.push_back(body);

    GameObject tower{Game::rectangle_positions({}, 0.05, 0.03), {0.0f, 0.04}};
    game_objects.push_back(tower);

    canon = GameObject{Game::rectangle_positions({}, 0.12, 0.008), {0.0f, 0.06}, -90};
}

std::vector<GameObject> Tank::get_game_objects() {
    std::vector<GameObject> tmp_game_objects = {game_objects};
    for (GameObject &gameObject: tmp_game_objects) {
        gameObject.translation += translation;
        gameObject.rotation += rotation;
    }

    canon.translation += translation;
    canon.rotation += rotation;
    tmp_game_objects.emplace_back(canon);

    return tmp_game_objects;
}