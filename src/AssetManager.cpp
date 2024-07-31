// Source: SFML Game Engine by Sonar Systems
#include "AssetManager.hpp"

namespace Rep {
void AssetManager::LoadTexture(const std::string& name, const std::string& fileName) {
    sf::Texture newtexture;

    if (newtexture.loadFromFile(fileName)) {
        _textures[name] = newtexture;
    }
    else {
        std::cerr << "Failed to load texture: " << fileName << std::endl;
    }
}

sf::Texture& AssetManager::GetTexture(const std::string& name) { return _textures.at(name); }

void AssetManager::LoadFont(const std::string& name, const std::string& fileName) {
    sf::Font newfont;

    if (newfont.loadFromFile(fileName)) {
        _fonts[name] = newfont;
    }
    else {
        std::cerr << "Failed to load font: " << fileName << std::endl;
    }
}

sf::Font& AssetManager::GetFont(const std::string& name) { return _fonts.at(name); }
} // namespace Rep