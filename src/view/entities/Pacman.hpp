#ifndef PACMAN_HPP
#define PACMAN_HPP
#include "Character.hpp"

namespace View {

class Pacman : public Character {
public:
    /// @brief Constructor of Pacman, which initializes the texture of the entity in all directions
    explicit Pacman(sf::Texture& texture);
};

} // namespace View

#endif // PACMAN_HPP
