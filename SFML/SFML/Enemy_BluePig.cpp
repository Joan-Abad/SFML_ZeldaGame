#include "Enemy_BluePig.h"
#include "Room.h"
#include <iostream>
Enemy_BluePig::Enemy_BluePig(int directionHorizontal, int directionVertical, const sf::Vector2f SpawnPosition, int idRoomSpawn) : Entity("Art/enemy1.png"), initialVelocity(speed)
{
	roomSpawned = idRoomSpawn;

	spr_entity.setPosition(SpawnPosition);

	direccionVert = directionVertical;
	direccionHorizont = directionHorizontal;
	
}

/*directionVertical: 0 = NONE, 1 = Up , 2 = Down 
directionHotizonral: 0 = NONE, 1 = Left, 2 = Right */
void Enemy_BluePig::EnemyMovement(Map &map, Player &player)
{
//	std::cout << "\nPos X: " << spr_entity.getPosition().x;
//	std::cout << "\nPos Y: " << spr_entity.getPosition().y;
	
	switch (direccionHorizont)
	{
		case 0: 
			HorizontalSpeed = 0.f;
			break;
		case -1: 
			HorizontalSpeed = initialVelocity * -1;
			break;
		case 1: 
			HorizontalSpeed = initialVelocity;
			break;
		default:
			HorizontalSpeed = 0.f;
			break;
	}
	//std::cout << "HorizontalSpeed : " << direccionHorizontal;

	switch (direccionVert)
	{
	case 0:
		VerticalSpeed = 0.f;
		break;
	case -1:
		VerticalSpeed = initialVelocity * -1;
		break;
	case 1:
		VerticalSpeed = initialVelocity;
		break;
	default:
		VerticalSpeed = 0.f;
		break;
	}
	
	getSprite().move(HorizontalSpeed,VerticalSpeed);

	CheckAICollisions(map,player);
}

void Enemy_BluePig::CheckAICollisions(Map &map, Player &player)
{

	auto roomPlayerIsIn = map.rooms.at(player.getRoomId());
	//Get all AI on Vectors
	
	//CHECK COLLISION WITH WALLS
	for (auto roomPiece : roomPlayerIsIn->vecRoomPieces)
	{
		if (roomPiece->getRoomPieceType() == Wall)
		{
			if (spr_entity.getGlobalBounds().intersects(roomPiece->getSprite().getGlobalBounds()))
			{
				direccionHorizont *= -1;
				direccionVert *= -1;

				EnemyMovement(map,player);
			}
			else
			{
			}
		}
	}


		//CHECK COLLISION WITH PLAYER
		if (roomSpawned == player.getRoomId())
		{
			if (spr_entity.getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
			{
				std::cout << "\nTOUCHING PLAYER";
			}
		}
}

