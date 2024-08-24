#include "Level.hpp"

#include <iostream>

namespace Logic {
Level::Level(int levelNumber) {
    _levelNumber = levelNumber;
    _levelData = std::make_shared<LevelData>();
    loadLevel();
}
Level::~Level() {
    for (int i = 0; i < LEVEL_HEIGHT; i++) {
        for (int j = 0; j < LEVEL_WIDTH; j++) {
            _tiles[i][j]->setEntity(nullptr);
        }
    }
}

int Level::getLives() { return _levelData->lives; }

void Level::setPlayerDirection(Direction direction) { _pacman.lock()->setDirection(direction); }

std::weak_ptr<Tile> Level::getTile(int row, int col) { return std::weak_ptr<Tile>(_tiles[row][col]); }

void Level::loadLevel() {
    _tiles = TileMap();
    _tiles.resize(LEVEL_HEIGHT);
    for (int i = 0; i < LEVEL_HEIGHT; i++) {
        _tiles[i].resize(LEVEL_WIDTH);
        for (int j = 0; j < LEVEL_WIDTH; j++) {
            _tiles[i][j] = std::make_shared<Tile>();
        }
    }
    std::ifstream levelFile;

    levelFile.open(LEVEL_DIR + std::to_string(_levelNumber) + ".lvl");
    if (!levelFile.is_open()) {
        throw std::runtime_error("Could not open level file");
    }

    bool hasPacman = false;
    bool hasCoin = false;
    bool hasBlinky = false;
    bool hasInky = false;
    bool hasClyde = false;
    bool hasPinky = false;

    int row = 0;
    int col = 0;

    std::shared_ptr<Pacman> pacman = nullptr;

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
                pacman = std::make_shared<Pacman>(row, col);
                _pacman = std::weak_ptr<Pacman>(pacman);
                _tiles[row][col]->setEntity(std::move(pacman));
                break;

            case 'b':
                if (hasBlinky) {
                    throw std::runtime_error("Invalid level format, multiple blinkys!");
                }
                hasBlinky = true;
                _levelData->blinkyRow = row;
                _levelData->blinkyCol = col;
                _tiles[row][col]->setEntity(std::make_shared<Ghost>(CharacterName::Blinky, row, col));
                break;
            case 'i':
                if (hasInky) {
                    throw std::runtime_error("Invalid level format, multiple inkys!");
                }
                hasInky = true;
                _levelData->inkyRow = row;
                _levelData->inkyCol = col;
                _tiles[row][col]->setEntity(std::make_shared<Ghost>(CharacterName::Inky, row, col));
                break;
            case 'c':
                if (hasClyde) {
                    throw std::runtime_error("Invalid level format, multiple clydes!");
                }
                hasClyde = true;
                _levelData->clydeRow = row;
                _levelData->clydeCol = col;
                _tiles[row][col]->setEntity(std::make_shared<Ghost>(CharacterName::Clyde, row, col));
                break;
            case 'p':
                if (hasPinky) {
                    throw std::runtime_error("Invalid level format, multiple pinkys!");
                }
                hasPinky = true;
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
    levelFile.close();

    std::cout << "Level loaded" << std::endl;

    if (!hasPacman) {
        throw std::runtime_error("Invalid level format, missing pacman!");
    }
    // The ghosts are not mandatory, but they are in this case. The game would be boring without them ;)
    if (!hasBlinky) {
        throw std::runtime_error("Invalid level format, missing blinky!");
    }
    if (!hasInky) {
        throw std::runtime_error("Invalid level format, missing inky!");
    }
    if (!hasClyde) {
        throw std::runtime_error("Invalid level format, missing clyde!");
    }
    if (!hasPinky) {
        throw std::runtime_error("Invalid level format, missing pinky!");
    }
    if (!hasCoin) { // Level will be considered completed when all coins are collected or if there are no coins
        throw std::runtime_error("Invalid level format, missing coins!");
    }
}

std::weak_ptr<Pacman> Level::getPacman() { return _pacman; }

ScorePtr Level::getScore() { return _levelData->score; }

void Level::moveTileEntity(CharacterName name, int newRow, int newCol, bool isReplacing) {
    EntityPtr entity;

    switch (name) {
    case CharacterName::Pacman:
        entity = _tiles[_levelData->pacmanRow][_levelData->pacmanCol]->removeEntity();
        _levelData->pacmanRow = newRow;
        _levelData->pacmanCol = newCol;
        break;
    case CharacterName::Blinky:
        entity = _tiles[_levelData->blinkyRow][_levelData->blinkyCol]->removeEntity();
        _levelData->blinkyRow = newRow;
        _levelData->blinkyCol = newCol;
        break;
    case CharacterName::Inky:
        entity = _tiles[_levelData->inkyRow][_levelData->inkyCol]->removeEntity();
        _levelData->inkyRow = newRow;
        _levelData->inkyCol = newCol;
        break;
    case CharacterName::Clyde:
        entity = _tiles[_levelData->clydeRow][_levelData->clydeCol]->removeEntity();
        _levelData->clydeRow = newRow;
        _levelData->clydeCol = newCol;
        break;
    case CharacterName::Pinky:
        entity = _tiles[_levelData->pinkyRow][_levelData->pinkyCol]->removeEntity();
        _levelData->pinkyRow = newRow;
        _levelData->pinkyCol = newCol;
        break;


        case CharacterName::None:
            break;
    }

    _tiles[newRow][newCol]->setEntity(entity, isReplacing);
}

bool Level::isCompleted() {
    return _levelData->coinCount == 0 || _levelData->lives == 0 || _levelData->score->getScore() == 0;
}

void Level::takeLife() {
    if (_levelData->lives == 0) {
        return;
    }
    _levelData->lives--;
}

bool Level::isWon() {
    if (_levelData->lives == 0 || _levelData->score->getScore() == 0) {
        return false;
    }
    return _levelData->coinCount == 0;
}

void Level::eatCoin() {
    if (_levelData->coinCount == 0) {
        return;
    }
    _levelData->coinCount--;
}
} // namespace Logic