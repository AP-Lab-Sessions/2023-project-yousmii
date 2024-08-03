// Source: SFML Game Engine by Sonar Systems
#include "AssetManager.hpp"

namespace View {
template <typename T>
std::pair<std::string, T> AssetManager::Load(const std::string& name, const std::string& fileName) {
    T asset;
    if (!asset.loadFromFile(fileName)) {
        std::cerr << "Failed to load asset: " << name << " at " << fileName << std::endl;
    }
    return std::make_pair(name, asset);
}

void AssetManager::LoadTexture(const std::string& name, const std::string& fileName) {
    auto asset = Load<sf::Texture>(name, fileName);
    _textures.insert(asset);
}

sf::Texture& AssetManager::GetTexture(const std::string& name) { return _textures.at(name); }

void AssetManager::LoadFont(const std::string& name, const std::string& fileName) {
    auto asset = Load<sf::Font>(name, fileName);
    _fonts.insert(asset);
}

sf::Font& AssetManager::GetFont(const std::string& name) { return _fonts.at(name); }

void AssetManager::LoadImage(const std::string& name, const std::string& fileName) {
    auto asset = Load<sf::Image>(name, fileName);
    _images.insert(asset);
}

sf::Image& AssetManager::GetImage(const std::string& name) { return _images.at(name); }
} // namespace View
