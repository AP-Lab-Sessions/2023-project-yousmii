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

    template <typename T>
    std::pair<std::string, T> Load(const std::string& name, const std::string& fileName);

    void LoadTexture(const std::string& name, const std::string& fileName);
    sf::Texture &GetTexture(const std::string& name);

    void LoadFont(const std::string& name, const std::string& fileName);
    sf::Font &GetFont(const std::string& name);

    void LoadImage(const std::string& name, const std::string& fileName);
    sf::Image &GetImage(const std::string& name);

private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
    std::map<std::string, sf::Image> _images;
};



} // View

#endif //ASSETMANAGER_HPP
