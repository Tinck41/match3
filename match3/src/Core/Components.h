#pragma once

#include <SFML/Graphics.hpp>

struct TransformComponent {
	sf::Vector2f translation{ 0.f, 0.f };
	sf::Vector2f rotation{ 0.f, 0.f };
	sf::Vector2f scale{ 0.5f, 0.5f };
};

struct TagComponent {
	std::string name = "entity";
};

struct GridComponent {
	uint32_t columns = 0;
	uint32_t rows = 0;
	sf::Vector2f cellSize{ 0.f, 0.f };
};

struct SpriteComponent {
	std::string source = "";
	sf::Sprite sprite;

	sf::Color color{ 15, 200, 0, 255 };
};
