#ifndef SFML_PROJECT_UI_CONTROLS_HPP
#define SFML_PROJECT_UI_CONTROLS_HPP

#include <SFML/Graphics.hpp>

class UIControl {
    protected:
    float m_Width, m_Height;
    float m_X, m_Y;

    public:
    sf::Vector2f GetPosition() {
        return {m_X, m_Y};
    }
    sf::Vector2f GetSize() {
        return {m_Width, m_Height};
    }
    float GetWidth() {
        return m_Width;
    }
    float GetHeight() {
        return m_Height;
    }

    void SetPosition(sf::Vector2f pos) {
        m_X = pos.x;
        m_Y = pos.y;
    }
    void SetPosition(float x, float y) {
        m_X = x;
        m_Y = y;
    }

    virtual void Update(sf::Time elapsed) = 0;
    virtual void Render(sf::RenderWindow *window) = 0;
};

class Label : UIControl {
    private:
    sf::Text m_Text;
    sf::Font m_Font;

    public:
    Label() {
        m_Font.loadFromFile("content/fonts/Skullcrusher.ttf");
    }
    Label(sf::Font &font, std::string text, float x = 0, float y = 0, int size = 24) {
        m_Font = sf::Font(font);
        m_Text.setFont(m_Font);
        m_Text.setString(text);
        m_Text.setCharacterSize(size);
        m_Text.setPosition(x, y);
        m_X = x;
        m_Y = y;
    }

    void Update(sf::Time elapsed) {

    }

    void Render(sf::RenderWindow *window) override {
        m_Text.setFont(m_Font);
        window->draw(m_Text);
    }
};

#endif