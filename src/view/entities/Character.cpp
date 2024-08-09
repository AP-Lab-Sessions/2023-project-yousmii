
#include "Character.hpp"

#include <SFML/Graphics/Texture.hpp> // solves some missing functions
#include <stdexcept>
#include <utility>

namespace View {
Character::Character() {
    _frame = CharacterFrame::ONE;
    _direction = Direction::RIGHT;

    _sprite = sf::Sprite();
    _sprite.setScale(2, 2);

    _textures = CharacterTextures();
    _alive = true;
};

void Character::setTextures(Direction direction, TexturePtr textureOne, TexturePtr textureTwo) {
    _textures[direction].first = std::move(textureOne);
    _textures[direction].second = std::move(textureTwo);
}

void Character::setFullTextures(CharacterTextures& textures) {
    // Check if the textures map is complete
    for (int i = 0; i < 4; i++) {
        if (textures.find(static_cast<Direction>(i)) == textures.end()) {
            throw std::runtime_error("Texture map does not have all directions");
        } else {
            if (textures[static_cast<Direction>(i)].first == nullptr ||
                textures[static_cast<Direction>(i)].second == nullptr) {
                throw std::runtime_error("Texture map does not have all frames");
            }
        }
    }
    _textures = textures;
}

void Character::setDirection(Direction direction) { _direction = direction; }

void Character::update() {
    switchFrame();
    _sprite.setTexture(*getTexture());
}

void Character::setPosition(float x, float y) { _sprite.setPosition(x, y); }

sf::Sprite Character::getSprite() { return _sprite; }

void Character::switchFrame() {
    if (_frame == CharacterFrame::ONE) {
        _frame = CharacterFrame::TWO;
    } else {
        _frame = CharacterFrame::ONE;
    }
}
TexturePtr Character::getTexture() {
    TexturePtr texture;
    if (_frame == CharacterFrame::ONE) {
        texture = _textures[_direction].first;
    } else {
        texture = _textures[_direction].second;
    }
    if (texture == nullptr) {
        throw std::runtime_error("Texture not found");
    } else {
        return texture;
    }
}

bool Character::isAlive() { return _alive; }
void Character::die() { _alive = false; }
void Character::respawn() { _alive = true; }

} // namespace View