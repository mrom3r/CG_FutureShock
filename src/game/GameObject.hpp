
#ifndef FUTURESHOCK_GAMEOBJECT_HPP
#define FUTURESHOCK_GAMEOBJECT_HPP

#include <vector>
#include "Position.hpp"

struct GameObject {

    std::vector<Position> positions{};

    Position translation{};

    float rotation{};
    Position rotation_point{};

    GameObject() = default;

    explicit GameObject(std::vector<Position> positions);

};


#endif //FUTURESHOCK_GAMEOBJECT_HPP
