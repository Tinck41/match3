#pragma once

#define SCENES_PATH "../assets/scenes/"

#include <SFML/Graphics.hpp>
#include <entt.hpp>

#include "Systems/System.h"

class Scene
{
private:
	entt::registry m_Registry;

	std::vector<System*> m_Systems;

	bool Load(const std::string& sceneName = "default.json");
public:
	Scene();
	~Scene();

	entt::registry& GetRegistry() { return m_Registry; }

	void Update(float dt);
	void Render(sf::RenderWindow& window);
};

