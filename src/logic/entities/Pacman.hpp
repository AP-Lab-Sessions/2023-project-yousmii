#ifndef PACMAN_HPP
#define PACMAN_HPP
#include "../../DEFINITIONS.hpp"
#include "Entity.hpp"
#include "states/PacmanStateManager.hpp"

namespace Logic {

class Pacman : public Entity {
public:
    Pacman(int x, int y);
    ~Pacman() override = default;

    void update();
    void changeDirection(Direction direction);

private:
    void updateData();
    std::shared_ptr<PacmanStateManager> _stateManager;
    PacmanDataPtr _pacmanData;
};

} // Logic

#endif //PACMAN_HPP
