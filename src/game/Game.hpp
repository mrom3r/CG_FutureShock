
#ifndef FUTURESHOCK_GAME_HPP
#define FUTURESHOCK_GAME_HPP

#include "game/structs/Position.hpp"
#include "Graphics.hpp"

class Game {

    Position player_position{};
    float player_direction{};

    std::shared_ptr<Graphics> graphics{};

public:

    Game(const Graphics& _graphics);

    void update_positions();

    void draw_game();

    void draw_background();

    void draw_bullets();

    void draw_player();
};

#endif //FUTURESHOCK_GAME_HPP
