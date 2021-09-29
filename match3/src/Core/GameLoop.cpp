#include "m3pch.h"

#include "GameLoop.h"

GameLoop::GameLoop()
{
    Init();
}

GameLoop::~GameLoop()
{
}

void GameLoop::Init()
{
    m_Window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "match3");
    m_SceneManager = std::make_unique<SceneManager>();

    dt = deltaClock.restart();
}

void GameLoop::Run()
{
    while (m_Window->isOpen())
    {
        sf::Event event;
        while (m_Window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_Window->close();
        }

        m_SceneManager->Update(dt.asSeconds());
        m_SceneManager->Render(m_Window);

        dt = deltaClock.restart();
    }
}
