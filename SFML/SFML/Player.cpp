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
		std::cout << "X: " << getSprite().getPosition().x << std::endl;
		std::cout << "Y: " << getSprite().getPosition().y << std::endl;
	}
}

void Player::AllowPlayerMovement()
{
	canMoveUp = true;
	canMoveDown = true;
	canMoveLeft = true;
	canMoveRight = true;
}
