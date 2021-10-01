#pragma once

#include "System.h"

class GridSystem : 
	public System
{
private:

public:
	GridSystem() = default;
	~GridSystem() = default;

	virtual void Update(float dt, entt::registry& reg) override;
	virtual void Render(std::shared_ptr<sf::RenderWindow> window, entt::registry& reg) override;

};
