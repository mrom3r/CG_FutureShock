
#include "BulletManager.hpp"

BulletManager BulletManager::get_instance() {
    static BulletManager bullet_manager{};
    return bullet_manager;
}

void BulletManager::create_bullet(Position start, Position direction) {
    GameObject bullet_game_object{rectangle_positions(start, bullet_size, bullet_size)};
    bullet_game_object.collision = true;
    Bullet bullet{bullet_game_object, direction};
    bullets.emplace_back(bullet);
}

std::vector<GameObject> BulletManager::get_active_bullets_game_objects() {
    std::vector<GameObject> bullet_game_objects{};

    for (Bullet bullet : bullets) {
        bullet_game_objects.emplace_back(bullet.get_new_bullet());
    }

    return bullet_game_objects;
}


