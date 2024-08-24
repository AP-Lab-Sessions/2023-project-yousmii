#include "MovingState.hpp"

#include "PausedState.hpp"

namespace Logic {

MovingState::MovingState(PacmanDataPtr pacmanData) : _pacmanData(pacmanData) {}

void MovingState::init() {
    _pacmanData->isMoving = true;
    _pacmanData->isAlive = true;
}

void MovingState::move() { // Move pacman in the current direction, does not check for collisions
    switch(_pacmanData->direction) {
        case Direction::UP:
            _pacmanData->y -= 1;
            break;
        case Direction::DOWN:
            _pacmanData->y += 1;
            break;
        case Direction::LEFT:
            _pacmanData->x -= 1;
            break;
        case Direction::RIGHT:
            _pacmanData->x += 1;
            break;
    }
}

void MovingState::die() {
    _pacmanData->stateManager->addState(std::make_unique<PausedState>(_pacmanData));
}

void MovingState::slip() { _pacmanData->stateManager->addState(std::make_unique<PausedState>(_pacmanData)); }

void MovingState::changeDirection(Direction direction) {
    _pacmanData->direction = direction;
}

void MovingState::update() {
    move();
}

} // Logic