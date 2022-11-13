
#ifndef FUTURESHOCK_GAME_HPP
#define FUTURESHOCK_GAME_HPP

#include "game/structs/Position.hpp"

class Game {

    Position player_position{};
    float player_direction{};

public:

    Game();

    void update_positions();

    void draw_game();

    void draw_background();

    void draw_bullets();

    void draw_player();
};

#endif //FUTURESHOCK_GAME_HPP
