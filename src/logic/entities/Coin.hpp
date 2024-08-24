#ifndef COIN_HPP
#define COIN_HPP
#include "Entity.hpp"

namespace Logic {

class Coin : public Entity {
public:
    /// Constructor
    explicit Coin (int x, int y) : Entity(x, y) {_type = EntityType::COIN;}
};

} // Logic

#endif //COIN_HPP
