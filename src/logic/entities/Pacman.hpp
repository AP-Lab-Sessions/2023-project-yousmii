#ifndef PACMAN_HPP
#define PACMAN_HPP
#include "../../DEFINITIONS.hpp"
#include "Entity.hpp"
#include "states/PacmanStateManager.hpp"

namespace Logic{

/// @brief PacmanData is a struct that holds data of the pacman, such as its position, direction, and state manager, it is for the States
/// @remark x and y are the coordinates of the pacman, i wanna rename this to row and col but uh, i dont wanna break the code
/// refactoring is a lil too risky since x and y are used in libraries and stuff so i'll just leave it as is
struct PacmanData {
    int x, y; // new position of pacman

    bool isAlive;
    bool isMoving;

    Direction direction;
    PacmanStateManagerPtr stateManager;
};

typedef std::shared_ptr<PacmanData> PacmanDataPtr;

class Pacman : public Entity {
public:
    /// @brief Constructor of the Pacman class, initializes the statemanager to PausedState
    /// @param x The row of the pacman IM SORRY I CANT CHANGE IT WITHOUT RISKING BREAKING THE CODE
    /// @param y The column of the pacman
    explicit Pacman(int x, int y);

    /// @brief Updates pacman, applies state changes and moves pacman if it is moving
    void update();
    /// @brief Changes the direction of pacman
    void setDirection(Direction direction);

    /// @brief Returns the direction of pacman
    Direction getDirection() const { return _pacmanData->direction; }

    /// @brief Returns the position of pacman
    bool isMoving() const { return _pacmanData->isMoving; }

    /// @brief Returns the new position of pacman, used for collision detection by the simulation
    std::pair<int, int> getNewPosition() const;

    /// @brief Discards the new position of pacman, used when the simulation detects a collision
    void discardNewPosition();

private:
    PacmanDataPtr _pacmanData;
};

} // Logic

#endif //PACMAN_HPP
