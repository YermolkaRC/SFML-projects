#include "ui_controls.hpp"

Label::Label(const sf::Font *font, std::string text, float x, float y, int size) {
    m_Text.setFont(*font);
    m_Text.setString(text);
    m_Text.setCharacterSize(size);
    m_Text.setPosition(x, y);
    m_X = x;
    m_Y = y;
}

void Label::Update(sf::Time elapsed) {

}


void Label::Render(sf::RenderWindow *window) {
    window->draw(m_Text);
}

sf::Vector2f UIControl::GetPosition(){
    return {m_X, m_Y};
}

sf::Vector2f UIControl::GetSize(){
    return {m_Width, m_Height};
}

float UIControl::GetWidth(){
    return m_Width;
}

float UIControl::GetHeight(){
    return m_Height;
}

void UIControl::SetPosition(sf::Vector2f pos){
    m_X = pos.x;
    m_Y = pos.y;
}

void UIControl::SetPosition(float x, float y){
    m_X = x;
    m_Y = y;
}
