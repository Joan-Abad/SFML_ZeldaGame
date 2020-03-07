#pragma once
#include "Entity.h"
#include "Map.h"
#include "Player.h"
class Enemy_BluePig :public Entity
{
public: 
	/* directionVertical: 0 = NONE, 1 = Up , -1 = Down
		directionHotizonral: 0 = NONE, 1 = Left, -1 = Right */
	Enemy_BluePig(int directionHorizontal, int directionVertical, const sf::Vector2f SpawnPosition,int idRoomSpawn);

	
	void EnemyMovement(Map &map, Player &player);

	void CheckAICollisions(Map &map, Player &player);

	int direccionHorizont;
	int direccionVert;
	const float initialVelocity;
	
};

