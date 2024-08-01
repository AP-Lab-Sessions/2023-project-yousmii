// Source: SFML Game Engine by Sonar Systems

#ifndef ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

namespace View {

class AssetManager {
public:
    AssetManager() = default;
    ~AssetManager() = default;

    void LoadTexture(const std::string& name, const std::string& fileName);
    sf::Texture &GetTexture(const std::string& name);

    void LoadFont(const std::string& name, const std::string& fileName);
    sf::Font &GetFont(const std::string& name);

private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
};

} // View

#endif //ASSETMANAGER_HPP
