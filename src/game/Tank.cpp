
#include <glm/detail/type_mat.hpp>
#include <complex>
#include <glm/vec2.hpp>
#include <glm/detail/type_mat2x2.hpp>
#include "Tank.hpp"

Tank::Tank(Position _translation, Color _color) : translation(_translation), color(_color) {
    static unsigned int counter = 0;
    tank_id = counter++;


    std::vector<Position> body_positions{{-0.05, -0.025},
                                         {-0.04, -0.04},
                                         {0.04,  -0.04},
                                         {0.05,  -0.025},
                                         {0.05,  0.025},
                                         {-0.05, 0.025}};
    body = GameObject{body_positions};
    body.type = GameObject::TANK;
    game_objects.push_back(body);

    GameObject tower{rectangle_positions({}, 0.06, 0.03),
                     {0.0f, 0.04}};
    tower.type = GameObject::TANK;
    game_objects.push_back(tower);

    canon = GameObject{rectangle_positions({}, 0.1, 0.01), {0.0f, 0.05}, 270, {}};
    canon.type = GameObject::TANK;
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

    float color_multiplier{static_cast<float>(lives) / static_cast<float>(start_lives)};
    Color tmp_color{color.red * color_multiplier, color.green * color_multiplier, color.blue * color_multiplier};
    for (GameObject &gameObject: tmp_game_objects) {
        gameObject.color = tmp_color;
    }

    return tmp_game_objects;
}

void Tank::lift_canon() {
    if (canon.rotation < 315) {
        canon.rotation += canon_speed;
    }
}

void Tank::lower_canon() {
    if (canon.rotation > 225) {
        canon.rotation -= canon_speed;
    }
}

void Tank::shoot_canon() {
    auto time_difference = std::chrono::steady_clock::now() - last_shot;
    if (time_difference > reloading_time) {

        float rotation_rad = (canon.rotation + 90.0f) / 180.0f * 3.14159265358979323846f;

        glm::mat2 rotation_matrix{std::sin(rotation_rad), std::cos(rotation_rad),
                                  std::cos(rotation_rad), -std::sin(rotation_rad)};
        glm::vec2 tmp_point{bullet_speed, 0.0f};
        tmp_point = tmp_point * rotation_matrix;

        BulletManager::get_instance().create_bullet(translation + canon.translation, Position{tmp_point.x, tmp_point.y},
                                                    tank_id);
        last_shot = std::chrono::steady_clock::now();
    }
}

GameObject Tank::get_body() {
    GameObject tmp_game_object{body};

    tmp_game_object.translation += translation;
    tmp_game_object.rotation += rotation;

    return tmp_game_object;
}

void Tank::was_hit() {
    lives--;
    if (lives <= 0) {
        alive = false;
    }
}
