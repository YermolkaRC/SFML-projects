#ifndef SFML_PROJECT_SCREEN_HPP
#define SFML_PROJECT_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "ui_controls.hpp"

class Screen {
    protected:
    sf::Sprite m_Background;

};

class TestScreen {
    protected:
    Label start, options, exit;
    sf::Font m_Font;

    public:
    TestScreen() {

    }
    TestScreen(std::string font_name, int width, int height) {
        m_Font = *ResourceManager::GetFont(font_name);
        start = Label(m_Font, "Start game", width / 2.0, height / 2.0 - 24);
        options = Label(m_Font, "Options", width / 2.0, height / 2.0);
        exit = Label(m_Font, "Exit", width / 2.0, height / 2.0 + 24);
    }

    void Render(sf::RenderWindow *window) {
        start.Render(window);
        options.Render(window);
        exit.Render(window);
    }
};

class IntroScreen : Screen {

};

#endif