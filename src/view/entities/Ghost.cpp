#include "Ghost.hpp"

namespace View {
Ghost::Ghost(sf::Texture& texture, const CharacterName& name) {
    // Load normal textures
    for (int i = 0; i < 4; i++) {
        sf::Texture texture1;
        texture1.loadFromImage(texture.copyToImage(),
                               sf::IntRect(SPRITE_WIDTH * i * 2,
                                           SPRITE_HEIGHT * 4 + SPRITE_HEIGHT * static_cast<int>(name), SPRITE_WIDTH,
                                           SPRITE_HEIGHT));
        sf::Texture texture2;
        texture2.loadFromImage(texture.copyToImage(),
                               sf::IntRect(SPRITE_WIDTH + SPRITE_WIDTH * i * 2,
                                           SPRITE_HEIGHT * 4 + SPRITE_HEIGHT * static_cast<int>(name), SPRITE_WIDTH,
                                           SPRITE_HEIGHT));
        setTextures(static_cast<Direction>(i), texture1, texture2);
        _normalTextures[static_cast<Direction>(i)] = std::make_pair(texture1, texture2);
    }

    // Load dead textures
    for (int i = 0; i < 2; i++) {
        sf::Texture texture1;
        texture1.loadFromImage(texture.copyToImage(), sf::IntRect(SPRITE_WIDTH * 8 + SPRITE_WIDTH * i,
                                                                  SPRITE_HEIGHT * 5, SPRITE_WIDTH, SPRITE_HEIGHT));
        _deadTextures[static_cast<Direction>(i)] = std::make_pair(texture1, texture1);
    }

    // Load frightened textures
    sf::Texture fright1;
    fright1.loadFromImage(texture.copyToImage(),
                          sf::IntRect(SPRITE_WIDTH * 8, SPRITE_HEIGHT * 4, SPRITE_WIDTH, SPRITE_HEIGHT));
    sf::Texture fright2;
    fright2.loadFromImage(texture.copyToImage(), sf::IntRect(SPRITE_WIDTH * 10 + SPRITE_WIDTH, SPRITE_HEIGHT * 4,
                                                             SPRITE_WIDTH, SPRITE_HEIGHT));
    for (int i = 0; i < 2; i++) {
        _frightenedTextures[static_cast<Direction>(i)] = std::make_pair(fright1, fright2);
    }

    // Load calming textures
    sf::Texture calming1;
    calming1.loadFromImage(texture.copyToImage(),
                           sf::IntRect(SPRITE_WIDTH * 11, SPRITE_HEIGHT * 4, SPRITE_WIDTH, SPRITE_HEIGHT));
    for (int i = 0; i < 2; i++) {
        _calmingTextures[static_cast<Direction>(i)] = std::make_pair(fright1, calming1); // Creates a flashing effect
    }
}

void Ghost::changeState(GhostState state) {
    _state = state;
    switch (_state) {
    case GhostState::NORMAL:
        setFullTextures(_normalTextures);
        break;
    case GhostState::FRIGHTENED:
        setFullTextures(_frightenedTextures);
        break;
    case GhostState::DEAD:
        setFullTextures(_deadTextures);
        break;
    case GhostState::CALMING:
        setFullTextures(_calmingTextures);
        break;
    }
}

void Ghost::getState(GhostState& state) { state = _state; }

} // namespace View