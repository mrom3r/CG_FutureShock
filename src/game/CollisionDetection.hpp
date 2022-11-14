
#ifndef FUTURESHOCK_COLLISIONDETECTION_HPP
#define FUTURESHOCK_COLLISIONDETECTION_HPP

#include "GameObject.hpp"
#include <glm/vec2.hpp>
#include <glm/detail/type_mat.hpp>
#include <complex>
#include <glm/detail/type_mat2x2.hpp>
#include <cstdio>
#include <cstdlib>
#include <cfloat>
#include <iostream>

class CollisionDetection {

    CollisionDetection() = default;

public:

    static CollisionDetection get_instance();

    static bool check_collision(const GameObject& first, const GameObject& second);

};


#endif //FUTURESHOCK_COLLISIONDETECTION_HPP
