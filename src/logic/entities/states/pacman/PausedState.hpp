#ifndef PAUSEDSTATE_HPP
#define PAUSEDSTATE_HPP

#include "../PacmanState.hpp"

namespace Logic {

class PausedState : public PacmanState { // Also works as a setup state at the beginning of the game
public:
    PausedState(PacmanDataPtr pacmanData) : PacmanState(std::move(pacmanData)) {};
    ~PausedState() override = default;

    void init() override;
    void move() override;
    void die() override;
    void powerUp() override;
    void powerDown() override;
    void slip() override;

private:
    float _pauseTime = 1.0f; // 1 second pause

};

} // Logic

#endif //PAUSEDSTATE_HPP
