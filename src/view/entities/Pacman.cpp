#include "Pacman.hpp"

namespace View {
 Pacman::Pacman(sf::Texture& texture) {
     // Only one texture for Pacman
     for (int i = 0; i < 4; i++) {
         sf::Texture texture1;
            texture1.loadFromImage(texture.copyToImage(), sf::IntRect(0,  SPRITE_HEIGHT * i, SPRITE_WIDTH, SPRITE_HEIGHT));
         sf::Texture texture2;
            texture2.loadFromImage(texture.copyToImage(), sf::IntRect(SPRITE_WIDTH, SPRITE_HEIGHT * i, SPRITE_WIDTH, SPRITE_HEIGHT));
         setTextures(Direction(i), texture1, texture2);
    }
 }
} // namespace View