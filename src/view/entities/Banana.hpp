#ifndef BANANA_HPP
#define BANANA_HPP
#include "Collectable.hpp"

namespace View {

class Banana : public Collectable{
public:
    explicit Banana(sf::Texture texture);
};

// Well this game doesnt have easter eggs but it has bananas, so have this comment as your easter egg :)

} // View

#endif //BANANA_HPP
