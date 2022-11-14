
#include "Bullet.hpp"

GameObject Bullet::get_new_bullet() {
    GameObject new_bullet_game_object{game_object};
    new_bullet_game_object.translation += direction;
    return new_bullet_game_object;
}

Bullet::Bullet(GameObject bullet, const Position &direction) : game_object(std::move(bullet)), direction(direction) {
    static unsigned long long counter = 0;
    id = counter++;
}
