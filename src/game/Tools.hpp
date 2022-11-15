
#ifndef FUTURESHOCK_TOOLS_HPP
#define FUTURESHOCK_TOOLS_HPP

#include <complex>

static std::vector<Position> rectangle_positions(Position position, float width, float height) {
    float left{width / -2.0f + position.x};
    float down{height / -2.0f + position.y};

    return {{left,         down},
            {left + width, down},
            {left + width, down + height},
            {left,         down + height}};
}

static std::vector<Position> circle_positions(Position position, float radius, unsigned int count) {
    std::vector<Position> positions{};

    float angle_step{360.0f / static_cast<float>(count)};
    for (int i = 0; i < count; i++) {
        float x = position.x + std::cos(angle_step * static_cast<float>(i)) * radius;
        float y = position.y + std::sin(angle_step * static_cast<float>(i)) * radius;
        positions.emplace_back(Position{x, y});
    }

    return positions;
}

#endif //FUTURESHOCK_TOOLS_HPP
