
#ifndef FUTURESHOCK_BULLETMANAGER_HPP
#define FUTURESHOCK_BULLETMANAGER_HPP


#include <vector>
#include <algorithm>
#include "GameObject.hpp"
#include "Tools.hpp"
#include "Bullet.hpp"

/**
 * singleton class
 */
class BulletManager {

    BulletManager() = default;

    const float bullet_size{0.02f};

    std::vector<Bullet> bullets{};

public:

    static BulletManager& get_instance();

    void create_bullet(Position start, Position direction, unsigned int tank_id);

    std::vector<GameObject> get_active_bullets_game_objects();

    void deactivate_bullet(unsigned int bullet_id);

};


#endif //FUTURESHOCK_BULLETMANAGER_HPP
