#include "m3pch.h"
#include "GridSystem.h"

void GridSystem::Update(float dt, entt::registry& reg)
{
	auto view = reg.view<TransformComponent>();
	for (auto e : view)
	{
		TransformComponent& transfrom = reg.get<TransformComponent>(e);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			transfrom.translation.x += 1.f * dt * 100.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			transfrom.translation.x -= 1.f * dt * 100.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			transfrom.translation.y -= 1.f * dt * 100.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			transfrom.translation.y += 1.f * dt * 100.f;
		}
	}
}

void GridSystem::Render(sf::RenderWindow& window, entt::registry& reg)
{
	auto group = reg.group<GridComponent, TransformComponent>();
	for (auto e : group)
	{
		auto [grid, transform] = group.get<GridComponent, TransformComponent>(e);

		for (size_t i = 0; i <= grid.columns; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(transform.translation.x + grid.cellSize.x * i, transform.translation.y)),
				sf::Vertex(sf::Vector2f(transform.translation.x + grid.cellSize.x * i, transform.translation.y + grid.cellSize.y * grid.rows))
			};

			if (reg.any_of<SpriteComponent>(e)) {
				auto sprite = reg.get<SpriteComponent>(e);

				line[0].color = sprite.color;
				line[1].color = sprite.color;
			}

			window.draw(line, 2, sf::Lines);
		}

		for (size_t i = 0; i <= grid.rows; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(transform.translation.x, transform.translation.y + grid.cellSize.y * i)),
				sf::Vertex(sf::Vector2f(transform.translation.x + grid.cellSize.x * grid.columns, transform.translation.y + grid.cellSize.y * i))
			};

			if (reg.any_of<SpriteComponent>(e)) {
				auto sprite = reg.get<SpriteComponent>(e);

				line[0].color = sprite.color;
				line[1].color = sprite.color;
			}

			window.draw(line, 2, sf::Lines);
		}
	}
}
