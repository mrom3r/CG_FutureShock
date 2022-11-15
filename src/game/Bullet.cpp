
#include "Bullet.hpp"

GameObject Bullet::get_new_bullet() {
    GameObject new_bullet_game_object{game_object};

    // add color
    game_object.color = color;

    // add direction
    game_object.translation += direction;
    // add air resistance
    direction = Position{direction.x * air_resistance_multiplier, direction.y};
    // add gravity
    direction -= bullet_gravity;

    return new_bullet_game_object;
}

Bullet::Bullet(GameObject bullet, const Position &direction) : game_object(std::move(bullet)), direction(direction) {
    static unsigned long long counter = 0;
    id = counter++;
}
