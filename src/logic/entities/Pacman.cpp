#include "Pacman.hpp"

namespace Logic {
Pacman::Pacman(int x, int y)
    : Entity(x, y), _poweredUp(false), _alive(true), _moving(true), _direction(Direction::LEFT) {
    _type = EntityType::PACMAN;
}
} // namespace Logic