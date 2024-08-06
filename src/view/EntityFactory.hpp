#ifndef SPRITEFACTORY_HPP
#define SPRITEFACTORY_HPP

#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include "entities/Character.hpp"
#include "entities/Collectable.hpp"

#include <SFML/Graphics.hpp>

namespace View {

typedef std::shared_ptr<Character> CharacterPtr;
typedef std::shared_ptr<Collectable> CollectablePtr;
typedef std::map<CharacterName, CharacterPtr> Characters;
typedef std::map<CollectableName, std::vector<CollectablePtr>> Collectables;

// Managed by GameState
class EntityFactory {
public:
    explicit EntityFactory(sf::Texture& texture);
    ~EntityFactory() = default;

    void updateCharacters(); // Frame updating
    void updatePositions(); // Position updating
    void updateDirections(); // Direction updating

    void update();

    void getCharacters();
    void getCollectables();

    void isPacmanAlive();
    void pacmanDie();

private:
    void initCharacters();
    void initCollectables();

    sf::Texture& _spritesheet;
    Characters _characters;
    Collectables _collectables;
};

} // namespace View

#endif // SPRITEFACTORY_HPP
