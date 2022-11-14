
#ifndef FUTURESHOCK_COLLISIONDETECTION_HPP
#define FUTURESHOCK_COLLISIONDETECTION_HPP

#include "GameObject.hpp"
#include <cstdio>
#include <cstdlib>
#include <cfloat>

class CollisionDetection {

    CollisionDetection() = default;

public:

    static CollisionDetection get_instance();

    bool check_collision(GameObject first, GameObject second);

};


#endif //FUTURESHOCK_COLLISIONDETECTION_HPP
