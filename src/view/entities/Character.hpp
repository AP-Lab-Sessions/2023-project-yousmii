#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../../DEFINITIONS.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <map>
#include <memory>

namespace View {

/// @brief Represents the frame of the character.
enum class CharacterFrame { ONE = 1, TWO };

typedef std::shared_ptr<sf::Texture> TexturePtr;
/// @brief Holds the 2 textures of the character, depending on where it is facing.
typedef std::map<Direction, std::pair<TexturePtr, TexturePtr>> CharacterTextures;

///@brief Parent class: Represents a character in the game.
class Character {
public:
    Character();
    virtual ~Character() = default;

    /// @brief Set the textures for the character in the given direction. Each direction of a character has two frames.
    /// @param direction The direction the textures belong to
    /// @param textureOne The first frame
    /// @param textureTwo The second frame
    void setTextures(Direction direction, TexturePtr textureOne, TexturePtr textureTwo);

    /// @brief Set the full textures for the character.
    /// @param textures Full texture pack for the character, including all directions and frames.
    void setFullTextures(CharacterTextures& textures);

    /// @brief Update the direction of the character. Does not update the sprite, update must be called separately.
    /// @param direction The new direction of the character.
    void setDirection(Direction direction);

    /// @brief Switches the frame and updates the sprite. Purely for animation purposes, not for movement.
    void update();

    /// @brief Set the position of the character.
    /// @param x X coordinate, obviously
    /// @param y Y coordinate, obviously
    void setPosition(float x, float y);

    /// @brief Get the sprite of the character. Used for rendering.
    sf::Sprite getSprite();

    /// @brief Check if the character is alive.
    /// @return True if the character is alive, false otherwise.
    bool isAlive();
    /// @brief Changes _alive to false.
    /// @remark If the character is a ghost, it also changes the texture pack.
    virtual void die();
    /// @brief Changes _alive to true.
    /// @remark Changes the texture pack of the ghost to normal textures.
    virtual void respawn();

    bool _alive;

private:
    CharacterFrame _frame;
    Direction _direction;
    sf::Sprite _sprite;
    CharacterTextures _textures;

    /// @brief Changes the current frame of the character sprite
    void switchFrame();
    /// @brief Get the current texture of the character based on the current frame and direction.
    /// @return Pointer to the correct texture
    TexturePtr getTexture();
};

} // namespace View

#endif // CHARACTER_HPP
