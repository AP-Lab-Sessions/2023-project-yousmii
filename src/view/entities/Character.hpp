#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../DEFINITIONS.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <map>

namespace View {

enum class Frame { // Characters have 2 frames
    ONE = 1,
    TWO
};

typedef std::map<Direction, std::pair<sf::Texture, sf::Texture>> CharacterTextures;

class Character {
public:
    Character();
    ~Character() = default;

    void setTextures(Direction direction, sf::Texture textureOne, sf::Texture textureTwo);
    void setFullTextures(CharacterTextures& textures);
    void setDirection(Direction direction);

    void update();
    void setPosition(float x, float y);

    void getSprite(sf::Sprite& sprite);
    bool isAlive();
    void die();
    void respawn();

private:
    Frame _frame;
    Direction _direction;
    sf::Sprite _sprite;
    CharacterTextures _textures;
    bool _alive;

    void switchFrame();
    sf::Texture& getTexture();
};

} // namespace View

#endif // CHARACTER_HPP
