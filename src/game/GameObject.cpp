
#include "GameObject.hpp"

#include <utility>


GameObject::GameObject(Shape shape) : shape(std::move(shape)) {

}
