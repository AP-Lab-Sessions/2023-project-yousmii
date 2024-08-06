#ifndef COLLECTABLE_HPP
#define COLLECTABLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace View {

class Collectable {
public:
    Collectable();
    ~Collectable() = default;

    sf::Sprite getSprite();
    void setPosition(float x, float y);
    void setTexture(sf::Texture& texture);

    void eat() { _eaten = true; }
    bool isEaten() { return _eaten; }

private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    bool _eaten;
};

} // namespace View

#endif // COLLECTABLE_HPP
