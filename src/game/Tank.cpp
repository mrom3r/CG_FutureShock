
#include "Tank.hpp"

Tank::Tank(Position _translation, Color _color) : translation(_translation), color(_color) {
    std::vector<Position> body_positions{{-0.05, -0.025},
                                         {-0.04, -0.04},
                                         {0.04,  -0.04},
                                         {0.05,  -0.025},
                                         {0.05,  0.025},
                                         {-0.05, 0.025}};
    body = GameObject{body_positions};
    body.collision = true;
    game_objects.push_back(body);

    GameObject tower{rectangle_positions({}, 0.05, 0.03),
                     {0.0f, 0.04}};
    game_objects.push_back(tower);

    canon = GameObject{rectangle_positions({}, 0.1, 0.01), {0.0f, 0.05}, 270, {}};
}

std::vector<GameObject> Tank::get_game_objects() {
    std::vector<GameObject> tmp_game_objects = {game_objects};
    for (GameObject &gameObject: tmp_game_objects) {
        gameObject.translation += translation;
        gameObject.rotation += rotation;
    }

    GameObject tmp_canon{canon};

    tmp_canon.translation += translation;
    tmp_canon.rotation += rotation;

    tmp_game_objects.emplace_back(tmp_canon);

    for (GameObject& gameObject : tmp_game_objects) {
        gameObject.color = color;
    }

    return tmp_game_objects;
}

void Tank::lift_canon() {
    if (canon.rotation < 310) {
        canon.rotation += canon_speed;
    }
}

void Tank::lower_canon() {
    if (canon.rotation > 230) {
        canon.rotation -= canon_speed;
    }
}

void Tank::shoot_canon() {
    auto time_difference = std::chrono::steady_clock::now() - last_shot;
    if (time_difference > reloading_time) {
        std::cout << "shot" << std::endl;
        // TODO determine direction
        BulletManager::get_instance().create_bullet(translation, {0.01, 0.01});
        last_shot = std::chrono::steady_clock::now();
    }
}

GameObject Tank::get_body() {
    GameObject tmp_game_object{body};

    tmp_game_object.translation += translation;
    tmp_game_object.rotation += rotation;

    return tmp_game_object;
}
