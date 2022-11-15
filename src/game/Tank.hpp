
#ifndef FUTURESHOCK_TANK_HPP
#define FUTURESHOCK_TANK_HPP

#include <vector>
#include <iostream>
#include <chrono>
#include <memory>
#include "GameObject.hpp"
#include "Tools.hpp"
#include "BulletManager.hpp"

class Tank {

    bool alive{true};
    int start_lives{10};
    int lives{start_lives};

    std::vector<GameObject> game_objects{};
    Color color{};

    GameObject body{};
    GameObject canon{};

    const float canon_speed{1.0f};
    std::chrono::milliseconds reloading_time{500};
    std::chrono::time_point<std::chrono::steady_clock> last_shot{};

    const float bullet_speed{0.035f};

public:

    unsigned int tank_id{};

    Position translation{};
    float rotation{};

    Tank() = default;

    explicit Tank(Position _translation = {0.0, 0.0}, Color _color = {});

    std::vector<GameObject> get_game_objects();

    void lift_canon();

    void lower_canon();

    void shoot_canon();

    GameObject get_body();

    void was_hit();

};


#endif //FUTURESHOCK_TANK_HPP
