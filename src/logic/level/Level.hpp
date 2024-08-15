#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "../../DEFINITIONS.hpp"
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
    int score = 2000;
};

typedef std::shared_ptr<LevelData> LevelDataPtr;

class Level {
public:
    Level(int levelNumber);
    ~Level();

    std::weak_ptr<Tile> getTile(int row, int col);
    void updateLevel();

    int getScore();
    int getLives();

private:
    void loadLevel(); // works as a reset :)

    TileMap _tiles;
    int _levelNumber;
    LevelDataPtr _levelData;

    bool _isCompleted;
};

} // Logic

#endif //LEVEL_HPP
