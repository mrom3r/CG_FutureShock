
#ifndef FUTURESHOCK_GAME_HPP
#define FUTURESHOCK_GAME_HPP

#include <chrono>
#include "game/structs/Position.hpp"
#include "GameObject.hpp"
#include "Graphics.hpp"

class Game {

    std::shared_ptr<Graphics> graphics{};

    Position player_position{};
    float player_direction{};

    std::vector<GameObject> game_objects{};

public:

    explicit Game(const Graphics& _graphics);

    void update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration);

    void draw_game();

    void draw_background();

    void draw_bullets();

    void draw_player();
};

#endif //FUTURESHOCK_GAME_HPP
