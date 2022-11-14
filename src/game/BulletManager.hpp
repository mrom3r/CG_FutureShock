
#ifndef FUTURESHOCK_BULLETMANAGER_HPP
#define FUTURESHOCK_BULLETMANAGER_HPP


#include <vector>
#include "GameObject.hpp"
#include "Tools.hpp"
#include "Bullet.hpp"

class BulletManager {

    const float bullet_size{0.05f};

    std::vector<Bullet> bullets{};

public:

    void create_bullet(Position start, Position direction);

    std::vector<GameObject> get_active_bullets_game_objects();

};


#endif //FUTURESHOCK_BULLETMANAGER_HPP
