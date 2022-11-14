
#ifndef FUTURESHOCK_TANK_HPP
#define FUTURESHOCK_TANK_HPP

#include <vector>
#include "GameObject.hpp"
#include "Tools.hpp"

class Tank {

    std::vector<GameObject> game_objects{};
    GameObject canon{};

    float canon_speed{1.0f};

public:

    Position translation{};
    float rotation{};

    explicit Tank(Position _translation = {0.0, 0.0});

    std::vector<GameObject> get_game_objects();

    void lift_canon();

    void lower_canon();

};


#endif //FUTURESHOCK_TANK_HPP
