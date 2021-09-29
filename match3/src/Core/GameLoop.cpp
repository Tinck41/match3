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

    m_DeltaTime = m_DeltaClock.restart();
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

        SceneManager::getInstance().Update(m_DeltaTime.asSeconds());
        SceneManager::getInstance().Render(m_Window);

        m_DeltaTime = m_DeltaClock.restart();
    }
}