#include "Banana.hpp"
#include "../../DEFINITIONS.hpp"

namespace View {
Banana::Banana(sf::Texture texture) : Collectable() {
    TexturePtr newtexture = std::make_shared<sf::Texture>();
    newtexture->loadFromImage(texture.copyToImage(), sf::IntRect(9*SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
    setTexture(newtexture);
}
} // View
