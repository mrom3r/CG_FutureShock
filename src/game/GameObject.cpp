
#include "GameObject.hpp"

GameObject::GameObject(std::vector<Position> positions, const Position &translation, float rotation,
                       const Position &rotationPoint) : positions(std::move(positions)), translation(translation),
                                                        rotation(rotation), rotation_point(rotationPoint) {
    static unsigned int counter = 0;
    id = counter++;
}
