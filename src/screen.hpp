#ifndef SFML_PROJECT_SCREEN_HPP
#define SFML_PROJECT_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "ui_controls.hpp"

class Screen {
    protected:
    sf::Sprite m_Background;

};

class TestScreen {
    protected:
    std::vector<Label> m_Labels;

    public:
    TestScreen() {

    }
    TestScreen(const sf::Font *font, int width, int height) {
        m_Labels.resize(3);
        m_Labels[0] = Label(font, "Start game", width / 2.0, height / 2.0 - 24);
        m_Labels[1] = Label(font, "Options", width / 2.0, height / 2.0);
        m_Labels[2] = Label(font, "Exit", width / 2.0, height / 2.0 + 24);
    }

    void Render(sf::RenderWindow *window) {
        for (auto &label : m_Labels) {
            label.Render(window);
        }
    }
};

class IntroScreen : Screen {

};

#endif