
#ifndef FUTURESHOCK_GAMEOBJECT_HPP
#define FUTURESHOCK_GAMEOBJECT_HPP

#include "game/structs/Shape.hpp"
#include "game/structs/Position.hpp"

struct GameObject {

    Shape shape{};
    float rotation{};
    Position rotation_point{};

    GameObject() = default;

    explicit GameObject(Shape shape, float rotation = 0, const Position &rotationPosition = {0.0, 0.0});

};


#endif //FUTURESHOCK_GAMEOBJECT_HPP
