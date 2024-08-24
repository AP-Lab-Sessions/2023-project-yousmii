#include "EntityFactory.hpp"

#include "entities/Coin.hpp"
#include "entities/Fruit.hpp"
#include "entities/Ghost.hpp"
#include "entities/Pacman.hpp"
#include "entities/Wall.hpp"
#include "entities/Banana.hpp"

namespace View {
EntityFactory::EntityFactory(sf::Texture& texture, const EntityDataMap& data_map) : _spritesheet(texture) {
    // Read the data map and create the entities
    // Some extra funny thing is how i actually forgot that a row is a y coordinate and a column is an x coordinate, i totally did not spend 2 hours debugging that somewhere else
    for (int i = 0; i < LEVEL_HEIGHT; i++) {
        for (int j = 0; j < LEVEL_WIDTH; j++) {
            EntityType type = data_map[i][j].type;
            CharacterName name = data_map[i][j].name;
            switch (type) {
            case EntityType::PACMAN:
                _characters[CharacterName::Pacman] = std::make_shared<Pacman>(texture);
                _characters[CharacterName::Pacman]->setPosition(j * TILE_SIZE, i * TILE_SIZE);
                break;

            // Ghosts are created based on their name
            case EntityType::GHOST:

                switch (name) {
                case CharacterName::Blinky:
                    _characters[CharacterName::Blinky] = std::make_shared<Ghost>(texture, CharacterName::Blinky);
                    _characters[CharacterName::Blinky]->setPosition(j * TILE_SIZE, i * TILE_SIZE);
                    break;
                case CharacterName::Pinky:
                    _characters[CharacterName::Pinky] = std::make_shared<Ghost>(texture, CharacterName::Pinky);
                    _characters[CharacterName::Pinky]->setPosition(j * TILE_SIZE, i * TILE_SIZE);
                    break;
                case CharacterName::Inky:
                    _characters[CharacterName::Inky] = std::make_shared<Ghost>(texture, CharacterName::Inky);
                    _characters[CharacterName::Inky]->setPosition(j * TILE_SIZE, i * TILE_SIZE);
                    break;
                case CharacterName::Clyde:
                    _characters[CharacterName::Clyde] = std::make_shared<Ghost>(texture, CharacterName::Clyde);
                    _characters[CharacterName::Clyde]->setPosition(j * TILE_SIZE, i * TILE_SIZE);
                    break;
                default:
                    break;
                }
                break;

            case EntityType::COIN:
                _collectables[{i, j}] = std::make_shared<Coin>(texture);
                _collectables[{i, j}]->setPosition(j * TILE_SIZE, i * TILE_SIZE);
                break;

            case EntityType::FRUIT:
                _collectables[{i, j}] = std::make_shared<Fruit>(texture);
                _collectables[{i, j}]->setPosition(j * TILE_SIZE, i * TILE_SIZE);
                break;
            case EntityType::WALL:
                _walls.push_back(std::make_shared<Wall>(j * TILE_SIZE, i * TILE_SIZE));
                break;

            case EntityType::BANANA:
                _collectables[{i, j}] = std::make_shared<Banana>(texture);
                _collectables[{i, j}]->setPosition(j * TILE_SIZE, i * TILE_SIZE);
                break;

            default:
                break;
            }
        }
    }
}

void EntityFactory::updateCharacters() {
    if (nextUpdateAnimation <= 0) {
        for (auto& character : _characters) {
            character.second->update();
        }
        nextUpdateAnimation = 0.06f; // omg magic number
    } else {
        nextUpdateAnimation -= TICK_RATE;
    }
}


void EntityFactory::removeCollectable(int row, int col) { _collectables.erase({row, col}); }

void EntityFactory::moveCharacter(CharacterName name, int newRow, int newCol) {
    _characters[name]->setPosition(newCol * TILE_SIZE, newRow * TILE_SIZE);
}
void EntityFactory::setCharacterDirection(CharacterName name, Direction direction) {
    _characters[name]->setDirection(direction);
}

void EntityFactory::update() {
    updateCharacters();
}
void EntityFactory::drawAll(sf::RenderWindow& window) {
    for (auto& character : _characters) {
        window.draw(character.second->getSprite());
    }
    for (auto& collectable : _collectables) {
        window.draw(collectable.second->getSprite());
    }
    for (auto& wall : _walls) {
        window.draw(wall->getSprite());
    }
}

Characters EntityFactory::getCharacters() { return _characters; }

Collectables EntityFactory::getCollectables() { return _collectables; }

Walls EntityFactory::getWalls() { return _walls; }

CharacterPtr EntityFactory::getCharacter(CharacterName name) { return _characters[name]; }

} // namespace View