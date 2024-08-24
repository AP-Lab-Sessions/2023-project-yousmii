// Source: SFML Game Engine by Sonar Systems

#ifndef ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

namespace View {

/// @brief The Ass-etManager class is responsible for loading and storing assets such as textures and fonts.
/// @remark hehe ass :)
class AssetManager {
public:
    AssetManager() = default;
    ~AssetManager() = default;

    /// @brief Load a texture to the Asset library
    /// @param name Name you want to store it as
    /// @param fileName File path actually
    void LoadTexture(const std::string& name, const std::string& fileName);

    /// @brief Getter of a texture
    /// @param name Name of the texture
    /// @return Texture, SFML format
    sf::Texture& GetTexture(const std::string& name);

    /// @brief Load a font to the Asset library
    /// @param name Name you want to store it as
    /// @param fileName File path actually
    void LoadFont(const std::string& name, const std::string& fileName);

    /// @brief Getter of a font
    /// @param name name of the font, in most cases you can find the main font names in DEFINITIONS
    /// @return Font, SFML format
    sf::Font& GetFont(const std::string& name);

    /// @brief Load an Image to the asset library
    /// @param name Name you want to store it as
    /// @param fileName File path actually, but yea
    void LoadImage(const std::string& name, const std::string& fileName);

    /// @brief Getter for images
    /// @param name name of the image
    /// @return The image, SFML format
    sf::Image& GetImage(const std::string& name);

private:
    template <typename T> // Avoiding duplicate code like the pest <3
    /// @brief Loads a file to add it to one of the maps
    /// @param name Name you want to store it as
    /// @param fileName File path actually, but yea
    std::pair<std::string, T> Load(const std::string& name, const std::string& fileName);

    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
    std::map<std::string, sf::Image> _images;
};

} // namespace View

#endif // ASSETMANAGER_HPP
