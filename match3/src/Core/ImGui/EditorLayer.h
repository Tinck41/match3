#pragma once

#include <SFML/Graphics.hpp>
#include <entt.hpp>

class EditorLayer 
{
private:
	void Init();

	float m_Time = 0.f;
public:
	EditorLayer();
	~EditorLayer();

	void Update(float dt);
	void Render(std::shared_ptr<sf::RenderWindow> window);
};