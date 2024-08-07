#include "EntityFactory.hpp"

#include "entities/Ghost.hpp"
#include "entities/Pacman.hpp"

namespace View {
EntityFactory::EntityFactory(sf::Texture& texture) : _spritesheet(texture) {
    initCharacters();
    initCollectables();
}

void EntityFactory::initCharacters() {
    // Pacman
    _characters[CharacterName::Pacman] = std::make_shared<Pacman>(_spritesheet);
    // Ghosts
    _characters[CharacterName::Blinky] = std::make_shared<Ghost>(_spritesheet, CharacterName::Blinky);
    _characters[CharacterName::Pinky] = std::make_shared<Ghost>(_spritesheet, CharacterName::Pinky);
    _characters[CharacterName::Inky] = std::make_shared<Ghost>(_spritesheet, CharacterName::Inky);
    _characters[CharacterName::Clyde] = std::make_shared<Ghost>(_spritesheet, CharacterName::Clyde);
}

void EntityFactory::initCollectables() {
    // Create collectables based on map
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

Characters EntityFactory::getCharacters() {
    return _characters;
}

Collectables EntityFactory::getCollectables() {
    return _collectables;
}

CharacterPtr EntityFactory::getCharacter(CharacterName name) {
    return _characters[name];
}

void EntityFactory::isPacmanAlive() { _characters[CharacterName::Pacman]->isAlive(); }

void EntityFactory::pacmanDie() { _characters[CharacterName::Pacman]->die(); }

} // namespace View