#ifndef SFML_PROJECT_GAME_HPP
#define SFML_PROJECT_GAME_HPP

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <thread>
#include "content_manager.hpp"
#include "screen.hpp"

class Game {
  private:
    sf::Clock m_Clock;
    bool m_is_running;
    std::unique_ptr<sf::RenderWindow> m_Window;

    // Content Managers
    ContentManager<sf::Texture> m_TexManager;
    ContentManager<sf::Font> m_FontManager;

    TestScreen m_Screen;

    // FPS counter
    uint32_t m_Frames;
    sf::Time m_FPS_timer;

    // Main loop functions
    void Update(sf::Time);
    void Render(sf::Time);

  public:
    Game();
    void Run();
    void Init();
    ~Game();

};

#endif