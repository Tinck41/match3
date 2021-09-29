#pragma once

#include "Core/Scene/Scene.h"

class SceneManager {
private:
	std::shared_ptr<Scene> m_CurScene = nullptr;
public:
	SceneManager();
	~SceneManager();

	bool Load(const std::string& sceneName);

	void Update(float dt);
	void Render(std::shared_ptr<sf::RenderWindow> window);
	void Save();
};