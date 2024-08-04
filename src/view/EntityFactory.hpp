#ifndef SPRITEFACTORY_HPP
#define SPRITEFACTORY_HPP

#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include "entities/Character.hpp"
#include "entities/Collectable.hpp"

#include <SFML/Graphics.hpp>

namespace View {
// Managed by GameState
class EntityFactory {
public:
    EntityFactory(GameDataRef data);
    ~EntityFactory() = default;

    void initCharacters(const sf::Texture& texture);
    void initCollectables(const sf::Texture& texture); // Depends on map

    Character createCharacter(CharacterName name, const sf::Texture& texture);
    Collectable createCollectable(CharacterName name, const sf::Texture& texture);

    void drawCharacters();
    void drawCollectables();

private:
    GameDataRef _data;
    std::map<CharacterName, Character> _characters;
    std::map<CollectableName, std::vector<Collectable>> _collectables;
};

} // namespace View

#endif // SPRITEFACTORY_HPP
