
#ifndef FUTURESHOCK_WINDOWPOSITION2F_HPP
#define FUTURESHOCK_WINDOWPOSITION2F_HPP

#include "GamePosition2f.hpp"

struct WindowPosition2f {

    float x{};
    float y{};

    WindowPosition2f() = default;

    WindowPosition2f(float x, float y) : x(x), y(y) {}
};

#endif //FUTURESHOCK_WINDOWPOSITION2F_HPP
