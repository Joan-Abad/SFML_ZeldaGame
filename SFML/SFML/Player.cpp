#include "Player.h"
#include <iostream>
#include <vector>
#include "RoomPiece.h"
#include "Room.h"
#include "GraphicsUtils.h"

Player::Player(const sf::Vector2f windowSize) : Entity("Art/Soldier.png")
{
	// TODO : REMEMBER PLAYER ROOM IS AFTER CLOSING GAME AND POSITION
	//Player Room 
	id_RoomPlayerIs = 0;

	//Entity Speed
	speed = 0.2f;

	//Rotation Stuff
	spr_entity.setRotation(-90.f);
	spr_entity.setOrigin(tex_entity.getSize().x / 2, tex_entity.getSize().y / 2);
	playerWalkingDirection = PlayerWalkingDirection::Up;

	//Movement 
	canMoveUp = true;
	canMoveLeft = true;
	canMoveDown = true;
	canMoveRight = true;

	//Transform
	spr_entity.setScale(0.7f, 0.7f);
	spr_entity.setPosition(windowSize.x / 2, windowSize.y / 2);
	
	//Set collisions size
	sf::Vector2f rectCollisionSizeLeft = { GraphicsUtils::spriteSize(spr_entity).x / 10.f, GraphicsUtils::spriteSize(spr_entity).y/2 };
	sf::Vector2f rectCollisionSizeTop = { GraphicsUtils::spriteSize(spr_entity).x/2, GraphicsUtils::spriteSize(spr_entity).y/10.f };
	
	rectCollisionBot.setSize(rectCollisionSizeTop);
	rectCollisionLeft.setSize(rectCollisionSizeLeft);
	rectCollisionRight.setSize(rectCollisionSizeLeft);
	rectCollisionTop.setSize(rectCollisionSizeTop);

	//HIDE Rectangle collisions
	rectCollisionTop.setFillColor(sf::Color(0, 0, 0, 0));
	rectCollisionBot.setFillColor(sf::Color(0, 0, 0, 0));
	rectCollisionRight.setFillColor(sf::Color(0, 0, 0, 0));
	rectCollisionLeft.setFillColor(sf::Color(0, 0, 0, 0));

}

void Player::PlayerFunctionality(sf::Event & eventPI, Map &map)
{
	MovePlayerCollisions();

	//Player Input
	HandlePlayerInput(eventPI);

	//Collisions
	//PlayerCollisions(map);


}

void Player::drawPlayer(sf::RenderWindow & window)
{
	window.draw(spr_entity);
	window.draw(rectCollisionBot);
	window.draw(rectCollisionLeft);
	window.draw(rectCollisionRight);
	window.draw(rectCollisionTop);
}

void Player::MovePlayerCollisions()
{
	// TOP
	rectCollisionTop.setPosition(spr_entity.getPosition().x - (GraphicsUtils::spriteSize(spr_entity).x / 5), (spr_entity.getPosition().y - GraphicsUtils::spriteSize(spr_entity).y / 2) + rectCollisionTop.getSize().y/2 );

	// BOT
	rectCollisionBot.setPosition(spr_entity.getPosition().x - (GraphicsUtils::spriteSize(spr_entity).x / 5), (spr_entity.getPosition().y + GraphicsUtils::spriteSize(spr_entity).y / 2) - rectCollisionTop.getSize().y*2);

	// LEFT
	rectCollisionLeft.setPosition((spr_entity.getPosition().x - GraphicsUtils::spriteSize(spr_entity).x / 2) + rectCollisionLeft.getSize().x * 2, spr_entity.getPosition().y - GraphicsUtils::spriteSize(spr_entity).y / 4);

	// RIGHT
	rectCollisionRight.setPosition((spr_entity.getPosition().x + GraphicsUtils::spriteSize(spr_entity).x / 2) - rectCollisionLeft.getSize().x * 2, spr_entity.getPosition().y - GraphicsUtils::spriteSize(spr_entity).y / 4);
}

void Player::SetRoomId(const int NewId)
{
	id_RoomPlayerIs = NewId;
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (canMoveRight == true)
		{
			spr_entity.setPosition(spr_entity.getPosition().x + speed, spr_entity.getPosition().y);
			playerWalkingDirection = PlayerWalkingDirection::Right;
			AllowPlayerMovement();
		}
	}

	//Move Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (canMoveUp == true)
		{
			spr_entity.setPosition(spr_entity.getPosition().x, spr_entity.getPosition().y - speed);
			playerWalkingDirection = PlayerWalkingDirection::Up;
			AllowPlayerMovement();
		}
	}

	//Move Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		system("cls");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		DebugOn = true;
	}
}

void Player::PlayerCollisions(Map & map)
{
	/*
	//TODO : DONT FOR RANGE ALL ROMS, GET THE ROOM IN THE VECTOR THE SAME ROOM YOUR PLAYER IS IN
	PlayerWalkingDirection playerDirectionWhenColliding = PlayerWalkingDirection::Up;

	//Check all rooms
	for (auto &room : map.getRoomsOnMap())
	{

		for (int i = 0; i < room.second->vecRoomPieces.size(); i++)
		{
			/*if (i == 6)
			{
				switch (room.second->vecRoomPieces[i]->getRoomPieceType())
				{
				case Wall:
					std::cout << "\nROOM PIECE TYPE IS: WALL";
					break;
				case Floor:
					std::cout << "\nROOM PIECE TYPE IS: FLOOR";
					break;
				}				
			}*/
			//If Sprite stores is a wall

			/*if (DebugOn == true)
			{
				switch (room.second->vecRoomPieces[i]->getRoomPieceType())
				{
				case Wall:
					std::cout << "\nROOM " << i <<" PIECE TYPE IS: WALL";
					break;
				case Floor:
					std::cout << "\nROOM " << i << " PIECE TYPE IS: FLOOR";
					break;
				}
				//std::cout << "\nPIECE TYPE " << i << ": " << room.second->vecRoomPieces[i]->getRoomPieceType();
			}
			if (room.second->vecRoomPieces[i]->getRoomPieceType() == RoomPieceTypes::Wall)
			{
				//If this wall intersects with the player
				if (spr_entity.getGlobalBounds().intersects(room.second->vecRoomPieces[i]->getSprite().getGlobalBounds()))
				{
					std::cout << "\nWall bro on vec " << i << ", type: " << room.second->vecRoomPieces[i]->getRoomPieceType();
					
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
					//end loop
					i = room.second->vecRoomPieces.size();
				}
			}
			else
			{
				AllowPlayerMovement();
				playerColliding = false;
			}


		}
		DebugOn = false;
	}

	*/

	
}


void Player::AllowPlayerMovement()
{
	canMoveUp = true;
	canMoveDown = true;
	canMoveLeft = true;
	canMoveRight = true;
}
