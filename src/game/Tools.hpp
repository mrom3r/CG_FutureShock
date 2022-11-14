
#ifndef FUTURESHOCK_TOOLS_HPP
#define FUTURESHOCK_TOOLS_HPP

static std::vector<Position> rectangle_positions(Position position, float width, float height) {
    float left{width / -2.0f + position.x};
    float right{width / 2.0f + position.x};
    float up{height / 2.0f + position.y};
    float down{height / -2.0f + position.y};

    return {{left,         down},
            {left + width, down},
            {left + width, down + height},
            {left,         down + height}};
}

#endif //FUTURESHOCK_TOOLS_HPP
