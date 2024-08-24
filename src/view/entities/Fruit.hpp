#ifndef FRUIT_HPP
#define FRUIT_HPP
#include "Collectable.hpp"

namespace View {

class Fruit : public Collectable {
public:
    /// @brief Constructor of Fruit, which initializes the texture of the entity to the cherry texture
    explicit Fruit(sf::Texture texture);

};

} // View

#endif //FRUIT_HPP
