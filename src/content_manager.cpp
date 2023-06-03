#include "content_manager.hpp"

sf::Font *ResourceManager::m_ArialFont, *ResourceManager::m_SkullFont;
std::map<std::string, std::shared_ptr<sf::Texture>> ResourceManager::m_Textures;
std::string ResourceManager::m_Folder;

void ResourceManager::Init(std::string folder) {
        ResourceManager::m_Folder = folder;

        m_ArialFont = new sf::Font();
        m_ArialFont->loadFromFile(folder + "/fonts/arial.ttf");

        m_SkullFont = new sf::Font();
        m_SkullFont->loadFromFile(folder + "/fonts/Skullcrusher.ttf");
}

void ResourceManager::CleanUp(){
    if (m_ArialFont) {
        delete m_ArialFont;
    }
    if (m_SkullFont) {
        delete m_SkullFont;
    }
}

const sf::Font *ResourceManager::GetArialFont() {
    return m_ArialFont;    
}

const sf::Font *ResourceManager::GetSkullFont() {
    return m_SkullFont;
}

void ResourceManager::LoadFont(std::string file) {
    // sf::FileInputStream stream;
    // std::string path = ResourceManager::m_Folder + "/fonts/" + file;
    // stream.open(path);
    // if (!m_ArialFont) {
    //     Logger::Debug_log("Deleting old m_ArialFont.");
    //     delete m_ArialFont;
    // }
    // m_ArialFont = new sf::Font();
    // if (!m_ArialFont->loadFromStream(stream)) {
    //     Logger::Debug_log("Failed to load m_ArialFont: " + file);
    // }
    // Logger::Debug_log("Loaded m_ArialFont: " + file);
    Logger::Debug_log("Loading new font is Not Implemented!");
}

std::shared_ptr<sf::Texture> ResourceManager::GetTexture(std::string name){
    if (!m_Textures.contains(name)) {
        Logger::Debug_log("Failed to get texture: " + name);
        return nullptr;
    }
    return m_Textures[name];
}

void ResourceManager::LoadTexture(std::string file, std::string name){
    if (m_Textures.contains(name)) {
        Logger::Debug_log("Trying to load new texture for the same name: " + name + " @" + file);
        return;
    }

    sf::FileInputStream stream;
    std::string path = ResourceManager::m_Folder + "/textures/" + file;
    stream.open(path);
    auto content = std::make_shared<sf::Texture>();
    content->loadFromStream(stream);
    m_Textures.emplace(name, content);
    Logger::Debug_log("Loaded texture: " + name);
}
