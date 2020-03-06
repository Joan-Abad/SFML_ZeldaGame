#pragma once
#include "Entity.h"

class VictoryItem : public Entity
{
public:
	VictoryItem(const sf::Vector2f ScreenSize);

	sf::Vector2f &getPositionToSpawn() { return PositionToSpawn; };
	
private:

	sf::Vector2f PositionToSpawn;

};

