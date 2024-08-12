#ifndef PACMAN_HPP
#define PACMAN_HPP
#include "../../DEFINITIONS.hpp"
#include "Entity.hpp"
#include "states/GhostState.hpp"

#include <memory>
#include <stack>

namespace Logic {

class Pacman : public Entity {
public:
    Pacman(int x, int y);
    ~Pacman() override = default;

    void move();
    void changeDirection(Direction direction);
    void die();
    void powerUp();

    bool isPoweredUp() const { return _poweredUp; }
    bool isAlive() const { return _alive; }
    bool isMoving() const { return _moving; }
    Direction getDirection() const { return _direction; }

private:
    bool _poweredUp;
    bool _alive;
    bool _moving;
    Direction _direction;
};

} // Logic

#endif //PACMAN_HPP
