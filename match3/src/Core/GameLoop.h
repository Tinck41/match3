#pragma once

#include "Scene/SceneManager.h"

class GameLoop 
{
private:
	std::shared_ptr<sf::RenderWindow> m_Window = nullptr;
	std::unique_ptr<SceneManager> m_SceneManager = nullptr;

	sf::Clock deltaClock;
	sf::Time dt;

	void Init();
public:
	GameLoop();
	~GameLoop();

	void Run();
};
