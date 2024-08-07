#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../DEFINITIONS.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <map>
#include <memory>

namespace View {

enum class Frame { // Characters have 2 frames
    ONE = 1,
    TWO
};

typedef std::shared_ptr<sf::Texture> TexturePtr;
typedef std::map<Direction, std::pair<TexturePtr, TexturePtr>> CharacterTextures;

class Character {
public:
    Character();
    ~Character() = default;

    void setTextures(Direction direction, TexturePtr textureOne, TexturePtr textureTwo);
    void setFullTextures(CharacterTextures& textures);
    void setDirection(Direction direction);

    void update();
    void setPosition(float x, float y);

    sf::Sprite getSprite();
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
    TexturePtr getTexture();
};

} // namespace View

#endif // CHARACTER_HPP
