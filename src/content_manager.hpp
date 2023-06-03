#ifndef SFML_PROJECT_CONTENT_MANAGER_HPP
#define SFML_PROJECT_CONTENT_MANAGER_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <memory>
#include "logger.hpp"

class ResourceManager {
    private:
    static std::map<std::string, std::shared_ptr<sf::Texture>> m_Textures;
    static std::string m_Folder;
    ResourceManager() {}

    public:
    static sf::Font *m_ArialFont, *m_SkullFont;
    static void Init(std::string folder);
    static void CleanUp();

    static const sf::Font *GetArialFont();
    static const sf::Font *GetSkullFont();
    static void LoadFont(std::string file);

    static std::shared_ptr<sf::Texture> GetTexture(std::string name);
    static void LoadTexture(std::string file, std::string name);
};

#endif