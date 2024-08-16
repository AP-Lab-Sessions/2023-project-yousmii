#ifndef SPRITEFACTORY_HPP
#define SPRITEFACTORY_HPP

#include "../DEFINITIONS.hpp"

#include "entities/Character.hpp"
#include "entities/Collectable.hpp"
#include "entities/Wall.hpp"

#include <SFML/Graphics.hpp>

namespace View {

class Wall;

typedef std::shared_ptr<Character> CharacterPtr;
typedef std::shared_ptr<Collectable> CollectablePtr;
typedef std::shared_ptr<Wall> WallPtr;
typedef std::map<CharacterName, CharacterPtr> Characters;
typedef std::map<std::pair<int, int>, CollectablePtr> Collectables;
typedef std::vector<WallPtr> Walls;

// Managed by GameState
class EntityFactory {
public:
    explicit EntityFactory(sf::Texture& texture, const EntityDataMap& data_map);
    ~EntityFactory() = default;

    void updateCharacters(); // CharacterFrame updating
    void updatePositions();  // Position updating
    void updateDirections(); // Direction updating

    void update();

    void drawAll(sf::RenderWindow& window);

    Characters getCharacters();
    Collectables getCollectables();
    Walls getWalls();

    CharacterPtr getCharacter(CharacterName name);


private:
    sf::Texture& _spritesheet;
    Characters _characters;
    Collectables _collectables;
    Walls _walls;
};

typedef std::shared_ptr<EntityFactory> EntityFactoryPtr;

} // namespace View

#endif // SPRITEFACTORY_HPP
