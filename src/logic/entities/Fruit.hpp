
#ifndef FRUIT_HPP
#define FRUIT_HPP
#include "Entity.hpp"

namespace Logic {

class Fruit : public Entity {
public:
    Fruit(int x, int y) : Entity(x, y) {}
};

} // Logic

#endif //FRUIT_HPP
