
#ifndef FUTURESHOCK_SHAPE_HPP
#define FUTURESHOCK_SHAPE_HPP

#include <utility>
#include <vector>
#include "Position.hpp"
#include <utility>

struct Shape {

    std::vector<Position> positions{};
    float rotation{};

    Shape() = default;

    Shape(std::vector<Position> positions, float rotation) : positions(std::move(positions)), rotation(rotation) {}

};

#endif //FUTURESHOCK_SHAPE_HPP
