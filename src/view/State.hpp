#ifndef STATE_HPP
#define STATE_HPP

#include "COLORS.hpp"

namespace View { // Representation
class State {
public:
    virtual void init() = 0;

    virtual void HandleInput() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

    virtual void Pause() {}
    virtual void Resume() {}
};
} // namespace View

#endif // STATE_HPP