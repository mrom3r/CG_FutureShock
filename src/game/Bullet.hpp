
#ifndef FUTURESHOCK_BULLET_HPP
#define FUTURESHOCK_BULLET_HPP


#include "GameObject.hpp"

class Bullet {

    unsigned long long id;

    GameObject game_object;

    Position direction{};

public:

    Bullet(GameObject bullet, const Position &direction);

    GameObject get_new_bullet();

};


#endif //FUTURESHOCK_BULLET_HPP
