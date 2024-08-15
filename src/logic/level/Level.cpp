#include "Level.hpp"

namespace Logic {
Level::Level(int levelNumber) { _levelNumber = levelNumber; }

void Level::loadLevel() {
    _tiles = TileMap();
    std::ifstream levelFile;

    levelFile.open(LEVEL_DIR + std::to_string(_levelNumber) + ".lvl");
    if (!levelFile.is_open()) {
        throw std::runtime_error("Could not open level file");
    }

    bool hasPacman = false;
    bool hasCoin = false;

    int row = 0;
    int col = 0;

    std::string line;
    while (std::getline(levelFile, line)) {
        if (row >= LEVEL_HEIGHT) {
            throw std::runtime_error("Level height exceeded");
        }
        for (char c : line) {
            if (col >= LEVEL_WIDTH) {
                throw std::runtime_error("Level width exceeded");
            }
            if ((row == 0 || row == LEVEL_HEIGHT - 1 || col == 0 || col == LEVEL_WIDTH - 1) && c != '#') {
                throw std::runtime_error("Invalid level format");
            }
            switch (c) {
            case 'o':
                hasPacman = true;
                _levelData->pacmanRow = row;
                _levelData->pacmanCol = col;
                _tiles[row][col]->setEntity(std::make_shared<Pacman>(row, col));
                break;
            case 'b':
                _levelData->blinkyRow = row;
                _levelData->blinkyCol = col;
                _tiles[row][col]->setEntity(std::make_shared<Ghost>(CharacterName::Blinky, row, col));
                break;
            case 'i':
                _levelData->inkyRow = row;
                _levelData->inkyCol = col;
                _tiles[row][col]->setEntity(std::make_shared<Ghost>(CharacterName::Inky, row, col));
                break;
            case 'c':
                _levelData->clydeRow = row;
                _levelData->clydeCol = col;
                _tiles[row][col]->setEntity(std::make_shared<Ghost>(CharacterName::Clyde, row, col));
                break;
            case 'p':
                _levelData->pinkyRow = row;
                _levelData->pinkyCol = col;
                _tiles[row][col]->setEntity(std::make_shared<Ghost>(CharacterName::Pinky, row, col));
                break;
            case '#':
                _tiles[row][col]->setEntity(std::make_shared<Wall>(row, col));
                break;
            case ' ': // Empty space
                break;
            case '.':
                hasCoin = true;
                _levelData->coinCount++;
                _tiles[row][col]->setEntity(std::make_shared<Coin>(row, col));
                // Chance to spawn a banana?
                break;
            case 'f':
                _tiles[row][col]->setEntity(std::make_shared<Fruit>(row, col));
                break;
            case '\n':
                if (col != LEVEL_WIDTH) {
                    throw std::runtime_error("Invalid level format");
                } else {
                    break;
                }
            default:
                throw std::runtime_error("Invalid character in level file!");
                break;
            }
            col++;
        }
        row++;
        col = 0;
    }
    if (!hasPacman) {
        throw std::runtime_error("Invalid level format, missing pacman!");
    }
    if (!hasCoin) { // Level will be considered completed when all coins are collected or if there are no coins
        throw std::runtime_error("Invalid level format, missing coins!");
    }
}
} // namespace Logic