#ifndef PACMAN_HPP
#define PACMAN_HPP
#include "Character.hpp"

namespace View {

class Pacman : public Character {
public:
    explicit Pacman(sf::Texture& texture);
};

} // namespace View

#endif // PACMAN_HPP
