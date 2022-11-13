
#include "GameObject.hpp"

GameObject::GameObject(std::vector<Position> shape, float rotation, const Position &rotationPoint) : positions(
        std::move(
                shape)), rotation(rotation), rotation_point(rotationPoint) {}
