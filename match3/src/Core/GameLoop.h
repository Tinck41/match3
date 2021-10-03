#pragma once

#include "Core/Scene/Scene.h"
#include "Core/ImGui/EditorLayer.h"

class GameLoop 
{
private:
	sf::RenderWindow m_Window;

	sf::Clock m_DeltaClock;
	sf::Time m_DeltaTime;

	Scene m_ActiveScene;

	std::unique_ptr<EditorLayer> m_EditorLayer = nullptr;

	void Init();
public:
	GameLoop();
	~GameLoop();

	void Run();
};
