#ifndef DEADSTATE_HPP
#define DEADSTATE_HPP

#include "../PacmanState.hpp"
#include "../../Pacman.hpp"

namespace Logic {

class DeadState : public PacmanState {
public:
    DeadState(PacmanDataPtr pacmanData);
    ~DeadState() override = default;

    void init() override;
    void move() override;
    void die() override;
    void powerUp() override;
    void powerDown() override;
    void slip() override;
    void changeDirection(Direction direction) override;

    void update() override;

private:
    PacmanDataPtr _pacmanData;
    float _deathTime; // 1 second death
};

} // Logic

#endif //DEADSTATE_HPP
