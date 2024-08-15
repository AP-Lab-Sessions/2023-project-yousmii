#include "EntityFactory.hpp"

#include "entities/Coin.hpp"
#include "entities/Fruit.hpp"
#include "entities/Ghost.hpp"
#include "entities/Pacman.hpp"

namespace View {
EntityFactory::EntityFactory(sf::Texture& texture, const EntityDataMap& data_map) : _spritesheet(texture) {
    for (int i = 0; i < LEVEL_HEIGHT; i++) {
        for (int j = 0; j < LEVEL_WIDTH; j++) {
            EntityType type = data_map[i][j].type;
            CharacterName name = data_map[i][j].name;
            switch (type) {
            case EntityType::PACMAN:
                _characters[CharacterName::Pacman] = std::make_shared<Pacman>(texture);
                _characters[CharacterName::Pacman]->setPosition(j * TILE_SIZE, i * TILE_SIZE);
                break;

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
                _collectables.push_back(std::static_pointer_cast<Collectable>(std::make_shared<Coin>(texture)));
                _collectables.back()->setPosition(j * TILE_SIZE, i * TILE_SIZE);
                break;

            case EntityType::FRUIT:
                _collectables.push_back(std::static_pointer_cast<Collectable>(std::make_shared<Fruit>(texture)));
                _collectables.back()->setPosition(j * TILE_SIZE, i * TILE_SIZE);
                break;
            case EntityType::WALL:
                _walls.push_back(std::make_shared<Wall>(j * TILE_SIZE, i * TILE_SIZE));
                break;

            default:
                break;
            }
        }
    }
}

void EntityFactory::updateCharacters() {
    for (auto& character : _characters) {
        character.second->update();
    }
}

void EntityFactory::updatePositions() {
    // Still need to figure this one out
    // Prolly will be that there will be a map of positions and directions for each character
}
void EntityFactory::updateDirections() {}

void EntityFactory::update() {
    updateCharacters();
    updatePositions();
    updateDirections();
}
void EntityFactory::drawAll(sf::RenderWindow& window) {
    for (auto& character : _characters) {
        window.draw(character.second->getSprite());
    }
    for (auto& collectable : _collectables) {
        window.draw(collectable->getSprite());
    }
    for (auto& wall : _walls) {
        window.draw(wall->getSprite());
    }
}

Characters EntityFactory::getCharacters() { return _characters; }

Collectables EntityFactory::getCollectables() { return _collectables; }

Walls EntityFactory::getWalls() {return _walls;}

CharacterPtr EntityFactory::getCharacter(CharacterName name) { return _characters[name]; }

} // namespace View