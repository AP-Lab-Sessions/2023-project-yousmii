#ifndef COLLECTABLE_HPP
#define COLLECTABLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace View {
///@remarks This class works very differently from the Character class
class Collectable {
public:
    Collectable();
    ~Collectable() = default;

    /// @brief Get the sprite of the collectable.
    sf::Sprite getSprite();
    /// @brief Set the position of the collectable's sprite
    void setPosition(float x, float y);
    /// @brief Set the texture of the collectable's sprite
    void setTexture(sf::Texture& texture);

private:
    sf::Sprite _sprite;
    sf::Texture _texture;
};

} // namespace View

#endif // COLLECTABLE_HPP
