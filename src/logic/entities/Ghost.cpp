
#include "Ghost.hpp"

namespace Logic {
Ghost::Ghost(CharacterName name, int x, int y)
    : Entity(x, y), _name(name), _frightened(false), _alive(true), _moving(false), _chasing(false), _direction(Direction::LEFT) {
    _type = EntityType::GHOST;
}

} // Logic