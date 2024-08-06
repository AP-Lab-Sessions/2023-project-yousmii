
#include "Character.hpp"
#include <SFML/Graphics/Texture.hpp> // solves some missing functions

namespace View {
Character::Character() {
    _frame = Frame::ONE;
    _direction = Direction::DOWN;
    _sprite = sf::Sprite();
    _textures = std::map<Direction, std::pair<sf::Texture, sf::Texture>>();
};

void Character::setTextures(Direction direction, sf::Texture textureOne, sf::Texture textureTwo) {
    _textures[direction].first = textureOne;
    _textures[direction].second = textureTwo;
}

void Character::setDirection(Direction direction) { _direction = direction; }

void Character::updateSprite() {
    switchFrame();
    _sprite.setTexture(getTexture());
}

void Character::setPosition(float x, float y) { _sprite.setPosition(x, y); }

void Character::getSprite(sf::Sprite& sprite) { sprite = _sprite; }

void Character::switchFrame() {
    if (_frame == Frame::ONE) {
        _frame = Frame::TWO;
    } else {
        _frame = Frame::ONE;
    }
}
sf::Texture& Character::getTexture() {
    if (_frame == Frame::ONE) {
        return _textures[_direction].first;
    } else {
        return _textures[_direction].second;
    }
}

} // namespace View