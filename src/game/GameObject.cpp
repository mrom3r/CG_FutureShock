
#include "GameObject.hpp"

#include <utility>

GameObject::GameObject(Shape shape, float rotation, const Position &rotationPosition)
: shape(std::move(shape)), rotation(rotation), rotation_point(rotationPosition) {}
