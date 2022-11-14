
#ifndef FUTURESHOCK_POSITION_HPP
#define FUTURESHOCK_POSITION_HPP

struct Position {

    float x{};
    float y{};

    Position() = default;

    Position(float x, float y) : x(x), y(y) {}

    Position operator+(Position position) {
        this->x += position.x;
        this->y += position.y;
        return *this;
    }

    Position operator-(Position position) {
        this->x -= position.x;
        this->y -= position.y;
        return *this;
    }

    Position operator+=(Position position) {
        this->x += position.x;
        this->y += position.y;
        return *this;
    }

    Position operator-=(Position position) {
        this->x -= position.x;
        this->y -= position.y;
        return *this;
    }

};

#endif //FUTURESHOCK_POSITION_HPP
