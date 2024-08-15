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

struct OutputData { // Easy access to the output data, cannot alter the original data
    int score;
    int lives;
    int coins;
};

struct EntityData {
    int row;
    int col;
    Direction direction;
};

class Level {
public:
    Level(int levelNumber);
    ~Level();

    void loadLevel(); // works as a reset :)
    std::weak_ptr<Tile> getTile(int row, int col);
    std::weak_ptr<OutputData> getOutputData() const;

    std::unordered_map<std::string, EntityData> getInitialEntityData() const;

private:
    TileMap _tiles;
    int _levelNumber;
    LevelDataPtr _levelData;
};

} // Logic

#endif //LEVEL_HPP
