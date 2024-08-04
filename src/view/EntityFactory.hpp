#ifndef SPRITEFACTORY_HPP
#define SPRITEFACTORY_HPP

#include "Game.hpp"
#include "entities/Character.hpp"
#include "entities/Collectable.hpp"

#include <SFML/Graphics.hpp>

namespace View {

// Managed by GameState
class EntityFactory {
public:
    EntityFactory() = default;
    ~EntityFactory() = default;

    Character createCharacter(std::string name, const sf::Texture& texture);
    Collectable createCollectable(std::string name, const sf::Texture& texture);

    void drawCharacters(GameDataRef data);
    void drawCollectables(GameDataRef data);

private:
    std::map<std::string, Character> _characters;
    std::map<std::string, Collectable> _collectables;
};

} // namespace View

#endif // SPRITEFACTORY_HPP
