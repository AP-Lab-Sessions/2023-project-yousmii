#ifndef GHOST_HPP
#define GHOST_HPP
#include "Character.hpp"

namespace View {

class Ghost : public Character {
public:
    Ghost(sf::Texture& texture, const CharacterName& name);
    void changeState(GhostState state);
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
