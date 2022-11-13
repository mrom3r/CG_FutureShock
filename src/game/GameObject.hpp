
#ifndef FUTURESHOCK_GAMEOBJECT_HPP
#define FUTURESHOCK_GAMEOBJECT_HPP

#include "game/structs/Shape.hpp"

struct GameObject {

    Shape shape{};

    GameObject(Shape shape);

};


#endif //FUTURESHOCK_GAMEOBJECT_HPP
