#ifndef SFML_PROJECT_UI_CONTROLS_HPP
#define SFML_PROJECT_UI_CONTROLS_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "logger.hpp"
#include "content_manager.hpp"

class UIControl {
    protected:
    float m_Width, m_Height;
    float m_X, m_Y;

    public:
    sf::Vector2f GetPosition();
    sf::Vector2f GetSize();
    float GetWidth();
    float GetHeight();

    void SetPosition(sf::Vector2f pos);
    void SetPosition(float x, float y);

    virtual void Update(sf::Time elapsed) = 0;
    virtual void Render(sf::RenderWindow *window) = 0;
};

class Label : UIControl {
    private:
    sf::Text m_Text;

    public:
    Label() {}
    Label(const sf::Font *font, std::string text, float x = 0, float y = 0, int size = 24);
    void Update(sf::Time elapsed) override;
    void Render(sf::RenderWindow *window) override;
};

class ClickableLabel : UIControl {

};

class ChoiceList : UIControl {

};

class Slider : UIControl {

};

class CheckBox : UIControl {

};

class TextBox : UIControl {

};

#endif