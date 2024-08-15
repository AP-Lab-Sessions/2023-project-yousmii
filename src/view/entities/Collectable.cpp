#include "Collectable.hpp"

#include "DEFINITIONS.hpp"

namespace View {
Collectable::Collectable() {
    _sprite = sf::Sprite();
    _sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
    _texture = nullptr;
}

void Collectable::setTexture(TexturePtr texture) {
    _texture = std::move(texture);
    _sprite.setTexture(*_texture);
}

void Collectable::setPosition(float x, float y) { _sprite.setPosition(x, y); }

sf::Sprite Collectable::getSprite() { return _sprite; }

} // namespace View