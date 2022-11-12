
#ifndef FUTURESHOCK_POSITION_HPP
#define FUTURESHOCK_POSITION_HPP

#include <stdexcept>

struct Position {

    float x{};
    float y{};

    Position() = default;

    Position(float x, float y) : x(x), y(y) {}

};

#endif //FUTURESHOCK_POSITION_HPP
