#ifndef GHOST_HPP
#define GHOST_HPP
#include "../../DEFINITIONS.hpp"
#include "Entity.hpp"

#include <list>

namespace Logic {

class Ghost : public Entity{
public:
    Ghost(CharacterName name, int x, int y);
    ~Ghost() = default;

    void die();
    void frighten();
    void move(std::list<Direction> available_directions);

    bool isFrightened() const { return _frightened; }
    bool isAlive() const { return _alive; }
    bool isMoving() const { return _moving; }
    bool isChasing() const { return _chasing; }
    Direction getDirection() const { return _direction; }
    CharacterName getName() const { return _name; }

private:
    CharacterName _name;
    bool _frightened;
    bool _alive;
    bool _moving;
    bool _chasing;
    Direction _direction;
};

} // Logic

#endif //GHOST_HPP
