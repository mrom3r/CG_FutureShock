
#ifndef FUTURESHOCK_GAMEOBJECT_HPP
#define FUTURESHOCK_GAMEOBJECT_HPP

#include <vector>
#include "Position.hpp"
#include "Color.hpp"

struct GameObject {

    enum Type {DEFAULT, MAP, TANK, BULLET};

    Type type{DEFAULT};

    unsigned int id{};

    unsigned int tank_id{};

    std::vector<Position> positions{};

    Position translation{};

    float rotation{};
    Position rotation_point{};

    Color color{0.0, 0.5, 1.0};

    GameObject() = default;

    explicit GameObject(std::vector<Position> positions, const Position &translation = {}, float rotation = 0,
                        const Position &rotationPoint = {});

};


#endif //FUTURESHOCK_GAMEOBJECT_HPP
