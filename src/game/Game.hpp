
#ifndef FUTURESHOCK_GAME_HPP
#define FUTURESHOCK_GAME_HPP

#include <chrono>
#include "Position.hpp"
#include "GameObject.hpp"
#include "Graphics.hpp"

class Game {

    std::shared_ptr<Graphics> graphics{};

    std::vector<GameObject> game_objects{};

public:

    explicit Game(const Graphics &_graphics);

    void update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration);

    void draw_game();

    static std::vector<Position> rectangle_positions(Position position, float width, float height);

};

#endif //FUTURESHOCK_GAME_HPP
