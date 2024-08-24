
#ifndef FRUIT_HPP
#define FRUIT_HPP
#include "Entity.hpp"

namespace Logic {

class Fruit : public Entity {
public:
    explicit Fruit(int x, int y) : Entity(x, y) {_type = EntityType::FRUIT;}
};

} // Logic

#endif //FRUIT_HPP
