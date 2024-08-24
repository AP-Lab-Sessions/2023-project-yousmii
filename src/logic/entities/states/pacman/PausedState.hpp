#ifndef PAUSEDSTATE_HPP
#define PAUSEDSTATE_HPP

#include "../PacmanState.hpp"
#include "../../Pacman.hpp"

namespace Logic {

class PausedState : public PacmanState {
public:
    explicit PausedState(PacmanDataPtr pacmanData, float pauseTime = 1.0f);

    /// @brief Initialize paused state
    void init() override;

    /// @brief move in the paused state, its impossible >:)
    void move() override{};
    /// @brief die in the paused state it refreshes the pause time to 3 seconds
    void die() override;
    /// @brief slip in the paused state, what a klutz
    void slip() override;

    void update() override;

private:
    PacmanDataPtr _pacmanData;
    float _pauseTime; // 1 second pause
};

} // Logic

#endif //PAUSEDSTATE_HPP
