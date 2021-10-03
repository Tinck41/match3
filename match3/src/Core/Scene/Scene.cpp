#include "m3pch.h"

#include "Scene.h"
#include "nlohmann/json.hpp"
#include "Core/Components.h"
#include "Systems/GridSystem.h"
 
bool Scene::Load(const std::string& sceneName)
{
	nlohmann::json json;

	try
	{
		std::ifstream stream(SCENES_PATH + sceneName);
		json = nlohmann::json::parse(stream);
	}
	catch (nlohmann::json::parse_error& ex)
	{
		std::cerr << "parse error at byte " << ex.byte << std::endl;
		return false;
	}

	auto entities = json["entities"];
	for (size_t i = 0; i < entities.size(); i++)
	{
		auto entity = m_Registry.create();

		auto components = entities[i]["components"][0];

		if (components.contains("TagComponent"))
		{
			TagComponent tagComponent;

			if (components["TagComponent"].contains("name"))
			{
				tagComponent.name = components["TagComponent"]["name"];
			}

			m_Registry.emplace<TagComponent>(entity, tagComponent);
		}
		else
		{
			TagComponent tagComponent;
			m_Registry.emplace<TagComponent>(entity, tagComponent);
		}

		
		if (components.contains("TransformComponent")) 
		{
			TransformComponent transformComponent;

			if (components["TransformComponent"].contains("translation"))
			{
				transformComponent.translation.x = components["TransformComponent"]["translation"][0];
				transformComponent.translation.y = components["TransformComponent"]["translation"][1];
			}
			if (components["TransformComponent"].contains("rotation"))
			{
				transformComponent.rotation.x = components["TransformComponent"]["rotation"][0];
				transformComponent.rotation.y = components["TransformComponent"]["rotation"][1];
			}
			if (components["TransformComponent"].contains("scale"))
			{
				transformComponent.scale.x = components["TransformComponent"]["scale"][0];
				transformComponent.scale.y = components["TransformComponent"]["scale"][1];
			}

			m_Registry.emplace<TransformComponent>(entity, transformComponent);
		}
		else 
		{
			TransformComponent transformComponent;
			m_Registry.emplace<TransformComponent>(entity, transformComponent);
		}

		if (components.contains("GridComponent"))
		{
			GridComponent gridComponent;

			if (components["GridComponent"].contains("columns"))
			{
				gridComponent.columns = components["GridComponent"]["columns"];
			}
			if (components["GridComponent"].contains("rows"))
			{
				gridComponent.rows = components["GridComponent"]["rows"];
			}
			if (components["GridComponent"].contains("cellSize"))
			{
				gridComponent.cellSize.x = components["GridComponent"]["cellSize"][0];
				gridComponent.cellSize.y = components["GridComponent"]["cellSize"][1];
			}

			m_Registry.emplace<GridComponent>(entity, gridComponent);
		}

		if (components.contains("SpriteComponent"))
		{
			SpriteComponent spriteComponent;

			m_Registry.emplace<SpriteComponent>(entity, spriteComponent);
		}
	}

	return true;
}

Scene::Scene()
{
	Load();

	m_Systems.push_back(new GridSystem());
}

Scene::~Scene()
{
}

void Scene::Update(float dt)
{
	for (auto system : m_Systems)
	{
		system->Update(dt, m_Registry);
	}
}

void Scene::Render(sf::RenderWindow& window)
{
	for (auto system : m_Systems)
	{
		system->Render(window, m_Registry);
	}
}


