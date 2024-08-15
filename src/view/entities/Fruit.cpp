#include "Fruit.hpp"

#include "DEFINITIONS.hpp"

namespace View {

Fruit::Fruit(sf::Texture texture) : Collectable() {
    TexturePtr newtexture = std::make_shared<sf::Texture>();
    newtexture->loadFromImage(texture.copyToImage(), sf::IntRect(2*SPRITE_WIDTH, 3*SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
    setTexture(newtexture);

}

} // View