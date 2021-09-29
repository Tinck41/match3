#include "m3pch.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{
}

bool SceneManager::Load(const std::string& sceneName)
{
	return false;
}

void SceneManager::Update(float dt)
{
	m_CurScene->Update(dt);
}

void SceneManager::Render(std::shared_ptr<sf::RenderWindow> window)
{
	m_CurScene->Render(window);
}

void SceneManager::Save()
{
}
