#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Map.h"

enum PlayerWalkingDirection
{
	Up,
	Down,
	Right,
	Left
};

class Player : public Entity
{
public:
	Player();

	void PlayerFunctionality(sf::Event &eventPI, Map &map);

private:

	//Rooms / Map
	int RoomPlayerIs;

	//Player Input
	void HandlePlayerInput(sf::Event &eventPI);
	void PlayerMovement();
	void PlayerFacing();

	bool canMoveUp;
	bool canMoveDown;
	bool canMoveRight;
	bool canMoveLeft;
	

	//Collisions
	void PlayerCollisions(Map &map);
	bool playerColliding = false;
	void AllowPlayerMovement();

	//Rotation
	PlayerWalkingDirection playerWalkingDirection;
};

