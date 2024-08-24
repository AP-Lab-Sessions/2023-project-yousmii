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

typedef std::vector<std::vector<std::shared_ptr<Tile>>> TileMap;

struct LevelData { // Easy access to the level data, less searching for the right tile
    int pacmanRow;
    int pacmanCol;

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

class Level {
public:
    explicit Level(int levelNumber);
    ~Level();

    std::weak_ptr<Tile> getTile(int row, int col);

    int getLives();
    void eatCoin();
    void takeLife();

    void setPlayerDirection(Direction direction);
    std::weak_ptr<Pacman> getPacman();
    ScorePtr getScore();

    void moveTileEntity(CharacterName name, int newRow, int newCol, bool isReplacing = false);
    bool isCompleted();
    bool isWon();

private:
    void loadLevel(); // works as a reset :)
    std::weak_ptr<Pacman> _pacman;

    // std::weak_ptr<Ghost> _blinky;
    // std::weak_ptr<Ghost> _inky;
    // std::weak_ptr<Ghost> _clyde;
    // std::weak_ptr<Ghost> _pinky;

    TileMap _tiles;
    int _levelNumber;
    LevelDataPtr _levelData;
};

typedef std::shared_ptr<Level> LevelPtr;

} // Logic

#endif //LEVEL_HPP
