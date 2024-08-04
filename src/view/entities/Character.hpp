#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "SFML/Graphics/Sprite.hpp"

#include <map>

namespace View {

enum class Frame { // Characters have 2 frames
    ONE = 1,
    TWO
};

enum class Direction { UP, RIGHT, DOWN, LEFT };

class Character {
public:
    Character();
    ~Character() = default;

    void setTextures(Direction direction, sf::Texture textureOne, sf::Texture textureTwo);
    void setDirection(Direction direction);

    void updateSprite();
    void setPosition(float x, float y);

    void getSprite(sf::Sprite& sprite);

private:
    Frame _frame;
    Direction _direction;
    sf::Sprite _sprite;
    std::map<Direction, std::pair<sf::Texture, sf::Texture>> _textures;

    void switchFrame();
    sf::Texture& getTexture();
};

} // namespace View

#endif // CHARACTER_HPP
