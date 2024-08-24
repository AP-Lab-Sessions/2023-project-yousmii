#include "Coin.hpp"

#include "DEFINITIONS.hpp"

#include <SFML/Graphics.hpp>

namespace View {
    Coin::Coin(sf::Texture &texture) : Collectable() {
        TexturePtr newtexture = std::make_shared<sf::Texture>();
        // yes, it has its own texture
        newtexture->loadFromImage(texture.copyToImage(), sf::IntRect(10*SPRITE_WIDTH, 3*SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
        setTexture(newtexture);
    }
} // View