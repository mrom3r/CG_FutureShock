
#include "Bullet.hpp"

GameObject Bullet::get_new_bullet() {
    GameObject new_bullet_game_object{game_object};
    // add bullet id
    new_bullet_game_object.bullet_id = bullet_id;

    // add tank id
    new_bullet_game_object.tank_id = tank_id;

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

Bullet::Bullet(GameObject bullet, const Position &direction, unsigned int _tank_id) : game_object(std::move(bullet)),
                                                                                      direction(direction),
                                                                                      tank_id(_tank_id) {
    static unsigned int counter = 0;
    bullet_id = counter++;
}
