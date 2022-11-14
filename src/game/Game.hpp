
#ifndef FUTURESHOCK_GAME_HPP
#define FUTURESHOCK_GAME_HPP

#include <chrono>
#include "Position.hpp"
#include "GameObject.hpp"
#include "Graphics.hpp"
#include "CollisionDetection.hpp"
#include "Tank.hpp"
#include "BulletManager.hpp"

class Game {

    std::shared_ptr<Graphics> graphics{};

    GameObject map;
    GameObject left_border;
    GameObject right_border;

    std::vector<GameObject> game_objects{};

    const float gravity{-0.002};

public:

    Tank player{Position{-0.5, 0.0}, Color{0.0f, 1.0f, 0.0f}};
    Tank enemy{Position{0.6, 0.0}, Color{1.0f, 0.0f, 0.0f}};

    explicit Game(const Graphics &_graphics);

    void update_game(std::chrono::duration<long long int, std::ratio<1, 1000000000>> duration);

    void draw_game();
};

#endif //FUTURESHOCK_GAME_HPP
