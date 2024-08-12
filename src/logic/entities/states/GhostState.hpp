#ifndef CHARACTERSTATE_HPP
#define CHARACTERSTATE_HPP

namespace Logic {

class GhostState {
public:
    GhostState() = default;
    virtual ~GhostState() = default;

    virtual void setup() = 0;
    virtual void move() = 0;
    virtual void die() = 0;
};

} // namespace Logic

#endif // CHARACTERSTATE_HPP
