
#ifndef FUTURESHOCK_GAMEOBJECT_HPP
#define FUTURESHOCK_GAMEOBJECT_HPP

#include <vector>
#include "Position.hpp"

struct GameObject {

    unsigned long long id;

    bool collision = false;

    std::vector<Position> positions{};

    Position translation{};

    float rotation{};
    Position rotation_point{};

    GameObject() = default;

    GameObject(std::vector<Position> positions, const Position &translation = {}, float rotation = 0,
               const Position &rotationPoint = {});

};


#endif //FUTURESHOCK_GAMEOBJECT_HPP
