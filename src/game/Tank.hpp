
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

    std::shared_ptr<BulletManager> bullet_manager{};

    std::vector<GameObject> game_objects{};
    GameObject canon{};

    float canon_speed{1.0f};
    std::chrono::milliseconds reloading_time{1000};
    std::chrono::time_point<std::chrono::steady_clock> last_shot{};

public:

    Position translation{};
    float rotation{};

    Tank() = default;

    explicit Tank(std::shared_ptr<BulletManager> _bullet_manager, Position _translation = {0.0, 0.0});

    std::vector<GameObject> get_game_objects();

    void lift_canon();

    void lower_canon();

    void shoot_canon();

};


#endif //FUTURESHOCK_TANK_HPP
