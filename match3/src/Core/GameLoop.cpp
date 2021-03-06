#include "m3pch.h"

#include "GameLoop.h"

#include <imgui.h>
#include <imgui-SFML.h>

GameLoop::GameLoop()
{
    Init();
}

GameLoop::~GameLoop()
{
}

void GameLoop::Init()
{
    m_Window.create(sf::VideoMode(800, 600), "match3");
    m_ActiveScene = std::make_shared<Scene>();

    m_EditorLayer = std::make_unique<EditorLayer>();
    m_EditorLayer->SetScene(m_ActiveScene);

    m_DeltaTime = m_DeltaClock.restart();
}

void GameLoop::Run()
{
    ImGui::SFML::Init(m_Window);

    while (m_Window.isOpen())
    {
        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
                m_Window.close();
        }

        ImGui::SFML::Update(m_Window, m_DeltaTime);

        m_EditorLayer->Update(m_DeltaTime.asSeconds());
        m_ActiveScene->Update(m_DeltaTime.asSeconds());

        m_Window.clear();
        m_EditorLayer->Render(m_Window);
        m_ActiveScene->Render(m_Window);
        ImGui::SFML::Render(m_Window);
        m_Window.display();

        m_DeltaTime = m_DeltaClock.restart();
    }
}
