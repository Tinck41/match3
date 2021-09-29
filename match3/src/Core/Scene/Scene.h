#pragma once

#include <SFML/Graphics.hpp>

class Scene
{
private:

	
public:
	Scene();
	~Scene();

	void Update(float dt);
	void Render(std::shared_ptr<sf::RenderWindow> window);
};

