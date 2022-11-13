
#ifndef FUTURESHOCK_GAMEOBJECT_HPP
#define FUTURESHOCK_GAMEOBJECT_HPP

#include <vector>
#include "Position.hpp"

struct GameObject {

    std::vector<Position> positions{};
    float rotation{};
    Position rotation_point{};

    GameObject() = default;

    explicit GameObject(std::vector<Position> shape, float rotation = 0, const Position &rotationPoint = {0.0, 0.0});

};


#endif //FUTURESHOCK_GAMEOBJECT_HPP
