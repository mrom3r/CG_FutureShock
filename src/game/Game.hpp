
#ifndef FUTURESHOCK_GAME_HPP
#define FUTURESHOCK_GAME_HPP

#include <chrono>
#include "Position.hpp"
#include "GameObject.hpp"
#include "Graphics.hpp"
#include "CollisionDetection.hpp"
#include "Tank.hpp"

class Game {

    CollisionDetection collision_detection{};

    std::shared_ptr<Graphics> graphics{};

    GameObject background{};
    std::vector<GameObject> permanent_game_objects{};

    std::vector<GameObject> game_objects{};

    const float gravity{-0.001};

public:

    explicit Game(const Graphics &_graphics);

    void update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration);

    void draw_game();

    static std::vector<Position> rectangle_positions(Position position, float width, float height) {
        float left{width / -2.0f + position.x};
        float right{width / 2.0f + position.x};
        float up{height / 2.0f + position.y};
        float down{height / -2.0f + position.y};

        return {{left, down},
                {left + width, down},
                {left + width, down + height},
                {left, down + height}};
    }
};

#endif //FUTURESHOCK_GAME_HPP
