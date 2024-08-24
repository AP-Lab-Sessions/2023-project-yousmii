#ifndef SPRITEFACTORY_HPP
#define SPRITEFACTORY_HPP

#include "../DEFINITIONS.hpp"

#include "entities/Character.hpp"
#include "entities/Collectable.hpp"
#include "entities/Wall.hpp"

#include <SFML/Graphics.hpp>

namespace View {

class Wall;

/// Yeah I know, this is a lot of typedefs but it's necessary for readability
typedef std::shared_ptr<Character> CharacterPtr;
typedef std::shared_ptr<Collectable> CollectablePtr;
typedef std::shared_ptr<Wall> WallPtr;
typedef std::map<CharacterName, CharacterPtr> Characters;
typedef std::map<std::pair<int, int>, CollectablePtr> Collectables;
typedef std::vector<WallPtr> Walls;

// Managed by GameState
class EntityFactory {
public:
    /// @brief Constructor, creates the entities based on the data map received from Logic::Camera
    /// @param texture The spritesheet
    /// @param data_map The data map for the entities, see EntityDataMap in DEFINITIONS
    explicit EntityFactory(sf::Texture& texture, const EntityDataMap& data_map);

    /// @brief Destructor, doesnt do anything, smart pointers take care of the memory management
    ~EntityFactory() = default;

    /// @brief Updates the character frames,
    void updateCharacters();

    /// @brief Removes a collectable, used when Pacman eats a collectable
    void removeCollectable(int row, int col);

    /// @brief Moves a character to a new position
    void moveCharacter(CharacterName name, int newRow, int newCol);

    /// @brief Sets the direction of a character
    void setCharacterDirection(CharacterName name, Direction direction);

    /// @brief Updates the entities, was gonna use it for more stuff but it's just for the character frames
    /// @remarks If you want to add more stuff to update, you can add a new function and call it in here
    void update();

    /// @brief Draws all the entities on the given window
    /// @param window The window to draw the entities on, reference so it's not copied
    void drawAll(sf::RenderWindow& window);

    /// @brief Getters for the entities
    Characters getCharacters();

    /// @brief Getters for the collectables
    Collectables getCollectables();

    /// @brief Getters for the walls
    Walls getWalls();

    /// @brief Getter for a specific character, used for moving the player
    CharacterPtr getCharacter(CharacterName name);

private:
    /// @brief The next time the animation should be updated
    float nextUpdateAnimation;

    /// @brief The spritesheet
    sf::Texture& _spritesheet;

    /// @brief The characters
    Characters _characters;

    /// @brief The collectables, includes the bananas
    Collectables _collectables;

    //// @brief The walls
    Walls _walls;
};

/// @brief Typedef for the EntityFactory smart pointer, used for readability
typedef std::shared_ptr<EntityFactory> EntityFactoryPtr;

} // namespace View

#endif // SPRITEFACTORY_HPP
