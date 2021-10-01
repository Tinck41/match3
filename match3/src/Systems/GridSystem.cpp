#include "m3pch.h"
#include "GridSystem.h"

void GridSystem::Update(float dt, entt::registry& reg)
{

}

void GridSystem::Render(std::shared_ptr<sf::RenderWindow> window, entt::registry& reg)
{
	auto group = reg.group<GridComponent, TransformComponent>();
	for (auto e : group)
	{
		auto [grid, transform] = group.get< GridComponent, TransformComponent>(e);

		for (size_t i = 0; i <= grid.columns; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(transform.translation.y + grid.cellSize.x * i, transform.translation.y)),
				sf::Vertex(sf::Vector2f(transform.translation.y + grid.cellSize.x * i, transform.translation.y + grid.cellSize.x * grid.columns))
			};

			window->draw(line, 2, sf::Lines);
		}

		for (size_t i = 0; i <= grid.rows; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(transform.translation.x, transform.translation.x + grid.cellSize.y * i)),
				sf::Vertex(sf::Vector2f(transform.translation.x + grid.cellSize.y * grid.rows, transform.translation.x + grid.cellSize.y * i))
			};

			window->draw(line, 2, sf::Lines);
		}
	}
}
