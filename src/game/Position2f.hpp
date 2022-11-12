#ifndef FUTURESHOCK_POSITION2F_HPP
#define FUTURESHOCK_POSITION2F_HPP

struct Position2f {

    float x{};
    float y{};

    Position2f() = default;

    Position2f(float x, float y) : x(x), y(y) {}

};

#endif //FUTURESHOCK_POSITION2F_HPP
