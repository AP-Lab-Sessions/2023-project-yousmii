#include "Collectable.hpp"

namespace View {
Collectable::Collectable() {
    _sprite = sf::Sprite();
    _texture = sf::Texture();
}

void Collectable::setTexture(sf::Texture& texture) {
    _texture = texture;
    _sprite.setTexture(_texture);
}

void Collectable::setPosition(float x, float y) { _sprite.setPosition(x, y); }

sf::Sprite Collectable::getSprite() { return _sprite; }

} // namespace View