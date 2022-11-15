
#ifndef FUTURESHOCK_BULLET_HPP
#define FUTURESHOCK_BULLET_HPP


#include "GameObject.hpp"

class Bullet {

    unsigned long long id;

    Position direction{};

    Color color{1.0, 0.53,0.0};

    float air_resistance_multiplier{0.99f};
    Position bullet_gravity{0.0, 0.0005};

public:

    GameObject game_object;

    Bullet(GameObject bullet, const Position &direction);

    GameObject get_new_bullet();

};


#endif //FUTURESHOCK_BULLET_HPP
