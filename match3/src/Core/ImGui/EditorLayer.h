#pragma once

#include <SFML/Graphics.hpp>
#include <entt.hpp>

#include "Core/Scene/Scene.h"

class EditorLayer 
{
private:
	void Init();

	std::shared_ptr<Scene> m_ActiveScene = nullptr;

	float m_Time = 0.f;
public:
	EditorLayer();
	~EditorLayer();

	void SetScene(std::shared_ptr<Scene> scene);

	void Update(float dt);
	void Render(sf::RenderWindow& window);
};