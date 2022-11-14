
#ifndef FUTURESHOCK_TANK_HPP
#define FUTURESHOCK_TANK_HPP

#include <vector>
#include "GameObject.hpp"
#include "Game.hpp"

class Tank {

    std::vector<GameObject> game_objects{};
    GameObject canon{};

public:

    Position translation{};
    float rotation{};

    std::vector<GameObject> get_game_objects();

    Tank();
};


#endif //FUTURESHOCK_TANK_HPP
