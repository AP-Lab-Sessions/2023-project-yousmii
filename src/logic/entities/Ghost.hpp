#ifndef GHOST_HPP
#define GHOST_HPP
#include "../../DEFINITIONS.hpp"
#include "Entity.hpp"
// #include "states/GhostStateManager.hpp"

#include <list>

namespace Logic {

class Ghost : public Entity{
public:
    explicit Ghost(CharacterName name, int x, int y);

    // void die();
    // void frighten();
    // void move(std::list<Direction> available_directions);

private:
    bool _frightened;
    bool _alive;
    bool _moving;
    bool _chasing;
    Direction _direction;

    // GhostStateManager _stateManager;
};

} // Logic

#endif //GHOST_HPP
