#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Map.h"

class Map;

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
	Player(const sf::Vector2f windowSize);

	void PlayerFunctionality(sf::Event &eventPI, Map &map);

	//Getters
	int getRoomId() { return id_RoomPlayerIs; };

	//Collision
	sf::RectangleShape rectCollisionLeft;
	sf::RectangleShape rectCollisionRight;
	sf::RectangleShape rectCollisionBot;
	sf::RectangleShape rectCollisionTop;

	//Movement
	bool canMoveUp;
	bool canMoveDown;
	bool canMoveRight;
	bool canMoveLeft;
	bool PlayerWonTheGame = false;

	void drawPlayer(sf::RenderWindow &window);
	void MovePlayerCollisions();
	void SetRoomId(const int NewId);

private:

	//Rooms / Map
	int id_RoomPlayerIs;

	//Player Input
	void HandlePlayerInput(sf::Event &eventPI);
	void PlayerMovement();
	void PlayerFacing();
	
	bool DebugOn = false;

	//Collisions
	void PlayerCollisions(Map &map);
	bool playerColliding = false;
	void AllowPlayerMovement();

	//Rotation
	PlayerWalkingDirection playerWalkingDirection;

};

