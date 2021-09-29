#include "m3pch.h"
#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Update(float dt)
{
}

void Scene::Render(std::shared_ptr<sf::RenderWindow> window)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	window->draw(shape);
}


