#pragma once

#include "Scene/SceneManager.h"

class GameLoop 
{
private:
	std::shared_ptr<sf::RenderWindow> m_Window = nullptr;

	sf::Clock m_DeltaClock;
	sf::Time m_DeltaTime;

	void Init();
public:
	GameLoop();
	~GameLoop();

	void Run();
};
