#pragma once

#include "Core/Scene/Scene.h"

class GameLoop 
{
private:
	std::shared_ptr<sf::RenderWindow> m_Window = nullptr;

	sf::Clock m_DeltaClock;
	sf::Time m_DeltaTime;

	Scene m_ActiveScene;

	void Init();
public:
	GameLoop();
	~GameLoop();

	void Run();
};
