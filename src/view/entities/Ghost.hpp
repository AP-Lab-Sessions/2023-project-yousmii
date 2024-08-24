#ifndef GHOST_HPP
#define GHOST_HPP
#include "Character.hpp"

namespace View {

class Ghost : public Character {
public:
    /// @brief Constructor of Ghost, which initializes the texture of the entity in all directions
    explicit Ghost(sf::Texture& texture, const CharacterName& name);

    /// @brief Changes the texture pack of the ghost to the dead one, just eyes and no body
    void die() override;

    /// @brief Changes the texture pack of the ghost to the flashing one, indicating that the power-up is about to end
    void respawn() override;

    /// @brief Changes the texture pack of the ghost according to the given state
    /// @param state The state to change to
    void changeState(GhostState state);

    /// @brief Returns the current state of the ghost
    void getState(GhostState& state);

private:
    CharacterTextures _deadTextures;
    CharacterTextures _frightenedTextures;
    CharacterTextures _calmingTextures; // Indicating that Frightened mode is about to end (flashing)
    CharacterTextures _normalTextures;

    GhostState _state;
};

} // namespace View

#endif // GHOST_HPP
