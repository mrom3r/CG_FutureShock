
#ifndef FUTURESHOCK_SHAPE_HPP
#define FUTURESHOCK_SHAPE_HPP

#include <vector>
#include "Position.hpp"

struct Shape {

    std::vector<Position> positions{};

    Shape() = default;

    explicit Shape(std::vector<Position> positions) : positions(std::move(positions)) {}

};

#endif //FUTURESHOCK_SHAPE_HPP
