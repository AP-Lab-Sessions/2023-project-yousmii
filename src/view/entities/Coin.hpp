

#ifndef COIN_HPP
#define COIN_HPP
#include "Collectable.hpp"

namespace View {

class Coin : public Collectable {
public:
    explicit Coin(sf::Texture& texture);

};

} // View

#endif //COIN_HPP
