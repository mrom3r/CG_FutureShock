
#include "BulletManager.hpp"

BulletManager& BulletManager::get_instance() {
    static BulletManager bullet_manager{};
    return bullet_manager;
}

void BulletManager::create_bullet(Position start, Position direction, unsigned int tank_id) {
    GameObject bullet_game_object{circle_positions(start, bullet_size, 8)};
    bullet_game_object.type = GameObject::BULLET;
    Bullet bullet{bullet_game_object, direction, tank_id};
    bullets.emplace_back(bullet);
}

std::vector<GameObject> BulletManager::get_active_bullets_game_objects() {
    // delete bullets far out of screen or deactivated
    bullets.erase(
            std::remove_if(bullets.begin(), bullets.end(),
                           [](const Bullet & bullet) {
                return !bullet.active
                || bullet.game_object.translation.x > 5.0f
                || bullet.game_object.translation.x < -5.0f
                || bullet.game_object.translation.y < -2.0f;
            }),
            bullets.end());


    std::vector<GameObject> bullet_game_objects{};

    for (Bullet &bullet: bullets) {
        bullet_game_objects.emplace_back(bullet.get_new_bullet());
    }

    return bullet_game_objects;
}

void BulletManager::deactivate_bullet(unsigned int bullet_id) {
    for (Bullet &bullet : bullets) {
        if (bullet.bullet_id == bullet_id) {
            bullet.active = false;
        }
    }
}


