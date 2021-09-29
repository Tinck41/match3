#pragma once

#include <SFML/Graphics.hpp>

class Scene
{
private:
	sf::RenderWindow window;

	void Update();
	void Render();
public:
	Scene();
	~Scene();
};

