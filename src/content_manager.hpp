#ifndef SFML_PROJECT_CONTENT_MANAGER_HPP
#define SFML_PROJECT_CONTENT_MANAGER_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <memory>

template<class T> 
class ContentManager {
    private:
    std::unordered_map<std::string, T> m_Content;
    std::string m_Folder;

    public:
    /// @brief 
    /// @param folder relative path to content folder
    /// @return true if folder is correct
    bool Init(std::string folder);
    
    /// @brief Loads content from %file and saves it under %name. %name must be unique
    /// @param file filename with extension
    /// @param name name for future access
    /// @return true if successfully loaded
    bool LoadContent(std::string file, std::string name);

    /// @brief Gets pointer to content from saved mapping
    /// @param name name given at LoadContent()
    /// @return Pointer to content or nullptr if not found
    T *GetContentPtr(std::string name);

    T &GetContent(std::string name);
};

template <class T>
bool ContentManager<T>::Init(std::string folder) {
    m_Folder = folder;
    // TODO: check if folder is correct
    return true;
}

template <class T>
bool ContentManager<T>::LoadContent(std::string file, std::string name){
    if (m_Content.contains(name)) {
        return false;
    }

    sf::FileInputStream stream;
    std::string path = m_Folder + "/" + file;
    if (!stream.open(path)) {
        return false;
    }
    T content;
    if (!content.loadFromStream(stream)) {
        return false;
    }
    m_Content.emplace(name, content);
    return true;
}

template <class T>
T *ContentManager<T>::GetContentPtr(std::string name){
    if (!m_Content.contains(name)) {
        return nullptr;
    }

    return &(m_Content[name]);
}

template <class T>
T &ContentManager<T>::GetContent(std::string name) {
    return m_Content[name];
}

class ResourceManager {
    public:
    inline static std::unique_ptr<std::unordered_map<std::string, sf::Font>> m_Fonts;
    inline static std::string m_Folder;
    ResourceManager() {}

    public:

    inline static void Init(std::string folder) {
        ResourceManager::m_Folder = folder;
        ResourceManager::m_Fonts = std::make_unique<std::unordered_map<std::string, sf::Font>>();
    }
    inline static sf::Font *GetFont(std::string name) {
        return &(ResourceManager::m_Fonts.get()->operator[](name));
    }
    inline static void LoadFont(std::string file, std::string name) {
        sf::FileInputStream stream;
        std::string path = ResourceManager::m_Folder + "/" + file;
        stream.open(path);
        sf::Font content;
        content.loadFromStream(stream);
        ResourceManager::m_Fonts->emplace(name, content);
    }
};

#endif