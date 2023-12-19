#include "Game.h"
#include <assert.h>

std::shared_ptr<State> Game::getCurrentState() {
    assert(!mStates.empty());
    return mStates.top();
}

void Game::pushState(std::unique_ptr<State> state) {
    assert(state != nullptr);

    mStates.push(std::move(state));
    mStates.top()->onEnter();
}

void Game::popState() {
    assert(!mStates.empty());

    mStates.top()->onExit();
    mStates.pop();
}
