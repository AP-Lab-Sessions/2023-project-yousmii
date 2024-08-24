#include "PausedState.hpp"
#include "MovingState.hpp"

namespace Logic {
PausedState::PausedState(PacmanDataPtr pacmanData, float pauseTime) : _pacmanData(std::move (pacmanData)), _pauseTime(pauseTime) {
};

void PausedState::init() {
    _pacmanData->isMoving = false;
}

void PausedState::die() {
    _pauseTime = 3.0f; // 2 seconds pause
}

void PausedState::slip() {
    // actually, it's impossible to slip in the paused state >:)
}

void PausedState::update() {
    _pauseTime -= TICK_RATE; // Defined in DEFINITIONS.hpp
    if (_pauseTime <= 0.0f) {
        _pacmanData->stateManager->addState(std::make_unique<MovingState>(_pacmanData));
    }
}


} // Logic