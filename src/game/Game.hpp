
#ifndef FUTURESHOCK_GAME_HPP
#define FUTURESHOCK_GAME_HPP

#include <chrono>
#include "Position.hpp"
#include "GameObject.hpp"
#include "Graphics.hpp"
#include "CollisionDetection.hpp"

class Game {

    CollisionDetection collision_detection{};

    std::shared_ptr<Graphics> graphics{};

    std::vector<GameObject> game_objects{};

public:

    explicit Game(const Graphics &_graphics);

    void update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration);

    void draw_game();

    std::vector<Position> rectangle_positions(Position position, float width, float height) {
        return {{position.x / -2.0f,        position.y / -2.0f},
                {position.x / 2.0f + width, position.y / 2.0f},
                {position.x / 2.0f + width, position.y / -2.0f + height},
                {position.x / -2.0f,        position.y / 2.0f + height}};
    }
};

#endif //FUTURESHOCK_GAME_HPP
