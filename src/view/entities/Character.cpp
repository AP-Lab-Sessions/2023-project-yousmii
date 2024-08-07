
#include "Character.hpp"
#include <SFML/Graphics/Texture.hpp> // solves some missing functions
#include <utility>

namespace View {
Character::Character() {
    _frame = Frame::ONE;
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

void Character::setFullTextures(CharacterTextures& textures) { _textures = textures; }

void Character::setDirection(Direction direction) { _direction = direction; }

void Character::update() {
    switchFrame();
    _sprite.setTexture(*getTexture());
}

void Character::setPosition(float x, float y) { _sprite.setPosition(x, y); }

sf::Sprite Character::getSprite() { return _sprite; }

void Character::switchFrame() {
    if (_frame == Frame::ONE) {
        _frame = Frame::TWO;
    } else {
        _frame = Frame::ONE;
    }
}
TexturePtr Character::getTexture() {
    if (_frame == Frame::ONE) {
        return _textures[_direction].first;
    } else {
        return _textures[_direction].second;
    }
}

bool Character::isAlive() { return _alive; }
void Character::die() { _alive = false; }
void Character::respawn() { _alive = true; }

} // namespace View