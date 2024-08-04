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

private:
    sf::Sprite _sprite;
    sf::Texture _texture;
};

} // View

#endif //COLLECTABLE_HPP
