#include "game.hpp"

void Game::Init() {
    Logger::Debug_log("Begun Game::Init()");
    m_Clock = sf::Clock();
    m_Frames = 0;

    Logger::Debug_log("Creating window...");
    m_Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Game!");
    m_Window.get()->setFramerateLimit(75);
    Logger::Debug_log("Done.");

    Logger::Debug_log("Initializing content managers...");
    ResourceManager::Init("content");
    ResourceManager::LoadFont("arial.ttf");
    ResourceManager::LoadTexture("dog.jpg", "dog");
    Logger::Debug_log("Done.");

    m_Screen = TestScreen(ResourceManager::GetSkullFont(), m_Window->getSize().x, m_Window->getSize().y);
}

void Game::Update(sf::Time elapsed) {
    
    // FPS stuff
    m_FPS_timer += elapsed;
    ++m_Frames;
    if (m_FPS_timer.asSeconds() >= 1.0f) {
        m_FPS_timer = sf::Time::Zero;
        std::cout << m_Frames << '\n';
        m_Frames = 0;
    }
}

void Game::Render(sf::Time elapsed) {
    m_Window->clear();
    sf::Sprite sprite;
    sprite.setTexture(*ResourceManager::GetTexture("dog"));
    m_Window->draw(sprite);

    m_Screen.Render(m_Window.get());
    m_Window->display();
}

Game::Game() {
    Logger::Init();
}

void Game::Run(){
    while (m_Window->isOpen()) {
        sf::Event event;
        while (m_Window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    m_Window->close();
                    break;

                case sf::Event::Resized:
                    // Respond to window resize
                    break;

                case sf::Event::LostFocus:
                    m_Window->setFramerateLimit(20);
                    break;
                case sf::Event::GainedFocus:
                    m_Window->setFramerateLimit(75);
                    break;

                case sf::Event::TextEntered:
                    // User text input
                    break;
                case sf::Event::KeyPressed:
                    // Single key presses go here
                    break;
                
            }
        }

        sf::Time elapsed = m_Clock.restart();
        this->Update(elapsed);
        this->Render(elapsed);
    }
}

Game::~Game(){
}
