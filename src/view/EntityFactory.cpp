#include "EntityFactory.hpp"

namespace View {
EntityFactory::EntityFactory(GameDataRef data) : _data(data) {
    _data->assets.LoadTexture("Sprites", "assets/textures/Sprites.png");

    initCharacters(_data->assets.GetTexture("Sprites"));
    initCollectables(_data->assets.GetTexture("Sprites"));
}

void EntityFactory::initCharacters(const sf::Texture& texture) {}

void EntityFactory::initCollectables(const sf::Texture& texture) {}
} // namespace View