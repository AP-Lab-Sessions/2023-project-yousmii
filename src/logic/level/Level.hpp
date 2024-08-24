#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "../../DEFINITIONS.hpp"
#include "Score.hpp"
#include "Tile.hpp"

#include <fstream>
#include <memory>
#include <unordered_map>

#include <vector>

namespace Logic {

/// TileMap is a 2D vector of shared pointers to Tile objects
typedef std::vector<std::vector<std::shared_ptr<Tile>>> TileMap;

/// LevelData is a struct that holds the data of the level
/// @remarks It is used to easily access the data of the level, such as the position of the player, ghosts, and the score
struct LevelData { // Easy access to the level data, less searching for the right tile
    int pacmanRow; // y coordinate
    int pacmanCol; // x coordinate please keep that in mind

    int blinkyRow;
    int blinkyCol;

    int inkyRow;
    int inkyCol;

    int clydeRow;
    int clydeCol;

    int pinkyRow;
    int pinkyCol;

    int coinCount = 0;
    int lives = 3;
    ScorePtr score = std::make_shared<Score>();
};

typedef std::shared_ptr<LevelData> LevelDataPtr;

/// Level class is responsible for holding the data of the level, such as the tiles, player, ghosts, and the score
/// @remarks It doesnt update the entities, it only holds the data
class Level {
public:
    /// Constructor of the Level class
    explicit Level(int levelNumber);
    ~Level();

    /// @brief Returns a weak pointer to the tile at the given row and column
    std::weak_ptr<Tile> getTile(int row, int col);

    /// @brief Returns the lives of the player
    int getLives();
    /// @brief Eats a coin, increases the score and decreases the coin count
    void eatCoin();

    /// @brief Decreases the lives of the player
    void takeLife();

    /// @brief Sets the direction of the player
    void setPlayerDirection(Direction direction);

    /// @brief Returns a weak pointer to the player
    std::weak_ptr<Pacman> getPacman();

    /// @brief Returns a weak pointer to the ghost with the given name
    std::weak_ptr<Entity> getGhost(CharacterName name);

    /// @brief Returns a pointer to the score
    ScorePtr getScore();

    /// @brief Moves the given entity to the new row and column
    void moveTileEntity(CharacterName name, int newRow, int newCol, bool isReplacing = false);

    /// @brief Returns if the level is completed
    bool isCompleted();

    /// @brief Returns if the level is won
    bool isWon();

private:
    void loadLevel(); // works as a reset of the entire level
    std::weak_ptr<Pacman> _pacman;

    TileMap _tiles;
    int _levelNumber;
    LevelDataPtr _levelData;
};

typedef std::shared_ptr<Level> LevelPtr;

} // Logic

#endif //LEVEL_HPP
