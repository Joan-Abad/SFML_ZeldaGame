#include "Player.h"
#include <iostream>
#include <vector>
#include "RoomPiece.h"
#include "Room.h"
Player::Player() : Entity("Art/Soldier.png")
{
	// TODO : REMEMBER PLAYER ROOM IS AFTER CLOSING GAME AND POSITION
	//Player Room 
	RoomPlayerIs = 0;

	//Entity Speed
	speed = 0.1f;

	//Rotation Stuff
	spr_entity.setRotation(-90.f);
	spr_entity.setOrigin(tex_entity.getSize().x / 2, tex_entity.getSize().y / 2);
	playerWalkingDirection = PlayerWalkingDirection::Up;

	//Movement 
	canMoveUp = true;
	canMoveLeft = true;
	canMoveDown = true;
	canMoveRight = true;
}

void Player::PlayerFunctionality(sf::Event & eventPI, Map &map)
{
	//Player Input
	HandlePlayerInput(eventPI);

	//Collisions
	PlayerCollisions(map);
}

void Player::HandlePlayerInput(sf::Event & eventPI)
{
	//Player Movement
	PlayerMovement();

	//Player facing rotation
	PlayerFacing();

}

void Player::PlayerMovement()
{
	//Move Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (canMoveLeft == true)
		{
			spr_entity.setPosition(spr_entity.getPosition().x - speed, spr_entity.getPosition().y);
			playerWalkingDirection = PlayerWalkingDirection::Left;
			AllowPlayerMovement();
		}
	}

	//Move Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (canMoveRight == true)
		{
			spr_entity.setPosition(spr_entity.getPosition().x + speed, spr_entity.getPosition().y);
			playerWalkingDirection = PlayerWalkingDirection::Right;
			AllowPlayerMovement();
		}
	}

	//Move Up
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (canMoveUp == true)
		{
			spr_entity.setPosition(spr_entity.getPosition().x, spr_entity.getPosition().y - speed);
			playerWalkingDirection = PlayerWalkingDirection::Up;
			AllowPlayerMovement();
		}
	}

	//Move Down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (canMoveDown == true)
		{
			spr_entity.setPosition(spr_entity.getPosition().x, spr_entity.getPosition().y + speed);
			playerWalkingDirection = PlayerWalkingDirection::Down;
			AllowPlayerMovement();
		}
	}

	

}

void Player::PlayerFacing()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		spr_entity.setRotation(-90.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		spr_entity.setRotation(90.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		spr_entity.setRotation(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		spr_entity.setRotation(180.f);
	}
}

void Player::PlayerCollisions(Map & map)
{
	//TODO : DONT FOR RANGE ALL ROMS, GET THE ROOM IN THE VECTOR THE SAME ROOM YOUR PLAYER IS IN
	PlayerWalkingDirection playerDirectionWhenColliding = PlayerWalkingDirection::Up;

	//Check all rooms
	for (auto room : map.getRoomsOnMap())
	{

		for (int i = 0; i < room.second->vecRoomPieces.size(); ++i)
		{
			//If Sprite stores is a wall
			if (room.second->vecRoomPieces[i]->getRoomPieceType() == RoomPieceTypes::Wall)
			{
				//If this wall intersects with the player
				if (spr_entity.getGlobalBounds().intersects(room.second->vecRoomPieces[i]->getSprite().getGlobalBounds()))
				{
					if (playerColliding == false)
					{
						playerDirectionWhenColliding = playerWalkingDirection;
						playerColliding = true;
					}
					//if player is colliding
					if (playerColliding == true)
					{
						const float fixPush = 0.5f;
						if (playerDirectionWhenColliding == PlayerWalkingDirection::Up)
						{
							canMoveUp = false;
							spr_entity.move(0, fixPush);
						}
						if (playerDirectionWhenColliding == PlayerWalkingDirection::Down)
						{
							canMoveDown = false;
							spr_entity.move(0, -fixPush);
						}
						if (playerDirectionWhenColliding == PlayerWalkingDirection::Right)
						{
							canMoveRight = false;
							spr_entity.move(-fixPush, 0);
						}
						if (playerDirectionWhenColliding == PlayerWalkingDirection::Left)
						{
							canMoveLeft = false;
							spr_entity.move(fixPush, 0);
						}
					}
					i = room.second->vecRoomPieces.size();
				}
			}
			else
			{
				AllowPlayerMovement();
				playerColliding = false;
			}


		}

	}
}


void Player::AllowPlayerMovement()
{
	canMoveUp = true;
	canMoveDown = true;
	canMoveLeft = true;
	canMoveRight = true;
}
