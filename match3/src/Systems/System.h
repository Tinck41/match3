#pragma once

#include <entt.hpp>
#include <SFML/Graphics.hpp>

#include "Core/Components.h"

class System {
private:

public:
	System() = default;
	~System() = default;

	virtual void Update(float dt, entt::registry& reg) = 0;
	virtual void Render(sf::RenderWindow& window, entt::registry& reg) = 0;
};
