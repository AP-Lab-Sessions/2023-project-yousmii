#ifndef STATE_HPP
#define STATE_HPP

namespace Rep { // Representation
class State {
public:
    virtual void init() = 0;

    virtual void HandleInput() = 0;
    virtual void Update(double dt) = 0;
    virtual void Draw(double dt) = 0;

    virtual void Pause() {}
    virtual void Resume() {}
};
} // namespace Rep

#endif // STATE_HPP
