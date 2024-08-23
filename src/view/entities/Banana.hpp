#ifndef BANANA_HPP
#define BANANA_HPP
#include "Collectable.hpp"

namespace View {

class Banana : public Collectable{
public:
    Banana(sf::Texture texture);
};

} // View

#endif //BANANA_HPP
