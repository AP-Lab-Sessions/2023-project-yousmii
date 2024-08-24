#ifndef PAUSEDSTATE_HPP
#define PAUSEDSTATE_HPP

#include "../PacmanState.hpp"
#include "../../Pacman.hpp"

namespace Logic {

class PausedState : public PacmanState {
public:
    PausedState(PacmanDataPtr pacmanData);
    ~PausedState() override = default;

    void init() override;
    void move() override;
    void die() override;
    void slip() override;

    void update() override;
    void changeDirection(Direction direction) override;

private:
    PacmanDataPtr _pacmanData;
    float _pauseTime; // 1 second pause
};

} // Logic

#endif //PAUSEDSTATE_HPP
