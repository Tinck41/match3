#pragma once

#include "Core/Scene/Scene.h"

class SceneManager {
private:
	SceneManager();
	~SceneManager();
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

	std::unique_ptr<Scene> m_CurScene = nullptr;
public:
	static SceneManager& getInstance() {
		static SceneManager instance;

		return instance;
	}

	bool LoadScene(const std::string& sceneName);

	void Update(float dt);
	void Render(std::shared_ptr<sf::RenderWindow> window);
	void Save();
};