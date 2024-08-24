#include "MovingState.hpp"

#include "PausedState.hpp"

#include <iostream>

namespace Logic {

MovingState::MovingState(PacmanDataPtr pacmanData) : _pacmanData(pacmanData) {}

void MovingState::init() {
    _pacmanData->isMoving = true;
    _pacmanData->isAlive = true;
}

void MovingState::move() { // Move pacman in the current direction, does not check for collisions
    switch (_pacmanData->direction) {
    case Direction::UP:
        _pacmanData->x -= 1;
        break;
    case Direction::DOWN:
        _pacmanData->x += 1;
        break;
    case Direction::LEFT:
        _pacmanData->y -= 1;
        break;
    case Direction::RIGHT:
        _pacmanData->y += 1;
        break;
    }
    /*Omg hii there!
     *So I'm just gonna rant in here
     *Perhaps you might have seen some comment there talking about rows and columns, now thats something i forgot about
     *So yeah, when i was implementing the pacman movement, I forgot to consider the fact that the pacman is moving in a
     *grid So the pacman should move in rows and columns, not x and y So yeah, I was wondering why when i was moving to
     *the right, i went up instead. I was like "what the heck is happening" eventually i figured it out and fixed it
     *I did laugh at myself for a bit, but hey, we all make mistakes right?
     *So yeah, that's it, just wanted to share that
     *Thanks for reading this, have a great day!
     */
}

void MovingState::die() { _pacmanData->stateManager->addState(std::make_unique<PausedState>(_pacmanData, 2.0f)); }

void MovingState::slip() { _pacmanData->stateManager->addState(std::make_unique<PausedState>(_pacmanData)); }

void MovingState::update() {
    if (_nextMove <= 0.0f) {
        move();
        _nextMove = 1.0f / 3.0f; // 3 moves per second
    } else {
        _nextMove -= TICK_RATE;
    }
}

} // namespace Logic